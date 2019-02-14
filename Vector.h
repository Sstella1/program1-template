#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include "Planet.h"
class Vector{
		int index;
		Planet ** planets;
	public:
		Vector();
		~Vector();
		void insert(int, Planet *);
		Planet * read(int);
		bool remove(int);
		unsigned int size(){return this->index;}
};

#endif
