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
void travelkit::adjFind()
{
    std::cout<<"\n==Function: bool adjFind(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to find any existing path between two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of CITY) and its 2.(NAME of CITY)"<<std::endl;
    std::cout<<" - This function return true-false bool."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::adjRoad()
{
    std::cout<<"\n==Function: bool adjRoad(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to build a road between two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and its 2.(NAME of 2st CITY)"<<std::endl;
    std::cout<<" - This function return true-false bool."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::adjFlight()
{
    std::cout<<"\n==Function: bool adjFlight(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to create a flight between two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and 2.(NAME of 2st CITY)"<<std::endl;
    std::cout<<" - This function return true-false bool."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::addCity()
{
    std::cout<<"\n==Function: void addCity(string nameCity)"<<std::endl;
    std::cout<<" - This function will prompt the user to a parameter to add a city"<<std::endl;
    std::cout<<" - Enter 1.(NAME of CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but add the city to the map"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::addRoad()
{
    std::cout<<"\n==Function: void addRoad(string city1, string city2, int weight)"<<std::endl;
    std::cout<<" - This function will prompt the user to three parameters to build a road between two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and its 2.(NAME of 2st CITY) and its 3.(Driving Length)"<<std::endl;
    std::cout<<" - This function does not return anything, but update the road information of the map"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::addFlight()
{
    std::cout<<"\n==Function: void addFlight(string city1, string city2, int weight)"<<std::endl;
    std::cout<<" - This function will prompt the user to three parameters to create a flight between two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and 2.(NAME of 2st CITY) and its 3.(Flying Distance)"<<std::endl;
    std::cout<<" - This function does not return anything, but update the flight information of the map"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::deleteCity()
{
    std::cout<<"\n==Function: void deleteCity(string nameCity)"<<std::endl;
    std::cout<<" - This function will prompt the user to a parameter to add a city"<<std::endl;
    std::cout<<" - Enter 1.(NAME of CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but delete the city from the map"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::deleteRoad()
{
    std::cout<<"\n==Function: void deleteRoad(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to delete the road between two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and its 2.(NAME of 2st CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but delete the road information from the map"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::deleteFlight()
{
    std::cout<<"\n==Function: void deleteFlight(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to delete the flight between two cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY) and 2.(NAME of 2st CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but delete the flight information from the map"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::findCity()
{
    std::cout<<"\n==Function: bool findCity(string city)"<<std::endl;
    std::cout<<" - This function will prompt the user to a parameter to find the city"<<std::endl;
    std::cout<<" - Enter 1.(NAME of CITY)"<<std::endl;
    std::cout<<" - This function returns true-false whether the city is found or not."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::buildDistrict()
{
    std::cout<<"\n==Function: void buildDistrict()"<<std::endl;
    std::cout<<" - This function does not return anything, but update the district information of the map."<<std::endl;
    std::cout<<" - Each district is determined by having roads connected in breadth-first search."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::cityInReach()
{
    std::cout<<"\n==Function: void cityInReach(string city1)"<<std::endl;
    std::cout<<" - This function will prompt the user to one parameter to find all possible reached cities"<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but print out all possible reached cities"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::bestTravel()
{
    std::cout<<"\n==Function: void bestTravel(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to find the best-time-consuming path"<<std::endl;
    std::cout<<" - Enter 1.(NAME of starting CITY) and 2.(NAME of destination CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but print out the best-time path."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::leastCity()
{
    std::cout<<"\n==Function: void leastCity(string city1, string city2)"<<std::endl;
    std::cout<<" - This function will prompt the user to two parameters to find the least visiting-cities path"<<std::endl;
    std::cout<<" - Enter 1.(NAME of starting CITY) and 2.(NAME of destination CITY)"<<std::endl;
    std::cout<<" - This function does not return anything, but print out the least visiting-cities path."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::popularitize()
{
    std::cout<<"\n==Function: int popularitize(string city1)"<<std::endl;
    std::cout<<" - This function will prompt the user to a parameter to find the popularity of the city"<<std::endl;
    std::cout<<"the popular degrees that will lastly be considered in the cost of traveling."<<std::endl;
    std::cout<<" - The popular degrees is computed by how many adjacent connections of the city."<<std::endl;
    std::cout<<" - Enter 1.(NAME of 1st CITY)"<<std::endl;
    std::cout<<" - This function returns the popularity of entering the destination from the starting city."<<std::endl;
    std::cout<<std::endl;
}
void travelkit::displayRoads()
{
    std::cout<<"\n==Function: void displayRoads()"<<std::endl;
    std::cout<<" - This function will print all available roads in the map"<<std::endl;
    std::cout<<" - No parameter needed"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::displayFlights()
{
    std::cout<<"\n==Function: void displayFlights()"<<std::endl;
    std::cout<<" - This function will print all available flights in the map"<<std::endl;
    std::cout<<" - No parameter needed"<<std::endl;
    std::cout<<std::endl;
}
void travelkit::displayMaps()
{
    std::cout<<"\n==Function: void displayMaps()"<<std::endl;
    std::cout<<" - This function will print all available connections in the map"<<std::endl;
    std::cout<<" - No parameter needed"<<std::endl;
    std::cout<<std::endl;
}
