#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subj.h"

struct Base *Create(enum ItemType t) {
  struct Base *p = NULL;
  switch (t) {
    case Star:
      p = (struct Base*)calloc(1, sizeof(struct Star));
      break;
    case Planet:
      p = (struct Base *)calloc(1, sizeof(struct Planet));
      break;
    case None:
      printf("\nWrong item type!\n\n");
      break;
  }
  if (p) p->type = t;
  return p;
}

void InputStar(struct Star* p) {
  printf("%d\n\n", p->type);
  do {
    printf("Enter star name (Ctrl-D):\n> ");
    p->name = (char *)malloc(sizeof(char) * 100);
    scanf(" %100[^\n]", p->name);
    if (p->name != NULL)
      break;
    printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
  do {
    printf("Enter star mass (solar mass):\n> ");
    if (scanf("%lf", &p->mass)) break;
    else printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
  do {
    printf("Enter star diameter (km):\n> ");
    if (scanf("%d", &p->diameter)) break;
    else printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
  do {
    printf("Enter star temperature (Kelvin):\n> ");
    if (scanf("%d", &p->temperature)) break;
    else printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
  do {
    printf("Enter star apparent magnitude (W/m2):\n> ");
    if (scanf("%lf", &p->appMagn)) break;
    else printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
  do {
    printf("Enter star's distance to Earth (km):\n> ");
    if (scanf("%d", &p->distToEarth)) break;
    else printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
  printf("%d\n", p->type);
  PrintStar(p);
}

void InputPlanet(struct Planet* p) {
  if (!p)
    return;

  do {
    fflush(stdin);
    printf("Enter planet name:\n> ");
    p->name = (char *)malloc(sizeof(char) * 100);
    scanf(" %100[^\n]", p->name);
    if (p->name != NULL)
      break;
    printf("Wrong input!\n");
  } while (1);
  do {
    printf("Enter planet mass (solar mass):\n> ");
    if (scanf("%lf", &p->mass)) break;
    else printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
  do {
    printf("Enter planet diameter (km):\n> ");
    if (scanf("%d", &p->diameter)) break;
    else printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
  do {
    printf("Enter planetary system:\n> ");
    p->planetarySystem = (char *)malloc(sizeof(char) * 100);
    scanf(" %100[^\n]", p->planetarySystem);
    if (p->planetarySystem != NULL)
      break;
    printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
  do {
    printf("Enter orbit diameter (km):\n> ");
    if (scanf("%d", &p->orbitDiameter)) break;
    else printf("Wrong input!\n");
    fflush(stdin);
  } while (1);
}

void InputItem(struct Base* p) {
  if (!p)
    return;

  switch (p->type) {
    case Star:
      InputStar((struct Star*)p);
      break;
    case Planet:
      InputPlanet((struct Planet*)p);
      break;
    default:
      printf("Unknown object type!\n");
      break;
  }
}

void PrintStar(struct Star* p) {
  printf("Name: %s\t Mass: %lf\n", p->name, p->mass);
  printf("Diameter: %d\t Temperature: %d\n", p->diameter, p->temperature);
  printf("Apparent magnitude: %lf\nDistance to Earth: %d\n\n", p->appMagn, p->distToEarth);
}

void PrintPlanet(struct Planet* p) {
  printf("Name: %s\t Mass: %lf\n", p->name, p->mass);
  printf("Diameter: %d\t Orbit diameter: %d\n", p->diameter, p->orbitDiameter);
  printf("Planetary system: %s\n\n", p->planetarySystem);
}

void PrintItem(struct Base *p) {
  if (!p)
    return;

  switch (p->type) {
    case Star:
      PrintStar((struct Star*)p);
      break;
    case Planet:
      PrintPlanet((struct Planet*)p);
      break;
  }
}

void PrintSpaceItems(struct List* list) {
  struct Base* curr;
  int i = 0;
  for (curr = (struct Base*)list->head; curr != NULL; curr = (struct Base*)curr->next) {
    printf("%d\t%p\t%p\t%p\n", i, curr, curr->prev, curr->next);
    PrintItem(curr);
    i++;
  }
  printf("\n");
}

struct Base *SearchByName(struct List* list, char *name) {
  struct Base* curr;
  for (curr = (struct Base*)list->head; curr != NULL; curr = (struct Base*)curr->next) {
    if (!strcmp(name, curr->name)) {
      return curr;
    }
  }
}

void SearchByDistance(struct List* list, double start, double end) {
  struct Base* curr;
  int i = 0;
  for (curr = (struct Base*)list->head; curr != NULL; curr = (struct Base*)curr->next) {
    if (curr->type == Star) {
      int dist = ((struct Star*)curr)->distToEarth;
      if (dist >= start && dist <= end) {
        printf("\n%d.\n", i);
        PrintItem(curr);
        i++;
      }
    }
  }
}

void Swap(struct List* list, int i1) {
  struct Item* tmp1 = Remove(list, i1);
  Insert(list, tmp1, i1 + 1);
  // struct Item* tmp2 = Remove(list, i2);
  // Insert(list, tmp2, i1);
}

void SortList(struct List* list) {
  struct Base* curr;
  int swapped = 1;
  for (int i = 0; i < Count(list); i++) {
    if (swapped == 0)
      break;

    swapped = 0;
    for (curr = (struct Base*)list->head; curr != NULL; curr = ((struct Base*)curr->next)) {  
      if (curr->next != NULL) {
        if (curr->type == Star) {
          if (strcmp(curr->name, ((struct Base*)curr->next)->name) > 0) {
            Swap(list, GetIndex(list, (struct Item*)curr));
            curr = ((struct Base*)curr->prev);
            swapped = 1;
          }
        }
      } else {
        break;
      }
    }
  }
}