/*
Project Name  : Memory Game
Developed By  : Shashi kumar Sah
Language Used : C++

Important Points
ßßßßßßßßßßßßßßßß
* The game has a main menu. Aceess the main menu using w,a,s,d keys.
* The game is also protected by user-password combo required at begining.
* The password of the game is "shashi".
* You can know read the instructions in the menu to know about game
*/
#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int ar[20];
int br[20];
const int r=5;   //row size
const int c=4;   //column size
int b[r][c];    //random genrator matrix
char ap[24];   //stores username
/*This function is used for generating a random 2D
array with 10 matching elements.*/
void randoms(int le)
{
       for(int i=0;i<20;i++)
       {
	 ar[i]=i;
       }
       randomize();
       int temp;
       int x=random(100)+100;
       for(int s=0;s<x;s++)
       {
	 int n=random(20);
	 int p=random(20);
	 if(n!=p)
	 {
	   temp=ar[n];
	   ar[n]=ar[p];
	   ar[p]=temp;
	 }
       }
       int ss=15;
       for(int n=0;n<20;)
       {
	  br[n]=ss;
	  n++;
	  br[n]=ss;
	  n++;
	  if(le==1)
	  {
	  br[n]=ss;
	  n++;
	  br[n]=ss;
	  n++;
	  }

	  ss++;
       }
       int mm=0,z;
       for(i=0;i<r;i++)
       {
	   for(int j=0;j<c;j++)
	   {
		 z=ar[mm];
		 b[i][j]=br[z];
		 mm++;
	   }
       }
}
/*This function is used to display the actual characters
hidden inside the 2D matrix */
void dis(void)
{

  char sz;
  for(int ii=0;ii<r;ii++)
       {
	      gotoxy(15,8+2*ii);
	      for(int jj=0;jj<c;jj++)
	      {
		sz=b[ii][jj];
		cout<<"\t "<<sz;
	      }
       }
}

/*
Now here it begins the game code:
* 1st step is to display the resultant 2D matrix for some time.
* After that the matrix elements are hidden and replaced by @.
* Now as the user enters the index of matrix we are supposed
  to go at that point and reveal the content of that index.
* Now the 2nd time the user enters the index and the element of
  the matrix matches with the previous ones,you scored the point
  and both remains open.Now the indexes of both the elements are
  stored inside a array so that we can check later on that the user
  dont enter the same index.
* If it does not matches with the previous one we are supposed to
  close both the elements after showing the 2nd element for a while.
* As the game progresses the chances decreases.Once your chances are
  over u are shown the full matrix and asked to quit the game.
* Every time it is also checked wheiter the user has entered q or Esc
* We also check whiter the user hand entered consecutive same indexes
*/
int level(void);
void game(void)
{
       textbackground(BLACK);
       clrscr();
       textmode(3);
       textcolor(WHITE);
       int lev=level();

       randoms(lev);

       textmode(3);
       textbackground(BLACK);
       clrscr();

       int a[4][5];
       int zz=65;
       gotoxy(17,6);
       for(int x=0;x<c;x++)
       cout<<"["<<x<<"]     "  ;
       for(int z=0;z<r;z++)
       {
       gotoxy(7,8+z*2);
       cout<<"["<<z<<"]";
       zz++;
       }
       dis();
       if(lev==1)
       delay(3000);
       else
       delay(1500);
       for(int ii=0;ii<r;ii++)
       {
	      gotoxy(15,8+2*ii);
	      for(int jj=0;jj<c;jj++)
	      {
		cout<<"\t @";
	      }
       }
       gotoxy(5,5);
       cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß";
       gotoxy(5,18);
       cout<<"ßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßß";
       gotoxy(5,6);
       for(int Ai=0;Ai<13;Ai++)
      {
      gotoxy(5,6+Ai);
      cout<<"ß";
      }
      gotoxy(45,6);
       for(int Aai=0;Aai<12;Aai++)
      {
      gotoxy(45,6+Aai);
      cout<<"ß";
      }
       int q=1,ppi,ppj,qqi,qqj,pp,qq,ip,jp;
       int u[20],v[20],w=0;
       int ch=25;
       int score=0;
       int l=0;
       int ssp=25,mx=5,ab=0;
       for(int aa=0;aa<26;aa++,ch--)
  {
     if(q==3)
     q=1;
       sp:
       int no;
       char cc,dd;
       gotoxy(55,10);
       cprintf("Player  :   ");
       puts(ap);
       int zo=strlen(ap);
       zo++;
       gotoxy(55,11);
       cprintf("Level   :  ");cout<<setw(zo)<<lev;

       gotoxy(55,12);
       cprintf("Chances :  ");cout<<setw(zo)<<ch;

       gotoxy(55,13);
       cprintf("Score   :  ");cout<<setw(zo)<<score;

    if(ssp!=ch&&ch>0)
    {

      gotoxy(mx,6+ab);
      textcolor(6);
      cprintf("ß");
      textcolor(WHITE);
      ssp--;
      ab++;
      if(ssp==13)
      {
	ab=0;
	mx=45;
      }

    }

       gotoxy(7,20);
       cout<<"Enter the Positon to continue  [R][C]";
       gotoxy(39,20);
       cc=getche();
       no=cc;
       if(no==27)
       goto nn;
       gotoxy(42,20);
       dd=getche();
       if(cc=='q'||dd=='q')
	goto nn;
       int i,j;
       if(cc>97)
       i=cc-97;
       else
       i=cc-48;
       j=dd-48;
       if(i>4||j>3)
       goto sp;
       if(q==1)
       {
	ip=i;
	jp=j;
       }
       if(q==2)
       {
	if(i==ip&&j==jp)
	goto sp;
       }
       int kkr=2;
       if(w>0)
       {
       for(int bb=0;bb<=w;bb++)
       {
	if(u[bb]==i&&v[bb]==j)
	kkr=3;
       }
       }
       if(kkr==3)
       goto sp;

       char k=b[i][j];
       if(q==1)
       {
       pp=k;
       ppi=i;
       ppj=j;
       }
       else
       {
       qq=k;
       qqi=i;
       qqj=j;
       }
       textbackground(GREEN);
       gotoxy(17+j*8,8+2*i);
       cprintf("   ");
       gotoxy(17+j*8,8+2*i);
       cout<<" "<<k;
       textbackground(BLACK);
       if(q==2)
       {
	     if(pp==qq)
	     {
		 u[w]=ppi;
		 v[w]=ppj;
		 w++;
		 u[w]=qqi;
		 v[w]=qqj;
		 w++;
			score=score+50;
		     int sk[6]={1,3,4,5,6};
		     int bo=sk[l];
		      l++;
		      if(l==5)
		      l=0;
		     textbackground(bo);
		     gotoxy(17+ppj*8,8+2*ppi);
		     cprintf("   ");
		     gotoxy(17+ppj*8,8+2*ppi);
		     cout<<" "<<k;
		     textbackground(bo);
		     gotoxy(17+qqj*8,8+2*qqi);
		     cprintf("   ");
		     gotoxy(17+qqj*8,8+2*qqi);
		     cout<<" "<<k;
		     textbackground(BLACK);
	     }
	     else
	     {
	     delay(600);
		     textbackground(BLACK);
		     gotoxy(17+qqj*8,8+2*qqi);
		     cprintf("   ");
		     gotoxy(17+qqj*8,8+2*qqi);
		     cout<<" "<<"@";

		     gotoxy(17+ppj*8,8+2*ppi);
		     cprintf("   ");
		     gotoxy(17+ppj*8,8+2*ppi);
		     cout<<" "<<"@";


	     }
	     if(score==500)
	     {
		gotoxy(50,3);
		cprintf("Score   :  ");cout<<setw(zo)<<score;
		gotoxy(12,24);
		cprintf("...CONGRATULATIONS YOU WON...");
		goto hp;
	     }
       }
       q++;

  }
       nn:
       gotoxy(17,24);
       cprintf("....GAME OVER....");
       gotoxy(12,25);
       textcolor(6);
       cprintf("Press any key to unlock all ");
       getch();
       gotoxy(12,25);
       cout<<"                            ";
       hp:
       gotoxy(12,25);
       textcolor(4);
       cprintf("   Press any key to quit   ");
       dis();
       getch();

}
/*
Now this the password function

* It is invoked at the start of the programme.
* You are provided with 5 chances
*/
void pass(void)
{
	     textbackground(BLACK);
	     clrscr();
	     int i=0,c;
	     char ar[25],a;
	     int aar[25]={115,104,97,115,104,105};

       char str[25];
       char pu;
       for(i=0;i<7;i++)
       {
	 pu=aar[i];
	 str[i]=pu;
       }
	     gotoxy(10,10);
	     textbackground(4);
	     for(i=0;i<40;i++)
	     {
	     delay(10);
	     cprintf(" ");
	     }
	     for(i=0;i<10;i++)
	     {
	      gotoxy(50,10+i);
	      cprintf("  ");
	     }
	     for(i=0;i<40;i++)
	     {
		gotoxy(50-i,20);
		delay(10);
		cprintf("  ");
	     }
	     for(i=0;i<10;i++)
	     {
		gotoxy(10,20-i);
		delay(20);
		cprintf("  ");
	     }
	     textbackground(BLACK);
	     gotoxy(14,13);
	     cprintf("  Username       :   ");
	     gets(ap);
	     gotoxy(14,15);
	     cprintf("  Password       :   ");
	     int z=3;
	     sk:
	     i=0;
       do
       {
	a=getch();
	c=a;
	if(c!=13)
	{
	  cprintf("*");
	  ar[i]=a;
	  i++;
	}
       }while(c!=13);
       ar[i]='\0';
       gotoxy(21,17);
       if(strcmp(ar,str))
       {
       textcolor(1);
       cprintf("  ACCESS DENIED");
       getch();
       gotoxy(35,15);
       cprintf("               ");
       gotoxy(21,17);
       cprintf("               ");
       z--;
       if(z==-1)
       exit(0);
       gotoxy(35,15);
       goto sk;
       }
       else
       {
       textcolor(2);
       cprintf("  ACESS GRANTED");
       getch();
       }

}
void ins(void);
/* Here is the Main function which contains a drop down menu
   As u enter choices the resulting operation is performed
   Use w,a,s,d key instead of Up,down as i dont know the code
   for up down keys.
*/
void main(void)
{
	  textmode(3);
	  pass();
	  textbackground(BLACK);
	  clrscr();
	  int i=1,a,k=2,p=1;
	  char  c;
	  while(k!=3)
	  {
	  textcolor(WHITE);
	  textbackground(BLACK);
	  clrscr();
	  gotoxy(24,9);
	  cprintf("..Main Menu..");
	  if(i==1)
	  textbackground(p);
	  gotoxy(15,11);
	  cprintf("Play Now ");
	  textbackground(BLACK);
	  if(i==2)
	  textbackground(p);
	  gotoxy(15,13);
	  cprintf("Instructions");
	  textbackground(BLACK);
	  if(i==3)
	  textbackground(p);
	  gotoxy(15,15);
	  cprintf("About Me");
	  textbackground(BLACK);
	  if(i==4)
	  textbackground(p);
	  gotoxy(15,17);
	  cprintf("Exit ");
	  textbackground(BLACK);
	  c=getch();
	  a=c;
	  if(c=='s'||c=='d'||c=='S'||c=='D')
	  i++;
	  if(c=='w'||c=='a'||c=='A'||c=='W')
	  i--;
	  if(i==5)
	  i=1;
	  if(i==0)
	  i=4;
	  if(a==13)
		   {
		       clrscr();
			  if(i==1)
			  {
			  game();
			  }
			  if(i==2)
			  {
			  ins();
			  }
			  if(i==3)
			  {
			  cout<<"\n\n        About Me";
			  cout<<"\n\nName     :  Shashi kumar sah";
			  cout<<"\n\nCollege  :  A.R.S.D College";
			  cout<<"\n\nCourse   :  Bsc(H) Computer Science";
			  cout<<"\n\nEmail    :  shashichander007@yahoo.com";

			  getch();
			  }
			  if(i==4)
			  {
			  gotoxy(13,15);
			  cout<<"     Thanks for playing the game";
			  k=3;
			  delay(1000);
			  }
		   }
	  }


}

void ins(void)
{
cout<<"\n\n                           Instructions\n\n";

cout<<"\n* The game is about finding a matching pairs hidden in 5*4 matrix.";

cout<<"\n* The matrix elements are composed of signs and characters.The matrix consist";
cout<<"\n  of 20 elements out of which 10 are unique [In Level 1 five are unique]";

cout<<"\n* The other 10 elements are repetions of unique ones to match the elements of     the cell";

cout<<"\n* The initial screen displays 5*4 matrix with the elements being hidden under";
cout<<"\n  the '@'symbol";

cout<<"\n* The rows are named as A,B,C,D,E and columns are named as 0 1 2 3";

cout<<"\n* The user needs to enter the cell numbers to open the respective cell";

cout<<"\n* If the two consecutive turned out cells do not match then they are";
cout<<"\n  turned back to their default '@' symbol when the third element is entered";

cout<<"\n* On the other hand if turned out cell match then the cell values remain visible";
cout<<"  we have to find the next pair in similar manner";

cout<<"\n* If all cells are turned out with matching values the game is over";

cout<<"\n\n* Enter q or Esc to quit any time between the game ";
getch();

}


int level(void)
{
	  clrscr();
	  int i=1,a,k=2,p=2;
	  char  c;
	  textcolor(WHITE);
	  int jp;
	  while(k!=3)
	  {
	  textbackground(BLACK);
	  clrscr();
	  gotoxy(20,8);
	  cprintf("..Select Level..");
	  if(i==1)
	  textbackground(p);
	  gotoxy(15,11);
	  cprintf("Level 1");
	  textbackground(BLACK);
	  if(i==2)
	  textbackground(p);
	  gotoxy(15,13);
	  cprintf("Level 2");
	  textbackground(BLACK);

	  c=getch();
	  a=c;
	  if(c=='s'||c=='d')
	  i++;
	  if(c=='w'||c=='a')
	  i--;
	  if(i==3)
	  i=1;
	  if(i==0)
	  i=2;
	  if(a==13)
		   {
			  if(i==1)
			  {
			  jp=1;
			  }
			  if(i==2)
			  {
			  jp=2;
			  }
			  k=3;
		   }
	  }
	  return jp;
}