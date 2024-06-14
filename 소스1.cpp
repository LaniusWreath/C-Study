#include "iostream"
#include "string"

using namespace std;

int main()
{
	string s1 = "hello";
	string s2 = "aa";
	string s3 = "abc";
	string s4 = "ac";
	string s5 = "aa";

	cout << s1.substr(2, 3) << endl;
	cout << s1.replace(2, 3, "hi") << endl;
	cout << s2.compare(s3) << endl;
	cout << s2.compare(s5) << endl;
	cout << s4.compare(s2) << endl;

	return 0;
}