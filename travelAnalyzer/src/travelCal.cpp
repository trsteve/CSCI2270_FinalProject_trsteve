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
    cities.erase(cities.begin()+position);
}

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



bool travelCal::findCity(std::string v){
    bool found = false;
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].name == v){
            found = true;
        }
    }
    return found;
}
void travelCal::resetVisited(){
    for(int i = 0; i < cities.size(); i++){
            cities[i].visited=false;
    }
}
void travelCal::setMapSize(int ss){
    numberCities = ss;
}
void travelCal::popularitize(){

    for(int i=0;i<cities.size();i++){
        cities[i].popularity = popularitize(cities[i]);
    }

};
int travelCal::popularitize(city c){

    return c.adj.size();

}
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
bool travelCal::noDistrict(){
    for(int i = 0; i < cities.size(); i++){
        if(cities[i].district==-1){
            return true;
        }
    }
    return false;
}
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
