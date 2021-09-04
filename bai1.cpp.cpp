#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;
//==============
long power(int x,int y)
{
	if (x==0)
	{return 0;
	}
	long result=1;
	for (int i=0;i<y;i++)
	{
		result=result*x;
	}
	return result;
}

//====================
long string2int(string x)
{
	long result=0;
	long n=x.length();
	for (int i=0;i<n;i++)
	{
		if (x[i]<48&&x[i]>57)
		{
			return 0;
		}
		else
		{
		result=result+(x[i]-48)*power(10,n-1-i);	
		}
	}
	return result;
	
}
//====================
void addUser(string name, string pass)
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

}
//====================================

void addList(string name)
{
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

//====================================

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
//=================
void TotalUser(int x)
{
	ofstream count;
	string path="D:/Code/User/count";
	count.open(path.c_str(),std::ios::trunc);
	if (count.fail())
	{
		cout<<"can't file"<<endl;
	}
	else
	{
		count<<x;
		cout<<"OK";
	}
	count.close();
	
}
//==============
int getCount()
{
	string path="D:/Code/User/count";
	ifstream fileCount;
	fileCount.open(path.c_str());
	string data;
	getline(fileCount,data);
	int x=string2int(data);
	return x;
}

//============
int main()
{
int a=getCount();
cout<<a+10;
	return 0;
}
