#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while(getline(cin,s))
    {
        string ret;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == ' ')
            {
                ret+=" ";
                continue;
            }
            char tmp = char(((s[i]-'A'-5 +26)%26 +'A'));
            ret+=tmp;
        }
        cout<<ret<<endl;
    }
    return 0;
}