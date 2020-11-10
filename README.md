# Taller de programacion
# Trabajo Práctico n°3
## Alumno: Montiel Ramiro
## Padron: 100870
### Repositorio: https://github.com/ramaMont/taller-tp3

## Introduccion

El trabajo práctico consiste en realizar dos programas: un cliente y un servidor. 
- El cliente envia petitorios HTTP al servidor mediante la red, espera la respuesta, la imprime por pantalla y finaliza. 
- El servidor, debe soportar múltiples clientes a la vez, a medida que acepta conexiones, va resolviendo los petitorios de cada cliente de forma concurrente y va mostrando los petitorios que se hicieron. Para finalizar el programa servidor, el mismo está esperando que por teclado se ingrese la letra "q", luego de presionarla, todas las conexiones son cerradas y luego programa se cierra.

Los petitorios HTTP soportados son:
- `GET  <recurso>` El cual retorna el contenido del recurso pedido si existe y no encontrado si no existe.
- `POST <recurso> <body>` El cual inserta en el servidor el body recibido en el recurso seleccionado, si el recurso ya se encontraba en uso, el mismo es pisado.

Si se envía otro tipo de petitorio HTTP que no es de los arriba mencionado, el servidor retorna que se utilizo un método no permitido.

Al momento de ejecutar al programa cliente se debe seguir la siguiente sintaxis:

`./client <server-host> <server-port>`

Al momento de ejecutar al programa cliente se debe seguir la siguiente sintaxis:

`./server <server-port> <root_file>`

Siendo root_file un archivo de texto que sera insertado en el directorio raiz ("/") del servidor.

Tanto en el programa Servidor como en el Cliente:

- **No** se pudede alterar el orden de los parámetros.
- No hay perdidas de memoria al finalizar la ejecucion de los mismos.
- Los programas avisan si se ingreso incorrectamente alguno de sus parametros emitiendo mensajes de error.
- Los programas avisan si surgio algun error durante su ejecucion.

## Descripcion de la resolucion del trabajo

### Cliente

Para resolver el trabajo practico se creó la clase: `ClientHolder` la cual contiene a las clases comunes: 
`Socket` y `ParamReaderClient`.
A continuacion se muestra el diagrama de clases simplificado correspondiente al cliente:

#### Diagrama de clases programa cliente

![diagrama cliente](http://www.plantuml.com/plantuml/png/bSzDwiCW40NmlQTm-VyWq2Ea54gw2yq9h1c2H9qmCsRHqhlNwAfaq-wU-FWzRLaCIGfUyUpYOiW4RRrXFegGkoM1YyKuk3leWoeN-kGTHEdGZq3weVG_Ba16a7v-rVDpfjzALp1PgU9cDIjOGTA6fXGW2dBs9v0UIJ9VSeSitqqDQ6UeliixN8xdCNEv6S5McY6EWr391DQjK5QKUllmNzFidxwlr4dLPZC5_m80)

En el mismo podemos observar:

- Durante la construccion del cliente se construyen tambien los objetos que componen dicha clase, para aprovechar los beneficios de RAII.
- Durante la construccion del objeto Socket, se realiza la iteracion de la funcion getaddrrinfo y luego se procede a la conexion del mismo.
- La clase ClientHolder tiene modificado su operador (), aqui es donde se realiza toda la tarea del cliente: Como ya tiene inicializado el objeto Socket, en esta funcion simplemente se envia el petitorio y se espera a su respuesta, una vez realizado esto, el programa termina.

### Servidor

Para resolver el trabajo practico se creó la clase: `ServerHolder` la cual contiene a las clase común `ParamReaderServer` y
por otra parte tambien contiene a una clase solamente conocida por parte del servidor llamada `Servidor`.
A continuacion se muestra el diagrama de clases simplificado correspondiente al servidor:

#### Diagrama de clases programa servidor genérico

![diagrama servidor](http://www.plantuml.com/plantuml/png/bPB1Yjmm38RlVWgVIhibq7jBsQLbQA67ORBtnUk8Z8aZkP8yBIrzzpes0mbJwEOKMRA-Nx_YUr77ckTeP0gO7BlP-kX47bGvF6U5hvwm3x_0lZErO7lW2_0NYWEm_MtiMqh0JebVlp5_NeuvBfTEu0gb4HTMTm5VIDRnc6T09Idy4VH8h0LVuqE8i4-g9p-1Ldv0jLAFXw7WpYJwBOW21XohWFCUadwA0R0f2k3GAzUOmOVBNl5YBWpKxCqksGB9B2JBiJJyRAvEBLjb4idcd752-e4d-BvF-l7yi9Xn0wsN--7npE26kuys0R2yBuMse1AykavROX_1uO5Ot0GepN_6jXEbL8CWdmbXxrH7Q7_xtxhFHD5E0Eb9NIpGyPeByiGPiMJ-CuencpTwrtMth-tsodM4RQKhbTKUpIfkNSt2EjsjO3VtctlJFcj2osoRxm67FCU_)

En el mismo podemos observar:
- Los objetos pertenecientes al servidor tambien se inicializan de forma RAII.
- El servidor contiene solamente 2 estructuras: el lector de parametros y el objeto Servidor, el cual es el encargado de almacenar toda la informacion y de procesar los petitorios.
- La clase ServerHolder tiene modificado su operador (), aqui es donde se realiza toda la tarea del servidor: Lo que hace es lanzar el thread ThAceptador y se queda esperando el ingreso de un caracter para finalizar el programa. Si se ingresa una letra "q" entonces se procede a terminar el thread ThAceptador y se finaliza el programa.
- La clase ThAceptador se encarga de crear los threads que van a resolver las consultas de los clientes (los ThPeer), para ello inicializa al socket con el cual realiza el accept durante el constructor de la misma, además finaliza la ejecucion de los threads cliente que ya terminaron, limpia la memoria y finaliza las conexiones de los ThPeer una vez que por teclado se recibió la letra "q".
- Se explicará el funcionamiento de la clase ThPeer en la siguiente seccion.

#### Diagrama de clases programa servidor: Manejo de petitorios

A continuacion se muestra el diagrama de clases simplificado correspondiente al manejo de los petitorios por parte los ThPeer en el programa servidor:

![diagrama servidor ThPeer](http://www.plantuml.com/plantuml/png/fPHDYzim48Rl-XKwBVk1eVVsi4jBIw4Ki-azoFAG2CiQHpDA-j7yzqwaE8sp119o6xtMlC_CQF0piOcSUg-eSs4mqVJQUaFqmXnTanY-MWmpznlqEvK_w5TOrH4j467KVvIkI6w6XOwmIa0iGWti6AF3HosE199n_w3qqr3Ixky8ujgr61_UgwswX6mQWHZBvOO-08H_plRYVhu0JziWJD72xSOrqXddKMcm_NKxvploY_UuWVQOrWCliPq7qyDDeo-C6TfkFoSNM5C-Vcx5UOd4tnmn1A7cPpRMmi0VlOF0MI08xOnZZYDOjmO9jrV0zpLdV6y6BIOf4jBkA0a_nNS1_5hKicf8atCANS1DA9juJUC_bZL08PSPI70t5YHnW-Xr1p3CsNWnNOoQetbC8MJbIQ8o2SOX1uu-OO1Io_zj_l2tgdRxU2hLIAVQqQkhVOsLg8TBn-9OxgWzxhJIp66qLI5F1U5Eb0bryX-OijzyAc3r3A5DlVy7)

En el mismo podemos observar:
- La clase ReqProcessor funciona como una fabrica abstracta de petitorios, se encarga de parsear el petitorio recibido y en funcion del tipo que sea (GET, POST o NOTALLOWED) retorna un objeto de alguno de estos 3 tipos.
- La clase ThPeer resuelve los petitorios de forma polimórfica, para ello, usa al objeto recien creado por ReqProcessor y le aplica el mismo método `process` sin importar que tipo de objeto sea (Get, Post, NotAllowed) ya que los 3 respetan la interfaz Petitorio.
- La clase ThPeer utiliza al Socket que contiene para recibir el petitorio por red y tambien para enviar la respuesta. Luego de realizar toda su tarea, el hilo cambia su atributo booleano `is_running` para que posteriormente cuando el thread ThAceptador acepte a un nuevo cliente o se cierre, limpie su memoria y lo finalice.

#### Diagrama de clases: Herencias utilizadas:

A continuacion se muestra el diagrama de clases simplificado a las herencias utilizadas que no se mostraron en los diagramas anteriores para simplificar su visualizacion:

![diagrama herencias](http://www.plantuml.com/plantuml/png/pPBFIiH03CRlynHp4lzGy04yxAA8tehrlioseOwTJagIwS4_xsvskcBBme8AugbVlePylxHPiJYIr0V3dO-38zVREZZcjGZvRHAuhp5M_WNifSalxECJWMligx65J79w67kHXvsUgNf67xCOlOvtmL9QrYmuB0pFDnX1hNVp7PPr3OEu1Ya3ZL2BoW60MCiAwmv4nKa5D7hjKhr53BO363RYWWQrdvxdZL96TVw0kmHGvF_CMEwQ7i0riFYsZjhKGnJaMK0BKYB9pnDskqyvXpFLKtthmoysk0vUcO_DlqFUy-yF_EgjAEO7jlJp3pJp-pl_iiqiEVSVhdgqPQ8rAuXDwiC7)

En el mismo podemos observar:
- Las clases ThAceptador y ThPeer funcionan en hilos separados ya que heredan de la clase Thread, la cual tiene como atributo un std::thread y tiene implementado el metodo virtual start() el cual es usado por las clases hijas.
- Las clases ParamReaderClient y  ParamReaderServer heredan de la clase ParamReader para no duplicar codigo a la hora de inicializarse y al momento de devolver el puerto, y en cada una se implementaron funciones propias de cada objeto para retornar el DNS del host, en el caso del cliente o el path al archivo en el caso del servidor.
