#include <iostream>
using namespace std;
class Sudoku{
	// mooi  doi tuong tuong ung voi mot otrong bang
	public:
	 bool num[9]={true,true,true,true,true,true,true,true,true};
	 int yes_number=0;
	 
	 //dat gia tri ban dau cho O
	 void initial_value(int x){
	 	for (int i=0;i<9;i++)
	 	{
	 		if((i+1)!=x){
	 			num[i]=false;
			 }
		 }
		 yes_number =x;
	 }
	 //in ra man hinh cac gia tri co the co cua doi tuong
	void print_screen(){
		if (yes_number==0)
		{
			for (int i=0;i<9;i++)
			{
			if (num[i]==true){
				cout<<i+1;
							 }
			else
			cout<<"_";
			}	
		}
		else
		cout<<"____"<<yes_number<<"____";

	
	}
};
// So Sanh 2 doi tuong SUKUDO
	bool Compare_SU(Sudoku x1,Sudoku x2)
	{
		bool Ok=true;
		if (x1.yes_number=!x2.yes_number)
		{
		Ok=false;
		}
		for (int i=0;i<9;i++)
		{
			if (x1.num[i]!=x2.num[i])
			{
				Ok=false;
				break;
			}
			
		}
		return Ok;
		
	}

	int check_number(Sudoku &cell)
	{
     // Kiem tra doi tuong da co gia tri hay chua
	     int check=0;
	 	for (int i=0;i<9;i++)
         {
             if(cell.num[i]==true) {
                 check++;
             }
         }
         return check;
	 }
	 
	 // dawt gia tri cho doi tuong
	 void set_numeber(Sudoku &Cell){
	 	if (check_number(Cell)==1)
	 	for (int i=0;i<9;i++)
	 	{
	 		if (Cell.num[i]==true)
	 		{ 
	 		Cell.yes_number=i+1;
	 		break;
			 }
		 }
	 }
//duyet Clus
	int setLoop(int x)
	{
		if (x%3==0)
		{
		return x;
		}
		if (x%3==1){
			return x-1;
		}
		if (x%3==2){
			return x-2;
		}
	}
	
// loai tru cac gia tri khong hop le trong moi O

	void setInthecell(Sudoku (&Cell)[9][9])
	{
		for(int i=0;i<9;i++)
		{
			for (int j=0;j<9;j++)
			{
				if(Cell[i][j].yes_number==0)
				{
					//In square
					int a=setLoop(i);
					int b=setLoop(j);
					for (int k=a;k<(a+3);k++)
					{
						for (int h=b;h<(b+3);h++)
						{   
							int NumInCellOrther= Cell[k][h].yes_number;
							if(NumInCellOrther!=0)
							{
								Cell[i][j].num[NumInCellOrther-1]=false;
							}
						}
					}	
					
					// in Row
					for (int cl=0;cl<9;cl++)
					{
						int cellortherinrow=Cell[i][cl].yes_number;
						if (cellortherinrow!=0)
						{
							Cell[i][j].num[cellortherinrow-1]=false;
						}
					}
					//in Colum
						for (int rw=0;rw<9;rw++)
					{
						int cellortherincolum=Cell[rw][j].yes_number;
						if (cellortherincolum!=0)
						{
							Cell[i][j].num[cellortherincolum-1]=false;
						}
					}
				}
				
			}
		}
		
	}
	void Only_Number( Sudoku (&Cell)[9][9]) //
	{	
	//IN CLUS				
	
		for (int i=0;i<9;i=i+3)
		{
			for (int j=0;j<9;j=j+3)
			{
				int x[9]={0};	

				for (int h=i;h<(i+3);h++)
				{
					for (int k=j;k<(j+3);k++)
					{
						if (Cell[h][k].yes_number==0)	
						{
							for (int nb=0;nb<9;nb++)
							{
								if (Cell[h][k].num[nb]==true)
								{
									x[nb]++;
								}
							}
						}
					}
				}
				for (int nbx=0;nbx<9;nbx++)
				{
					bool ok=false;
					if(x[nbx]==1) {
						for (int h=i;h<(i+3);h++)
						{
							for (int k=j;k<(j+3);k++)
							{
								if (Cell[h][k].num[nbx]==true)
								{
									Cell[h][k].initial_value(nbx+1);
									ok=true;
									break;
								}
							}
							if (ok==true)
							break;
						}
					}
				}
			}
		}
		// In Row
	
		for (int i=0;i<9;i++)
		{
			int xr[9]={0};
			for (int j=0;j<9;j++)
				
			{
				if (Cell[i][j].yes_number==0)	
					{
								for (int nbr=0;nbr<9;nbr++)
								{
									if (Cell[i][j].num[nbr]==true)
									{
										xr[nbr]++;
									}
								}
					}			
			}
			for (int t=0;t<9;t++)	
				{
					if (xr[t]==1)
					{
						for (int j1=0;j1<9;j1++)
						{
							if (Cell[i][j1].num[t]==true)
							{
								Cell[i][j1].initial_value(t+1);
								break;
							}
						}
					}
				}
		}
		//In Colum
		for (int i=0;i<9;i++)
		{
			int xr[9]={0};
			for (int j=0;j<9;j++)
				
			{
				if (Cell[j][i].yes_number==0)	
					{
								for (int nbr=0;nbr<9;nbr++)
								{
									if (Cell[j][i].num[nbr]==true)
									{
										xr[nbr]++;
									}
								}
					}			
			}
			for (int t=0;t<9;t++)	
				{
					if (xr[t]==1)
					{
						for (int j1=0;j1<9;j1++)
						{
							if (Cell[j1][i].num[t]==true)
							{
								Cell[j1][i].initial_value(t+1);
								break;
							}
						}
					}
				}
		}
		
		
	}
	// truong hop xac dinh duoc cac cap so giong nhau tai moi vi tri trong 1 clus/row/colum
	void Only_Number( Sudoku (&Cell)[9][9]) //
	{	
	//IN CLUS				
	
		for (int i=0;i<9;i=i+3)
		{
			for (int j=0;j<9;j=j+3)
			{
				int x[9][9]={0};	

				for (int h=i;h<(i+3);h++)
				{
					for (int k=j;k<(j+3);k++)
					{
						if (Cell[h][k].yes_number==0)	
						{
							for (int nb=0;nb<9;nb++)
							{
								if (Cell[h][k].num[nb]==true)
								{
									x[nb]++;
								}
							}
						}
					}
				}
				for (int nbx=0;nbx<9;nbx++)
				{
					bool ok=false;
					if(x[nbx]==1) {
						for (int h=i;h<(i+3);h++)
						{
							for (int k=j;k<(j+3);k++)
							{
								if (Cell[h][k].num[nbx]==true)
								{
									Cell[h][k].initial_value(nbx+1);
									ok=true;
									break;
								}
							}
							if (ok==true)
							break;
						}
					}
				}
			}
		}
		// In Row
	
		for (int i=0;i<9;i++)
		{
			int xr[9]={0};
			for (int j=0;j<9;j++)
				
			{
				if (Cell[i][j].yes_number==0)	
					{
								for (int nbr=0;nbr<9;nbr++)
								{
									if (Cell[i][j].num[nbr]==true)
									{
										xr[nbr]++;
									}
								}
					}			
			}
			for (int t=0;t<9;t++)	
				{
					if (xr[t]==1)
					{
						for (int j1=0;j1<9;j1++)
						{
							if (Cell[i][j1].num[t]==true)
							{
								Cell[i][j1].initial_value(t+1);
								break;
							}
						}
					}
				}
		}
		//In Colum
		for (int i=0;i<9;i++)
		{
			int xr[9]={0};
			for (int j=0;j<9;j++)
				
			{
				if (Cell[j][i].yes_number==0)	
					{
								for (int nbr=0;nbr<9;nbr++)
								{
									if (Cell[j][i].num[nbr]==true)
									{
										xr[nbr]++;
									}
								}
					}			
			}
			for (int t=0;t<9;t++)	
				{
					if (xr[t]==1)
					{
						for (int j1=0;j1<9;j1++)
						{
							if (Cell[j1][i].num[t]==true)
							{
								Cell[j1][i].initial_value(t+1);
								break;
							}
						}
					}
				}
		}
		
		
	}
	
	//==================================
	void This_it(Sudoku (&Cell)[9][9])
	{
		for (int i=0;i<9;i++)
	{
		for (int j=0;j<9;j++){
			int check=check_number(Cell[i][j]);
			if (check==1){
				set_numeber(Cell[i][j]);
			}	
		}
		
	}
	}
int main(int argc, const char** argv) {
	int check;
	Sudoku content[9][9];
	content[0][2].initial_value(8);
	content[0][3].initial_value(2);
	content[0][6].initial_value(1);
	content[1][0].initial_value(3);
	content[1][8].initial_value(7);
	content[3][3].initial_value(5);
	content[3][6].initial_value(8);
	content[3][7].initial_value(2);
	content[4][4].initial_value(7);
	content[5][4].initial_value(6);
	content[6][0].initial_value(6);
	content[6][1].initial_value(7);
	content[6][8].initial_value(3);
	content[7][3].initial_value(8);
	content[7][5].initial_value(1);
	content[7][7].initial_value(5);
	content[8][0].initial_value(4);


	setInthecell(content);
	This_it(content);
	
	Only_Number(content);
	for (int i=0;i<40;i++){
	setInthecell(content);
	This_it(content);}
	
	Only_Number(content);
	for (int i=0;i<40;i++){
	setInthecell(content);
	This_it(content);}
	
	Only_Number(content);
	for (int i=0;i<40;i++){
	setInthecell(content);
	This_it(content);}


	
	


	cout<<"\n\n\n";
	for (int i=0;i<9;i++)
	{
		cout<<"    ";
		for (int j=0;j<9;j++){
			content[i][j].print_screen();
		cout<<"     ";	
		}
		cout<<endl;
		cout<<endl;
		cout<<endl;
	
	}


    return 0;
}
