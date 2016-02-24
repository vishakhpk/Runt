//Runt v3.14.15
//Project by Vishakh P & Nirmal Shaju
//Class 12C

#include<fstream>
#include<iostream>
#include<iomanip>
#include<customIO.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

using namespace std;

using namespace Colour;

class scoredb
{
	char nam[25];
	int sc;
	public:
	void disp();
	void record(int,char []);
	void cleanup();
}; 

class runt: private scoredb
{
      char a[100][100];
      int move;
      int count;
      int win;
      int lose;
      int finalscore;
	  public:
      void loading();
      void initialise();
      void moves();
      void score();
      void game_centre();
      void main_menu();
      void score(int);
};

void runt::loading()
{//Loading bar graphics
     char cho;
     double i=0;
     int n=0,x=0;
     do
     {
     x=int(i/5);
     system("cls");
     n++;
     int b=n%7;
     cout<<RED<<"\nLoading map";
     for( int c=0;c<b;c++)
        cout<<".";
     cout<<GREEN<<"\n____________________\n";
     for(int k=0;k<x;k++)
        cout<<YELLOW<<"#";
     cout<<endl;
     cout<<GREEN<<"____________________\n";
     cout<<endl;
     cout<<WHITE<<int(i)<<"%";
     i+=25;
     }while(i<=101);
     system("cls");
     cout<<WHITE<<"\nPress any key to begin\n";
     getchar();
}

void runt::initialise()
{
//sets matrix at the beginning of each game
     int m,n;
     for(m=0;m<20;m++)
          for(n=0;n<60;n++)
          a[m][n]=' ';
     for(int x=0;x<60;x++)//boundary wall
     {
          a[0][x]=35;
          a[x][0]=35;
          a[x][59]=35;
          a[19][x]=35;
     }
     int c=0,r1,r2;
     srand(time(0));
     for(c=0;c<200;c++)//random obstacles
          {
          r1=rand()%19+1;
          r2=rand()%59+1;
          a[r1][r2]=35;
          }
     for(c=0;c<25;c++)//random mines
          {
                      r1=rand()%17+3;
                      r2=rand()%57+3;
                      if(a[r1][r2]!=35)
                       a[r1][r2]='O';
          }
     c=0;
     do
     {
              r1=rand()%18+1;
              r2=rand()%58+1;
              if(a[r1][r2]!=35)
                               {
                               a[r1][r2]=42;//food
                               c++;
                               }
              else if(a[r1][r2]==35)
                   a[r1][r2]==35;
     }while(c<=20);
     a[18][57]=' ';
     a[19][57]=232;
     a[18][56]=a[18][55]=a[18][54]=a[18][53]=a[18][52]=' ';
     a[2][3]=a[3][3]=a[4][3]=a[5][3]=a[6][3]=a[7][3]=' ';
     a[0][3]=' ';
     a[1][3]=' ';
}

void runt::moves()
{//Checks and performs moves on the runt
     int c1=0,c2=0,p1=19,p2=57,ch, m,n, mc=0;
     count=0;
     do
     {
   	 mc=0;
     system("cls");   
     for(m=0;m<20;m++)
                {
                for(n=0;n<60;n++)
                {
                                 if (a[m][n]==42)
                                    cout<<YELLOW<<a[m][n];
                                 else if (a[m][n]==35)
                                      cout<<GREEN<<a[m][n];
                                 else if(a[m][n]=='O')
                                      cout<<BLACK<<a[m][n];
                                 else
                                 {
										mc=0;
                                      if ( a[m+1][n] == 'O')
                                      {
                                       mc++;
                                      }
                                     
                                     if ( a[m+1][n+1] == 'O')
                                     {
											      mc++;
                                    }
                                     if ( a[m+1][n-1] == 'O')
                                     {
											mc++;
                                        }
                                     
                                     if ( a[m-1][n+1] == 'O')
                                     {
											mc++;
                                        }
                                     
                                     if ( a[m][n+1] == 'O')
                                     {
											 mc++;
                                    }       
                                     
                                     if ( a[m][n-1] == 'O')
                                     {
											mc++;
                                        }
                                            
                                     if ( a[m-1][n-1] == 'O')
                                     {
											mc++;
                                        }
                                            
                                     if ( a[m-1][n] == 'O')
                                       {
											mc++;
                                        }
                                       
								     if(mc>0)
								     {
                                            if(mc == 1)
                                                cout<<PINK<<a[m][n];
                                            else if(mc == 2)
                                                cout<<RED<<a[m][n];
                                            else
								      	         cout<<DKRED<<a[m][n];
                                
								     }
									  else
                                            cout<<CYAN<<a[m][n];
                                 }
                }
                cout<<endl;
                }
     cout<<WHITE<<"You have "<<150-move<<" moves left\n";
     cout<<"Enter choice\n";
     ch = getch();
     if(ch==105||ch==73)//up
                   if(a[p1-1][p2]==35)
                   {
                                       cout<<RED<<"\nInvalid Move\n"<<WHITE;
                                      Sleep(2000);
                  }    
                   else if(a[p1-1][p2]=='O')
                                       lose=1;
                   else if(a[p1-1][p2]==32) 
                                       {
                                       a[p1-1][p2]=232;
                                       a[p1][p2]=' ';
                                       p1--;
                                       }
                   else if(a[p1-1][p2]==42) 
                                       {
                                       a[p1-1][p2]=232;
                                       a[p1][p2]=' ';
                                       p1--;
                                       count++;
                                       }
     if(ch==106||ch==74)//left
                   if(a[p1][p2-1]==35)
                   {
                                       cout<<RED<<"\nInvalid Move\n"<<WHITE;
                                       Sleep(1000);
                  }
                   else if(a[p1][p2-1]=='O')
                                      lose=1;
                   else if(a[p1][p2-1]==32)
                                       {
                                       a[p1][p2-1]=232;
                                       a[p1][p2]=' ';
                                       p2--;
                                       }
                   else if(a[p1][p2-1]==42)
                                       {
                                       a[p1][p2-1]=232;
                                       a[p1][p2]=' ';
                                       p2--;
                                       count++;
                                       }
                                       
     if(ch==107||ch==75)//down
                   if(a[p1+1][p2]==35)
                   {
                                       cout<<RED<<"\nInvalid Move\n"<<WHITE;
                                       Sleep(1000);
                  }
                   else if(a[p1+1][p2]=='O')
                                      lose=1;
                   else if(a[p1+1][p2]==32)
                                       {
                                       a[p1+1][p2]=232;
                                       a[p1][p2]=' ';
                                       p1++;
                                       }
                   else if(a[p1+1][p2]==42)
                                       {
                                       a[p1+1][p2]=232;
                                       a[p1][p2]=' ';
                                       p1++;
                                       count++;
                                       }                                  
     if (ch==108||ch==76)//right
                   if(a[p1][p2+1]==35)
                   {
                                       cout<<RED<<"\nInvalid Move\n"<<WHITE;
                                       Sleep(1000);
                  }
                   else if(a[p1][p2+1]=='O')
                                      lose=1;
                   else if(a[p1][p2+1]==32)  
                                       {
                                       a[p1][p2+1]=232;
                                       a[p1][p2]=' ';
                                       p2++;
                                       }
                   else if(a[p1][p2+1]==42)  
                                       {
                                       a[p1][p2+1]=232;
                                       a[p1][p2]=' ';
                                       p2++;
                                       count++;
                                       }
     if(ch!=105&&ch!=73&&ch!=106&&ch!=74&&ch!=107&&ch!=75&&ch!=108&&ch!=76)
     {
                cout<<RED<<"\nInvalid Move\n"<<WHITE;
                Sleep(1000);
     }
                               
     move++;
     if(a[0][3]!=32)
                win=1;
     }while(move<150&&win!=1&&lose!=1);
}

void runt::score()
{//Calculates final score
     system("cls");
     if(win==0||lose==1)
     {
      	cout<<BROWN<<" You Lose :(\n Your Score is Zero....\n You are really bad\n";
	 	finalscore=0;				
	 }
	 else
     {     
	 finalscore=count*(150-move);
     cout<<WHITE<<"\nYou Win!!!\n Your Score: "<<finalscore;
     if(win==1)
          {
          if(count*(150-move)>500)
               cout<<RED<<"\nYou are legendary!!!! ^_^\n";
          else if(count*(150-move)>200&&count*(150-move)<=500)
               cout<<YELLOW<<"\nYou are awesome!!!\n";
          else if(count*(150-move)>100&& count*(150-move)<=200)
               cout<<GREEN<<"\nYou are good!!\n";
          else if(count*(150-move)<=100)
               cout<<BLUE<<"\nYou are Ok.\n";
          }
     }
score(finalscore);
}

void runt::score(int a)
{//Submits for score
	char ch,b[25];
	cout<<WHITE<<"\nDo you want to submit score? (y/n)\n";
	cin>>ch;
	if(ch=='y')
		{
		cout<<"Enter player name\n";
		getchar();
		gets(b);
		record(a,b);//PASSES DATA TO RECRD	
		}
	cout<<"Do you want to view the high scores?\n";
	cin>>ch;
	if(ch=='y')
		{
		disp();
		}
}

void scoredb::record(int a,char b[])
{//Records score in the file
	scoredb temp;
	strcpy(temp.nam,b);
	temp.sc=a;
	fstream f("Score.dat",ios::binary|ios::app|ios::out);
	f.write((char*)&temp,sizeof(temp));
	f.close();
	cout<<"\nScore has been uploaded\n";
}

void scoredb::disp()
{//Displays 3 highscores from the file
	scoredb temp,a[100];
	int i=0;
	fstream f("Score.dat",ios::binary|ios::in);
	while(f.read((char*)&a[i],sizeof(a[i])))
		{
		if(f.eof())
			break;
		i++;
	    }
	for(int j=0;j<i;j++)
		for(int k=j+1;k<i;k++)
			{
				if(a[k].sc>a[j].sc)
					{
						temp=a[k];
						a[k]=a[j];
						a[j]=temp;
					}
			}
	cout<<RED<<"_____________________________________________\n";
	cout<<YELLOW<<setw(15)<<"NAME"<<'\t'<<'\t'<<setw(5)<<"HIGHSCORE\n";
	cout<<RED<<"_____________________________________________\n";
	if(i>=3)
	{
	for(int j=0;j<3;j++)
		{
			cout<<BLUE<<setw(15)<<a[j].nam<<'\t'<<'\t'<<setw(5)<<a[j].sc<<endl;
		}
	}
	else if(i==2)
	{
	for(int j=0;j<2;j++)
		{
			cout<<BLUE<<setw(15)<<a[j].nam<<'\t'<<'\t'<<setw(5)<<a[j].sc<<endl;
		}
	}
	else if(i==1)
	{
	for(int j=0;j<1;j++)
		{
			cout<<BLUE<<setw(15)<<a[j].nam<<'\t'<<'\t'<<setw(5)<<a[j].sc<<endl;
		}
	}	
	f.close();
	if(i>=90)
		cleanup();
    getchar();		
}

void scoredb::cleanup()
{//Cleans up the file to prevent too many redundant records
	scoredb temp,a[100];
	int i=0;
	fstream f("Score.dat",ios::binary|ios::in);
	while(f.read((char*)&a[i],sizeof(a[i])))
		{
		if(f.eof())
			break;
		i++;
	    }
	for(int j=0;j<i;j++)
		for(int k=j+1;k<i;k++)
			{
				if(a[k].sc>a[j].sc)
					{
						temp=a[k];
						a[k]=a[j];
						a[j]=temp;
					}
			}
	f.close();
	fstream f2("Temp.dat",ios::binary|ios::out);
	for(int j=0;j<5;j++)
		f2.write((char*)&a[j],sizeof(a[j]));
	remove("Score.dat");
	rename("Temp.dat","Score.dat");
	f2.close();
}

void runt::game_centre()
{//Main game centre, calls other functions in sequence 
     win=0;
     lose=0;
     move=0;
     loading();
     initialise();
     moves();
     score();
}

void runt::main_menu()
{//Main menu display
     cout<<GREEN<<"Welcome to :\n\n";
     cout<<RED<<"@@@  @  @ @   @ @@@@@\n";
     cout<<"@  @ @  @ @@  @   @\n";
     cout<<"@@@  @  @ @ @ @   @\n";
     cout<<"@ @  @  @ @  @@   @\n";
     cout<<"@  @ @@@@ @   @   @  v3.14.15 "<<DKRED<<" by Gunner4ever and Sole Binary\n";
        Sleep(2000);
    cout<<BLUE<<"\n\nINSTRUCTIONS:\n";
     cout<<" a)Guide the little runt across the maze.\n b)Use i,k,j,l to move up,down,left and right.\n"
     <<" c)Gather as much food("<<YELLOW<<'*'<<BLUE<<") as you can while navigating the maze.\n"
     <<" d)But remember the main objective is to reach the other end.\n"
     <<" e)The score is calulated by multiplying the number of * collected with the         number of moves you have left. \n"
     <<" f)So you have to strike the right balance.\n g)You have a total of 150 moves.      Remember that any "<<RED<<"invalid"<<BLUE<<" move is counted   as a move lost. So DON'T be stupid.\n"
     <<" h)You start at the bottom right corner(blue runt) and you have to reach the      top left opening in the maze.\n"
     <<" i)Be sure not to step on any of the landmines which are invisible\n"
     <<" \t1. If you your surrounding 3x3 area has 1 mine, runt turns "<<PINK<<char(232)<<BLUE<<'\n'
     <<" \t2. If you your surrounding 3x3 area has 2 mines, runt turns "<<RED<<char(232)<<BLUE<<'\n'
     <<" \t3. If you your surrounding 3x3 area has 3 or more mines, runt turns "<<DKRED<<char(232)<<'\n';
      
     cout<<WHITE<<endl<<"Press Enter to begin!!"<<endl;
     getchar();
     char cho;
     do
     {
     game_centre();
     cout<<WHITE<<"\n\nPlay again?(y/n)\n";
     cin>>cho;
     }while(cho=='y'||cho=='Y');
     system("cls");
     cout<<RED<<"@@@@  @@  @@ @@ @@@@   @@  @   @ @@@@ @@@\n";
     cout<<"@    @  @ @ @ @ @     @  @ @   @ @    @  @\n";
     cout<<"@ @@ @@@@ @ @ @ @@@   @  @ @   @ @@@  @@@\n";
     cout<<"@  @ @  @ @   @ @     @  @  @ @  @    @ @\n";
     cout<<"@@@@ @  @ @   @ @@@@   @@    @   @@@@ @  @\n";
     getchar();
     getchar();
}

int main()
{
      runt a;
      a.main_menu();
      return 0;
}

