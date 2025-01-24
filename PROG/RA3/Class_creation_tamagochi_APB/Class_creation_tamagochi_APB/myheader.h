#pragma once
// My header is used to declare all libraries and functions I will use for the program in general
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;
const int HUNGER = 50, BOREDOM = 50;
void menuCritter();
void deathHandler(int passedHunger);