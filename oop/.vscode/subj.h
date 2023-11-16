//#ifndef SUBJ_H
//#define SUBJ_H
//
//#include "list.h"
//
//enum ItemType { itNone, itStar, itPlanet };
//
//struct Base {
//	struct Item* next;
//	struct Item* prev;
//	enum ItemType type;
//	char* name;
//	double mass;
//	int diameter;
//};
//
//struct Star {
//	struct Item* next;
//	struct Item* prev;
//	enum ItemType type;
//	char* name;
//	double mass;
//	int diameter;
//	int temperature;
//	double appMagn; // apparent magnitude
//	int distToEarth; // distance
//};
//
//struct Planet {
//	struct Item* next;
//	struct Item* prev;
//	enum ItemType type;
//	char* name;
//	double mass;
//	int diameter;
//	char* planetarySystem;
//	int orbitDiameter;
//};
//
//struct Base* Create(enum ItemType);
//void InputStar(struct Star*);
//void InputPlanet(struct Planet*);
//void InputItem(struct Base*);
//void PrintStar(struct Star*);
//void PrintPlanet(struct Planet*);
//void PrintItem(struct Base*);
//void PrintSpaceItems(struct List*);
//struct Base* SearchByName(struct List*, char*);
//void SearchByDistance(struct List*, double, double);
//void SortList(struct List*);
//
//#endif