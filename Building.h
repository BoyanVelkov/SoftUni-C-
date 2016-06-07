#ifndef BUILDING_H
#define BUILDING_H

#include <stdint.h>
#include <string>
#include <iostream>

class Building
{
    public:
        Building(std::string name, uint8_t floors, uint8_t offices, uint16_t employees, uint8_t freeWorkingSeats);
        virtual ~Building();
        //seters
        void setName(std::string name);
        void setFloors(uint8_t floors);
        void setOffices(uint8_t offices);
        void setEmployees(uint16_t employees);
        void setFreeWorkingSeats(uint8_t freeWorkingSeats);

        //geters
        std::string getName();
        uint8_t getFloors();
        uint8_t getOffices();
        uint16_t getEmployees();
        uint8_t getFreeWorkingSeats();

    private:
        std::string name;
        uint8_t floors;
        uint8_t offices;
        uint16_t employees;
        uint8_t freeWorkingSeats;
};

#endif // BUILDING_H
