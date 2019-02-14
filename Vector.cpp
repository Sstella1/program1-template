#include <iostream>

Vector::Vector(){
	index = 0;
	planets = NULL;
}

Vector::~Vector(){
	for(int i = 0; i < this.getIndex(); i++){
		delete this->planets[i];
	}
	delete[] this->planets;
}

Vector::void insert(int index, Planet * p){
	Planet ** pl = new Planet*[index+1]
	if(this->index < index){
		for(int i = 0; i < this->index; i++){
				pl[i] = new Planet((*this->planets[i]).getDistance());
				delete this->planets[i];
				this->planets[i] = NULL;
		}
		pl[index] = p;
		this->index = index;
	}
	else{
		int buffer = 0;
		for(int i = 0; i < this->index; i++){
			if(i == index){
				pl[i] = p;
				buffer++;	
			}		
			else{
				pl[i+buffer] = new Planet((*this->planets[i]).getDistance());
				delete this->planets[i];
				this->planets[i] = NULL;
			}
		}
		this->index++;
	}
	delete[] this->planets;
	this->planets = pl;
	return;
}

Planet * Vector::read(int index){
	if(index > this->index) return NULL;
	return this->planets[index];
}

bool Vector::remove(int index){
	if(index > this->index || this->planets[index] == NULL) return false;
	Planet **pl = new Planet*[this->index-1];
	int buffer = 0;
	for(int i = 0; i < this->current_planets; i++){
		if(i == index){
			delete pl[i];
			pl[i] = NULL;
			buffer++;
		}
		else{
			pl[i-buffer] = new Planet((*this->planets[i]).getDistance());
			delete this->planets[i];
			this->planets[i] = NULL;
		}
	}
	this->index--;
	delete[] this->planets;
	this->planets = pl;
	return true;
}





















