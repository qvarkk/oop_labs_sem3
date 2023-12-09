#include <iostream>
#include <cstdlib>
#include <string>
#include "subj.h"

Base* Base::Create(ItemType t) {
    Base* p = nullptr;
    switch (t) {
        case itStar:
            p = new Star();
            break;
        case itPlanet:
            p = new Planet();
            break;
        case itNone:
            std::cout << "\nWrong item type!\n" << std::endl;
            break;
        }
    // if (p) p->SetType(t);
    return p;
}

void Star::Input() {
    std::cout << "Enter temperature: " << std::endl;
    std::cin >> temperature;
    std::cout << "Enter apparent magnitude: " << std::endl;
    std::cin >> appMagn;
    std::cout << "Enter distance to Earth: " << std::endl;
    std::cin >> distToEarth;
}

void Planet::Input() {
    std::cout << "Enter orbit diameter: " << std::endl;
    std::cin >> orbitDiameter;
    std::cout << "Enter planetary system: " << std::endl;
    std::cin >> planetarySystem;
}

void Base::Input() {
    std::cout << "Enter name: " << std::endl;
    std::cin >> name;
    std::cout << "Enter mass: " << std::endl;
    std::cin >> mass;
    std::cout << "Enter diameter: " << std::endl;
    std::cin >> diameter;
    switch (type) {
        case itStar:
            ((Star*)this)->Input();
            break;
        case itPlanet:
            ((Planet*)this)->Input();
            break;
        default:
            std::cout << "Unknown object type!" << std::endl;
            break;
        }
}

void Star::Print() {
    std::cout << "Star temperature: " << temperature << std::endl;
    std::cout << "Apparent magnitude: " << appMagn << std::endl;
    std::cout << "Distance to the Earth: " << distToEarth << std::endl;
}

void Planet::Print() {
    std::cout << "Orbit diameter: " << orbitDiameter << std::endl;
    std::cout << "Planetary system: " << planetarySystem << std::endl;
}

void Base::Print() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Mass: " << mass << std::endl;
    std::cout << "Diameter: " << diameter << std::endl;
    switch (type) {
        case itStar:
            ((Star*)this)->Print();
            break;
        case itPlanet:
            ((Planet*)this)->Print();
            break;
    }
}

void Base::SetType(ItemType type) {
    this->type = type;
}

ItemType Base::GetType() {
    return type;
}

std::string Base::GetName() {
    return name;
}

double Star::GetDistanceToEarth() {
    return distToEarth;
}

std::string Planet::GetPlanetarySystem() {
    return planetarySystem;
}

int Planet::GetOrbitDiameter() {
    return orbitDiameter;
}

void SubjList::Print() {
    for (Base* p = (Base*)GetHead(); p; p = (Base*)p->GetNext()){
		p->Print();
		std::cout << std::endl;
	}
}

void SubjList::Swap(int index) {
    Item *tmp1 = Remove(index);
    Insert(tmp1, index + 1);
}

int Compare(struct Base* curr) {
  if ((curr->GetType() == itStar && ((Base*)curr->GetNext())->GetType() == itStar && curr->GetName().compare(((Base*)curr->GetNext())->GetName()) > 0) ||
    (curr->GetType() == itPlanet && ((Base*)curr->GetNext())->GetType() == itPlanet && ((Planet*)curr)->GetOrbitDiameter() < ((Planet*)curr->GetNext())->GetOrbitDiameter()) ||
    (curr->GetType() == itPlanet))
    return 1;
  else
    return 0;
}

void SubjList::Sort() {
    Base *curr, *currStar, *tmp;
  
    int swapped = true;
    for (int i = 0; i < Count(); i++) {
        if (swapped == false)
            break;

        swapped = false;
        for (curr = (Base*)GetHead(); curr; curr = ((Base*)curr->GetNext())) {  
            if (curr->GetNext() != NULL) {
                // if(curr->Compare(curr->GetNext))
                //     swap();
                if (Compare(curr)) {
                    Swap(GetIndex((struct Item*)curr));
                    swapped = true;
                    if (curr->GetPrev())
                        curr = ((struct Base*)curr->GetPrev());
                }
            } else {
                break;
            }
        }
    }

    int count;
    curr = (Base*)GetHead();
    currStar = (Base*)GetHead();
    for (int i = 0; i < Count(); i++) {
        if (currStar->GetType() == itStar) {
            count = false;
            curr = (struct Base*)currStar->GetNext();
            for (int j = i + 1; j < Count(); j++) {
                if (curr->GetType() != itPlanet) {
                    curr = (struct Base*)curr->GetNext();
                    continue;
                }
                if (currStar->GetName().compare(((struct Planet*)curr)->GetPlanetarySystem()) == 0) {
                    tmp = (struct Base*)curr->GetNext();
                    curr = (struct Base*)Remove(j);
                    Insert((struct Item*)curr, i + count + 1);
                    curr = tmp;
                    count++;
                } else {
                    curr = (struct Base*)curr->GetNext();
                }
            }
        }
        currStar = (struct Base*)currStar->GetNext();
    }
}

void SubjList::SearchByName(std::string name) {
    Base* curr = (Base*)GetHead();
    for (curr; curr; curr = (struct Base*)curr->GetNext()) {
        if (!name.compare(curr->GetName())) {
            curr->Print();
        }
    }
}

void SubjList::SearchByDistance(double start, double end) {
    Base* curr = (Base*)GetHead();
    int i = 0;
    for (curr; curr; curr = (struct Base*)curr->GetNext()) {
        if (curr->GetType() == itStar) {
            double dist = ((struct Star*)curr)->GetDistanceToEarth();
            if (dist >= start && dist <= end) {
                std::cout << i + 1 << ". ";
                curr->Print();
                i++;
            }
        }
    }
}