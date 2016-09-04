// Code for Project 1
// Report poll results

#include <iostream>
using namespace std;   // pp. 38-39 in Savitch 6/e explains this line

int main()
{
    int NumberSurveyed;
    int forClinders;
    int forCrump;
    
    cout << "How many registered voters were surveyed? ";
    cin >> numberSurveyed;
    cout << "How many of them say they will vote for Clinders? ";
    cin >> forClinders;
    cout << "How many of them say they will vote for Crump? ";
    cin >> forCrump;
    
    double pctClinders = 100.0 * forClinders / numberSurveyed;
    double pctCrump = 100.0 * forCrump / numberSurveyed;
    
    cout.setf(ios::fixed);       // see pp. 32-33 in Savitch 6/e
    cout.precision(1);
    
    cout << endl;
    cout << pctClinders << "% say they will vote for Clinders." << endl;
    cout << pctCrump << "% say they will vote for Crump." << endl;
    
    if (forClinders > forCrump)
        cout << "Clinders is predicted to win the election." << endl;
    else
        cout << "Crump is predicted to win the election." << endl;

