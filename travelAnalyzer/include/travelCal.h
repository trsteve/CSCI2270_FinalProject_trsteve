#ifndef TRAVELCAL_H
#define TRAVELCAL_H
#include <vector>
#include <iostream>
#include <stack>
#include <queue>

struct city; //pre-initial that the struct adjVertex does not call that vertex *v in line 9 does not declare**

struct connection{
    int cost;
    int time;
};

struct adjCity{
    city *c; //**
    connection road;
    connection flight;
};


struct city{
    std::string name;
    bool visited;
    int district;
    int arrayID;
    int refID;
    int distance;
    int popularity;
    city *previous;
    std::vector<adjCity> adj;
};

struct path{
    int dist;
    int time;
    std::stack<city*> path;
};


class travelCal
{
    public:
        travelCal();
        ~travelCal();
        bool adjFind(std::string v1, std::string v2);
        bool adjRoad(std::string v1, std::string v2);
        bool adjFlight(std::string v1, std::string v2);
        void addRoad(std::string v1, std::string v2, int cost);
        void addFlight(std::string v1, std::string v2, int cost);
        void addCity(std::string name);
        void setMapSize(int ss);
        void displayRoads();
        void displayFlights();
        void displayMaps();
        bool findCity(std::string v);
        void resetVisited();
        void buildDistrict();
        bool noDistrict();
        bool inDistrict(std::string v1,std::string v2);
        void cityInReach(std::string startingCity);
        void leastCity(std::string v1,std::string v2);
        void bestTravel(std::string v1,std::string v2);
        connection selectLessTime(adjCity);
        connection selectMoreTime(adjCity);
        void popularitize();
        int popularitize(city);
    protected:
    private:
        //vector<edge> edges;
        std::vector<city> cities;
        int numberCities;
};

#endif // TRAVELCAL_H
