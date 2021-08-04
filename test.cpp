#include <iostream>
#include <typeinfo>
using namespace std;
bool check(int a[4][4]){
	for (int j=0;j<4;j++)
	{
		for (int i=0;i<4;i++)
	{
		if (a[j][i]>5)
		return false;
	}
	}

	return true;
}

int main(int argc, const char** argv) {
int a[4]={1,2,3,3};
for (int i=0;i<4;i++)
{
	if (a[i]==3)
	{
		cout<<i<<endl;
		break;
	}
}
cout<<i<<endl;
return 0;


}
