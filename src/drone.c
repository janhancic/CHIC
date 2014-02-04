#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "drone.h"
#include <stdarg.h>

orientation_t* droneOrientation;


void init() {
   // initialise the arduino
   droneOrientation = orientation_init();
}

void loop() {
   droneOrientation->update();

   drone_print("%f %f %f \n", droneOrientation->x, droneOrientation->y, droneOrientation->z);
}

void drone_print(char* format, ...) {
#ifndef SIMULATE
   printf("%s\n", format);   
#else
   va_list arglist;
   va_start( arglist, format );
   vprintf( format, arglist );
   va_end( arglist );
#endif
}

void start() {
   init();

   while(1) {
      loop();
   }

#ifdef SIMULATE
  sleep(1); 
#endif
}

