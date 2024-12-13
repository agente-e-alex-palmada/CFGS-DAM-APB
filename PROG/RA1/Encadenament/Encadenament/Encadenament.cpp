
#include <iostream>
using namespace std;

int main()
{
    float nota;
    cout << "Diguem una nota:" << endl;

    cin >> nota;
    if (nota >= 9) {
        cout << "Excelent" << endl;
    }else if (nota >= 7) {
        cout << "Notable" << endl;
    }else if (nota >= 5) {
        cout << "Aprobat" << endl;
    }else {
        cout << "Suspes" << endl;
    }
}