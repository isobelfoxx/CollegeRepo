// Question 1
#include <iostream>
using namespace std;

string cipher(string s, int n) { 
  	int len = s.length ();
	for(int letter = 0; letter < len; letter++)
	{
      s[letter] = s[letter] + n;
	}
	return s;
}
   
int main()
{
    cout << cipher("hello", 2);
    return 0;
}

// The following message “[]qr|)r|)j)wx})|x)|nl{n})vn||jpn*” stands for “This is a not so secret message”
