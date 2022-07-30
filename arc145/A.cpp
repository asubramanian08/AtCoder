// Official: Correct
#include <string>
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (str.front() == 'A' && str.back() == 'B')
        cout << "No" << endl;
    else if (str == "BA")
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}