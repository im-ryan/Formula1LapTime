/**
* Ryan Huett
* Date: 5/14/2018
* Visual Studio 2017
* Class LapTime that determines a Formula 1's theoretical lap time on
* any of the 57 laps of a race as well as displaying the time to the user.
*/
#pragma once
#include<iostream>
using namespace std;

// Given values
const double BASE_TIME = 89.28;	// sec
const int TOTAL_LAPS = 57;
const double MPG = 7.25;
const double LAP_LENGTH = 5.412; // km
const double MILES_TO_KM = 1.609;
const double GAL_TO_KG = 2.99;
const double FUEL_LOSS_TIME = 0.2; // sec
const double TIRE_DEGREDATION_TIME = 0.05; // sec

const double FUEL_USED_PER_LAP = (LAP_LENGTH / (MPG * MILES_TO_KM)) * GAL_TO_KG;

class LapTime
{
	int currentLapNumber;

public:
	void setLapNumber(int lapNum) { currentLapNumber = lapNum; }
	void displayLapTime();
};