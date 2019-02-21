#include "Star.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Star::Star(){
	this->current_planets = 0;
	this->planets = NULL;
}

Star::~Star(){
	for(int i = 0; i < this->current_planets; i++){
		delete this->planets[i];
	}
	delete[] this->planets;
}

long int Star::addPlanet(){
	Planet **pl = new Planet*[this->current_planets + 1];
	for(int i = 0; i < this->current_planets; i++){
		pl[i] = new Planet((*this->planets[i]).getDistance());
		delete this->planets[i];
		this->planets[i] = NULL;
	}
	Planet *new_planet = new Planet(rand()%3001);
	pl[this->current_planets] = new_planet;
	this->current_planets++;
	delete[] this->planets;
	this->planets = pl;
	return new_planet->getID();
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
			pl[i-buffer] = new Planet((*this->planets[i]).getDistance());
			delete this->planets[i];
		}
		else{
			delete this->planets[i];
			buffer++;
		}
	}
	this->current_planets--;
	delete[] this->planets;
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
	return;
}

void Star::printStarInfo(){
	cout << "The star currently has " << this->current_planets << " planets." << endl;

	cout << "Planets:" << endl;
	for(int i = 0; i < this->current_planets; i++){
		cout << "\tPlanet " << (*this->planets[i]).getType() << (*this->planets[i]).getID() << " is " << (*this->planets[i]).getDistance() << " million miles away at position " << (*this->planets[i]).getPos() << " around the star." << endl;
	}
	return;
}

Starlist::Starlist(){

}
Starlist::~Starlist(){
	
}

long Starlist::addPlanet(){
	return list.insert(list.size()+1,new Planet(rand()%3001)).getPlanetId();
}
bool Starlist::removePlanet(int index){
return remove(index);
}
Planet* Starlist::getPlanet(int){
return list.read(index).getPlanetId();
}

void Starlist::orbit(){
while(list!=NULL){

}
}
void Starlist::printStarInfo(){
}

unsigned int Starlist::getCurrentNumPlanets(){
return this->list.size();
}

Starvector::Starvector(){
	this->vec = new Vector();
}

Starvector::~Starvector(){
	delete this->vec;
}

long Starvector::addPlanet(){
	return this->vec->insert(this->vec->index, new Planet(rand()%3001));
}

bool Starvector::removePlanet(int index){
	return this->vec->removePlanet(index);
}

Planet * Starvector::getPlanet(int index){
	return this->vec->read(index);
}

void Starvector::orbit(){
	for(int i = 0; i < this->vec->index; i++){
		if(this->vec->planets[i] != NULL) this->(*vec->planets[i]).orbit();
	}
	return;
}

void Starvector::printStarInfo(){
	int num = 0;
	for(int i = 0; i < this->vec->index; i++){
		if(this->vec->planets[i] != NULL) num++;
	}
	cout << "The star currently has " << num << " planets, and " << (this->vec->index) - num + 1 << " empty spaces to hold a planet." << endl;

	for(int i = 0; i < this->vec->index; i++){
		if(this->vec->planets[i] != NULL){
			cout << "\tPlanet " << this->(*vec->planets[i]).getType() << this->(*vec->planets[i]).getID() << " is " << this->(*vec->planets[i]).getDistance() << " million miles away at position " << this->(*vec->planets[i]).getPos() << " around the star." << endl;
		}
	}
	return;
}

unsigned int Starvector::getCurrentNumPlanets(){
	return this->vec->size();
}




















