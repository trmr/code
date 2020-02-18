#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int i;

    vector<string> msg {"Hello", "C++", "World", "from", "VS Code!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}