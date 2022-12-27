#include <iostream>

using namespace std;

int main() {
    int l, s;
    cin >> l;
    cin >> s;
    if(l>=s)
    {
        cout<< "Congratulations, you are within the speed limit!" << endl;
    }
    else if(s>l && s-l<=20)
    {
        cout<< "You are speeding and your fine is $100." << endl;
    }
    else if(s>l && s-l>20 && s-l<31)
    {
        cout<< "You are speeding and your fine is $270." << endl;
    }
    else if(s-l>=31)
    {
        cout<< "You are speeding and your fine is $500." << endl;
    }
    return 0;
}
