#include "TripPlanner.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;


string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last = str.find_last_not_of(" \t\r\n");
    if (first == string::npos || last == string::npos) return "";
    return str.substr(first, (last - first + 1));
}

int main() {
    srand(time(0));
    TripPlanner planner;
    string country;
    int option;
    vector<string> selectedCities;

    cout << "Welcome to the Tourist Trip Planner!\n";

    planner.displayCountries();
    cout << "\nEnter the country you want to visit: ";
    getline(cin, country);

    if (planner.countries.find(country) == planner.countries.end()) {
        cout << "Invalid country selected.\n";
        return 0;
    }

    cout << "\nWould you like to:\n";
    cout << "1. Pick cities yourself\n";
    cout << "2. Get city recommendations\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> option;
    cin.ignore();

    if (option == 1) {
        planner.displayCities(country);
        cout << "\nEnter city names you want to visit (type 'done' when finished):\n";
        string cityInput;
        while (true) {
            getline(cin, cityInput);
            if (cityInput == "done") break;
            selectedCities.push_back(trim(cityInput));
        }
    } else if (option == 2) {
        vector<string> allCities = planner.getCities(country);
        int count = min(2, (int)allCities.size());

        while (selectedCities.size() < count) {
            string randomCity = allCities[rand() % allCities.size()];
            if (find(selectedCities.begin(), selectedCities.end(), randomCity) == selectedCities.end()) {
                selectedCities.push_back(randomCity);
            }
        }

        cout << "\nRecommended Cities:\n";
        for (string city : selectedCities) {
            cout << "- " << city << endl;
        }
    } else {
        cout << "Invalid option selected.\n";
        return 0;
    }

    // Interests input
    cout << "\nEnter your interests (comma-separated, e.g., Nature, History, Entertainment): ";
    string interestsInput;
    getline(cin, interestsInput);
    vector<string> userInterests;

    size_t pos = 0;
    while ((pos = interestsInput.find(',')) != string::npos) {
        string token = trim(interestsInput.substr(0, pos));
        userInterests.push_back(token);
        interestsInput.erase(0, pos + 1);
    }
    userInterests.push_back(trim(interestsInput));

    // Travel speed input
    string speed;
    cout << "\nSelect travel speed:\n";
    cout << "- Relaxed (few visits per day)\n";
    cout << "- Moderate (balanced)\n";
    cout << "- Fast (many visits per day)\n";
    cout << "Enter your travel speed choice: ";
    getline(cin, speed);
    speed = trim(speed);

    // Budget input
    int budget;
    cout << "\nEnter your budget in USD (or 0 if no budget): ";
    cin >> budget;
    cin.ignore();

    // Final trip planning
    planner.planTrip(country, selectedCities, userInterests, speed, budget);

    return 0;
}
