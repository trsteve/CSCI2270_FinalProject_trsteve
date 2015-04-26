#ifndef TRAVELKIT_H
#define TRAVELKIT_H


class travelkit
{
    public:
        travelkit();
        virtual ~travelkit();
        void projectSummary();
        void howtorun();

        void adjFind();
        void adjRoad();
        void adjFlight();

        void addCity();
        void addRoad();
        void addFlight();

        void deleteCity();
        void deleteRoad();
        void deleteFlight();

        void displayRoads();
        void displayFlights();
        void displayMaps();

        void findCity();

        void buildDistrict();

        void cityInReach();

        void leastCity();
        void bestTravel();
        void popularitize();
    protected:
    private:
};

#endif // TRAVELKIT_H
