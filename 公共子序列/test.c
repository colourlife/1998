#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string s1;
    string s2;
    vector<vector<int>> arr;
    cin>>s1;
    cin>>s2;
    int m = s1.length();
    int n = s2.length();
    arr.resize(m);
    int max = 0;
    for(int i=0;i<m;++i)
    {
        arr[i].resize(n);
    }
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(s1[i] == s2[j])
            {
                if(i>=1&&j>=1)
                {
                    arr[i][j] = arr[i-1][j-1]+1;
                }
                else
                    arr[i][j] = 1;
            }
            if(arr[i][j]>max)
                max = arr[i][j];
        }
    }
    cout<<max<<endl;
    return 0;
}