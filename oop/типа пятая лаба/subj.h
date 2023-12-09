#ifndef SUBJ_H
#define SUBJ_H

#include <string>
#include "list.h"
#include "item.h"

enum ItemType { itNone, itStar, itPlanet };

class Base : public Item {
	private:
		ItemType type;
		std::string name;
		double mass;
		int diameter;
	public:
		Base() : type(ItemType::itNone), name(""), mass(0.0), diameter(0) {}
		~Base() {}
		Base* Create(ItemType);
		void Input();
		void Print();
		void SetType(ItemType);
		ItemType GetType();
		std::string GetName();
};

class Star : public Base {
	private: 
		int temperature;
		double appMagn; // apparent magnitude
		int distToEarth; // distance
	public:
		Star() : temperature(0), appMagn(0.0), distToEarth(0) {SetType(ItemType::itStar);}
		~Star(){}
		void Input();
		void Print();
		double GetDistanceToEarth();
};

class Planet : public Base {
	private:
		std::string planetarySystem;
		int orbitDiameter;
	public:
		Planet() : planetarySystem(""), orbitDiameter(0) {SetType(ItemType::itPlanet);}
		~Planet() {};
		void Input();
		void Print();
		int GetOrbitDiameter();
		std::string GetPlanetarySystem();
};

class SubjList : public List {
    friend class Base;
public:
    void Print();
    void Swap(int);
		void Sort();
    void SearchByDistance(double, double);
		void SearchByName(std::string);
};


// Base* SearchByName(List*, char*);
// void SearchByDistance(List*, double, double);
// void SortList(List*);

#endif
