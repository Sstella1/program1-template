#include "Star.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Star::Star(){
	this->current_planets = 0;
	this->next_id = 1;
	this->planets = NULL;
}

Star::~Star(){
	for(int i = 0; i < this->current_planets; i++){
		delete this->planets[i];
	}
	
}

int Star::addPlanet(){
	Planet **pl = new Planet*[this->current_planets + 1];
	for(int i = 0; i < this->current_planets; i++){
		pl[i] = new Planet((*this->planets[i]).getDistance(), (*this->planets[i]).getID());
		delete this->planets[i];
		this->planets[i] = NULL;
	}
	Planet *new_planet = new Planet(rand()%3001, this->next_id);
	pl[this->current_planets] = new_planet;
	this->current_planets++;
	this->next_id++;
	this->planets = pl;
	return this->next_id-1;
}

bool Star::removePlanet(int id){
	bool planet_check = false;
	for(int i = 0; i < this->current_planets; i++){
		if((*this->planets[i]).getID() == id){ planet_check = true; break;}
	}
	if(!planet_check) return false;
	
	Planet **pl = new Planet*[this->current_planets + 1];
	int buffer = 0;
	for(int i = 0; i < this->current_planets; i++){
		if((*this->planets[i]).getID() != id){
			pl[i-buffer] = new Planet((*this->planets[i]).getDistance(), (*this->planets[i]).getID());
			delete this->planets[i];
		}
		else{
			delete this->planets[i];
			buffer++;
		}
	}
	this->current_planets--;
	this->planets = pl;
	return true;
}

Planet * Star::getFurthest(){
	Planet * furthest_planet = this->planets[0];
	for(int i = 1; i < this->current_planets; i++){
		if((*this->planets[i]).getDistance() >= (*furthest_planet).getDistance()){
			furthest_planet = this->planets[i];
		}
	}
	return furthest_planet;
}

Planet * Star::getPlanet(int id){
	for(int i = 0 ; i < this->current_planets; i++){
		if((this->planets[i])->getID() == id) return this->planets[i];
	}
	return NULL;
}

void Star::orbit(){
	for(int i = 0; i < this->current_planets; i++){
		(*this->planets[i]).orbit();
	}
}

void Star::printStarInfo(){
	cout << "The star currently has " << this->current_planets << " planets." << endl;

	cout << "Planets:" << endl;
	for(int i = 0; i < this->current_planets; i++){
		cout << "\tPlanet " << (*this->planets[i]).getType() << (*this->planets[i]).getID() << " is " << (*this->planets[i]).getDistance() << " million miles away at position " << (*this->planets[i]).getPos() << " around the star." << endl;
	}
}



