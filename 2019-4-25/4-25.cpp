#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int i=0;
        int j = 0;
        int count = 0;
        while(i<s1.size())
        {
            while(s1[i] == s2[j] && i< s1.size() && j<s2.size())
            {
                i++;
                j++;
            }
            if(j == s2.size())
            {
                count++;
            }
            else
            {
                i++;
            }
            j = 0;
        }
        cout<<count<<endl;
    }
    return 0;
}