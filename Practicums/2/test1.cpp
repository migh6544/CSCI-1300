
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int CountAtoJ(string s)
{
    int count = 0;
    if (s == "")
    {
        count = -1;
    }
    if (s != "" || s != " ")
    {
        for (int i = 0; i < s.length(); i++)
	    {
            if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || s[i] == 'F' || s[i] == 'G'|| s[i] == 'H'|| s[i] == 'I'|| s[i] == 'J')
		    {
		        ++count;
		    }
	    }
    }
    if (s != "" && count == 0)
    {
        count = -2;
    }
    return count;
}


int main()
{
   cout << CountAtoJ("all the best") << endl;
}
