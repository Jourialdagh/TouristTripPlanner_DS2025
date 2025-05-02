#ifndef PLACE_H
#define PLACE_H

#include <string>
using namespace std;

struct Place {
    string name;
    string type;     // "Attraction" or "Restaurant"
    string category; // Nature, History, Entertainment, etc.
    int visitTime;   // hours (0 if restaurant)
    int cost;        // USD (0 if restaurant)

    Place(string n, string t, string c = "", int time = 0, int price = 0)
        : name(n), type(t), category(c), visitTime(time), cost(price) {}
};

#endif

