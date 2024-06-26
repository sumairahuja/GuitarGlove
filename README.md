# GuitarGlove
1. Idea

Our idea is to create an assistive guitar learning experience through a smart glove. Each finger of the glove will have 6 LEDs representing the 6 strings of the guitar. These LEDs will light up to indicate where each finger should be placed on the strings. The glove will also have sensors to detect the hand's position and will only light up the LEDs when the hand is in the correct position to play the chord (correct fret ). This glove will connect to a guitar learning website, allowing the user to choose the chord they want to play and making learning guitar more intuitive and engaging.

2. Problem Statement

Learning the guitar is not easy: teachers are expensive, musical notes are hard to understand, and remembering each chord is difficult. So we created a cheap alternative for children, while helping with making learning chords more intuitive and creating a fun experience for users

3. SDGs in play

Our project aligns with SDG 4 (Quality Education) by making music education more accessible and interaactive. It also supports SDG 9 (Industry, Innovation, and Infrastructure) by using technology to create an innovative educational tool.

4. Constraints

 The glove has to be attachable to any guitar, so portability is an important factor
 
 The case had to be sturdy since movements in the ultrasonic sensor could give incorrect readings
 
 It needed to be aesthetically pleasing, as users would not want to attach an unattractive product to their guitar or wear an unattractive glove.
 
 We needed to find an easy way to attach the sensor to the guitar

5. Solutions Brainstorming

We first decided to use an actuator to create a device that could move your fingers to the correct chords, however, we could not produce enough torque. Then we thought of making the guitar light up depending on where your fingers had to go, but that had already been innovated. Then we thought to make a glove that is attached to the guitar and moves horizontally across the fretboard to the right position and LEDs that later indicate which strings have to be pressed, however after talking to our mentors we decided to go with our current idea.

6. Final Solution

The GuitarGlove

Design Process

For the design, we curated an acrylic box that would fit around the ultrasonic sensor and laser-cut it via Makercase. We had multiple iterations and once we were sure, we laser-cut it

Code

All code used has been uploaded under Source files.

Materials, Machines, and tools used

Black glove

4 LED strips

2 ESP8266s

9V battery

Ultrasonic Sensor

Guitar(for testing)

Breadboard(for testing)

Resistor(for testing)

Jumper wires

Solder

Wire Cutters

Scissors

Laser Cutting Machine

Solder Iron


7. Skills Used

Throughout the project, we utilized various skills we learned over the past year in both online and offline skill-building sessions. For our assistive guitar learning glove, we employed circuit-making skills from our Electronics and Robotics classes to create the first prototype using the ESP8266. We connected various devices and used coding skills to modify libraries for the sensors to achieve the desired output. Our IoT skills were crucial as we connected the glove using Adafruit.IO and Arduino, enabling the ESP8266 to connect to another one. Additionally,  we used our soldering techniques to connect the wires. When designing the aesthetically pleasing outer casing for the sensor, our CAD lessons were invaluable; we created a 3D model before laser cutting to ensure precision. In summary, all the skill-building courses we participated in were essential to successfully creating our final prototype, a feat we couldn't have imagined achieving before.

8. Challenges Faced and Solutions

Challenges were abundant as we made our project. Firstly, when we arrived at residency we decided on using an IR sensor but the values we got were inaccurate so we changed to an ultrasonic sensor, which produced better results.

Secondly, Adafruit was a software that was relatively new for us so we learned from our mentors and used the internet to learn how to effectively use Adafruit.

Lastly, at the end the LEds were not lighting up, we took a long time to detect the problem, but after making use of the multimeter we saw our problem and had to resolder some wires.


