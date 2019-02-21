#ifndef STAR_H
#define STAR_H
#include "Planet.h"
#include "Vector.h"
#include "List.h"

class Star{
	
	private:
        int current_planets;
	public:
        Planet ** planets;
        Star();
		~Star();
        long int addPlanet();
		bool removePlanet(int);
        Planet * getFurthest();
		Planet * getPlanet(int);
        void orbit();
        void printStarInfo();
        int getCurrentNumPlanets(){return this->current_planets;}
};

class Starlist{
	public:
		List list;
		Starlist();
		~Starlist();
		long addPlanet();
		bool removePlanet(int);
		Planet*getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets();

};

class Starvector{
		Vector vec;
	public:
		Starvector();
		~Starvector();
		long addPlanet();
		bool removePlanet(int);
		Planet * getPlanet(int);
		void orbit();
		void printStarInfo();
		unsigned int getCurrentNumPlanets(){return this->vec.size();}
		
};


#endif
