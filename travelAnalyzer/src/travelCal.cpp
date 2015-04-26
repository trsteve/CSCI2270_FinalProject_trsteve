#include "travelCal.h"
#include "math.h"

travelCal::travelCal()
{
    //ctor
}

travelCal::~travelCal()
{
    //dtor
}

/*
Function prototype:
bool travelCal::adjFind(std::string v1, std::string v2);

Function description:
This method executes true-false whether there is existing path to the adjacent cities as prompting.

Example:

tC->adjFind(Boulder,Denver);

Pre-condition: Unknown result whether a path is existed
Post-condition: Function return true, if there is an adjacent path;
*/
bool travelCal::adjFind(std::string v1, std::string v2){
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v1){
            for(int j = 0; j < cities[i].adj.size(); j++){
                if(cities[i].adj[j].c->name == v2){
                    return true;
                }
            }
        }
    }
    return false;
}

/*
Function prototype:
bool travelCal::adjRoad(std::string v1, std::string v2);

Function description:
This method executes true-false whether there is existing road to the adjacent cities as prompting.

Example:

tC->adjRoad(Boulder,Denver);

Pre-condition: Unknown result whether a road is existed
Post-condition: Function return true, if there is an adjacent road;
*/
bool travelCal::adjRoad(std::string v1, std::string v2){
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v1){
            for(int j = 0; j < cities[i].adj.size(); j++){
                if(cities[i].adj[j].c->name == v2){
                    if(cities[i].adj[j].road.cost!=-1){
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
    return false;
}

/*
Function prototype:
bool travelCal::adjFlight(std::string v1, std::string v2);

Function description:
This method executes true-false whether there is existing flight between the cities as prompting.

Example:

tC->adjRoad(Denver,Boston);

Pre-condition: Unknown result whether a road is existed
Post-condition: Function return true, if there is an connecting flight;
*/
bool travelCal::adjFlight(std::string v1, std::string v2){
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v1){
            for(int j = 0; j < cities[i].adj.size(); j++){
                if(cities[i].adj[j].c->name == v2){
                    if(cities[i].adj[j].flight.cost!=-1){
                        return true;
                    } else {
                        return false;
                    }
                }
            }
        }
    }
    return false;
}

/*
Function prototype:
void travelCal::addRoad(std::string v1, std::string v2, int cost);

Function description:
This method adds a road to the map; the information of the road is as entered.
The cost parameter is the driving distance.

Example:

tC->addRoad(Boulder,Denver,48);

Pre-condition: There is no road between two cities.
Post-condition: Method update the road between Boulder-Denver as 48 kilometers to the map.
*/
void travelCal::addRoad(std::string v1, std::string v2, int cost){

    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v1){
            for(int j = 0; j < cities.size(); j++){
                if(cities[j].name == v2 && i != j && adjFind(v1,v2)==false){
                    adjCity av;
                    av.c = &cities[j];
                    av.road.cost = cost;
                    av.road.time = ceil(cost/60);
                    av.flight.cost=-1;
                    av.flight.time=-1;
                    cities[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjCity av2;
                    av2.c = &cities[i];
                    av2.road.cost = cost;
                    av2.road.time = ceil(cost/60);
                    av2.flight.cost=-1;
                    av2.flight.time=-1;
                    cities[j].adj.push_back(av2);
                    //std::cout<<av2.c->name<<"--"<<av.road.cost<<"--"<<av.c->name<<std::endl;
                    return;

                } else if(cities[j].name == v2 && i != j && adjFind(v1,v2)==true){
                    for(int k = 0; k < cities[i].adj.size(); k++){
                        if(cities[i].adj[k].c->name == v2){
                            cities[i].adj[k].road.cost = cost;
                            cities[i].adj[k].road.time = ceil(cost/60);
                            break;
                        }
                    }
                    for(int m = 0; m < cities[j].adj.size(); m++){
                        if(cities[j].adj[m].c->name == v1){
                            cities[j].adj[m].road.cost = cost;
                            cities[j].adj[m].road.time = ceil(cost/60);
                            break;
                        }
                    }
                    //std::cout<<v1<<"--"<<cost<<"--"<<v2<<std::endl;
                }
            }
        }
    }
}

/*
Function prototype:
void travelCal::addFlight(std::string v1, std::string v2, int cost);

Function description:
This method adds a flight to the map; the information of the flight is as entered.
The cost parameter is the flying distance.

Example:

tC->addFlight(San Francisco,Denver,1980);

Pre-condition: There is no connecting flight between two cities.
Post-condition: Method update the flight between Boulder-Denver as 1980 kilometers to the map.
*/
void travelCal::addFlight(std::string v1, std::string v2, int cost){

    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v1){
            for(int j = 0; j < cities.size(); j++){
                if(cities[j].name == v2 && i != j && adjFind(v1,v2)==false){
                    adjCity av;
                    av.c = &cities[j];
                    av.flight.cost = cost;
                    av.flight.time = ceil(cost/550);
                    av.road.cost=-1;
                    av.road.time=-1;
                    cities[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjCity av2;
                    av2.c = &cities[i];
                    av2.flight.cost = cost;
                    av2.flight.time = ceil(cost/550);
                    av2.road.cost=-1;
                    av2.road.time=-1;
                    cities[j].adj.push_back(av2);
                    //std::cout<<av2.c->name<<"--"<<av.flight.cost<<"--"<<av.c->name<<std::endl;
                    return;

                } else if(cities[j].name == v2 && i != j && adjFind(v1,v2)==true){
                    for(int k = 0; k < cities[i].adj.size(); k++){
                        if(cities[i].adj[k].c->name == v2){
                            cities[i].adj[k].flight.cost = cost;
                            cities[i].adj[k].flight.time = ceil(cost/550);
                            break;
                        }
                    }
                    for(int m = 0; m < cities[j].adj.size(); m++){
                        if(cities[j].adj[m].c->name == v1){
                            cities[j].adj[m].flight.cost = cost;
                            cities[j].adj[m].flight.time = ceil(cost/550);
                            break;
                        }
                    }
                    //std::cout<<v1<<"--"<<cost<<"--"<<v2<<std::endl;
                }
            }
        }
    }
}

/*
Function prototype:
void travelCal::addCity(std::string n);

Function description:
This method adds a vertex(city) to the graph(map).

Example:

tC->addCity(Boulder);

Pre-condition: There is no Boulder in the map
Post-condition: Method add Boulder city to the map and pre-initialize all the variable in its struct
*/
void travelCal::addCity(std::string n){
    bool found = false;
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == n){
            found = true;
        }
    }
    if(found == false){
        city c;
        c.name = n;
        c.visited = false;
        c.district = -1;
        c.refID=-1;
        c.popularity=-1;
        cities.push_back(c);
        numberCities++;

    }


}

/*
Function prototype:
void travelCal::deleteCity(std::string name);

Function description:
This method delete the city information from the map

Example:

tC->deleteCity(Boulder);

Pre-condition: There is Boulder city in the map
Post-condition: Method delete all connecting flights, and roads that connect to Boulder from the map, and set Boulder city to NULL.
*/
void travelCal::deleteCity(std::string name){
    bool found = false;
    city *deleting;
    int position;
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == name){
            found = true;
            deleting = &cities[i];
            position = i;
            break;
        }
    }
    for(int j=0; j<deleting->adj.size();j++){
        //deleting->adj[j].c = NULL;
        deleting->adj[j].road.cost = -1;
        deleting->adj[j].road.time = -1;
        deleting->adj[j].flight.cost = -1;
        deleting->adj[j].flight.time = -1;
        for(int k=0; k<deleting->adj[j].c->adj.size();k++){
            if(deleting->adj[j].c->adj[k].c->name == name){
                deleting->adj[j].c->adj[k].road.cost = -1;
                deleting->adj[j].c->adj[k].road.time = -1;
                deleting->adj[j].c->adj[k].flight.cost = -1;
                deleting->adj[j].c->adj[k].flight.time = -1;
            }

        }
    }
    deleting = NULL;
    //cities.erase(cities.begin()+position);
    numberCities--;
}

/*
Function prototype:
void travelCal::deleteRoad(std::string v1,std::string v2);

Function description:
This method delete the road between two cities as entered.

Example:

tC->deleteRoad(Boulder,Denver);

Pre-condition: There is the connecting road between the cities
Post-condition: Method delete the road connection between Boulder and Denver.
*/
void travelCal::deleteRoad(std::string v1,std::string v2){
    city *d1;
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v1){
            d1 = &cities[i];
        }
    }
    for(int j=0; j<d1->adj.size();j++){
        if(d1->adj[j].c->name==v2){
            d1->adj[j].road.cost = -1;
            d1->adj[j].road.time = -1;
            for(int k=0; k<d1->adj[j].c->adj.size();k++){
                if(d1->adj[j].c->adj[k].c->name==v1){
                    d1->adj[j].c->adj[k].road.cost = -1;
                    d1->adj[j].c->adj[k].road.time = -1;
                }
            }
        }
    }
}

/*
Function prototype:
void travelCal::deleteFlight(std::string v1,std::string v2);

Function description:
This method delete the connecting flight between two cities as entered.

Example:

tC->deleteFlight(Boston,London);

Pre-condition: There is the connecting flight between the cities
Post-condition: Method delete the flight connection between Boston and London.
*/
void travelCal::deleteFlight(std::string v1,std::string v2){
    city *d1;
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v1){
            d1 = &cities[i];
        }
    }
    for(int j=0; j<d1->adj.size();j++){
        if(d1->adj[j].c->name==v2){
            d1->adj[j].flight.cost = -1;
            d1->adj[j].flight.time = -1;
            for(int k=0; k<d1->adj[j].c->adj.size();k++){
                if(d1->adj[j].c->adj[k].c->name==v1){
                    d1->adj[j].c->adj[k].flight.cost = -1;
                    d1->adj[j].c->adj[k].flight.time = -1;
                }
            }
        }
    }
}


/*
Function prototype:
bool travelCal::findCity(std::string v);

Function description:
This method return true-false whether the city is found, or the city is in the map.

Example:

tC->findCity(Boston);

Pre-condition: Unknown result whether Boston is already in the map.
Post-condition: Method return true, if Boston is in the map.
*/
bool travelCal::findCity(std::string v){
    bool found = false;
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v){
            found = true;
        }
    }
    return found;
}

/*
Function prototype:
void travelCal::resetVisited();

Function description:
This method resets visited variable of each cities in the map

Example:

tC->resetVisited();

Pre-condition: Any condition of visited variables
Post-condition: Method resets all cities.visited to unvisited == false;
*/
void travelCal::resetVisited(){
    for(int i = 0; i < cities.size(); i++){
            cities[i].visited=false;
    }
}

/*
Function prototype:
void travelCal::setMapSize(int ss);

Function description:
This method assigns new map size, or number of cities.

Example:

tC->setMapSize(10);

Pre-condition: Any number of cities in the map
Post-condition: Method sets the number of cities in the map as 10 cities.
*/
void travelCal::setMapSize(int ss){
    numberCities = ss;
}

/*
Function prototype:
void travelCal::popularitize();

Function description:
This method is a void function that contains a multiple call of int popularitize for all cities.

Example:

tC->popularitize();

Pre-condition: Any condition of popularity of each cities
Post-condition: Method executes each city's popularity to the assigned method.
*/
void travelCal::popularitize(){

    for(int i=0;i<cities.size();i++){
        cities[i].popularity = popularitize(cities[i]);
    }

};

/*
Function prototype:
int travelCal::popularitize(city c);

Function description:
This method executes the popularity of the city as the number of adjacent cities.

Example:

tC->popularitize(city c);

Pre-condition: Any condition of popularity of the city
Post-condition: Method return the popularity of the city as how many cities it connects to
*/
int travelCal::popularitize(city c){

    return c.adj.size();

}
/*
Function prototype:
void travelCal::buildDistrict();

Function description:
This method assigns the district number to each city. If the cities can be connect through roads, the cities are in the same district.

Example:

tC->buildDistrict();

Pre-condition: Any condition of district connecting
Post-condition: Method assigns district numbers to cities connected by roads.
*/
void travelCal::buildDistrict(){
    std::queue<city*> myqueue;
    city *s;
    city *u;
    int indexV=0;
    int district=1;
    for(int i=0; i<cities.size();i++){
        cities[i].visited=false;
    }
    while(indexV<cities.size()){
        if(cities[indexV].visited==false){
            cities[indexV].visited=true;
            cities[indexV].district=district;
            s=&cities[indexV];
            myqueue.push(s);
            while(!myqueue.empty()){
                u = myqueue.front();
                myqueue.pop();
                for(int j=0;j<u->adj.size();j++){
                  if(u->adj[j].c->visited==false && u->adj[j].road.cost!=-1){
                    u->adj[j].c->visited=true;
                    u->adj[j].c->district=u->district;
                    myqueue.push(u->adj[j].c);
                  }
                }
            }
            district++;
        }
        indexV++;
    }
}

/*
Function prototype:
bool travelCal::noDistrict();

Function description:
This method return true-false whether a city in the map has not been assigned to a district.

Example:

tC->noDistrict();

Pre-condition: Any condition of district connecting
Post-condition: Method return false if all cities have been assigned to districts.
*/
bool travelCal::noDistrict(){
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].district==-1){
            return true;
        }
    }
    return false;
}

/*
Function prototype:
bool travelCal::inDistrict(std::string v1,std::string v2);

Function description:
This method return true-false whether two cities in the map are in the same district.

Example:

tC->inDistrict(Boulder,Denver);

Pre-condition: Any condition of district connecting
Post-condition: Method returns true, if that Boulder is connecting to Denver by a road.
*/
bool travelCal::inDistrict(std::string v1,std::string v2){
    bool found1=false;
    bool found2=false;
    int districtC1;
    int districtC2;
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v1 && found1==false){
            districtC1 = cities[i].district;
            //cout<<districtC1<<endl;
            found1=true;
        }
        if(cities[i].name == v2 && found2==false){
            districtC2 = cities[i].district;
            //cout<<districtC2<<endl;
            found2=true;
        }
    }
    if(found1==true && found2==true){
        if(districtC1==districtC2){
                //cout<<"inDistrict"<<endl;
                return true;
        } else {
                return false;
        }
    }

}

/*
Function prototype:
void travelCal::displayRoads();

Function description:
This method displays all possible road connections.

Example:

tC->displayRoads();

Pre-condition: The map has some road connection
Post-condition: Method display all possible road connections in the map.
*/
void travelCal::displayRoads(){

    //loop through all cities and adjacent cities
    for(int i = 0; i < cities.size(); i++){
        std::cout<<cities[i].district<<":"<<cities[i].name<<"-->";
        for(int j = 0; j < cities[i].adj.size(); j++){
            //cout<<cities[i].adj[j].v->name<<"*"<<cities[i].adj[j].weight<<"*";
            if(j<cities[i].adj.size()){
                if(cities[i].adj[j].road.cost!=-1){
                    std::cout<<cities[i].adj[j].c->name<<"**"<<cities[i].adj[j].road.cost<<"**";
                }
            }
        }
        std::cout<<std::endl;
    }

}

/*
Function prototype:
void travelCal::displayFlights();

Function description:
This method displays all possible flight connections.

Example:

tC->displayFlights();

Pre-condition: The map has some flight connection
Post-condition: Method display all possible flight connections in the map.
*/
void travelCal::displayFlights(){

    //loop through all cities and adjacent cities
    for(int i = 0; i < cities.size(); i++){
        std::cout<<cities[i].district<<":"<<cities[i].name<<"-->";
        for(int j = 0; j < cities[i].adj.size(); j++){
            //cout<<cities[i].adj[j].v->name<<"*"<<cities[i].adj[j].weight<<"*";
            /*std::cout<<cities[i].adj[j].c->name;
            if(j!=cities[i].adj.size()){
                std::cout<<"**";
                if(cities[i].adj[j].flight.cost!=-1){
                    std::cout<<cities[i].adj[j].flight.cost<<"**";
                }
            }*/
            if(j<cities[i].adj.size()){
                if(cities[i].adj[j].flight.cost!=-1){
                    std::cout<<cities[i].adj[j].c->name<<"**"<<cities[i].adj[j].flight.cost<<"**";
                }
            }
        }
        std::cout<<std::endl;
    }

}
/*
Function prototype:
void travelCal::displayMaps();

Function description:
This method displays both road and flight connections separately.

Example:

tC->displayMaps();

Pre-condition: The map has some flight and road connections.
Post-condition: Method displays both road and flight connections separately.
*/
void travelCal::displayMaps(){

    std::cout<<"======ROAD MAP======"<<std::endl;
    displayRoads();
    std::cout<<"\n======FLIGHT MAP======"<<std::endl;
    displayFlights();

    //loop through all cities and adjacent cities
    /*for(int i = 0; i < cities.size(); i++){
        std::cout<<cities[i].district<<":"<<cities[i].name<<"-->";
        for(int j = 0; j < cities[i].adj.size(); j++){
            //cout<<cities[i].adj[j].v->name<<"*"<<cities[i].adj[j].weight<<"*";
            std::cout<<cities[i].adj[j].c->name;
            if(j!=cities[i].adj.size()-1)
                std::cout<<"**";
        }
        std::cout<<std::endl;
    }*/

}

/*
Function prototype:
void travelCal::cityInReach(std::string startingCity);

Function description:
This method displays cities that a city can be connected via roads and flights.

Example:

tC->cityInReach(Boulder);

Pre-condition: The map has some flight and road connections starting from Boulder.
Post-condition: Method displays cities that can travel from Boulder via roads and flights.
*/
void travelCal::cityInReach(std::string startingCity){
  std::queue<city*> myqueue;
  city *s;
  city *u;
  for(int i=0; i<cities.size(); i++){
      cities[i].visited = false;
      if(cities[i].name == startingCity){
          cities[i].visited = true;
          s = &cities[i];
          std::cout<<s->name<<std::endl;
      }
  }
  myqueue.push(s);
  while(!myqueue.empty()){
    u = myqueue.front();
    myqueue.pop();
    for(int j=0;j<u->adj.size();j++){
      if(u->adj[j].c->visited==false){
        u->adj[j].c->visited=true;
        myqueue.push(u->adj[j].c);
        std::cout<<u->adj[j].c->name<<std::endl;
      }
    }
  }
}

/*
Function prototype:
connection travelCal::selectLessTime(adjCity adj);

Function description:
This method returns the connecting option between a road and a flight between two cities whether which one has the least time-spending.

Example:

tC->selectLessTime(Denver,Seattle);

Pre-condition: The map has a flight and road connection starting from Denver to Seattle.
Post-condition: Method return the flight connection, because it takes less time to travel from Denver to Seattle by Flying.
*/
connection travelCal::selectLessTime(adjCity adj){
    adjCity testing = adj;
    if(testing.flight.cost!=-1 && testing.road.cost!=-1){//have flight and road, select flight
        return testing.flight;
    } else if(testing.flight.cost==-1){//no flight connection always select road
        return testing.road;
    } else if(testing.road.cost==-1){//no road connection always select flight
        return testing.flight;
    }
}

/*
Function prototype:
connection travelCal::selectMoreTime(adjCity adj);

Function description:
This method returns the connecting option between a road and a flight between two cities whether which one has the most time-spending.

Example:

tC->selectMoreTime(Denver,Seattle);

Pre-condition: The map has a flight and road connection starting from Denver to Seattle.
Post-condition: Method return the road connection, because it takes more time to travel from Denver to Seattle by Flying.
*/
connection travelCal::selectMoreTime(adjCity adj){
    adjCity testing = adj;
    if(testing.flight.cost!=-1 && testing.road.cost!=-1){//have flight and road, select road
        return testing.road;
    } else if(testing.flight.cost==-1){//no flight connection always select road
        return testing.road;
    } else if(testing.road.cost==-1){//no road connection always select flight
        return testing.flight;
    }
}

/*
Function prototype:
void travelCal::leastCity(std::string v1,std::string v2);

Function description:
This method display the path information that the path is visiting the least number of cities, as Dijkstra's algorithm with unweight edges.

Example:

tC->leastCity(Denver,London);

Pre-condition: The map has a flight and road connection starting from Denver to London.
Post-condition: Method displays "2,Denver,Boston,London" == "numberOfConnections,Denver,Boston,London"
*/
void travelCal::leastCity(std::string v1,std::string v2){
    std::queue<city*> myqueue;
    //int s_array[vertices.size()];
    int distacePath=0;
    city *s;
    city *u;
    city *e;
    bool found1=false;
    bool found2=false;
    for(int i=0; i<cities.size();i++){
        cities[i].visited=false;
        if(cities[i].name == v1 && found1==false){
            s = &cities[i];
            found1=true;
        }
        if(cities[i].name == v2 && found2==false){
            e = &cities[i];
            found2=true;
        }
        //s_array[i]=cities[i].refID;
        cities[i].arrayID = i;
        //cout<<"i: "<<i<<" refID: "<<s_array[i]<<endl;
    }
    s->visited = true;
    myqueue.push(s);
    while(!myqueue.empty()){
        u = myqueue.front();
        myqueue.pop();
        for(int j=0;j<u->adj.size();j++){
          if(u->adj[j].c->visited==false){
            u->adj[j].c->visited=true;
            u->adj[j].c->refID=u->arrayID;
            //s_array[u->adj[j].v->arrayID]=u->arrayID;
            //cout<<u->name<<" : "<<u->adj[j].v->name<<" : "<<u->arrayID<<endl;
            if(u->adj[j].c->name!=e->name){
                myqueue.push(u->adj[j].c);
                for(int a=0; a<cities.size();a++){
                //cout<<"arrayID: "<<a<<" refID: "<<s_array[a]<<endl;
                }
            } else {
                //int k=e->arrayID;
                for(int a=0; a<cities.size();a++){
                //cout<<"arrayID: "<<a<<" refID: "<<s_array[a]<<endl;
                }
                city *rePath = u->adj[j].c;
                path pathShort;
                pathShort.dist=0;
                int refID=rePath->refID;
                //cout<<"theerarun::city: "<<rePath->name<<" refID: "<<refID<<endl;
                while(rePath->name!=s->name){
                  pathShort.path.push(rePath);
                  refID = rePath->refID;
                  distacePath++;
                  //cout<<"theerarun::city: "<<rePath->name<<" :startCity: "<<s->name<<endl;
                  rePath = &cities[refID];
                }
                rePath = &cities[refID];
                pathShort.path.push(rePath);
                pathShort.dist=distacePath;
                std::cout<<pathShort.dist;
                while(!pathShort.path.empty()){
                    std::cout<<","<<pathShort.path.top()->name;
                    pathShort.path.pop();
                }
                std::cout<<std::endl;
            }
          }
        }
      }
};

/*
Function prototype:
void travelCal::bestTravel(std::string source,std::string destination);

Function description:
This method display the path information that the path contains the least time-spending connections.

Example:

tC->bestTravel(Denver,London);

Pre-condition: The map has a flight and road connection starting from Denver to London.
Post-condition: Method displays "16460 kilometers,~$1421,Denver,New York City,Paris,Barcelona,Saudi Arabia" == "distanceTravel,approx-dollarCost,Denver,New York City,Paris,Barcelona,Saudi Arabia"
*/
void travelCal::bestTravel(std::string source,std::string destination){
  std::stack<city*> mystack;
  int distancePath=0;
  int storeDist = 0;
  int distTemp=0;
  city *s;
  city *u;
  city *e;
  city *tempVertex;
  city *checkSolved;
  for(int i=0;i<cities.size();i++){
    cities[i].visited=false;
    cities[i].distance=0;
    if(cities[i].name==source){
      s = &cities[i];
    } else if(cities[i].name==destination){
      e = &cities[i];
    }
  }
  s->visited=true;
  u=s;
  connection distSelect = selectLessTime(u->adj[0]);
  storeDist= distSelect.cost;
  while(u->name!=e->name){
    int i = cities.size()-1;
    int refMaxDist=0;
    for(int k=0;k<u->adj.size();k++){
        if(u->adj[k].c->visited==false){
            distSelect = selectMoreTime(u->adj[k]);
            refMaxDist = std::max(refMaxDist,distSelect.cost);
        }
    }
    int refMinDist=refMaxDist;
    for(int k=0;k<u->adj.size();k++){
        if(u->adj[k].c->visited==false){
            distSelect = selectLessTime(u->adj[k]);
            refMinDist = std::min(refMinDist,distSelect.cost);
        }
    }

    storeDist=u->distance+refMinDist;
    while(i>-1){
      if(cities[i].visited==true){
        checkSolved = &cities[i];
        int j =checkSolved->adj.size()-1;
        while(j>-1){
          if(checkSolved->adj[j].c->visited==false){
              distSelect = selectLessTime(checkSolved->adj[j]);
            if(storeDist >= (distSelect.cost + checkSolved->distance)){
                  distTemp= distSelect.cost;
                  tempVertex = checkSolved->adj[j].c;
                  tempVertex->previous=checkSolved;
                  distTemp = distTemp+checkSolved->distance;
                  tempVertex->distance = distTemp;
                  storeDist = distTemp;
                  //std::cout<<"ss:"<<storeDist<<":ss"<<std::endl;
            }
          }
            j--;
        }
      }
      i--;
    }
    tempVertex->visited = true; //solved
    u = tempVertex;
    storeDist = u->distance;
  }
  distancePath = u->distance;
  mystack.push(u);
  while(s->name!=u->name){
    u = u->previous;
    mystack.push(u);
  }
  std::cout<<distancePath<<" kilometers,";
  int dollar = distancePath/12+(s->popularity)/(e->popularity)*50;
  std::cout<<"~$"<<dollar;
  while(!mystack.empty()){
    std::cout<<","<<mystack.top()->name;
    mystack.pop();
  }
  std::cout<<std::endl;
};
