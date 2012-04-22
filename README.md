# Customized version of Adafruits LPD8806 library #

The library has been modified so that it's interchangable with my version of
the Adafruit\_WS2801 library.  It takes 8 bit color values and adjusts them 
to 7 bits for the LPD8806 when sending them to the strip. 

Modified examples have been removed and placed in their own repository.




# Arduino library for LPD8806 #
This Library was written for the LPD8806 PWM LED driver chips, strips and pixels.
But the LPD8803/LPD8809 will probably work too.

## Where to Buy? ##
Pick some up at [Adafruit Industries](http://www.adafruit.com/products/306)

## Download ##
Click the Downloads Tab in the Tabbar above. 
Or follow [this](https://github.com/adafruit/LPD8806/zipball/master) link

## Installation ##
* Uncompress the Downloaded Library
* Rename the uncompressed folder to LPD8806
* Check that the LPD8806 folder contains LPD8806.cpp and LPD8806.h
* Place the LPD8806 library folder your <arduinosketchfolder>/libraries/ folder, 
  if the libraries folder does not exist - create it first!
* Restart the IDE
