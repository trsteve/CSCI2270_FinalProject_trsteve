#ifndef TRAVELCLASS_H
#define TRAVELCLASS_H
#include <vector>
#include <iostream>
#include <stack>
#include <queue>

struct city; //pre-initial that the struct adjVertex does not call that vertex *v in line 9 does not declare**

struct connection;

struct adjCity{
    city *c; //**
    std::vector<connection> cnt;
};

struct connection{
    std::string type;
    int weight;
};

struct city{
    std::string name;
    bool visited;
    int district;
    int arrayID;
    int refID;
    int distance;
    city *previous;
    std::vector<adjCity> adj;
};

struct path{
    int dist;
    std::stack<city*> path;
};


class travelClass
{
    public:
        travelClass();
        ~travelClass();
        void addRoad(std::string v1, std::string v2, int weight);
        void addFlight(std::string v1, std::string v2, int weight);
        void addCity(std::string name);
        void setMapSize(int ss);
        void displayMaps();
        bool findCity(std::string v);
        void resetVisited();
        void buildDistrict();
        bool noDistrict();
        bool inDistrict(std::string v1,std::string v2);
        void cityInReach(std::string startingCity);
        void leastCity(std::string v1,std::string v2);
        void shortestDistance(std::string v1,std::string v2);
    protected:
    private:
        //vector<edge> edges;
        std::vector<city> cities;
        int numberCities;
};
#endif // TRAVELCLASS_H
