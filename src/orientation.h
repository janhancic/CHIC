#include <stdlib.h>

typedef struct _orientation orientation_t;
typedef struct _acceleration acceleration_t;

struct _orientation {
   double x;
   double y;
   double z;
   void (*update)(); 
};

struct _acceleration {
   double x;
   double y;
   double z;
};

orientation_t* orientation_init();
