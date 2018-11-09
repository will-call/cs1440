#ifndef WEATHERANALYZER_REGION_H
#define WEATHERANALYZER_REGION_H

#include <string>
#include <fstream>
#include "Station.h"

#define MAX_STATION_COUNT 20

class Region {

private:
    Station*        _stations[MAX_STATION_COUNT];
    int             _stationCount=0;
    int             _currentStation;

public:
    Region();
    void load(std::ifstream &input);
    void resetStationIteration();
    Station* getNextStation();
    Station* findStation(std::string& id);

private:
    Station* addStation(std::string& id, std::string& name);
};

#endif //WEATHERANALYZER_REGION_H

