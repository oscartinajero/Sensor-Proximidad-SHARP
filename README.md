# Sensor-Proximidad-SHARP
Sensor de Proximidad SHARP GP2Y0A02YK0F, medición de 20cm a 150cm. 

Se muestra mensaje en Display LCD 1602, marca la distancia en Centímetros. 

Practica con Sensores Arduino.

Al sensor de proximidad se le coloca un capacitor de 10uf como recomendación del fabricante.
Va conectado de la siguiente manera:
*El cable rojo va al positivo del capacitor, el cual va a la alimentación de 5V.
*El cable negro va a GND.
*El cable amarillo va al Puerto A0.

https://github.com/oscartinajero/Sensor-Proximidad-SHARP/blob/main/img/Sensor-Sharp-En-Arduino.PNG

El Display va conectado de la siguiente manera:
*El cable amarillo es el SDA. -   Va en el Puerto A4
*El cable Gris es el SCL.     -   Va en el Puerto A5
*El cable Rojo es VCC.        -   Va a los 5V
*El cable Negro es GND.       -   Va a GND.

https://github.com/oscartinajero/Sensor-Proximidad-SHARP/blob/main/img/LCD-En_Arduino.PNG

Los LEDs van conectados del puerto 2 al 4, ocupando esos tres lugares, cada LED lleva su propia resistencia de 220 OHMS.

https://github.com/oscartinajero/Sensor-Proximidad-SHARP/blob/main/img/LEDs-En-Arduino.PNG
