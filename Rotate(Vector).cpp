#include<iostream>
#include<vector>
using namespace std;

int main()
{   vector<int> v;
    int n,ele,key=0;
    cout << "Enter Size of array";
    cin >>n;
    cout << "Enter number to rotate array: " << endl;
    cin >> key;
    cout << "Enter Elemnets\n" << endl;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        v.push_back(ele);
    }
    for (int i = 0; i <key; i++)
    {
    ele=v.at(0);
    v.erase(v.begin());
        v.push_back(ele);
    }
    for (int v1 : v)
    {
        cout << v1 << " ";
    }
    return 0;
}
