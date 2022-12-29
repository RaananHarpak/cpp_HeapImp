#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"

using namespace std;
int ConvertToInt(string& stringToConvert, int& index);
string GetData(string& stringToConvert, int& index);
char GetCharFromLine(string& stringToConvert, int& index);
void InsertNode(int& priority, string& stringToConvert, int& index, string& data, Map& map);

void main()
{
	int n;
	string line;
	string stringToConvert;
	string data;
	int index = 0;
	int priority;
	Map map;

	cin >> n;
	if (n < 0)
	{
		cout << "wrong input";
		exit(0);
	}

	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		getline(cin, line);
		index = 0;
		stringToConvert = line;
		//GETCHAR
		char funcChar = GetCharFromLine(stringToConvert, index);
		if (i==0)
		{
			if (funcChar != 'e' && funcChar != 'E')
			{
				cout << "wrong input";
				exit(0);
			}
		}
		switch (funcChar)
		{
		case 'a':// Max
		case 'A':
		{
			Node res = map.Max();
			cout << res.GetPriority() << " " << res.GetData() << endl;
			break;
		}
		case 'B':// DeleteMax
		case 'b':
		{
			Node res = map.DeleteMax();
			cout << res.GetPriority() << " " << res.GetData() << endl;
				break;
		}
		case 'C':// Min
		case 'c':
		{
			Node res = map.Min();
			cout << res.GetPriority() << " " << res.GetData() << endl;
			break;
		}
		case 'd':// DeleteMin
		case 'D':
		{
			Node res = map.DeleteMin();
			cout << res.GetPriority() << " " << res.GetData() << endl;
			break;
		}
		case 'e':// CreateEmpty
		case 'E':
		{
			if (i != 0) {
				cout << "wrong input" << endl;
			}
			else
			{
				map = map.CreateEmpty();
			}
			break;
		}
		case 'f':// insert
		case 'F':
		{
			InsertNode(priority, stringToConvert,index,data,map);
			break;
		}
		case 'g':// Median
		case 'G':
		{
			Node res = map.Median();
			cout << res.GetPriority() << " " << res.GetData() << endl;

			//ERROR
			break;
		}
		default:
		{
			cout << "wrong input";
			exit(0);
		}
		}
	}

}
void InsertNode(int& priority,string& stringToConvert,int& index,string& data,Map& map) {
	//Get priority from line input:
	priority = ConvertToInt(stringToConvert, index);
	//Get data from line input
	data = GetData(stringToConvert, index);
	//Create new Node with priority and data
	Node node(priority, data);
	map.Insert(node);
}
int ConvertToInt(string& stringToConvert,int& index) {
	int number = 0;
	int sign = 1;
	while (index < stringToConvert.size() && stringToConvert[index] == ' ')
	{
		index++;
	}
	if (index < stringToConvert.size() && stringToConvert[index] == '-')
	{
		sign = -1;
		index++;
	}
	if (index >= stringToConvert.size() || !isdigit(stringToConvert[index]))
	{
		cout << "wrong input";
		exit(0);
	}
	while (index < stringToConvert.size() && isdigit(stringToConvert[index]))
	{
		number = number * 10 + (stringToConvert[index++] - '0');
	}
	return number * sign;
}
string GetData(string& stringToConvert,int& index)
{
	string sub_str = "";
	//while (!end(stringToConvert, index) && stringToConvert[index] == ' ')
	while (index< stringToConvert.size() && stringToConvert[index] == ' ')
	{
		index++;
	}
	while (index < stringToConvert.size())
	{
		sub_str += stringToConvert[index++];
	}
	if (sub_str.size() == 0)
	{
		cout << "wrong Input";
		exit(0);
	}
	return sub_str;
}
char GetCharFromLine(string& stringToConvert,int& index)
{
	while (stringToConvert.size() > index && stringToConvert[index] == ' ')
	{
		index++;
	}
	return stringToConvert[index++];
}