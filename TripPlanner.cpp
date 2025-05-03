#include "TripPlanner.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

TripPlanner::TripPlanner() {
    // Saudi Arabia
    CityNode riyadh("Riyadh");
    riyadh.addAttraction("Riyadh Boulevard", "Entertainment", 5, 100);
    riyadh.addAttraction("Masmak Fortress", "History", 5, 200);
    riyadh.addAttraction("Kingdom Centre Tower", "Landmark", 3, 300);
    riyadh.addRestaurant("Al Nakheel Restaurant");
    riyadh.addRestaurant("Nozomi Riyadh");

    CityNode jeddah("Jeddah");
    jeddah.addAttraction("Jeddah Corniche", "Nature", 3, 50);
    jeddah.addAttraction("Red Sea Mall", "Entertainment", 4, 300);
    jeddah.addAttraction("Al Balad Historic District", "History", 5, 300);
    jeddah.addRestaurant("Toki Jeddah");
    jeddah.addRestaurant("Shawarma Shakir Aljazeera");

    CityNode alula("AlUla");
    alula.addAttraction("AlUla Old Town", "History", 5, 200);
    alula.addAttraction("Edge of the World", "Nature", 4, 250);
    alula.addRestaurant("Suhail Restaurant AlUla");
    alula.addRestaurant("Somewhere AlUla");

    countries["Saudi Arabia"] = {riyadh, jeddah, alula};

    // Japan
    CityNode tokyo("Tokyo");
    tokyo.addAttraction("Tokyo Tower", "Landmark", 4, 400);
    tokyo.addAttraction("Meiji Shrine", "History", 5, 150);
    tokyo.addAttraction("Ghibli Museum", "Entertainment", 5, 400);
    tokyo.addAttraction("Akihabara District", "Entertainment", 5, 350);
    tokyo.addRestaurant("Ichiran Ramen Tokyo");
    tokyo.addRestaurant("Sushi Dai Tokyo");

    CityNode kyoto("Kyoto");
    kyoto.addAttraction("Fushimi Inari Shrine", "History", 3, 250);
    kyoto.addAttraction("Kyoto Temples", "History", 3, 100);
    kyoto.addAttraction("Arashiyama Bamboo Grove", "Nature", 4, 200);
    kyoto.addRestaurant("Gion Karyo Kyoto");
    kyoto.addRestaurant("Omen Kyoto");

    CityNode osaka("Osaka");
    osaka.addAttraction("Osaka Castle", "History", 3, 150);
    osaka.addAttraction("Namba Parks", "Entertainment", 5, 500);
    osaka.addAttraction("Universal Studios Japan", "Entertainment", 5, 450);
    osaka.addRestaurant("Mizuno Osaka");
    osaka.addRestaurant("Kushikatsu Daruma Osaka");

    countries["Japan"] = {tokyo, kyoto, osaka};

    // Austria
    CityNode vienna("Vienna");
    vienna.addAttraction("Schönbrunn Palace", "History", 4, 200);
    vienna.addAttraction("St. Stephen’s Cathedral", "History", 3, 100);
    vienna.addAttraction("Hofburg Palace", "History", 4, 250);
    vienna.addRestaurant("Steirereck Vienna");
    vienna.addRestaurant("Plachutta Vienna");

    CityNode salzburg("Salzburg");
    salzburg.addAttraction("Salzburg Old Town", "History", 3, 100);
    salzburg.addAttraction("Hohensalzburg Fortress", "History", 4, 250);
    salzburg.addRestaurant("St. Peter Stiftskeller Salzburg");
    salzburg.addRestaurant("Bärenwirt Salzburg");

    CityNode hallstatt("Hallstatt");
    hallstatt.addAttraction("Hallstatt Village", "Nature", 5, 50);
    hallstatt.addAttraction("Hallstatt Skywalk", "Nature", 4, 100);
    hallstatt.addRestaurant("Restaurant Im Seehotel Gruner Baum");
    hallstatt.addRestaurant("Braugasthof Hallstatt");

    countries["Austria"] = {vienna, salzburg, hallstatt};
}

void TripPlanner::displayCountries() {
    cout << "Available Countries:\n";
    for (auto& pair : countries) {
        cout << "- " << pair.first << endl;
    }
}

void TripPlanner::displayCities(string country) {
    cout << "Available Cities in " << country << ":\n";
    for (CityNode city : countries[country]) {
        cout << "- " << city.cityName << endl;
    }
}

vector<string> TripPlanner::getCities(string country) {
    vector<string> cityNames;
    for (CityNode city : countries[country]) {
        cityNames.push_back(city.cityName);
    }
    return cityNames;
}

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void TripPlanner::planTrip(string country, vector<string> selectedCities, vector<string> userInterests, string speed, int budget) {
    cout << "\nYour Day Plan:\n";

    int totalHours = 0;
    int estimatedCost = 0;
    vector<string> route;

    for (string cityName : selectedCities) {
        cout << "\nCity: " << cityName << endl;
        bool foundAttraction = false;

        for (CityNode city : countries[country]) {
            if (city.cityName == cityName) {
                for (Place p : city.attractions) {
                    for (string interest : userInterests) {
                        if (toLower(p.category).find(toLower(interest)) != string::npos) {
                            cout << "- Visit: " << p.name << " (" << p.category << ") - " << p.visitTime << " hrs, $" << p.cost << "\n";
                            totalHours += p.visitTime;
                            estimatedCost += p.cost;
                            route.push_back(p.name);
                            foundAttraction = true;
                            break;
                        }
                    }
                }
                if (!foundAttraction) {
                    cout << "- No matching attractions found based on your interests.\n";
                }

                for (Place p : city.restaurants) {
                    cout << "- Eat at: " << p.name << "\n";
                }
            }
        }
    }

    if (!route.empty()) {
        cout << "\nSuggested Route:\n";
        for (size_t i = 0; i < route.size(); i++) {
            cout << route[i];
            if (i != route.size() - 1) cout << " -> ";
        }
        cout << endl;
    }

    cout << "\nTotal Visit Time: " << totalHours << " hours\n";

    int hoursPerDay = (speed == "Relaxed") ? 5 : (speed == "Moderate") ? 7 : 10+;
    int days = totalHours / hoursPerDay + (totalHours % hoursPerDay != 0 ? 1 : 0);
    cout << "Estimated Days Needed (" << speed << "): " << days << " day(s)\n";

    cout << "Estimated Total Cost: $" << estimatedCost << endl;

    if (budget > 0) {
        if (estimatedCost <= budget) {
            cout << "Your trip fits within your budget!\n";
        } else {
            cout << "Your trip exceeds your budget by $" << (estimatedCost - budget) << endl;
        }
    }
}
