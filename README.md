# MicrocontrollerSongs

How to Use: Load one of the song sketches into an Arduino Uno Rev 3 or Arduino Nano with digital pin 8 connected to one pin of a 5 V buzzer.  Connect the other buzzer pin to the Arduino ground GND.  For best results use a higher quality 5 V buzzer.
What do I mean by higher quality 5 V buzzer? An example would be the Murata Electronics PKM22EPPH4002-B0.
PKM22EPPH4002-B0 Buzzer Link- https://www.digikey.com/product-detail/en/murata-electronics/PKM22EPPH4002-B0/490-7031-ND/2595277

Advantages of These No Delay Sketches:
1) No delay() function used in the code. There are quite a few Arduino 5 V buzzer song sketches out there.  For Example, the musical notes were written out for the Star Wars song in an Arduino sketch by NickSort (credit here: https://gist.github.com/nicksort/4736535).  But all those Arduino songs I have found use the delay function.  The problem with this is that the delay function prevents accomplishing other tasks with your Arduino unless you want to attempt interrupts or embed additional input reading commands all throughout your code.  The no delay sketches use the millis() function and while loops so that delay() is not necessary.  It took me a long time to figure out how to avoid delay() in these songs. 
2) Enum used in order to save variable memory space.  Thanks to Gray Mack in the Arduino for Beginners Facebook group for this suggestion.

Special Thanks to Bill at the DroneBot Workshop whose video "Arduino Uno to ATmega328 - Shrinking Your Arduino Project" originally opened my eyes to the existence of Arduino songs (https://www.youtube.com/watch?v=Sww1mek5rHU&t=526s).
