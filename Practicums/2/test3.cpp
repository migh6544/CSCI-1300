#include <iostream>
#include <fstream>
#include <string>

using namespace std;


void printNormalHeartRates(string names[], int hr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (hr[i] >= 70 && hr[i] <= 190)
        {
            cout << names[i] << " " << hr[i] << endl;
        }
    }
}

int main()
{
    string patients[3] = {"Jamie", "Sebastien", "Shaun"};
    int heart_rate[3] = {90, 70, -12};
    printNormalHeartRates(patients, heart_rate, 3);
}