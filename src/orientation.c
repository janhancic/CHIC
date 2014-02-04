#include "orientation.h"

static void poll_orientation();


orientation_t *orientation;

orientation_t* orientation_init() {
   orientation = (orientation_t*)malloc(sizeof(orientation_t));

   orientation->update = poll_orientation;

   return orientation;
}

static void poll_orientation() {
   orientation->x = 0;
   orientation->y = 1;
   orientation->z = 0;
}
