# Tourist Trip Planner (C++ & GUI)

This project is a real-world travel planning system built using C++ for the Data Structures course project. It lets users select countries, cities, and interests to generate a full travel itinerary with estimated time, cost, and a suggested route.

---

## Features

- Country selection (Saudi Arabia, Japan, Austria)
- Choose cities or get smart AI-style recommendations
- Filter attractions based on interests (Nature, History, Entertainment, etc.)
- Calculate total cost based on places selected
- Calculate total time & days needed (based on user travel speed)
- Show suggested route
- Output is structured and realistic
- GUI version included for beautiful website-style display

---

## Code Structure

| File | Purpose |
|------|---------|
| `Place.h` | Defines Place structure (attraction or restaurant) |
| `CityNode.h` | Defines each city with its attractions and restaurants |
| `TripPlanner.h` | TripPlanner class header |
| `TripPlanner.cpp` | Loads data and implements trip logic |
| `main.cpp` | Main function to interact with user and run the trip planner |

---

## Console Preview

```
City: Tokyo
- Visit: Meiji Shrine (History) - 2 hrs, $150
- Eat at: Sushi Dai Tokyo

Suggested Route:
Meiji Shrine -> Sushi Dai Tokyo

Total Visit Time: 4 hrs
Estimated Days: 1 day
Estimated Total Cost: $150
```

---

## GUI Version

- `DS_projectGUI.zip` contains the web version of the app built using HTML, CSS, and JS.
- Beautiful beige theme based on travel apps 
- Users can input countries, cities, and see card-based plans with real images

---

## Team Members

- Jouri Aldaghma — Led the project planning, implemented core C++ logic (TripPlanner, data structures), and integrated the GUI version using HTML/CSS/JS.
- Maram Alhusami — Assisted in C++ design, tested logic for budget/speed estimation, helped write project documentation and validated data consistency.
- Farah Aburayya — Worked on the GUI presentation, researched real locations and categories for each city, and helped with final formatting, README, and visuals.

---

## Technologies Used

- C++  
- STL (vectors, maps, strings)  
- HTML/CSS/JavaScript (for GUI)

---

## Final Verdict

 Meets all Data Structures project requirements  
 Bonus features: AI recs, budget check, speed-based planning  
 Web version included for UX showcase  
