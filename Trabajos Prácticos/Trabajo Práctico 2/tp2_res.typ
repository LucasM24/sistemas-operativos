+ Algunas system calls de XINU:
  - suspend(pid): Suspende un proceso poniendolo en hibernación. Esta
    función desactiva las interrupciones cuando es invocada. La
    suspención solo es válida para procesos que están en estado listo
    o ejecutando.
  - resume(pid): Quita un proceso del estado de suspención y lo pone
    en estado listo.
  - getprio(pid): Permite obtener la prioridad en la planificación de
    un procesos arbitrario.
  - chprio(pid, newprio)
