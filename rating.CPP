#include<stdio.H>
#include<conio.H>
#include<math.H>
#include<string.h>
#include<stdlib.h>
#define max 20
int q=0;
int nu=0;
int d;
float Ra[100];
float Probability(int rating1, int rating2)
{   float g= rating1-rating2;
    float a=g/400;
    float b=pow(10,a);
    float c=1+b;
    float e=1.00/c;
    return e;
}
void EloRating(float Ra, float Rb, int K, int d)
{

    float Pb = Probability(Ra, Rb);
    float Pa = Probability(Rb, Ra);
    if (d == 1) {
	Ra = Ra + K * (1 - Pa);
	Rb = Rb + K * (0 - Pb);
    }
    else {
	Ra = Ra + K * (0 - Pa);
	Rb = Rb + K * (1 - Pb);
    }

    printf("Updated Ratings:-\n");
    printf("Ra = %f",Ra);
    printf("\nRb = %f",Rb);
}

int insq(char queue[max][80], int *rear, char data[80])
{
	if(*rear == max -1)
	return(-1);
	else
	{
	*rear = *rear + 1;
	strcpy(queue[*rear], data);
	return(1);
	}
}
int delq(char queue[max][80], int *front, int *rear, char data[80])
{
if(*front == *rear)
return(-1);
else
{
(*front)++;
strcpy(data, queue[*front]);
return(1);
}
}
char *peek(char queue[max][80], int *nu, char data[80])
{
if (*nu==-1)
printf("Wrong");
else
strcpy(data, queue[*nu]);
return queue[*nu];
}

int main()
{
	int op1;
	clrscr();
do
{
	clrscr();
	printf("\n\n\n\t\t\t*****Welcome to the voting system***** \nYour choice matters");
	printf("\n 1.Insert the Options");
	printf("\n 2.Insert your Votes");
	printf("\n 3.Show the results");
	printf("\n 4.Exit");
	printf("\n\n Enter your option ");
	scanf("%d",&op1);
	switch(op1)
	{
	case 1:
		clrscr();
		char queue[max][80], data[80];
		int front, rear, reply;
		int ch;
		front = rear = -1; //... Initialize a Queue
		do
		{
		printf("------------------------------\n");
		printf("\tMenu");
		printf("\n------------------------------");
		printf("\n 1. Insert Your Option In The List");
		printf("\n 2. Delete Your Option From The Lisy");
		printf("\n.3. Enter To Read Your Particular Option");
		printf("\n 4. Exit");
		printf("\n------------------------------n");
		printf("\nChoose operation ");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1:
		 printf("\nEnter Your Option  ");
		 scanf("%s",data);
		 nu=nu+1;
		 reply = insq(queue,&rear,data);
		 if(reply == -1 )
		  printf("\nOOPS! The List is Full \n");
		  else
		 printf("\n '%s' is inserted in the List.\n\n",data);
		  break;
		case 2:
		  reply = delq(queue, &front, &rear, data);
		  if( reply == -1 )
		  printf("\nThe List is Empty \n");
		  else
		  {
		  printf("\nDeleted Option from the List is  %s\n", data);
		  nu=nu-1;
		  }
		  printf("\n%d",nu);
		  break;
		case 3:	  printf("Enter the no");
		  int no;
		  scanf("%d",&nu);
		  char var[90];
		  *var=*peek(queue,&nu,data);
		  printf("\n %s \n",data);
		  break;
		  }
		  }while(ch<4);
		  break;
	case 2:   for(int j=0;j<6;j++)
		  {
		  int d;
		  int K = 30;
		  srand(time(0));
		  int a=1,b=1,v1=1,v2=1;
		  char data1[80],data2[80];
		  while(a==b && v1==v2)
		    {
		    a=rand()%nu;
		    b=rand()%nu;
		    v1=a;
		    v2=b;
		    }
		  peek(queue,&a,data1);
		  peek(queue,&b,data2);
		  printf("\nWhich Do you Choose\n \t\t\t 1.%s or 2.%s\n",data1,data2);
		  scanf("%d",&d);
		  if(q==0)
		  {
			for(int i=0;i<nu;i++)
				{
				Ra[i]=1000;
				}
		  }
		  if(d==1)
		  {
		  float Pb=Probability(Ra[a],Ra[b]);
		  float Pa=Probability(Ra[b],Ra[a]);
		  d=1;
		  Ra[a]=Ra[a]+K*(1-Pa);
		  Ra[b]=Ra[b]+K*(0-Pb);
		  }
		  else
		  {
		  d=0;
		  float Pb=Probability(Ra[a],Ra[b]);
		  float Pa=Probability(Ra[b],Ra[a]);
		  Ra[a]=Ra[a]+K*(0-Pa);
		  Ra[b]=Ra[b]+K*(1-Pb);
		  }
		  q=q+1;
		  }
		  getch();
		  break;
	case 3:
		  clrscr();
		  printf("\n The Following are the ratings\n");
		  for(int i=0;i<nu;i++)
		  {
		  char var[90];
		  *var=*peek(queue,&i,data);
		  printf("\n %s:- %f \n",data,Ra[i]);
		  }
		  getch();
		  break;
	}
}while (op1<4);
getch();
return 0;
}