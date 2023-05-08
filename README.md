# Portable Piano

<h2>Artistic Vision</h2>


<h2>Hardware</h2>
The hardware involved in this project included the following: an <a href="https://www.amazon.com/LILYGO-T-Display-Arduino-Development-CH9102F/dp/B099MPFJ9M?th=1">ESP32 TTGO T-display</a>, ten <a href="https://www.adafruit.com/product/3101?gclid=Cj0KCQjw0tKiBhC6ARIsAAOXutmiu32D4X_OT_O9jRZb08zuguUAwx8xPmHqIJxUwAfb7TyfkgBVUAcaAqpwEALw_wcB">pushbuttons</a> (preferably soft/squishy ones), an <a href="https://www.amazon.com/HiLetgo-LM386-Audio-Amplifier-Module/dp/B00LNACGTY">LM386 amplifier</a>, an <a href="https://www.amazon.com/Uxcell-a15080600ux0275-Internal-Magnet-Speaker/dp/B0177ABRQ6/ref=sr_1_3?keywords=8+Ohm+Speakers&qid=1683555958&sr=8-3">8-ohm speaker</a>, a breadboard, and a good supply of wires. See the diagram below for details on how to wire the components together.

<img width="700" alt="Screen Shot 2023-05-05 at 9 24 09 PM" src="https://user-images.githubusercontent.com/34355688/236850360-6bea3358-c0ac-4536-bdbf-ee59580ba5a4.png">

Choosing the correct ESP32 pins for the buttons might take some trial and error–for some reason, my GPIO pins 37,38,39 did not seem to work so I had to test out each pin until I had enough for all ten of the buttons. The amplifier also gave me some issues with the onboard potentiometer. I would recommend playing a tone and fidgeting with the potentiometer until the speaker is loud enough and not static-y.

<h2>Software</h2>

ESP32 tone library: https://github.com/weedmanu/ToneESP32. I've also included the library folder (ToneESP32) above.


<h2>Enclosure</h2>
