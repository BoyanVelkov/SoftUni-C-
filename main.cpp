#include <iostream>
#include <float.h>
#include <climits>
#include "Building.h"

#define ARRAY_SIZE 3

void mostEmployees(Building* arr);
void mostFreePlaces(Building* arr);
void highestCoefficient(Building* arr);
void mostAndLeastPeoplePerFloor(Building* arr);

int main()
{
    Building XYZIndustries("XYZ Industries", 6, 127, 600, 196);
    Building RapidDevelopmentCrew("Rapid Development Crew", 8, 210, 822, 85);
    Building SoftUni("SoftUni", 11, 106, 200, 60);

    Building businessPark[ARRAY_SIZE] = {XYZIndustries, RapidDevelopmentCrew, SoftUni};

    mostEmployees(businessPark);
    mostFreePlaces(businessPark);
    highestCoefficient(businessPark);
    mostAndLeastPeoplePerFloor(businessPark);
    /// Add bool restorant i class Building, if true set floor "--"
    return 0;
}

void mostEmployees(Building* arr)
{
    // number of max employees
    uint16_t maxEmployees = 0;
    // number of the firm with max employees
    uint8_t arrNumber = 0;

    for(size_t i = 0; i < ARRAY_SIZE; i++){

        if (arr[i].getEmployees() > maxEmployees){

            maxEmployees = arr[i].getEmployees();
            arrNumber = i;
        }
    }
    std::cout << "Most employees in: " << arr[arrNumber].getName() << "." << std::endl;
}

void mostFreePlaces (Building* arr)
{
    // number ot max free places
    uint8_t maxFreePl = 0;
    // number of the firm with max free places
    uint8_t arrNumber = 0;

    for (size_t i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr[i].getFreeWorkingSeats() > maxFreePl ){

            maxFreePl = arr[i].getFreeWorkingSeats();
            arrNumber = i;
        }
    }
    std::cout << "Most free plases in: " << arr[arrNumber].getName() << "." << std::endl;
}

void highestCoefficient(Building* arr)
{
    // highest coefficient
    double highestCoeff = DBL_MIN;
    // number of the firm with highest coefficient
    uint8_t arrNumber = 0;

    for (size_t i = 0; i < ARRAY_SIZE; i++){

        uint16_t employees = arr[i].getEmployees();
        uint8_t freeSeats = arr[i].getFreeWorkingSeats();
        double coeff = employees / (employees + freeSeats);

        if(coeff > highestCoeff){

            highestCoeff = coeff;
            arrNumber = i;
        }
    }
    std::cout << "Highest coefficient in " << arr[arrNumber].getName() << "." << std::endl;
}

void mostAndLeastPeoplePerFloor(Building* arr)
{
    // most peopla per floor
    double maxEmployees = 0;
    // least people per floor
    double leastEmployees = DBL_MAX;
    //number of the firm with least people per floor
    uint8_t arrNumberMin = UCHAR_MAX;
    // number of the firm with most people per floor
    uint8_t arrNumberMax = 0;

    for (size_t i = 0; i < ARRAY_SIZE; i++){

        uint16_t employeers = arr[i].getEmployees();
        uint8_t floor = arr[i].getFloors();
        double empTemp = employeers / floor;

        if (empTemp > maxEmployees){

            maxEmployees = empTemp;
            arrNumberMax = i;
        }
        if (empTemp < leastEmployees){

            leastEmployees = empTemp;
            arrNumberMin = i;
        }
    }
    std::cout << "Most people per floor: " << arr[arrNumberMax].getName() << "." << std::endl;
    std::cout << "Least people per floor: " << arr[arrNumberMin].getName() << "." << std::endl;
}
