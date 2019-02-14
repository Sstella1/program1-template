#include "Planet.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Planet::Planet(int distance, int id){
	this->id = id;
	this->distance = distance;
   	this->pos = rand() % 360;
	int random = rand() % 4;
	if(random == 1) this->type = 'h';
	else if(random == 2) this->type = 'g';
	else this->type = 'r';
}

int Planet::orbit(){
	this->pos++;
	if(this->pos == 360) this->pos = 0;
	return this->pos;
}
