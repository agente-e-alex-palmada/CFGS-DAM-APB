//Here's the libraries and declarations for the program to run
#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> insertPlayers(vector<string> names);
vector<int> insertPuntuation(int& numPlayers);
string checkWinner(vector<string>& names, vector<int>& scores);