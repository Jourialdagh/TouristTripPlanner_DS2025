#ifndef TRIPPLANNER_H
#define TRIPPLANNER_H

#include "CityNode.h"
#include <map>
#include <vector>
using namespace std;

class TripPlanner {
public:
    map<string, vector<CityNode>> countries;

    TripPlanner();
    void displayCountries();
    void displayCities(string country);
    vector<string> getCities(string country);
    void planTrip(string country, vector<string> selectedCities, vector<string> userInterests, string speed, int budget);
};

#endif
