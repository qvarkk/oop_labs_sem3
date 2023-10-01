#ifndef SUBJ_H
#define SUBJ_H

#include "list.h"

enum ItemType {None, Star, Planet};

struct Base {
  enum ItemType type;
  struct Item* next;
  struct Item* prev;
  char* name;
  double mass;
  double diameter;
};

struct Star {
  enum ItemType type;
  struct Item* next;
  struct Item* prev;
  char* name;
  double mass;
  int diameter;
  int temperature;
  double appMagn; // apparent magnitude
  int distToEarth; // distance
};

struct Planet {
  enum ItemType type;
  struct Item* next;
  struct Item* prev;
  char* name;
  double mass;
  int diameter;
  char* planetarySystem;
  int orbitDiameter;
};

struct Base *Create(enum ItemType);
void InputStar(struct Star*);
void InputPlanet(struct Planet*);
void InputItem(struct Base*);
void PrintStar(struct Star*);
void PrintPlanet(struct Planet*);
void PrintItem(struct Base*);
void SortList(struct List*);
struct Base* SearchByName(char *name);
struct Base* SearchByDistance(double start, double end);

#endif
