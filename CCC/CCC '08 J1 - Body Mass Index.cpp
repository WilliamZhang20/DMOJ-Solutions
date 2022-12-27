#include <iostream>

using namespace std;

int main() {
    float w, h, BMI;
    cin >> w;
    cin >> h;
    BMI=w/(h*h);
    if(BMI>25)
    {
       cout<<"Overweight"<< endl;
    }
    else if(BMI>=18.5 && BMI<=25)
    {
        cout << "Normal weight" << endl;
    }
    else if(BMI<18.5)
    {
        cout << "Underweight" << endl;
    }
    return 0;
}
