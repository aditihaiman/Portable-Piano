# Portable Piano

<h2>Artistic Vision</h2>


<h2>Hardware</h2>
The hardware involved in this project included the following: an <a href="https://www.amazon.com/LILYGO-T-Display-Arduino-Development-CH9102F/dp/B099MPFJ9M?th=1">ESP32 TTGO T-display</a>, ten <a href="https://www.adafruit.com/product/3101?gclid=Cj0KCQjw0tKiBhC6ARIsAAOXutmiu32D4X_OT_O9jRZb08zuguUAwx8xPmHqIJxUwAfb7TyfkgBVUAcaAqpwEALw_wcB">pushbuttons</a> (preferably soft/squishy ones), an <a href="https://www.amazon.com/HiLetgo-LM386-Audio-Amplifier-Module/dp/B00LNACGTY">LM386 amplifier</a>, an <a href="https://www.amazon.com/Uxcell-a15080600ux0275-Internal-Magnet-Speaker/dp/B0177ABRQ6/ref=sr_1_3?keywords=8+Ohm+Speakers&qid=1683555958&sr=8-3">8-ohm speaker</a>, a breadboard, and a good supply of wires. See the diagram below for details on how to wire the components together.

<img width="700" alt="Screen Shot 2023-05-05 at 9 24 09 PM" src="https://user-images.githubusercontent.com/34355688/236850360-6bea3358-c0ac-4536-bdbf-ee59580ba5a4.png">

Choosing the correct ESP32 pins for the buttons might take some trial and error–for some reason, my GPIO pins 37, 38, and 39 did not seem to work so I had to test out each pin until I had enough for all ten of the buttons. The amplifier also gave me some issues with the onboard potentiometer. I would recommend playing a tone and fidgeting with the potentiometer until the speaker is loud enough and not static-y.

<h2>Software</h2>
The Arduino tone library is not supported on ESP32s, I tried several methods to get around this. I settled on the ToneESP32 library which provides the same functionality as the Arduino tone library. The library is available above or here: https://github.com/weedmanu/ToneESP32. This was the only library that worked in playing tones without excessive noise. However, the tone function requires a duration which produces a slight beeping effect when a key is pressed for a long time. This is something I would like to experiment with more to improve the sound quality.

To most accurately simulate the reaction time of a piano, I used interrupts. Each pin corresponding to a button behaves as an interrupt that reads the pin value when a change is detected (both during a rising or falling edge). Overall, the code is fairly simply, with a tone being played if a button has been pressed. However, only one tone can play at a time, so pressing multiple buttons will still only play one tone. 

To get the code working, simply flash it onto the ESP32 and connect all the hardware as shown above. Make sure the button and speaker pins numbers in the code match the arrangement of the hardware.



<h2>Enclosure</h2>

The bulk of the work went into building the enclosure and figuring out how to build the keyboard without making the buttons visible. I used the following materials:

<ul>
  <li>A decent supply of thin and thick paperboard</li>
  <li>Corrugated cardboard</li>
  <li>Black origami paper</li>
  <li>Black and white acrylic paint</li>
  <li>Bristle and sponge brushes </li>
  <li>Ruler</li>
  <li>Scissors</li>
  <li>Box cutter</li>
  <li>Pencil</li>
  <li>Superglue</li>
  <li>Laser cutter (optional but recommended)</li>
  <li>Elmer's glue</li>
</ul>

<h3>Body and legs</h3>
To make the base, cut out a grand piano shaped size of sturdy paperboard. Mine had a length of about 14.5in and width of 11.5in. The exact dimensions don't really matter just make sure to leave an extra inch lengthwise or so for the keyboard area. Cut out a length of bendy paperboard for the rim of the piano. Bend the rim around the frame and glue it down. Once the glue has dried, paint everything black with a sponge brush to ensure an even coat. Use a small bristle brush for the parts that are hard to reach. You should have something that looks like this: 

![IMG_9128](https://user-images.githubusercontent.com/34355688/236873329-214cebbf-e0c7-469c-85df-68af97e60562.jpg)


<img width="936" alt="Screen Shot 2023-05-08 at 11 57 11 AM" src="https://user-images.githubusercontent.com/34355688/236871769-3c8a4ce4-e877-4e26-b24c-9b33391f1be1.png">
