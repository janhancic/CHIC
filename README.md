non-recursive Arduino Makefile build
====

This is a very simple, modular non-recursife Makefile build for Arduino applications based on the [template and suggestions of Emilie van Bergen](http://evbergen.home.xs4all.nl/nonrecursive-make.html).
After looking at several Makefile builds for Arduino sketches, I decided that none of them does what I want/need or does it in a way I didn't like. Therefore I decided to write my own one.

Usage
===

In order to make the build find the Arduino libraries, the variable ARDUINO_DIR needs to be set.

On a mac, if you've installed the arduino dmg, the variable should point to:

	ARDUINO_DIR	= /Applications/Arduino.app/Contents/Resource/Java

On linux (Using fedora and installing the arduino rpm) the location would be
	
	ARDUINO_DIR	= /usr/share/arduino

Currently the build is for arduino uno, but can easily be adjusted by modifying the global variables in the top level makefile. In order to compile and upload the program, following commands are required.

	make		# compiles the target $(TGT_UP) with flags specified in the top-level Makefile 
	make upload	# creates the hex file out of $(TGT_UP) and uploads it on the port $(ARDUINO_PORT)
