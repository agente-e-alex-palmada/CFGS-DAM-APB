#include <iostream>
using namespace std;
int main()
{
    int listSize = 4;
    int numberProcessed = 0;
    double sum = 0;
    while (numberProcessed < listSize) {
        double value;
        cin >> value;
        sum += value;
        ++numberProcessed;
    }
    double average = sum / numberProcessed;
    cout << "Average: " << average << endl;
}