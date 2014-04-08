non-recursive Arduino Makefile build
====

This is a very simple, modular non-recursive Makefile build for Arduino applications based on the [template and suggestions of Emilie van Bergen](http://evbergen.home.xs4all.nl/nonrecursive-make.html).
After looking at several Makefile builds for Arduino sketches, I decided that none of them does what I want/need or does it in a way I didn't like. Therefore I decided to write my own one.

Usage
===

In order to make the build find the Arduino libraries, the environment variable ARDUINO_DIR needs to be set.

On a mac, if you've installed the arduino dmg, the variable should look something like:

	ARDUINO_DIR	= /Applications/Arduino.app/Contents/Resource/Java

On linux (Using fedora and installing the arduino rpm) the location would be
	
	ARDUINO_DIR	= /usr/share/arduino


All the global build configuration like USB port to use, mcu etc is in the top level Makefile. Currently the configuration is for Arduino Uno. In order to use another arduino, the variables in this file need to be adjusted. 

The top-level makefile also contains the following variables with the default values shown below. All these can be overridden by exporting them.

	ARDUINO_CORE      = $(ARDUINO_DIR)/hardware/arduino/cores/arduino       
	ARDUINO_VARIANT   = $(ARDUINO_DIR)/hardware/arduino/variants/standard   
	ARDUINO_LIB_DIR   = $(ARDUINO_DIR)/libraries                            

If you install the avr libraries on OSX via brew for example, the binaries might be outdated or not compatible with the arduino libraries. If this happens, you can set the following variable to point to whatever location your arduino binaries are in.

	ARDUINO_BIN_DIR   = $(ARDUINO_DIR)/hardware/tools/avr/bin      # this is the path on my OSX environment

The default make target compiles everything. And in order to upload the application to an arduino, the upload target is the one to use.

	make		# compiles the target $(TGT_UP) with flags specified in the top-level Makefile 
	make upload	# creates the hex file out of $(TGT_UP) and uploads it on the port $(ARDUINO_PORT)

Testing
===

As I am a massive fan of TDD, I've also added a unit testing framework with an example test to the project. The tests will run as part of the "make" task, or when invoked manually, e.g. make src/myClass.test.
The default setup for the tests must look like the example shown below.

	src
	 - class.cpp
	 - test_class.cpp

The build will assume, that test_<name>.cpp is a test for the file <name>.cpp and compile the two files into one <name>.test executable. As the test framework does not compile with avr-g++ it uses g++ to compile the tests. In order to do this, we need to mock out the Arduino.h and files like Servo.h. The example code shows how that can be achieved.
