#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string removeStars(string s)
{
    string out = "";
    if (s != "")
    {
        char a = 0;
        for (int i = 0; i < s.length(); i++)
	    {
            if (s[i] == '*')
		    {
		        s[i] = i-i;
		    }
	    }
	out = s; 
    }
    return out;
}

int main()
{
    cout << removeStars("H*e*l*l*oWorld") << endl;
}