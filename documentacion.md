## Resumen

En el presente trabajo, el lector podrá encontrar cómo se ha desarrollado un sistema wearable que, mediante vibración, facilita a los intérpretes de una banda de música seguir el mismo tempo.

Este mecanismo no es de nueva invención. Existe, al menos uno, llamado “Body Beat”, de la marca “Peterson” que, a pesar de su gran cantidad de funciones, no ha tenido el éxito esperado en el mercado debido a su elevado coste. Un sistema que hiciese las veces de metrónomo wireless a un precio menor atraería a muchos más clientes.

Para que todos los miembros de la agrupación puedan llevar el mismo pulso, se ha creado una red inalámbrica de sensores (WSN) que permite la sincronización de los aparatos que portan todos los músicos. La red de sensores ha sido concebida utilizando la implementación de ZigBee propuesta por la empresa “Digi International”, mientras la lógica de los circuitos se ha puesto en manos de la plataforma hardware Arduino (utilizándose diversas versiones del mismo).

El tipo de red que forman los dispositivos XBee ZigBee es de tipo malla pero, utilizando la configuración de las motas, se ha pasado a tener una topología de estrella. Dispone de dos tipos de wearables:

* Director: su mota juega el papel de “coordinador” de la red. Es quien crea la red y establece los caminos que deben seguir las comunicaciones que haya en la red. Además de la comunicación con los otros elementos del sistema, tiene la opción de conectar, a través de Bluetooth, con un dispositivo Android. 
* Músico: contiene una mota del tipo “dispositivo final”. Simplemente, recibe (del dispositivo “director”) el tempo con el que el micromotor vibrador debe activarse (además, al llegar el paquete con la traza de datos, se sincroniza con el resto de dispositivos de la red, de forma que todos vibren a la vez).

Estas redes suelen tener también motas de tipo “router” (permiten establecer un enlace entre la mota coordinadora y la final en caso que los paquetes no puedan llegar debido a problemas de distancia, por ejemplo), aunque en este caso se ha desestimado para procurar que los paquetes den solo un salto (evitando retardos). Por otra parte, gracias a la utilización de dispositivos finales en vez de routers, una vez que toda la red se encuentre sincronizada, el director podrá apagar su mota (ahorrando energía) y, al haber inactividad en la red, las motas de los músicos entrarán en estado de hibernación (también ahorrando energía).

Como se comentaba cuando se hablaba del dispositivo del director, se puede conectar con un dispositivo móvil Android. Como es necesario que el director indique el tempo que el sistema debe marcar a los músicos, esta aplicación móvil es la que transfiere al controlador la velocidad a la que debe compaginar a los intérpretes (para evitar sobrecargar la red, se hace una coordinación cada cierto tiempo -por si hubiera habido retrasos en la organización inicial- y cada dispositivo subdivide en función del tempo que se le ha enviado). Buscando facilitar al usuario la utilización de esta tecnología, se ha desarrollado tanto una aplicación para teléfonos móviles, como para smartwatches que funcionen con el sistema operativo Android Wear.


##### Palabras clave

ZigBee, Metrónomo, Arduino, WSN, Xbee, Android



## Resumen en inglés

One of the principles of engineering is creating solutions to the problems of users. In this dissertation, the reader will be able to find how a wearable system has been developed helping musicians to go on the same “tempo” through vibration while they are playing music. This device sends the same pulse to all musicians and keep the “tempo” constant.


Some companies have developed similar systems. For example, Peterson created an item called “Body Beat”. It has a big range of functions and odds but it is too expensive for the majority of musicians. One device cheaper than only with synchronization functions (the most important ability of this system) could attract more buyers. Furthermore, to create a free and open hardware platform could interest other developers to improve the functionality of this product (helping musicians, music teachers and other music professionals to play music with a better quality).


All music band’s components need to have the same pulse (if each instrumentalist had a different pulse, each one would read his score in a different speed and it would be a problem). It is possible because it has been created using a wireless sensor network (they enable communication with a very low energy cost). Then, when all nodes are synchronized, they know when they have to start the vibrations. But they do not have to be vibrating all time. They have to vibrate constantly as many times as the director said (for example, if compasses are of 4/4 and tempo 60 bpm -Beats Per Minute-, each node will vibrate 1 time per second).

This network has been deployed using ZigBee implementation of the “Digi International” company. Also, circuit logic has been put into operation using the hardware platform called Arduino (various versions of this, like Arduino Lilypad, Arduino Uno or Arduino Leonardo).


In the following pages , it is explained in more detail why certain decisions have been taken (some experiments in time between node's communications, explanations about XBee communication packets...)

XBee Zigbee’s devices are organized in mesh network but, changing each node’s configuration, we have now a network with star topology. There are two kinds of wearables:
Music director: it is the coordinator of network. It is who start the network and establish the paths of communication packets between all nodes. In addition, it is able to send data to every node and receive data from an Android device via Bluetooth. Only one in each network.
Musician: it is composed of an “end device” node. It receives (from “music director device”) data (which contains “tempo”). Arduino takes this tempo and performs calculations to decide when it has to activate or deactivate a vibration motor (this motor helps musician to keep track of the correct pulse). There is one for each musician (in network, there will be as nodes as musicians).

* Director’s device can be connected to an Android device (which could be a smartphone or a smartwatch, because one application has been developed to each one). This application allows director to indicate music’s “tempo” and each application was developed using Google’s recommendations about design (Material Design principles).

* Taking this base, it is possible to create new functions such as installing a vibration sensors in drums to measure the tempo of the band and provide a feedback to the director. Another possibility could be rollcalling at the band (only it is necessary show what nodes are in the network at the moment).


##### Palabras clave

ZigBee, Metronome, Arduino, WSN, Xbee, Android


## Objetivos 

El objetivo de este proyecto, como ya se ha manifestado en el resumen, es la de crear un dispositivo hardware que permita a los componentes de una banda de música seguir el mismo pulso (y de forma constante) durante la ejecución de una obra.

Los principales objetivos a alcanzar con este desarrollo son:
* Que el sistema sea wireless: se quiere realizar la sincronización entre los dispositivos que portan los músicos sin utilizar una conexión física entre ellos
* Conseguir un precio menor que otras soluciones del mercado: utilizando una tecnología distinta a la que han usado otros productos, tratar de obtener un sistema con un menor costo
* Escalable en el número de dispositivos: el sistema no debe verse resentido con el aumento del número de dispositivos en la red
* Ampliable en funciones: posibilidad de desarrollar nuevas funcionalidades partiendo de la red de sensores
* Vestible: debe ser un sistema discreto y cómodo para el portador
* Bajo consumo energético: debido a que hay actuaciones que pueden durar varias horas, es necesario que el sistema consuma poca energía para evitar agotar la fuente de alimentación
* Tecnología lo más libre posible: se desea utilizar herramientas libres para tratar de atraer al mayor número de desarrolladores posible. Además por la propia naturaleza del software/hardware libre, la comunidad aportará parches y soluciones a los problemas que puedan presentarse, mejorando la calidad del desarrollo
* Suficiente para cubrir las necesidades del mercado: aunque anteriormente se mencionaba que se desea que el sistema sea ampliable en funciones, es también necesario que la versión inicial tenga unas funciones mínimas que permitan cubrir las necesidades básicas del mercado


Como objetivos secundarios:
* Utilizar diversas versiones de la plataforma hardware Arduino: se tiene como objetivo utilizar distintas versiones de Arduino para poder obtener el producto con distintos formatos (Arduino Lilypad, Arduino Uno...)
* Desarrollar una red inalámbrica de sensores: teniendo en cuenta la actual dirección de la industria respecto a este tipo de tecnología (su aplicación, por ejemplo. en el “Internet de las Cosas”), es interesante trabajar con esta tecnología
* Crear un dispositivo wearable: actualmente es uno de los sectores en los que más están trabajando las compañías. Si miramos la curva de Gatner [X], en el año 2014 estas tecnologías se situaban en la cima del ciclo.


Hay que destacar entre los aspectos formativos previos más utilizados para el desarrollo del proyecto los conocimientos adquiridos a lo largo del grado sobre ingeniería del software (para establecer los requisitos, planificación y costes del desarrollo), programación de dispositivos móviles y alguna formación en desarrollo de dispositivos hardware.


##Bibliografía

* “Teoría Completa de la Música”. Autor: DIonisio de Pedro. Editorial: Real Musical
* “Lenguaje Musical 1-4”. Grado Elemental. Autores: Raúl Segura Varo, María Torres Moreno, Marta Torres Moreno. Editorial: R.C.M. Musicales
* “Building Wireless Sensor Networks”. Autor: Robert Faludi. Editorial: O’Reilly
* Blog de Robert Faludi: https://www.faludi.com/
* “Hype Cycle for the Internet of Things, 2014”  https://www.gartner.com/doc/2804217?ref=ddisp
* “Dynamic Wireless Sensor Networks”. Autores: Sharief M.A. Oteafy, Hossam S. Hassanein. Editorial:  Wiley-ISTE