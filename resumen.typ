

= Unidad 1

== Procesos

El kernel tiene la capacidad de poner en ejecución a los programas que se
encuentran almacenados en el sistema. Cuando un programa se encuentra en
ejecución lo llamamos *proceso*. El sistema operativo controla la *creación*,
*ejecución* y *finalización* de procesos.

Un proceso se crea cuando:

  - En la secuencia de *inicio del sistema*.
  - Cuando una aplicación realiza un *system call* para crear un proceso.
  - Cuando un usuario solicita ejecutar un programa ya sea traves de la linea de comandos o
    haciendo doble click sobre un ejecutable.

El estado de un proceso en ejecución es representado por el valor que tiene el
registro *program counter* o *PC* y el contenido de los registros del
procesador.
El diseño de la memoria asiganada a un proceso generalmente se divide in
multiple secciones. Estas secciones son:

#set list(indent: 1em)
- Sección de texto: Donde se encuentra el código ejecutable.
- Sección de datos: Variables globales.
- Sección Heap: Memoria que es asignada dinámicamente durante el tiempo de
  ejecución de un programa.
- Sección Stack: Almacen temporal de datos cuando se invocan funciones se
  almacenan elementos como parametros, direcciones de retorno y variables
  locales

Podemos ver que las secciones de texto y datos tienen un tamaño fijo es decir
no cambiar durante el tiempo de ejecución de un programa. Sin embargo las
secciónes heap y stack pueden crecer o achicarce dinámicamente durante el
tiempo de ejecución de un programa.

Cada vez que se llama a una función un registro de activación contiene los
parámetros de la función, variables locales y direcciones de retorno los cuales
son ubicados dentro de la pila. Cuando el control es devuelto de la función el
registro de activación es quitado de la pila.

Aunque dos procesos esten asociados al mismo programa ellos sin embargo son
considerados dos secuencias de ejecución separadas. Cada uno tendra sus
secciones texto, datos, heap, stack

= Creación de Procesos

Durante el curso de la ejecución de un proceso dicho proceso puede crear varios procesos nuevos. El
proceso creador es llamada *proceso padre* y los nuevos procesos son llamados procesos hijos. Cada
uno de estos procesos hijos pueden crear nuevos procesos formando así un arbol de procesos.

La mayoría de los sistemas operativos (incluyendo Unix, Linux, Windows) identifican sus procesos de
acuerdo a un identificador único llamado process identifi o pid el cual es usualmente un número
entero. Este identificador puede utilizarse como índice para acceder a varios atributos de un
procesos dentro del kernel.

#image("Arbol de procesos.jpg")

Cuando un proceso crea un nuevo proceso existen dos posibilidades con respecto a la ejecución:
  
  + El padre continua ejecutandose concurrentemente con su hijo.
  + El padre espera hasta que algun o todos sus hijos hallan terminado.

= Estado de un Proceso

A medida que un proceso se ejecuta cambia de estado. El estado de un proceso
se define en parte por la actividad actual de ese proceso. Un proceso puede
estar en uno de los siguientes estados:
  
#set list(indent: 1em)
  - New: El proceso ha sido creado.

  - Running: Las instrucciones están siendo ejecutadas.

  - Waiting: El proceso está en espera debido a la ocurrencia de un evento (
    Se completo un E/S o se recibio una llamada del sistema). 
  
  - Ready: El proceso está esperando a ser asignado a algún procesador.

= Bloque de Control de Proceso (Process Control Block)

Cada proceso es representado en el sistema operativo mediante un PCB también
llamada bloque de control de tarea. Este contiene distintas secciones con
información asociada a ese proceso en especifico. Algunas de ellas son:
  
#set list(indent: 1em)
  - *Process state*: Contiene información acerca del estado del proceso.
  
  - *Program counter*: El contador de programa indica la dirección de memoria de
    la próxima instrucción que debe ejecutar el procesador.

  - *Cpu register*: Los registros varían en cantidad y en tipo dependiendo de la
    aquitectura de la computadora. Entre ellos se incluyen el acumulador,
    puntero de pila, registros de índice y registros de proposito general.
    Toda esta información junto con el contador de programa debe ser
    resguardad cada vez que ocurre una interrupción esto es para permitir que
    le proceso siga ejecutandose una vez que se reasignado (rescheduled) a un
    procesador para que sea ejecutado.

  - *Información de la planificación del cpu*: Contiene información sobre la
    prioridad del proceso, punteros a la cola de planificación y otros
    parametros de planificación.

  - *Información de Administración de Memoria*: Contiene información de los
    registros limite y base, información sobre la tabla de páginas o la tabla
    de segmentos dependiendo del sistema de memoria utilizado en el sistema
    operativo.

  - *Información de Conteo*: Contiene información sobre la cantidad de cpu
    utilizado en tiempo real, limites de tiempo, número de cuentas, trabajos o
    procesos.

  - *Información del estado de E/S*: Esta información incluye la list de los
    dispositivos de entrada/salida asignados al proceso así como la lista de
    los archivos abiertos, etc.

En resumen el PCB sirve como repositorio de todos los datos necesarios para
iniciar o reanudar un proceso además de los datos de conteo.

= Estados de un proceso

Cuando se crea un proceso esta pasas por distintos estados durante su ciclo de
vida algunos son nuevo, listo, ejecutando bloqueado, listo suspendido,
bloqueado suspendido
