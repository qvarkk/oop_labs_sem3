#include "subj.h"

struct Base {
  char* name;
  double mass;
  double diameter;
};

struct Star {
  char* name;
  double mass;
  double diameter;
  double temperature;
  double appMagn; // apparent magnitude
  double distToEarth; // distance
};

struct Planet {
  char* name;
  double mass;
  double diameter;
  char* planetarySystem;
  double orbitDiameter;
};