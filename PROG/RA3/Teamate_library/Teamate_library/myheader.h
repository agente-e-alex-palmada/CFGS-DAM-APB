#pragma once
#ifndef MYHEADER_H
#define MYHEADER_H
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <string>
#include "mmr.h"
using namespace std;
using namespace mmr;
int mmrAdd(int& mmr, int& mmrChange, float& multiplier);
int mmrSub(int& mmr, int& mmrChange, float& multiplier);
bool validInput(char& yn);
void start();
#endif