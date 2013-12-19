non-recursive Arduino Makefile build
====

This is a very simple, modular non-recursive Makefile build for Arduino applications based on the [template and suggestions of Emilie van Bergen](http://evbergen.home.xs4all.nl/nonrecursive-make.html).
After looking at several Makefile builds for Arduino sketches, I decided that none of them does what I want/need or does it in a way I didn't like. Therefore I decided to write my own one.

Usage
===

In order to make the build find the Arduino libraries, the variable ARDUINO_DIR needs to be set.

On a mac, if you've installed the arduino dmg, the variable should point to:

	ARDUINO_DIR	= /Applications/Arduino.app/Contents/Resource/Java

On linux (Using fedora and installing the arduino rpm) the location would be
	
	ARDUINO_DIR	= /usr/share/arduino

All the global build configuration like USB port to use, mcu etc is in the top level Makefile. Currently the configuration is for Arduino Uno. In order to use another arduino, the variables in this file need to be adjusted. Also the ARDUINO_VARIANT currently points to standard and will have to be changed to whatever variant applies to your arduino.
The default make target compiles everything. And in order to upload the application to an arduino, the upload target is the one to use.

	make		# compiles the target $(TGT_UP) with flags specified in the top-level Makefile 
	make upload	# creates the hex file out of $(TGT_UP) and uploads it on the port $(ARDUINO_PORT)
