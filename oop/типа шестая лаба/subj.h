#ifndef SUBJ_H
#define SUBJ_H

#include <string>
#include "list.h"
#include "item.h"

enum ItemType { itNone, itStar, itPlanet };

class Base : public Item {
	private:
		std::string name;
		double mass;
		int diameter;
	public:
		Base() : name(""), mass(0.0), diameter(0) {}
		virtual ~Base() {}
		static Base* Create(ItemType);
		virtual void Input();
		virtual void Print();
		void SetType(ItemType);
		virtual ItemType GetType() = 0;
		std::string GetName();
  	bool operator < (const Base&);
		bool operator <= (const double);
		bool operator >= (const double);
		bool operator == (const std::string);
};

class Planet : public Base {
	private:
		std::string planetarySystem;
		int orbitDiameter;
	public:
		Planet() : planetarySystem(""), orbitDiameter(0) {}
		~Planet() {}
		void Input() override;
		void Print() override;
		ItemType GetType() override;
		int GetOrbitDiameter();
		std::string GetPlanetarySystem();
};

class Star : public Base {
	private: 
		int temperature;
		double appMagn; // apparent magnitude
		int distToEarth; // distance
	public:
		Star() : temperature(0), appMagn(0.0), distToEarth(0) {}
		~Star() {}
		void Input() override;
		void Print() override;
		ItemType GetType() override;
		double GetDistanceToEarth();
};

class SubjList : public List {
    friend class Base;
public:
		SubjList() {}
		virtual ~SubjList() {}
    void Print();
    void Swap(int);
		void Sort();
    void SearchByDistance(double, double);
		void SearchByName(std::string);
		Base& operator [] (const int);
};

#endif