#include "travelCal.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct city;//pre-initialize

struct adjCity;//pre-initialize

void displayMenu();
void displayAdd();
void menuAdd(travelCal * tC);
void displayDel();
void menuDel(travelCal * tC);
void readRoad(travelCal * tC, char * fileRoad);
void readFlight(travelCal * tC, char * fileFlight);

int main(int argc, char*argv[])
{
    int input;
    travelCal *tC=new travelCal();
    tC->setMapSize(0);
    readRoad(tC, argv[1]);
    readFlight(tC, argv[2]);
    bool quit = false;
    while(quit != true)
    {
        displayMenu();
        cin >> input;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');
        string stCity;
        string edCity;
        string cityName;
        switch (input)
        {
            // print maps
            case 1:
                tC->buildDistrict(); //always update a district
                tC->displayMaps();
                break;
            // call add functions
            case 2:
                menuAdd(tC);
                break;
            //find city
            case 3:
                cout<<"Enter a city name:"<<endl;
                getline(cin,cityName,'\n');
                if(tC->findCity(cityName)){
                    cout<<cityName<<" : found"<<endl;
                } else {
                    cout<<cityName<<" : not found"<<endl;
                }
                break;
           //find cities in reach
            case 4:
                cout<<"Enter a starting city name:"<<endl;
                getline(cin,cityName,'\n');
                if(tC->findCity(cityName)){
                    tC->cityInReach(cityName);
                } else {
                    cout<<cityName<<" : not found"<<endl;
                }
                break;

            // find path with least visit
            case 5:
                cout<<"Enter a starting city:"<<endl;
                getline(cin,stCity,'\n');
                //cin.ignore(stCity.max_size(),'\n');
                cout<<"Enter an ending city:"<<endl;
                getline(cin,edCity,'\n');
                //cin.ignore(edCity.max_size(),'\n');
                //cout<<stCity<<"--?-->"<<edCity<<endl;
                if(tC->findCity(stCity) && tC->findCity(edCity)){//if only found both
                    tC->leastCity(stCity,edCity);
                } else{
                    cout<<"One or more cities doesn't exist"<<endl;
                }
                break;
            // find best travel
            case 6:
                cout<<"Enter a starting city:"<<endl;
                getline(cin,stCity,'\n');
                //cin.ignore(stCity.max_size(),'\n');
                cout<<"Enter an ending city:"<<endl;
                getline(cin,edCity,'\n');
                //cout<<stCity<<"--?-->"<<edCity<<endl;
                //cin.ignore(edCity.max_size(),'\n');
                if(tC->findCity(stCity) && tC->findCity(edCity)){//if only found both
                    tC->bestTravel(stCity,edCity);
                } else{
                    cout<<"One or more cities doesn't exist"<<endl;
                }
                break;
            // call delete functions
            case 7:
                menuDel(tC);
                break;
            // quit
            case 8:
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            // invalid input
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }


    return 0;
}
void displayMenu()
{
    cout << "======Main Menu=====" << endl;
    //cout << "1. Find a movie" << endl;
    cout << "1. Print Map" << endl;
    cout << "2. Add ..." << endl;
    cout << "3. Find city" << endl;
    cout << "4. Find cities in reach" << endl;
    cout << "5. Find least city" << endl;
    cout << "6. Find best path" << endl;
    cout << "7. Delete ..." << endl;
    cout << "8. Quit" << endl;
    return;
}

void displayAdd(){

    cout << "======Add Menu=====" << endl;
    cout << "1. Add City" << endl;
    cout << "2. Add Road" << endl;
    cout << "3. Add Flight" << endl;
    cout << "4. Main Menu" << endl;
    return;
}

void menuAdd(travelCal *tC){

    int inputAdd;
    bool quit2 = false;
    while(quit2 != true)
    {
        displayAdd();
        cin >> inputAdd;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');
        string cityName;
        string stCity;
        string edCity;
        string weight;
        switch (inputAdd)
        {
            // add city
            case 1:
                cout<<"Enter a city name:"<<endl;
                getline(cin,cityName,'\n');
                if(tC->findCity(cityName)){
                    cout<<cityName<<" : existed"<<endl;
                } else {
                    tC->addCity(cityName);
                }
                break;
            // add road
            case 2:
                cout<<"Enter a starting city name:"<<endl;
                getline(cin,stCity,'\n');
                cout<<"Enter a destination city name:"<<endl;
                getline(cin,edCity,'\n');
                cout<<"Enter the driving distance:"<<endl;
                getline(cin,weight,'\n');
                if(tC->findCity(stCity) && tC->findCity(edCity)){//if only found both
                    tC->addRoad(stCity,edCity,atoi(weight.c_str()));
                } else{
                    cout<<"One or more cities doesn't exist"<<endl;
                }
                break;
            // add flight
            case 3:
                cout<<"Enter a starting city name:"<<endl;
                getline(cin,stCity,'\n');
                cout<<"Enter a destination city name:"<<endl;
                getline(cin,edCity,'\n');
                cout<<"Enter the flying distance:"<<endl;
                getline(cin,weight,'\n');
                if(tC->findCity(stCity) && tC->findCity(edCity)){//if only found both
                    tC->addFlight(stCity,edCity,atoi(weight.c_str()));
                } else{
                    cout<<"One or more cities doesn't exist"<<endl;
                }
                break;
            //return to main menu
            case 4:
                quit2 = true;
                break;
            // invalid input
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
    return;
}

void displayDel(){

    cout << "======Delete Menu=====" << endl;
    cout << "1. Delete City" << endl;
    cout << "2. Delete Road" << endl;
    cout << "3. Delete Flight" << endl;
    cout << "4. Main Menu" << endl;
    return;
}

void menuDel(travelCal *tC){

    int inputDel;
    bool quit3 = false;
    while(quit3 != true)
    {
        displayDel();
        cin >> inputDel;

        //clear out cin
        cin.clear();
        cin.ignore(10000,'\n');
        string cityName;
        string stCity;
        string edCity;
        switch (inputDel)
        {
            // del city
            case 1:
                cout<<"Enter a city name:"<<endl;
                getline(cin,cityName,'\n');
                if(tC->findCity(cityName)){
                    tC->deleteCity(cityName);
                } else {
                    cout<<cityName<<" does not existed"<<endl;
                }
                break;
            //del road
            case 2:
                cout<<"Enter a starting city name:"<<endl;
                getline(cin,stCity,'\n');
                cout<<"Enter a destination city name:"<<endl;
                getline(cin,edCity,'\n');
                if(tC->findCity(stCity) && tC->findCity(edCity)){//if only found both
                    tC->deleteRoad(stCity,edCity);
                } else{
                    cout<<"One or more cities doesn't exist"<<endl;
                }
                break;
            //del flight
            case 3:
                cout<<"Enter a starting city name:"<<endl;
                getline(cin,stCity,'\n');
                cout<<"Enter a destination city name:"<<endl;
                getline(cin,edCity,'\n');
                if(tC->findCity(stCity) && tC->findCity(edCity)){//if only found both
                    tC->deleteFlight(stCity,edCity);
                } else{
                    cout<<"One or more cities doesn't exist"<<endl;
                }
                break;
            //return to main menu
            case 4:
                quit3 = true;
                break;
            // invalid input
            default:
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break;
        }
    }
    return;
}
//read road map file
void readRoad(travelCal * tC, char * fileRoad)
{
    ifstream in_stream;
    //cout << fileName << endl;
    in_stream.open(fileRoad);
    if (!in_stream)
    {
        //cout << "Could not open file\n";
        return;
    }
    string readWord;
    int distanceEdge;
    vector<city> graphRead;
    int indexCity=0; //graphRead[0] = atlanta
    int indexTemp=0;
    int numberCities=0;
    bool citiesStored = false;
    bool edgesStored = false;
    bool found = false;
    bool cityStored = false;
    bool edgeStored = false;
    bool eol=false;
    bool cuttingline=false;
    bool inOldline;
    //cout<<"here\n";
    //cout<<"indexCity: "<<indexCity<<endl;
    //cout<<"indexTemp: "<<indexCity<<endl;
    while (!in_stream.eof())
    {
        getline(in_stream, readWord, '\t');
        //in_stream >> readWord;
        int posEnter = readWord.find("\n");
        inOldline=true;
        //cout<<"dd:"<<readWord<<":dd"<<endl;
        if(posEnter!=-1){
            eol = true;
            readWord = readWord.substr(0,posEnter-1);
        } else {
            eol =false;
        }
        //cout<<"ss:"<<readWord<<":ss"<<endl;
        found = false;
        if(citiesStored==false){
            cityStored = false;
        }
        edgeStored = false;
        cuttingline=false;
        while(cityStored==false && citiesStored==false){//storing the first line of the file --> cities
            //readWord = readWord.substr(0,posEnter);
            for(int i = 0; i < graphRead.size(); i++){
                if(readWord==graphRead[i].name){
                    found=true; //end of line one get first city name again.
                    citiesStored=true;
                    //cout<<"here5\n";
                }
            }
            //cout<<"here1\n";
            if(found==false){
                if(readWord!="Road"){
                    city v;
                    v.name = readWord;
                    graphRead.push_back(v);
                    tC->addCity(readWord);
                    //gC->displayEdges();
                    //cout<<graphRead[numberCities].name<<endl;
                    numberCities++;
                }
                cityStored=true;
                //cout<<"here2\n";
                if(eol){
                    citiesStored=true;
                    indexCity=0;
                    //cout<<"end of line"<<endl;
                    cuttingline=true;
                    //tC->setMapSize(numberCities);
                }
            }
            //cout<<"here3\n";
        }
        if(citiesStored==true && edgesStored==true){
            distanceEdge = atoi(readWord.c_str());
            if(distanceEdge!=0){
                edgeStored=true;
                edgesStored=true;
            } else if(distanceEdge==0){
                edgesStored=false;
            }
        }
        while(edgeStored==false && citiesStored==true && cuttingline==false && edgesStored==false){
            //cout<<"starting adding edges"<<endl;
            //readWord = readWord.substr(0,posEnter);
            distanceEdge = atoi(readWord.c_str());
            //cout<<"indexCity: "<<indexCity<<":"<<graphRead[indexCity].name<<endl;
            //cout<<"indexTemp: "<<indexTemp<<":"<<graphRead[indexTemp].name<<endl;
            //cout<<"distanceEdge: "<<distanceEdge<<endl;
            //cout<<graphRead[indexCity].name<<"-->"<<distanceEdge<<"-->"<<graphRead[indexTemp].name<<endl;
            if( distanceEdge!=-1 && distanceEdge!=0 ){
                //cout<<"checking: "<<graphRead[indexCity].name<<"--?--"<<graphRead[indexTemp].name<<endl;
                for(int k=0; graphRead[indexCity].adj.size();k++){
                    //cout<<"k: "<<k<<endl;
                    if(graphRead[indexCity].adj[k].c){
                        //cout<<graphRead[indexCity].adj[k].v->name<<endl;
                        if(graphRead[indexCity].adj[k].c->name==graphRead[indexTemp].name){
                        found=true;
                        //cout<<"found"<<endl;
                    } else {
                        //cout<<"done"<<endl;
                        break;
                    }
                    }
                }
                if(found==false){
                    tC->addRoad(graphRead[indexCity].name,graphRead[indexTemp].name,atoi(readWord.c_str()));
                    adjCity av;
                    av.c = &graphRead[indexTemp];
                    av.road.cost = atoi(readWord.c_str());
                    graphRead[indexCity].adj.push_back(av);
                    //another vertex for edge in other direction
                    adjCity av2;
                    av2.c = &graphRead[indexCity];
                    av.road.cost = atoi(readWord.c_str());
                    graphRead[indexTemp].adj.push_back(av2);
                    edgeStored=true;
                    //gC->displayEdges();
                    //cout<<"OPERATION: "<<graphRead[indexCity].name<<"-->"<<distanceEdge<<"-->"<<graphRead[indexTemp].name<<endl;
                    found=true;
                }
            } else if(distanceEdge==0 || distanceEdge==-1){
                //cout<<"same vertex or no edge"<<endl;
                edgeStored=true;
            }

            indexTemp++; //every reading number
            //cout<<"indexTemp: "<<indexTemp<<endl;
            //cout<<"numCity: "<<numberCities<<endl;
            //cout<<"indexTemp: "<<indexTemp<<endl;
            if(indexTemp==numberCities){
                citiesStored=true;
                //cout<<"end of line"<<endl;
                indexCity++;
                indexTemp=indexCity;
                edgesStored=true;
                //cout<<"indexTemp: "<<indexTemp<<endl;
                if(indexCity==numberCities){
                    return;
                }
            }

        }
        eol = false;
        //cout<<"end of read a word"<<endl;
    }
}
//read flight map file
void readFlight(travelCal * tC, char * fileFlight){
    ifstream in_stream;
    //cout << fileName << endl;
    in_stream.open(fileFlight);
    if (!in_stream)
    {
        //cout << "Could not open file\n";
        return;
    }
    string readWord;
    int distanceEdge;
    vector<city> graphRead;
    int indexCity=0; //graphRead[0] = atlanta
    int indexTemp=0;
    int numberCities=0;
    bool citiesStored = false;
    bool edgesStored = false;
    bool found = false;
    bool cityStored = false;
    bool edgeStored = false;
    bool eol=false;
    bool cuttingline=false;
    bool inOldline;
    //cout<<"here\n";
    //cout<<"indexCity: "<<indexCity<<endl;
    //cout<<"indexTemp: "<<indexCity<<endl;
    while (!in_stream.eof())
    {
        getline(in_stream, readWord, '\t');
        //in_stream >> readWord;
        int posEnter = readWord.find("\n");
        inOldline=true;
        //cout<<"dd:"<<readWord<<":dd"<<endl;
        if(posEnter!=-1){
            //cout<<"end of line"<<endl;
            eol = true;
            readWord = readWord.substr(0,posEnter-1);
        } else {
            eol =false;
        }
        //cout<<"ss:"<<readWord<<":ss"<<endl;
        found = false;
        if(citiesStored==false){
            cityStored = false;
        }
        edgeStored = false;
        cuttingline=false;
        while(cityStored==false && citiesStored==false){//storing the first line of the file --> cities
            //readWord = readWord.substr(0,posEnter);
            for(int i = 0; i < graphRead.size(); i++){
                if(readWord==graphRead[i].name){
                    found=true; //end of line one get first city name again.
                    citiesStored=true;
                    //cout<<"here5\n";
                }
            }
            //cout<<"here1\n";
            if(found==false){
                if(readWord!="Flight"){
                    city v;
                    v.name = readWord;
                    graphRead.push_back(v);
                    tC->addCity(readWord);
                    //gC->displayEdges();
                    //cout<<graphRead[numberCities].name<<endl;
                    numberCities++;
                }
                cityStored=true;
                //cout<<"here2\n";
                if(eol){
                    citiesStored=true;
                    indexCity=0;
                    //cout<<"end of line"<<endl;
                    cuttingline=true;
                    //tC->setMapSize(numberCities);
                }
            }
            //cout<<"here3\n";
        }
        if(citiesStored==true && edgesStored==true){
            distanceEdge = atoi(readWord.c_str());
            if(distanceEdge!=0){
                edgeStored=true;
                edgesStored=true;
            } else if(distanceEdge==0){
                edgesStored=false;
            }
        }
        while(edgeStored==false && citiesStored==true && cuttingline==false && edgesStored==false){
            //cout<<"starting adding edges"<<endl;
            //readWord = readWord.substr(0,posEnter);
            distanceEdge = atoi(readWord.c_str());
            //cout<<"indexCity: "<<indexCity<<":"<<graphRead[indexCity].name<<endl;
            //cout<<"indexTemp: "<<indexTemp<<":"<<graphRead[indexTemp].name<<endl;
            //cout<<"distanceEdge: "<<distanceEdge<<endl;
            //cout<<graphRead[indexCity].name<<"-->"<<distanceEdge<<"-->"<<graphRead[indexTemp].name<<endl;
            if( distanceEdge!=-1 && distanceEdge!=0 ){
                //cout<<"checking: "<<graphRead[indexCity].name<<"--?--"<<graphRead[indexTemp].name<<endl;
                for(int k=0; graphRead[indexCity].adj.size();k++){
                    //cout<<"k: "<<k<<endl;
                    if(graphRead[indexCity].adj[k].c){
                        //cout<<graphRead[indexCity].adj[k].v->name<<endl;
                        if(graphRead[indexCity].adj[k].c->name==graphRead[indexTemp].name){
                        found=true;
                        //cout<<"found"<<endl;
                    } else {
                        //cout<<"done"<<endl;
                        break;
                    }
                    }
                }
                if(found==false){
                    tC->addFlight(graphRead[indexCity].name,graphRead[indexTemp].name,atoi(readWord.c_str()));
                    //adjCity av;
                    //av.c = &graphRead[indexTemp];
                    //av.flight.cost = atoi(readWord.c_str());
                    //graphRead[indexCity].adj.push_back(av);
                    //another vertex for edge in other direction
                    //adjCity av2;
                    //av2.c = &graphRead[indexCity];
                    //av.flight.cost = atoi(readWord.c_str());
                    //graphRead[indexTemp].adj.push_back(av2);
                    edgeStored=true;
                    //gC->displayEdges();
                    //cout<<"OPERATION: "<<graphRead[indexCity].name<<"-->"<<distanceEdge<<"-->"<<graphRead[indexTemp].name<<endl;
                    found=true;
                }
            } else if(distanceEdge==0 || distanceEdge==-1){
                //cout<<"same vertex or no edge"<<endl;
                edgeStored=true;
            }

            indexTemp++; //every reading number
            //cout<<"indexTemp: "<<indexTemp<<endl;
            //cout<<"numCity: "<<numberCities<<endl;
            //cout<<"indexTemp: "<<indexTemp<<endl;
            if(indexTemp==numberCities){
                citiesStored=true;
                //cout<<"end of line"<<endl;
                indexCity++;
                indexTemp=indexCity;
                edgesStored=true;
                //cout<<"indexTemp: "<<indexTemp<<endl;
                if(indexCity==numberCities){
                    return;
                }
            }

        }
        eol = false;
        //cout<<"end of read a word"<<endl;
    }
}
