#ifndef SUBJ_H
#define SUBJ_H

#include "list.h"

enum ItemType {None, Star, Planet};

struct Base {
  struct Item* next;
  struct Item* prev;
  enum ItemType type;
  char* name;
  double mass;
  int diameter;
};

struct Star {
  struct Item* next;
  struct Item* prev;
  enum ItemType type;
  char* name;
  double mass;
  int diameter;
  int temperature;
  double appMagn; // apparent magnitude
  int distToEarth; // distance
};

struct Planet {
  struct Item* next;
  struct Item* prev;
  enum ItemType type;
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
void PrintSpaceItems(struct List*);
void SortList(struct List*);
struct Base* SearchByName(char *name);
struct Base* SearchByDistance(double start, double end);

#endif
