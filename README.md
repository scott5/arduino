# ovSAGE arduino night

## 2018-12-20

Here are a few of the sketches we talked about. Feel free to do whatever you
want to do with them. I'll get around to adding a CC license at some point.
These were cribbed from the official tutorials, other prople and some hackery
on my part, as I'm not at all up to speed with this device.

This is all done with the Kit-On-A-Shield from the [Programming Electronics
Academy](https://programmingelectronics.com/)

The file BSG_Centurion-Eye_Scan_01.mp3 is a sound byte from the original BSG of
a Cylon scanner. If you search, you can find some exampes of how to use it with
a more sophisticated Larson scanner.

The "bes" in the following list means Beginner Electronics Shield

* Blink_bes - Just a sketch to blink the onboard LED
* Larson_bes - The Cylon scanner
* barGraph_bes - A bar graph controlled with a pot
* interrupt_intro - using the interrupt to trigger events

I ran across some sound software (which plays "music" via the piezo buzzer) in
an article and it provided a header file for notes and related frequencies.
They are close enough for my purposes. The code then uses the notes and
durations to fill two arrays to play the music. It works reasonably well, and
looking at the code it struck me it would be annoying to have to enter this all
the time. It also reminded me of ABC notation, so if you look at a music file
written in that format, you get notes and durations.

## Example music source

    ABC notation
    X: 2
    T: Twinkle Little Star
    R: reel
    M: 4/4
    L: 1/8
    K: Cmaj
    C2C2G2G2|A2A2G4|F2F2E2E2|D2D2C4|
    G2G2F2F2|E2E2D4|G2G2F2F2|E2E2D4|
    C2C2G2G2|A2A2G4|F2F2E2E2|D2D2C4:|

Which produces sheet music or can be played by ABC aware software.

The music shows that the length is eigth notes, so the first note is a C that
is a quarter note (duration of 2 eigth notes). This maps well into the sketch.

Look at twinkle to see the code. The basics came from the
tone-output-using-an-arduino page below with a few modifications.

## Some links to view

* Software for the Kit on a shield (Basic Electronics Shield) can be found at the [Kit-on-a-Shield-Example-Code-20OCT16.zip](https://4c3q4z2euxqn29mk0e34ayce-wpengine.netdna-ssl.com/wp-content/uploads/2016/04/Kit-on-a-Shield-Example-Code-20OCT16.zip)

* [Mario Music for piezo on an arduino](https://www.hackster.io/techarea98/super-mario-theme-song-with-piezo-buzzer-and-arduino-2cc461)

* [Using tone() with Arduino for an easy way to make noise](https://programmingelectronics.com/an-easy-way-to-make-noise-with-arduino-using-tone/)

* [Playing Melodies using Arduino Tone() Function](https://circuitdigest.com/microcontroller-projects/playing-melodies-on-piezo-buzzer-using-arduino-tone-function)

* [Tone Output Using An Arduino](https://itp.nyu.edu/physcomp/labs/labs-arduino-digital-and-analog/tone-output-using-an-arduino/)

* [5 Common Arduino Programming Mistakes](https://www.baldengineer.com/5-common-arduino-programming-mistakes.html)

