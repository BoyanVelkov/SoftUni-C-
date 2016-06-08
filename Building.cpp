#include "Building.h"

Building::Building(std::string name, uint8_t floors, uint8_t offices, uint16_t employees, uint8_t freeWorkingSeats,
                   bool bIsHaveRestaurant)
{
    setName(name);
    setFloors(floors);
    setOffices(offices);
    setEmployees(employees);
    setFreeWorkingSeats(freeWorkingSeats);
    setRestaurant(bIsHaveRestaurant);
}

Building::~Building()
{
    //dtor
}

// seters
void Building::setName(std::string name)
{
    this->name = name;
}

void Building::setFloors(uint8_t floors)
{
    this->floors = floors;
}

void Building::setOffices(uint8_t offices)
{
    this->offices = offices;
}

void Building::setEmployees(uint16_t employees)
{
    this->employees = employees;
}

void Building::setFreeWorkingSeats(uint8_t freeWorkingSeats)
{
    this->freeWorkingSeats = freeWorkingSeats;
}

void Building::setRestaurant(bool bIsHaveRestaurant)
{
    this->bIsHaveRestaurant = bIsHaveRestaurant;
    // if have restaurant one floor less
    if(bIsHaveRestaurant){

        uint8_t floors = this->getFloors();
        floors --;
        this->setFloors(floors);
    }
}

// geters
std::string Building::getName()
{
    return this->name;
}

uint8_t Building::getFloors()
{
    return this->floors;
}

uint8_t Building::getOffices()
{
    return this->offices;
}

uint16_t Building::getEmployees()
{
    return this->employees;
}

uint8_t Building::getFreeWorkingSeats()
{
    return this->freeWorkingSeats;
}

bool Building::getRestaurant()
{
    return this->bIsHaveRestaurant;
}
