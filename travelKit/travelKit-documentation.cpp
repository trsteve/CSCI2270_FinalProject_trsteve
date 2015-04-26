#include <iostream>
#include "travelkit.h"

using namespace std;

void displayMenu();
void displayFunction();
void functionMenu(travelkit *kit);

int main()
{
    cout << "\n-     My Travel Analyzer    -" << endl;
    cout << "-   Program Documentation   -" <<endl;
    cout << "- Copyright 2015 by trsteve -\n" << endl;

    int input1;
    travelkit *kit = new travelkit;
    // Flag used for exiting menu
    bool quit1 = false;

    // Used for input

    while(quit1 != true)
    {
        displayMenu();
        cin >> input1;
        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');

        switch (input1)
        {
            // Project Summary
            case 1:
                kit->projectSummary();
                break;
            // How to Run
            case 2:
                kit->howtorun();
                break;
            // Function
            case 3:
                functionMenu(kit);
                break;
            // Quit
            case 4:
                quit1 = true;
                break;
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }



    return 0;
}

/*displays a menu with options*/
void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Project Summary" << endl;
    cout << "2. How to Run" << endl;
    cout << "3. Function" << endl;
    cout << "4. Quit" << endl;
    return;
}

void displayFunction(){
    cout << "======Function======" << endl;
    cout << "1. addCity" << endl;
    cout << "2. addRoad" << endl;
    cout << "3. addFlight" << endl;
    cout << "4. searchReach" << endl;
    cout << "5. searchDepth" << endl;
    cout << "6. searchShortestPath" << endl;
    cout << "7. searchLeastCity" << endl;
    cout << "8. travelAroundWorld" << endl;
    cout << "9. roadTripCost" << endl;
    cout << "10. flightTripCost" << endl;
    cout << "11. timeTripCost" << endl;
    cout << "12. popularity" << endl;
    cout << "13. exchangingCurrency" << endl;
    cout << "14. printRoadMap" << endl;
    cout << "15. printFlightMap" << endl;
    cout << "16. printMap" << endl;
    cout << "17. return" << endl;
    return;
}

void functionMenu(travelkit *kit){
    int input2;
            // Flag used for exiting menu
            bool quit2 = false;
            // Used for input
            while(quit2 != true)
            {
                displayFunction();
                cin >> input2;
                //clear out cin
                cin.clear();
                cin.ignore(10000,'\n');
                switch (input2)
                {
                    // addCity
                    case 1:
                        kit->addCity();
                        break;
                    // addRoad
                    case 2:
                        kit->addRoad();
                        break;
                    // addFlight
                    case 3:
                        kit->addFlight();
                        break;
                    // searchReach
                    case 4:
                        kit->bfTraversal();
                        break;
                    //searchDepth
                    case 5:
                        kit->dptTraversal();
                        break;
                    //searchShortestPath
                    case 6:
                        kit->shortestPath();
                        break;
                    //searchLeastCity
                    case 7:
                        kit->leastCity();
                        break;
                    //travelAroundWorld
                    case 8:
                        kit->travelAroundWorld();
                        break;
                    // roadTripCost
                    case 9:
                        kit->roadTrip();
                        break;
                    //flightTripCost
                    case 10:
                        kit->flightTrip();
                        break;
                    //timeTripCost
                    case 11:
                        kit->timeTrip();
                        break;
                    // popularity
                    case 12:
                        kit->popularity();
                        break;
                    //exchangingCurrency
                    case 13:
                        kit->exchangingCurrency();
                        break;
                    //printRoadMap
                    case 14:
                        kit->printRoadMap();
                        break;
                    // printFlightMap
                    case 15:
                        kit->printFlightMap();
                        break;
                    //printMap
                    case 16:
                        kit->printMap();
                        break;
                    //return MainMenu
                    case 17:
                        quit2 = true;
                        break;
                    default:
                        cout << "Invalid Input" << endl;
                        cin.clear();
                        cin.ignore(10000,'\n');
                        break;
            }
        }
}
