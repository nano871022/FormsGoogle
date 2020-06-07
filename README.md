# FormsGoogle
Se realiza la configuración para realizar conexiones al servidor de google para agregar registros de formulario

Esta api se contruye para realizar una facil utilización para la comunicación con la pagina de docs.google.com
con la cual permite cargar registros dentro del formulario

Se necesita lo siguiente
* fingerprint (const char *fingerprint[] = "00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00")
* Token al cual se desea cargar la informacion
* Campos a los cuales se le desea cargar la informacion, el formato es un Array de String
