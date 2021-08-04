#include <iostream>
using namespace std;
class Sudoku{
	// mooi  doi tuong tuong ung voi mot otrong bang
	public:
	 bool num[9]={true,true,true,true,true,true,true,true,true};
	 int yes_number=0;
//	 int count=9;
	 
	 //dat gia tri ban dau cho O
	 void initial_value(int x){
	 	for (int i=0;i<9;i++)
	 	{
	 		if((i+1)!=x){
	 			num[i]=false;
			 }
		 }
//		 count=0;
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

	int check_number(Sudoku cell)
	{
     // Kiem tra doi tuong co bao nhieu truong hop co the co
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
				int x[9]={};	

				for (int h=i;h<(i+3);h++)
				{
					for (int k=j;k<(j+3);k++)
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
			int xr[9]={};
			for (int j=0;j<9;j++)
				
			{

								for (int nbr=0;nbr<9;nbr++)
								{
									if (Cell[i][j].num[nbr]==true)
									{
										xr[nbr]++;
									}
								}
								
			}
			for (int t=0;t<9;t++)	
				{
					if (xr[t]==1)
					{
						for (int j1=0;j1<9;j1++)
						{
							if (Cell[i][j1].yes_number==0)
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
		}
		//In Colum
		for (int i=0;i<9;i++)
		{
			int xr[9]={};
			for (int j=0;j<9;j++)
				
			{

								for (int nbr=0;nbr<9;nbr++)
								{
									if (Cell[j][i].num[nbr]==true)
									{
										xr[nbr]++;
									}
								}
							
			}
			for (int t=0;t<9;t++)	
				{
					if (xr[t]==1)
					{
						for (int j1=0;j1<9;j1++)
						
						{
							if (Cell[j1][i].yes_number==0)
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
		
		
	}
	
	//=========
	
	//=========
	// truong hop xac dinh duoc cac cap so giong nhau tai moi vi tri trong 1 clus/row/colum
//	
int Pow(int a,int b)
{	int s=1;
	for(int i=1;i<=b;i++)
	{
		s=s*a;
	}
	return s;
}
	
	void Group_number( Sudoku (&Cell)[9][9]) //
	{	
	//IN CLUS				
	
		for (int i=0;i<9;i=i+3)
		{
			for (int j=0;j<9;j=j+3)
			{
				int c[9]={0};
				int ts=0;
				for (int h=i;h<(i+3);h++)
				{
					for (int k=j;k<(j+3);k++)
					{
						if (Cell[h][k].yes_number==0)	
						{	
							for (int ss=0;ss<9;ss++)
							{
								if (Cell[h][k].num[ss]==true)
								{
									int Nc=c[ss]/10;
									int Rc=c[ss]%10;
									c[ss]=(Nc+Pow(2,ts))*10+Rc+1;
								}
									
							}						
						}
					ts++;

					}
				}
				for (int ss=0;ss<9;ss++)
				{
					if (c[ss]%10==2)
					{
						for (int se=ss+1;se<9;se++)
						{
							if(c[ss]==c[se])
							{
								for (int h=i;h<(i+3);h++)
								{
									for (int k=j;k<(j+3);k++)
									{
										if (Cell[h][k].yes_number==0)
										{ 
										 if(Cell[h][k].num[ss]==true)
										 {
										 	for (int l=0;l<9;l++)
										 	{
										 		if((l!=se)&(l!=ss))
										 		{
										 			Cell[h][k].num[l]=false;
												 }
											 }
										 }
										}
									}
								}
							}
						}
					}
				}
			}
		}
		// In Row
	
		for (int i=0;i<9;i++)
		{
			int xr[9]={0};
			int tr=0;
			
			for (int j=0;j<9;j++)
			{

				if (Cell[i][j].yes_number==0)	
					{
							for (int sr=0;sr<9;sr++)
							{
								if (Cell[i][j].num[sr]==true)
								{
									int Ncr=xr[sr]/10;
									int Rcr=xr[sr]%10;
									xr[sr]=(Ncr+Pow(2,tr))*10+Rcr+1;
								}
									
							}			
					}
					tr++;			
				}
			for (int r1=0;r1<9;r1++)
			{
				if (xr[r1]%10==2)
				{
					for (int r2=r1+1;r2<9;r2++)
					{
						if(xr[r1]==xr[r2])
						{
								for(int j=0;j<9;j++)
								{
									if(Cell[i][j].yes_number==0)
									{
										if(Cell[i][j].num[r1]==true)
										{
											for (int r3=0;r3<9;r3++){
												if(r3!=r1&r3!=r2)
												{
													Cell[i][j].num[r3]=false;
												}
												
											}
										}
									}
								}
							}
					}
				}
			}	
		}

		//In Colum
		for (int i=0;i<9;i++)
		{
			int xc[9]={0};
			int tc=0;
			for (int j=0;j<9;j++)
				
			{

				if (Cell[j][i].yes_number==0)	
					{
							for (int sr=0;sr<9;sr++)
							{
								if (Cell[j][i].num[sr]==true)
								{
									int Ncc=xc[sr]/10;
									int Rcc=xc[sr]%10;
									xc[sr]=(Ncc+Pow(2,tc))*10+Rcc+1;
								}
									
							}			
					}
					tc++;			
			}
		for (int r1=0;r1<9;r1++)
		{
			if (xc[r1]%10==2)
			{
				for (int r2=r1+1;r2<9;r2++)
				{
					if(xc[r1]==xc[r2])
					{
							for(int j=0;j<9;j++)
							{
								if(Cell[j][i].yes_number==0)
								{
									if(Cell[j][i].num[r1]==true)
									{
										for (int r3=0;r3<9;r3++){
											if(r3!=r1&r3!=r2)
											{
												Cell[j][i].num[r3]=false;
											}
											
										}
									}
								}
							}
						}
				}
			}
		}	
		}
		
		
		
	}
	//=====================================
	//trong 1 hang/ cot co cac truong hop thuoc 1 clus la duy nhat trog clus ay thi cac cell khac trong hang/cot day khong the xay ra truong hop do
	void OnlyINclus(Sudoku (&Cell)[9][9])
	{
	for (int i=0;i<9;i=i+3)
	{
		for (int j=0;j<9;j=j+3){
			int i1=setLoop(i);
			int j1=setLoop(j);
			int x[9]={};
			for (int i2=i1;i2<i1+3;i2++)
			{
				for (int j2=j1;j2<j1+3;j2++)
				{
				if (Cell[i2][j2].yes_number==0)
				{
					for (int k=0;k<9;k++)
					{
						if(Cell[i2][j2].num[k]==true)
						{
							x[k]++;
						}
					}
				}
				}
			}
			for (int k=0;k<9;k++)
			{
				if(x[k]==2)
				{
					bool check=false;
					for (int i2=i1;i2<i1+3;i2++)
					{
						for (int j2=j1;j2<j1+3;j2++)
						{
							if(Cell[i2][j2].num[k]==true)
							{
								for (int i3=i2;i3<i1+3;i3++)
								{
									for (int j3=j2+1;j3<j1+3;j3++)
									{
										if(Cell[i3][j3].num[k]==true)
										{
											if(i3==i2)
											{
												check=true;
												for (int j4=0;j4<9;j4++)
												{
													if(j4!=j3&j4!=j2)
													{
														Cell[i2][j4].num[k]=false;
													}
													
												}
											}
											if(j3==j2)
											{
												check=true;
												for (int i4=0;i4<9;i4++)
												{
													if(i4!=j3&i4!=i2)
													{
														Cell[i4][j2].num[k]=false;
													}
													
												}
											}
										}
										if (check==true)
										break;
									}
									if (check==true)
										break;
									
								}
							}
							if (check==true)
										break;	
						}
							if (check==true)
										break;
					}
				}
				if(x[k]==3)
				{   
				bool check=false;
					for (int i2=i1;i2<i1+3;i2++)
					{
						for (int j2 =j1;j2<j1+3;j2++)
						{
							if (Cell[i2][j2].num[k]==true)
							{	
								check=true;
								int a=setLoop(i2);
								int b=setLoop(j2);
								if(Cell[a][j2].num[k]==true & Cell[a+1][j2].num[k]==true&Cell[a+2][j2].num[k]==true)
								{
											for (int c=0;c<9;c++)
												{
													if(c!=a&c!=a+1&c!=a+2)
													{
														Cell[c][j2].num[k]=false;
													}
													
												}
								}
								if(Cell[i2][b].num[k]==true & Cell[i2][b+1].num[k]==true&Cell[i2][b+2].num[k]==true)
								{
										for (int c=0;c<9;c++)
												{
													if(c!=b&c!=b+1&c!=b+2)
													{
														Cell[i2][c].num[k]=false;
													}
													
												}	
								}
							}
							if (check==true)
							break;	
						}
						if (check==true)
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
	//=========
	// Dam bao khong dien sai 
	bool CheckAll(Sudoku (&Cell)[9][9])
	{
		
		for (int clr=0;clr<9;clr=clr+3)
		{
			for (int clc=0;clc<9;clc=clc+3)
			{
				int ri=setLoop(clr);
				int ci=setLoop(clc);
				for (int i=ri;i<ri+3;i++)
				{
					for (int j=ci;j<ci+3;j++)
					{
						for (int i1=i;i1<ri+3;i1++)
						{
							for (int j1=j1+1;j1<ci+3;j1++)
							{
								if(Cell[i][j].yes_number!=0&Cell[i][j].yes_number==Cell[i1][j1].yes_number)
								{
							
								return false;
								}
							}
						}
					}
				}
				
			}
		}
		//row
		for (int r=0;r<9;r++)
		{
			for (int c=0;c<9;c++)
			{
				for (int c1=c+1;c1<9;c1++)
				{
					if(Cell[r][c].yes_number!=0&Cell[r][c].yes_number==Cell[r][c1].yes_number)
								{
								return false;
								}
				}
			}
		}
		//colum
		for (int r=0;r<9;r++)
		{
			for (int c=0;c<9;c++)
			{
				for (int c1=c+1;c1<9;c1++)
				{
					if(Cell[c][r].yes_number!=0&Cell[c][r].yes_number==Cell[c1][r].yes_number)
								{
								return false;
								}
				}
			}
		}
		return true;
	}
	//========
	//coppy mang
	void Duplicate(Sudoku (&Target)[9][9],Sudoku Source[9][9])
	{
		for (int i=0;i<9;i++)
		{
			for (int j=0;j<9;j++)
			{
				Target[i][j]=Source[i][j];
			}
		}
	}
	//================
	//sodanh 2 phan tu
	bool Compare_Cell(Sudoku x1,Sudoku x2)
	{
		if (x1.yes_number!=x2.yes_number)
		{
			return false;
		}
		for (int i=0;i<9;i++)
		{
			if (x1.num[i]!=x2.num[i])
			{
				return false;
			}
		}
		return true;
	}
	//=============
	//Kiem tra su thay doi cua cac Cell
	
	bool Compare_All(Sudoku table_old[9][9],Sudoku table_new[9][9])
	{
		for (int i=0;i<9;i++)
		{
			for (int j=0;j<9;j++)
			{
				if(Compare_Cell(table_old[i][j],table_new[i][j])==false)
				{
					return false;
				}
			}
		}
		return true;
	}
	//====================
	int count_case(Sudoku Cell)
	{
		int count=0;
		for (int i=0;i<9;i++)
		{
			if (Cell.num[i]==true)
			{
				count++;
			}
		}
		return count;
	}
	// Kiem tra bang da hoan thanh hay chua.
	bool Check_Done( Sudoku Cell[9][9])
	{
		bool check=true;
		for (int i=0;i<9;i++)
		{
			for (int j=0;j<9;j++)
			{
				int cout=count_case(Cell[i][j]);
				if (cout!=1)
				{
					check=false;
				return check;	
				}
				
			}
		}
		return check;
	}
	
	//===================
	void First_Step( Sudoku (&content)[9][9])
	{
	bool check_1=true,check_2=true,check_3=true,check_4=true;
	
	Sudoku Oldcontent[9][9];
	Sudoku Oldcontent_one[9][9];
	Sudoku Oldcontent_two[9][9];
	Sudoku Oldcontent_three[9][9];
	while (check_1)
		{
		Duplicate(Oldcontent,content);
		setInthecell(content);
		This_it(content);
		if (Compare_All(Oldcontent,content))
			{
				check_1=false;
			}
		}
	while (check_2)
	{
		Duplicate(Oldcontent_one,content);
		Only_Number(content);
		check_1=true;
			while (check_1)
			{
			Duplicate(Oldcontent,content);
			setInthecell(content);
			This_it(content);
			if (Compare_All(Oldcontent,content))
				{
					check_1=false;
				}
			}
		if (Compare_All(Oldcontent_one,content))
		{
			check_2=false;
		}
	}
	
	while (check_3)
	{
		Duplicate(Oldcontent_two,content);
		Group_number(content);
		check_2=true;
			while (check_2)
			{
			Duplicate(Oldcontent_one,content);
			Only_Number(content);
			check_1=true;
				while (check_1)
				{
				Duplicate(Oldcontent,content);
				setInthecell(content);
				This_it(content);
				if (Compare_All(Oldcontent,content))
					{
						check_1=false;
					}
				}
			if (Compare_All(Oldcontent_one,content))
			{
				check_2=false;
			}
	}
		
		if(Compare_All(Oldcontent_two,content))
		{
			check_3=false;
		}
	}
	while (check_4)
			{
				Duplicate(Oldcontent_three,content);
				OnlyINclus(content);
				check_3=true;
					while (check_3)
	{
		Duplicate(Oldcontent_two,content);
		Group_number(content);
		check_2=true;
			while (check_2)
			{
			Duplicate(Oldcontent_one,content);
			Only_Number(content);
			check_1=true;
				while (check_1)
				{
				Duplicate(Oldcontent,content);
				setInthecell(content);
				This_it(content);
				if (Compare_All(Oldcontent,content))
					{
						check_1=false;
					}
				}
			if (Compare_All(Oldcontent_one,content))
			{
				check_2=false;
			}
	}
		
		if(Compare_All(Oldcontent_two,content))
		{
			check_3=false;
		}
	}

				if (Compare_All(Oldcontent_three,content))
				{
					check_4=false;
				}
			}
		}
	//==================
	
int main(int argc, const char** argv) {
	Sudoku content[9][9];
	content[0][1].initial_value(4);
	content[0][2].initial_value(2);
	content[0][4].initial_value(8);
	content[1][1].initial_value(3);
	content[1][7].initial_value(1);
	content[2][4].initial_value(7);
	content[2][6].initial_value(9);
	content[3][3].initial_value(4);
	content[3][7].initial_value(5);
	content[4][0].initial_value(8);
	content[4][3].initial_value(3);
	content[5][0].initial_value(1);
	content[5][6].initial_value(7);
	content[6][3].initial_value(2);
	content[6][8].initial_value(4);
	content[7][0].initial_value(5);
	content[7][6].initial_value(8);

	First_Step(content);
	
	

		bool check_test=true;
		Sudoku Pre_Done[9][9];	
		Sudoku Pre_Done_case2[9][9];	
	
		while (check_test){
		bool checkloop=true;
		if (!Check_Done(content))
		{
		First_Step(content);
		Duplicate(Pre_Done,content);
		Duplicate(Pre_Done_case2,content);
		int count_2_case=0;
		for (int i=0;i<9;i++)
		{
			for (int j=0;j<9;j++)
			{
				if (content[i][j].yes_number ==0)
				{
				if(check_number(content[i][j])==2)
				{	count_2_case++;

					for (int n=0;n<9;n++)
					{
						if (Pre_Done[i][j].num[n]==true)
						{	
							Pre_Done[i][j].initial_value(n+1);
							First_Step(Pre_Done) ;
							for (int m=n+1;m<9;m++)
							{
								if (Pre_Done_case2[i][j].num[m]==true)
								{
									Pre_Done_case2[i][j].initial_value(m+1);
									First_Step(Pre_Done_case2);
									break; 
								}
							}
							
						break;	
						}
					}
					
					if(CheckAll(Pre_Done)&!CheckAll(Pre_Done_case2))
					{
						Duplicate(content,Pre_Done);
						checkloop=false;
					}
					if(!CheckAll(Pre_Done)&CheckAll(Pre_Done_case2))
					{
						Duplicate(content,Pre_Done_case2);
						checkloop=false;
					}
					if(CheckAll(Pre_Done)&CheckAll(Pre_Done_case2))
					{
						Duplicate(Pre_Done,content);
						Duplicate(Pre_Done_case2,content);
						count_2_case=count_2_case-1;
						continue;
					}
					
					if(!CheckAll(Pre_Done)&!CheckAll(Pre_Done_case2))
					{
						count_2_case=count_2_case-1;
						checkloop=false;
						check_test=false;
						cout<<"NO WAY"<<endl;

					}
				}	
				}
				
				if (checkloop==false)
				break;
			}
			if (checkloop==false)
				break;
		}	
		if (count_2_case==0)
		check_test=false;	
		}
		else check_test =false;
		
		}


 cout<<CheckAll(content)<<endl;

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
