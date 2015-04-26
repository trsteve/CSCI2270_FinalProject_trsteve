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
    cout << "3. Functions" << endl;
    cout << "4. Quit" << endl;
    return;
}

void displayFunction(){
    cout << "======Function======" << endl;
    cout << "1. adjFind" << endl;
    cout << "2. adjRoad" << endl;
    cout << "3. adjFlight" << endl;
    cout << "4. addRoad" << endl;
    cout << "5. addFlight" << endl;
    cout << "6. addCity" << endl;
    cout << "7. deleteCity" << endl;
    cout << "8. deleteRoad" << endl;
    cout << "9. deleteFlight" << endl;
    cout << "10. displayRoads" << endl;
    cout << "11. displayFlights" << endl;
    cout << "12. displayMaps" << endl;
    cout << "13. findCity" << endl;
    cout << "14. buildDistrict" << endl;
    cout << "15. cityInReach" << endl;
    cout << "16. leastCity" << endl;
    cout << "17. bestTravel" << endl;
    cout << "18. popularitize" << endl;
    cout << "19. return" << endl;
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
                    //adjacent city find
                    case 1:
                        kit->adjFind();
                        break;
                    // adjacent road find
                    case 2:
                        kit->adjRoad();
                        break;
                    // adjacent flight find
                    case 3:
                        kit->adjFlight();
                        break;
                    // addCity
                    case 4:
                        kit->addCity();
                        break;
                    // addRoad
                    case 5:
                        kit->addRoad();
                        break;
                    // addFlight
                    case 6:
                        kit->addFlight();
                        break;
                    // deleteCity
                    case 7:
                        kit->deleteCity();
                        break;
                    // deleteRoad
                    case 8:
                        kit->deleteRoad();
                        break;
                    // deleteFlight
                    case 9:
                        kit->deleteFlight();
                        break;
                     // displayRoads
                    case 10:
                        kit->displayRoads();
                        break;
                    // displayFlights
                    case 11:
                        kit->displayFlights();
                        break;
                    // displayMaps
                    case 12:
                        kit->displayMaps();
                        break;
                     // find a City
                    case 13:
                        kit->findCity();
                        break;
                    // build Districts
                    case 14:
                        kit->buildDistrict();
                        break;
                    // cityInReach
                    case 15:
                        kit->cityInReach();
                        break;
                     // find unweight path that means a path visiting the least number of Cities
                    case 16:
                        kit->leastCity();
                        break;
                    // find the best Travel path that have least time-cost
                    case 17:
                        kit->bestTravel();
                        break;
                    // popularitize cities that makes the cost of visiting some city different
                    case 18:
                        kit->popularitize();
                        break;
                    //return MainMenu
                    case 19:
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
