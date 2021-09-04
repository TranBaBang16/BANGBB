#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
void Registe(string name, string pass)
{
	
string path="D:/Code/User/"+name;
std::ofstream filedata(path.c_str(),std::ios::app);
if (filedata.fail())
{
	cout<<"can't write file";
}
else
{
	filedata<<name;
	filedata<<";";
	filedata<<pass;
	
	cout<<"successfull!";
}
filedata.close();
string path_list="D:/Code/User/List";
std::ofstream file_list(path_list.c_str(),std::ios::app);
if(file_list.fail())
{
	cout<<"can't open file List";
}
else
{
	file_list<<";";
	file_list<<endl;
	file_list<<name;
	cout<<endl;
	cout<<"add user success!";
}
file_list.close();
}
bool FindUser(string name)
{
	ifstream filedata;
	string path="D:/Code/User/List";
	filedata.open(path.c_str());
	
	if(filedata.fail())
	{
		cout<<"can't open file";
	}
	else
	{
	while (!filedata.eof())
	{
		string tt;
		string result;
		getline(filedata,tt,':');
		getline(filedata,result,';');
		if (result==name)
		{
		filedata.close();
		return true;	
		}

	}
	filedata.close();
	return false;
	}
	
	
	
	
}
int main()
{

	return 0;
}
