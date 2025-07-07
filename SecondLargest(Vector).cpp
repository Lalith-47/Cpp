#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{   vector<int> v;
    int n,ele;
    cout<<"Enter Size:\t";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        v.push_back(ele);
    }

   sort(v.begin(),v.end());
    for (int v1 : v)
    {
        cout << v1 << " ";
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (v.at(i)!=v.at(i-1))
        {
            cout << "\nSecond Largest: "<<v.at(i-1) << endl;
            break;
        }
    }

    return 0;
}
