#include "arrayset.h"

ArraySet::ArraySet(int initial_size) {
   _size          = initial_size;
   _num_elements  = 0;

   _arr = (void**)malloc(_size * sizeof(void*));
}

void ArraySet::add(void *elem) {
   if( _num_elements == _size ) {
      _size *= 2;
      _arr = (void**)realloc(_arr, _size * sizeof(void*));
   }

   _arr[_num_elements++] = elem;
}

void* ArraySet::get(int idx) {
   if(idx < 0 || idx >= _size) return NULL;

   return _arr[idx];
}

int ArraySet::_index_of(void *elem) {
   for( int i = 0; i < _num_elements; i++ ) {
      if( _arr[i] == elem ) return i;
   }

   return -1;
}

bool ArraySet::remove(void *elem) {
   int index = _index_of(elem); 
   if ( index < 0 ) return false;

   _arr[index] = _arr[--_num_elements];
   return true;
}

bool ArraySet::remove(int index) {
   if ( index < 0 ) return false;

   _arr[index] = _arr[--_num_elements];
   return true;
}

int ArraySet::size() {
   return _size;
}

int ArraySet::count() {
   return _num_elements;
}

ArraySet::~ArraySet() {
   free(_arr);
}
