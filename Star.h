#ifndef STAR_H
#define STAR_H
#include "Planet.h"
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




#endif
