# Portable Piano

<h2>Artistic Vision</h2>
The inspiration behind this project was to create a miniature model of a grand piano. With the weather starting to feel like spring, I found myself wishing more and more that I could somehow bring a piano outside to play music and enjoy the sun at the same time. This gave me the idea to create a piano that is small enough to easily carry around.

See my demo video here: https://youtu.be/I1Qyr8JF324

Read more about the artistic vision here: https://medium.com/@ah3820/portable-piano-10ae856a90e4

<h2>Hardware</h2>
The hardware involved in this project included the following: an <a href="https://www.amazon.com/LILYGO-T-Display-Arduino-Development-CH9102F/dp/B099MPFJ9M?th=1">ESP32 TTGO T-display</a>, ten <a href="https://www.adafruit.com/product/3101?gclid=Cj0KCQjw0tKiBhC6ARIsAAOXutmiu32D4X_OT_O9jRZb08zuguUAwx8xPmHqIJxUwAfb7TyfkgBVUAcaAqpwEALw_wcB">pushbuttons</a> (preferably soft/squishy ones), an <a href="https://www.amazon.com/HiLetgo-LM386-Audio-Amplifier-Module/dp/B00LNACGTY">LM386 amplifier</a>, an <a href="https://www.amazon.com/Uxcell-a15080600ux0275-Internal-Magnet-Speaker/dp/B0177ABRQ6/ref=sr_1_3?keywords=8+Ohm+Speakers&qid=1683555958&sr=8-3">8-ohm speaker</a>, a breadboard, and a good supply of wires. See the diagram below for details on how to wire the components together.

<img width="700" alt="Screen Shot 2023-05-05 at 9 24 09 PM" src="https://user-images.githubusercontent.com/34355688/236850360-6bea3358-c0ac-4536-bdbf-ee59580ba5a4.png">

Choosing the correct ESP32 pins for the buttons might take some trial and error–for some reason, my GPIO pins 37, 38, and 39 did not seem to work so I had to test out each pin until I had enough for all ten of the buttons. The amplifier also gave me some issues with the onboard potentiometer. I would recommend playing a tone and fidgeting with the potentiometer until the speaker is loud enough and not static-y.

<h2>Software</h2>
The Arduino tone library is not supported on ESP32s, I tried several methods to get around this. I settled on the ToneESP32 library which provides the same functionality as the Arduino tone library. The library is available above or here: https://github.com/weedmanu/ToneESP32. This was the only library that worked in playing tones without excessive noise. However, the tone function requires a duration which produces a slight beeping effect when a key is pressed for a long time. This is something I would like to experiment with more to improve the sound quality.

To most accurately simulate the reaction time of a piano, I used interrupts. Each pin corresponding to a button behaves as an interrupt that reads the pin value when a change is detected (both during a rising or falling edge). Overall, the code is fairly simple, with a tone being played if a button has been pressed. However, only one tone can play at a time, so pressing multiple buttons will still only play one tone. 

To get the code working, simply flash it onto the ESP32 and connect all the hardware as shown above. Make sure the button and speaker pins numbers in the code match the arrangement of the hardware.



<h2>Enclosure</h2>

The bulk of the work went into building the enclosure and figuring out how to build the keyboard without making the buttons visible. I used the following materials:

<ul>
  <li>A decent supply of thin (bendy) and thick (sturdy) paperboard</li>
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
To make the base, cut out a grand piano shaped size of sturdy paperboard. Mine had a length of about 14.5in and width of 11.5in. Cut a small hole in the back of the base to fit a USB-C cable that will power the piano. The exact dimensions don't really matter just make sure to leave an extra inch lengthwise or so for the keyboard area. Cut out a length of bendy paperboard for the rim of the piano. Bend the rim around the frame and glue it down. Once the glue has dried, paint everything black with a sponge brush to ensure an even coat. Use a small bristle brush for the parts that are hard to reach. You should have something that looks like this: 

![IMG_9128](https://user-images.githubusercontent.com/34355688/236874543-0252b8ef-d431-4921-b5af-e4015e178fdc.png)

For the legs, cut out twelve elongated trapezoids with the dimensions given below out of sturdy paperboard. For each leg, glue four of the pieces together to create a tapered rectangular prism. Paint the legs black then glue two of the legs on either side of the front of the piano and the last leg in the back. 

<img width="936" alt="Screen Shot 2023-05-08 at 11 57 11 AM" src="https://user-images.githubusercontent.com/34355688/236871769-3c8a4ce4-e877-4e26-b24c-9b33391f1be1.png"> 

To create the hood, trace the body of the piano on sturdy paperboard and cut around so the hood is slightly bigger (so it can rest on the rim without falling through). Cut the hood across about 4.5 inches from the wider end to create the part that folds back. Attach two short pieces of bendy paperboard to connect the pieces you just cut (these will act like the hinges). Check to make sure it's easy to open and close the lid. It should look something like this: 
![IMG_9375](https://user-images.githubusercontent.com/34355688/236876712-71390613-9b86-4989-a096-dd40b9d1c39f.jpg)

<h3>Keyboard and music stand</h3>
The keyboard is made out of three pieces all made from bendy paperboard. It will rest on an L-shaped box which is closed in on other side by rectangular prisms. Either laser cut (recommended for extra precision) or just cut out the keys from sturdy paperboard and paint the white keys white and everything else black. Once the keyboard boxes are cut out, glue the boxes to either side of the L-shaped box, paint it black, and glue it to the part of the frame that sticks out in the front. Dimensions are shown below (cut on solid lines, fold on dashed lines): 

<img width="1009" alt="Screen Shot 2023-05-08 at 12 53 22 PM" src="https://user-images.githubusercontent.com/34355688/236883927-4ca481ba-9393-4c46-b90f-5361a0528921.png">

For the music stand, cut pieces of sturdy paperboard as shown below. Attach two "hinges" on either side of the rim to support the music stand. This piece will not be glued to the frame so that the keyboard can be easily removed. 

<h3>Putting everything together</h3>
Attach the lid of the piano with another hinge (only on one side!). Cut out a thin, long piece of sturdy paperboard and reinforce it on one end with another piece of paperboard. Anchor this down right behind the keyboard and fold it over so it doesn't interfere with the lid. This will act as the prop. Check that when the lid is open and the prop is unfolded, it can support the lid. It should look something like this: 

![IMG_9383](https://user-images.githubusercontent.com/34355688/236887814-052a6fe3-2d58-4b04-ba6b-68d31df5ef7f.JPG)

Now all that's left is putting together the keyboard. Cut out a thin, long piece (10in by 0.5in) or corrugated cardboard. Make sure this piece of cardboard has holes in the middle from the corrugation. Glue the keys in the correct order to this piece of cardboard and make sure to leave about 0.25in sticking out behind the keys (this is where the music stand will rest). Connect three small breadboards together to create one long breadboard that fits snugly in the keyboard box. Arrange all the buttons to one side of the breadboard and put wires in place as shown below (make sure all the buttons are connected to the same common ground). These wires will go through the holes in the corrugated cardboard which will secure the keys in place on top of the buttons.
![IMG_9385](https://user-images.githubusercontent.com/34355688/236889875-65ec2b70-7157-4aa4-8afa-768d78010053.jpg)

![IMG_9384](https://user-images.githubusercontent.com/34355688/236889913-691fcd4b-6584-483f-b13c-e37752251391.jpg)

Connect the wires to the ESP32, place the keyboard in its box, place the music stand on its rests, and admire your work!

![IMG_9400](https://user-images.githubusercontent.com/34355688/236960219-87b42653-16ee-4057-bef9-261f4b666a58.JPG)
