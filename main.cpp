#include <iostream>
#include <float.h>
#include <climits>
#include <iomanip>
#include "Building.h"

#define ARRAY_SIZE 3

void mostEmployees(Building* arr);
void mostFreePlaces(Building* arr);
void highestCoefficient(Building* arr);
void mostAndLeastPeoplePerFloor(Building* arr);
void mostAndLeastOfficesPerFloor(Building* arr);
void mosetAndLeastEmployeesPerOffice(Building* arr);

int main()
{
    Building XYZIndustries("XYZ Industries", 6, 127, 600, 196, false);
    Building RapidDevelopmentCrew("Rapid Development Crew", 8, 210, 822, 85, true);
    Building SoftUni("SoftUni", 11, 106, 200, 60, false);

    Building businessPark[ARRAY_SIZE] = {XYZIndustries, RapidDevelopmentCrew, SoftUni};

    mostEmployees(businessPark);
    mostFreePlaces(businessPark);
    highestCoefficient(businessPark);
    mostAndLeastPeoplePerFloor(businessPark);
    mostAndLeastOfficesPerFloor(businessPark);
    mosetAndLeastEmployeesPerOffice(businessPark);

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
    std::cout << "Most employees " << maxEmployees << " in " << arr[arrNumber].getName() << " building." << std::endl;
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
    std::cout << "Most free plases " << (int)maxFreePl << " in " << arr[arrNumber].getName() << " building." << std::endl;
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
        double coeff = (double)employees / (employees + freeSeats);

        if(coeff > highestCoeff){

            highestCoeff = coeff;
            arrNumber = i;
        }
    }
    std::cout << "Highest coefficient " << std::setprecision(2) << highestCoeff << " in " << arr[arrNumber].getName()
              << " building." << std::endl;
}

void mostAndLeastPeoplePerFloor(Building* arr)
{
    // most peopla per floor
    double maxEmployees = DBL_MIN;
    // least people per floor
    double leastEmployees = DBL_MAX;
    //number of the firm with least people per floor
    uint8_t arrNumberMin = 0;
    // number of the firm with most people per floor
    uint8_t arrNumberMax = 0;

    for (size_t i = 0; i < ARRAY_SIZE; i++){

        uint16_t employeers = arr[i].getEmployees();
        uint8_t floor = arr[i].getFloors();
        double empTemp = (double)employeers / floor;

        if (empTemp > maxEmployees){

            maxEmployees = empTemp;
            arrNumberMax = i;
        }
        if (empTemp < leastEmployees){

            leastEmployees = empTemp;
            arrNumberMin = i;
        }
    }
    std::cout << "Most average people per floor " << std::setprecision(3) << maxEmployees << " in "
              << arr[arrNumberMax].getName() << " building." << std::endl;
    std::cout << "Least average people per floor " << std::setprecision(3) << leastEmployees << " in "
              << arr[arrNumberMin].getName() << " building." << std::endl;
}

void mostAndLeastOfficesPerFloor(Building* arr)
{
    // most offices per floor
    double maxOffices = DBL_MIN;
    // least offices per floor
    double leastOffices = DBL_MAX;
    // number of the firm with least offices per floor
    uint8_t arrNumberMin = 0;
    // number of the firm with most offices per floor
    uint8_t arrNumberMax = 0;

    for (size_t i = 0; i < ARRAY_SIZE; i++){

        uint8_t offices = arr[i].getOffices();
        uint8_t floors = arr[i].getFloors();
        double officesAverage = (double)offices / floors;

        if (officesAverage > maxOffices){

            maxOffices = officesAverage;
            arrNumberMax = i;
        }
        if (officesAverage < leastOffices){

            leastOffices = officesAverage;
            arrNumberMin = i;
        }
    }
    std::cout << "Most average offices per floor " << std::setprecision(3) << maxOffices << " in "
              << arr[arrNumberMax].getName() << " building." << std::endl;
    std::cout << "Least average offices per floor " << std::setprecision(3) << leastOffices << " in "
              << arr[arrNumberMin].getName() << " building." << std::endl;
}

void mosetAndLeastEmployeesPerOffice(Building* arr)
{
    // most employers per offices
    double maxEmployers = DBL_MIN;
    // least employers per offices
    double leastEmployers = DBL_MAX;
    // number of the firm with least employers per offices
    uint8_t arrNumberMin = 0;
    // number of the firm with most employers per offices
    uint8_t arrNumberMax = 0;

    for (size_t i = 0; i < ARRAY_SIZE; i++){

        uint16_t employeers = arr[i].getEmployees();
        uint8_t offices = arr[i].getOffices();
        double employersAverage = (double)employeers / offices;

        if (employersAverage > maxEmployers){

            maxEmployers = employersAverage;
            arrNumberMax = i;
        }
        if (employersAverage < leastEmployers){

            leastEmployers = employersAverage;
            arrNumberMin = i;
        }
    }
    std::cout << "Most average employers per office " << std::setprecision(3) << maxEmployers << " in "
              << arr[arrNumberMax].getName() << "building." << std::endl;
    std::cout << "Least average employers per office " << std::setprecision(3) << leastEmployers << " in "
              << arr[arrNumberMin].getName() << "building." << std::endl;
}
