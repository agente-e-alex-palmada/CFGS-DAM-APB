#pragma once
// My header is used to declare all libraries and functions I will use for the program in general
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <vector>
using namespace std;
const int HUNGER = 75, BOREDOM = 75;
void menu();
void deathHandler(int passedHunger);