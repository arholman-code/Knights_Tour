/************************************************************
I understand and have abided by the UNCG Academic Integrity
Policy:	Andrew Holman
*************************************************************
*************************************************************
Homework #3
Dr. Fu
CSC 330-01
Spring 2010
************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
	string input;
	map<string, string> s;
	s.insert(map<string, string>::value_type ("Arizona", "Phoenix"));
	s.insert(map<string, string>::value_type ("Illinois", "Chicago"));
	s.insert(map<string, string>::value_type ("California", "Sacramento"));

	cout << "Input the name of a state to check if it's in the map: ";
	cin >> input;

	map<string, string>::iterator iter = s.find(input);
	if (iter == s.end())
	{
		cout << "The state is not in the map.\n";
	}
	else
	{
		cout << "The state is in the map.\n";
		cout << iter -> first << "," << iter -> second << endl << endl;
	}

	multimap<string, string> ms;
	string ms_input;

	ms.insert(pair<string, string>("Arizona", "Phoenix"));
	ms.insert(pair<string, string>("Illinois", "Chicago"));
	ms.insert(pair<string, string>("Illinois", "Gary"));
	ms.insert(pair<string, string>("Nevada", "Reno"));
	ms.insert(pair<string, string>("Illinois", "Evanston"));
	ms.insert(pair<string, string>("California", "Sacramento"));

	cout << "Input the name of a state.  All instances of that state ";
	cout << "within the multimap\n will be output to the screen: ";
	cin >> ms_input;

	multimap<string, string>::iterator m_iter = ms.find(ms_input);
	if (m_iter != ms.end())
	{
		do{
			cout << ms_input << ", " << m_iter -> second;
			cout << endl;
			m_iter++;
		}while (m_iter != ms.upper_bound(ms_input));
	}
	else
		cout << "State not found.\n";

	return 0;
}