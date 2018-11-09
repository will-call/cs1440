#include <string>
#include <iostream>
#include <sstream>
#include "Region.h"
#include "Utils.h"

Region::Region() {}

void Region::load(std::ifstream &input)
{
    if (!input.is_open())
    {
        std::cout << "Input file is not open" << std::endl;
        return;
    }
    std::string line;
    std::getline(input, line);

    while (!input.eof())
    {
        std::getline(input, line);

        std::string fields[5];
        if (split(line, ',', fields, 5))
        {
            Station* station = findStation(fields[0]);

            if (station== nullptr)
                station = addStation(fields[0], fields[1]);

            if (station != nullptr)
                station->load(fields[2], fields[3], fields[4]);
        }
        else
        {
            std::cout << "Invalid stats line << " << line << std::endl;
        }
    }
}

Station* Region::findStation(std::string &id)
{
    Station* station = nullptr;

    for (int i=0; i<_stationCount && station==nullptr; i++)
    {
        if (_stations[i]->getId().compare(id)==0)
            station = _stations[i];
    }

    return station;
}

Station* Region::addStation(std::string &id, std::string &name)
{
    Station* station = nullptr;

    if (_stationCount<MAX_STATION_COUNT)
    {
        station = new Station(id, name);
        _stations[_stationCount++] = station;
    }
    else
        std::cerr << "To many stations -- Cannot add station " << id << ", " << name << std::endl;

    return station;
}

void Region::resetStationIteration()
{
    _currentStation = 0;
}

Station* Region::getNextStation()
{
    Station* stat = nullptr;
    if (_currentStation < _stationCount)
        stat = _stations[_currentStation++];
    return stat;
}