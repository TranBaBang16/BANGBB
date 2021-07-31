#include <iostream>
#include <typeinfo>
using namespace std;
void test(int (&a)[2][2]){
	for (int i=0;i<2;i++)
	{
		for (int j=0;j<2;j++)
		{
		a[i][j]=17;
		}
		
	}

}
int main(int argc, const char** argv) {
	int bang[4]={0};
	bang[2]++;
	cout<<bang[0];
	cout<<bang[1];
	cout<<bang[2];
	cout<<bang[3];
	
    return 0;
    
}
