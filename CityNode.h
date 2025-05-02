#ifndef CITYNODE_H
#define CITYNODE_H

#include "Place.h"
#include <vector>
#include <string>
using namespace std;

class CityNode {
public:
    string cityName;
    vector<Place> attractions;
    vector<Place> restaurants;

    CityNode(string name) {
        cityName = name;
    }

    void addAttraction(string name, string category, int time, int cost) {
        attractions.push_back(Place(name, "Attraction", category, time, cost));
    }

    void addRestaurant(string name) {
        restaurants.push_back(Place(name, "Restaurant"));
    }
};

#endif
