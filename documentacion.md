## Resúmen

En el presente trabajo, el lector podrá encontrar cómo se ha desarrollado un sistema wearable que, mediante vibración, facilita a los intérpretes de una banda de música seguir el mismo tempo.

Este mecanismo no es de nueva invención. Existe, al menos uno, llamado “Body Beat”, de la marca “Peterson” que, a pesar de su gran cantidad de funciones, no ha tenido el éxito esperado en el mercado debido a su elevado coste. Un sistema que hiciese las veces de metrónomo wireless a un precio menor atraería a muchos más clientes.

Para que todos los miembros de la agrupación puedan llevar el mismo pulso, se ha creado una red inalámbrica de sensores (WSN) que permite la sincronización de los aparatos que portan todos los músicos. La red de sensores ha sido concebida utilizando la implementación de ZigBee propuesta por la empresa “Digi International”, mientras la lógica de los circuitos se ha puesto en manos de la plataforma hardware Arduino (utilizándose diversas versiones del mismo).

El tipo de red que forman los dispositivos XBee ZigBee es de tipo malla pero, utilizando la configuración de las motas, se ha pasado a tener una topología de estrella. Dispone de dos tipos de wearables:

* Director: su mota juega el papel de “coordinador” de la red. Es quien crea la red y establece los caminos que deben seguir las comunicaciones que haya en la red. Además de la comunicación con los otros elementos del sistema, tiene la opción de conectar, a través de Bluetooth, con un dispositivo Android. 
* Músico: contiene una mota del tipo “dispositivo final”. Simplemente, recibe (del dispositivo “director”) el tempo con el que el micromotor vibrador debe activarse (además, al llegar el paquete con la traza de datos, se sincroniza con el resto de dispositivos de la red, de forma que todos vibren a la vez).

Estas redes suelen tener también motas de tipo “router” (permiten establecer un enlace entre la mota coordinadora y la final en caso que los paquetes no puedan llegar debido a problemas de distancia, por ejemplo), aunque en este caso se ha desestimado para procurar que los paquetes den solo un salto (evitando retardos). Por otra parte, gracias a la utilización de dispositivos finales en vez de routers, una vez que toda la red se encuentre sincronizada, el director podrá apagar su mota (ahorrando energía) y, al haber inactividad en la red, las motas de los músicos entrarán en estado de hibernación (también ahorrando energía).

Como se comentaba cuando se hablaba del dispositivo del director, se puede conectar con un dispositivo móvil Android. Como es necesario que el director indique el tempo que el sistema debe marcar a los músicos, esta aplicación móvil es la que transfiere al controlador la velocidad a la que debe compaginar a los intérpretes (para evitar sobrecargar la red, se hace una coordinación cada cierto tiempo -por si hubiera habido retrasos en la organización inicial- y cada dispositivo subdivide en función del tempo que se le ha enviado). Buscando facilitar al usuario la utilización de esta tecnología, se ha desarrollado tanto una aplicación para teléfonos móviles, como para smartwatches que funcionen con el sistema operativo Android Wear.
