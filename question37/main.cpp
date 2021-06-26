#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int n,m,i,j,a,b,cases,no_quotes,st[101],ed[101];
//save number of days for each month 0 for zero index to start at 1
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//enough space for 146,451 days days from 1700 Jan to 2100 December + 100 requests
char c[147000]; 

//check for leap year as per leap year formula provided (return 1 if true or 0 if false)
int leap(int y) { return (y%400==0)||((y%4==0)&&(y%100)); }

void get_date(int day)
{
    int y,m;
    //start from 1700 and count the number of years from each year towards passed year 
    //make sure each year is checked for leap year tp subtract correct number of days
    //loop will stop on exact year since it will be less than 365 + leap() (0 or 1)
    for(y=1700;day>365+leap(y);y++){ day-=365+leap(y); }       
    //start from 1700 and count the number of years from each year towards passed year 
    //make sure february is checked for leap year to subtract correct number of days (28 0r 29)
    //loop will stop when the number of days are less than the days of that month
	for(m=1;day>days[m]+(m==2&&leap(y));m++){ day-=days[m]+(m==2&&leap(y)); }
    
    //day was decreasing in the loops
	cout<<m<<"/"<<day<<"/"<<y;

}

//sub procedure of fill
int f(int x)

{

	int i,tmp,sum;

	tmp=x/10000;//get the year '9999'

	sum=0;
    //number of days since 1700
	for(i=1700;i<tmp;i++)
	{
		sum+=365;//add 365 days to each year
		if(leap(i)){ sum++; } //if it is a leap year add a one more day
	}

	tmp=x%10000/100;//get the month of the year we are in

	for(i=1;i<tmp;i++)
	{
        //get the number of days in that particular month and add to days acumulated in years
		sum+=days[i];
		if(i==2 && leap(x/10000)) { sum++; }//if February check or 28 or 29 days by sending year to leap() function
	}
    //return the total number of days by adding remaining days from above calculation of months
	return sum+x%100;
}

void fill(int a,int b,int x)

{

	int fa,fb;

	fa=f(a); //get total number of days from 1700

	fb=f(b); //get total number of days from 1700
    
    //replace characters starting at index x, 
	memset(&c[fa],x,fb-fa+1);//starting from start date adress fill 'fb-fa+1' with 'value of x' to indicate quote made

}

int main()

{
    
	while((cin>>n>>m) && n+m) //("%d%d",&n,&m)&&n+m)

	{

		memset(c,0,sizeof(c));//initialize the whole array c with zeros starting from first index
        
        //collect start date and end date of existing quotes and fill in st 
        //(strat date array), and ed (end date array)
		for(i=0;i<n;i++){ cin>>st[i]>>ed[i]; }			 
        
        //collecting new quote request dates
		for(i=0;i<m;i++)
		{            
			cin>>a>>b;
            //fill in c with start and end dates
			fill(a,b,2);
		}
        
        //fill in c array with original start dates and end dates by filling the days with 1s
		for(i=0;i<n;i++) { fill(st[i],ed[i],1); }
        //increment case number and print
		cout<<"Case "<<++cases<<":"<<endl;

		no_quotes=1;//default to no quotes
        
        
		for(i=0;i<147000;i++)

			if(c[i]>1)//if the day is an new start date (2)

			{

				no_quotes=0;//change because there is a quote

				get_date(i);//get the date of that index/day and print it

				if(c[i+1]<2)//if the next day is not a start date or end date of a new request

					printf("\n");

				else//then there needs to be a change to end date

				{

					printf(" to ");

					for(j=i;c[j]>1;j++);//find the new request end date which is the next 2 in the array

					get_date(j-1);

					printf("\n");

					i=j; //push next iteration to start the day after the last one (j)

				}
			}
            //if no quotes is equal to 1
			if(no_quotes)
				printf("No additional quotes are required.\n");
	}
	return 0;
}