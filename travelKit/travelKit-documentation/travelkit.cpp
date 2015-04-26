#include "travelkit.h"
#include <iostream>

travelkit::travelkit()
{
    //ctor
}

travelkit::~travelkit()
{
    //dtor
}

void travelkit::projectSummary()
{
    std::cout<< "\n====Travel Analyzer Summary===\n" <<std::endl;
    std::cout<<"Have you ever wonder to travel around the world? Have you ever done some calculation"<<std::endl;
    std::cout<<"of the cost before taking off? I have been thinking about it for a while."<<std::endl;
    std::cout<<"Since thie semester, I have learnt about the graph data structure, and the assignments."<<std::endl;
    std::cout<<"I am kind of want to make something that applied to this knowledge. I wonder"<<std::endl;
    std::cout<<"if I would build a travel plan to all cities I want to go, and put them into"<<std::endl;
    std::cout<<"the travel analyzer to calculate how much of the travel, and time costs. Another question has risen."<<std::endl;
    std::cout<<"What if I select to drive instead of flying, how different would it cost in both travel"<<std::endl;
    std::cout<<"and time costs. Maybe, I will add the blissfulness along the road into my account."<<std::endl;
    std::cout<<"Firstly, I will use ROADMAP file, and FLIGHTMAP file to insert my primary information."<<std::endl;
    std::cout<<"Then, I could add any city later on. I print out the road, flight map."<<std::endl;
    std::cout<<"What if I want to travel to along some cities in the map, not around the world."<<std::endl;
    std::cout<<"How much does it cost me, in money and time? What if I want to take the shortest path."<<std::endl;
    std::cout<<"What if I want to drive along the road and visit least number of cities."<<std::endl;
    std::cout<<"Breath-first Search could help out what nearby cities are. Depth-first Search could"<<std::endl;
    std::cout<<"help out what a possible path to the destination. Dijkstra's algorithm could help out"<<std::endl;
    std::cout<<" what shortest path I should take. However, that is only the travel cost."<<std::endl;
    std::cout<<"What if there is some choice of taking a plane or driving a car. What if the time is limited."<<std::endl;
    std::cout<<"These are the choices that my program want to find out and give"<<std::endl;
    std::cout<<"out solutions to users.\n"<<std::endl;
    return;
}
void travelkit::howtorun()
{
    std::cout<< "\n====Travel Analyzer How-TO====\n" <<std::endl;
    std::cout<<" - Firstly, the program will run by reading a ROADMAP file, and FLIGHTMAP file in command line argument."<<std::endl;
    std::cout<<" - *However, you will need these file to completely run the program."<<std::endl;
    std::cout<<" - Secondly, you can print the map to check the cities, roads, and flights."<<std::endl;
    std::cout<<" - By selecting Menu, it will calculate and implement each function."<<std::endl;
    std::cout<<" - There is no other dependent file; other than ROADMAP.txt and FLIGHTMAP.txt which I will provide in the repository folder.\n"<<std::endl;
    return;
}
void travelkit::addCity()
{
    std::cout<<"\n==Function: void addCity(string nameCity, int popularity)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to store a city"<<std::endl;
    std::cout<<" - Enter 1.(NAME of CITY) and its 2.(popularity)"<<std::endl;
    std::cout<<" - This function does not return anything, but add the city information of the map"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::addRoad()
{
    std::cout<<"\n==Function: void addRoad(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to build a road between two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and its 2.(NAME of 2st CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but update the road information of the map"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::travelkit::addFlight()
{
    std::cout<<"\n==Function: void addFlight(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to create a flight between two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and 2.(NAME of 2st CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but update the flight information of the map"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::bfTraversal()
{
    std::cout<<"\n==Function: void searchReach(string city1)"<<std::endl;
    std::cout<<" - This function will prompt the user to one parameter to find all possible reached cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but print out all possible reached cities"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::dptTraversal()
{
    std::cout<<"\n==Function: void searchDestination(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to find a possible path do exist"<<std::endl;
    std::cout<<" - Enter 1.(NAME of starting CITY) and 2.(NAME of destination CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but print out a possible reached path"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::shortestPath()
{
    std::cout<<"\n==Function: void searchShortestPath(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to find the shortest path"<<std::endl;
    std::cout<<" - Enter 1.(NAME of starting CITY) and 2.(NAME of destination CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but print out the shortest path."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::leastCity()
{
    std::cout<<"\n==Function: void searchLeastVisit(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to find the least visiting-cities path"<<std::endl;
    std::cout<<" - Enter 1.(NAME of starting CITY) and 2.(NAME of destination CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but print out the least visiting-cities path."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::travelAroundWorld()
{
    std::cout<<"\n==Function: void travelAroundWorld(string startingCity)"<<std::endl;
    std::cout<<" - This function will prompt the user to one parameter to find the least-cost-travel plan"<<std::endl;
    std::cout<<" - Enter 1.(NAME of starting CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but print out the least-cost-travel plan"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::roadTrip()
{
    std::cout<<"\n==Function: int roadTripCost(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameter to find the cost of taking a road between any two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and 2.(NAME of 2nd CITY)"<<std::endl;
    std::cout<<" - This function returns the cost of travel from taking the road"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::flightTrip()
{
    std::cout<<"\n==Function: int flightTripCost(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameter to find the cost of taking a flight between any two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and 2.(NAME of 2nd CITY)"<<std::endl;
    std::cout<<" - This function returns the cost of travel from taking the flight"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::timeTrip()
{
    std::cout<<"\n==Function: int timeTripCost(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameter to find the time-cost of taking a flight between any two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and 2.(NAME of 2nd CITY)"<<std::endl;
    std::cout<<" - This function returns the time-cost of travel"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::popularity()
{
    std::cout<<"\n==Function: int popularity(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameter to find the difference between"<<std::endl;
    std::cout<<"the popular degrees that will lastly be considered in the cost of traveling"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and 2.(NAME of 2nd CITY)"<<std::endl;
    std::cout<<" - This function returns the cost of entering the destination from the starting city."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::exchangingCurrency()
{
    std::cout<<"\n==Function: int exchangingCurrency(string baseCurrency, string alterCurrency)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameter to calculate new price due to the second currency"<<std::endl;
    std::cout<<" - Enter 1.(old currency) and 2.(new currency)"<<std::endl;
    std::cout<<" - This function returns the new price."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::printRoadMap()
{
    std::cout<<"\n==Function: void printRoadMap()"<<std::endl;
    std::cout<<" - This function will print all available roads in the map"<<std::endl;
    std::cout<<" - No parameter needed"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::printFlightMap()
{
    std::cout<<"\n==Function: void printFlightMap()"<<std::endl;
    std::cout<<" - This function will print all available flights in the map"<<std::endl;
    std::cout<<" - No parameter needed"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::printMap()
{
    std::cout<<"\n==Function: void printMap()"<<std::endl;
    std::cout<<" - This function will print all available connections in the map"<<std::endl;
    std::cout<<" - No parameter needed"<<std::endl;
    std::cout<<std::endl;
}
