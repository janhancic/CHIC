#include <stdlib.h>
#include <stdio.h>

#ifndef __arrayset_h
#define __arrayset_h

#define DEFAULT_SIZE 10

class ArraySet {
   private:
      void       **_arr;
      int        _num_elements;
      int        _size;
      int        _index_of(void *elem);

   public:
      ArraySet() : ArraySet(DEFAULT_SIZE) {}
      ArraySet(int initial_size);

      void     add(void *elem);
      bool     remove(void *elem);
      bool     remove(int index);
      void*    find(void *elem);
      void*    get(int idx);

      int   size();
      int   count();

      ~ArraySet();
};

#endif
