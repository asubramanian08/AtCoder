// Official: Correct
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str;
    cin >> str;
    cout << str[str.size() / 2] << endl;
    return 0;
}