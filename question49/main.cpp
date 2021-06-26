#include <iostream>

using namespace std ;

int main()
{
    int T ;
    string month, day ;
    cin >> T ;
    while(T--)//will break when T == 0
    {
        //Enter day and month
        cin >> month >> day ;
        int weekend;// initialize number of weekend days (Friday and Saturday)
        int days = 0, d = 0 ;//initialize number of days and day
        //assign total days according to the month entered 
        if(month == "FEB") days = 28 ;
        if(month == "JAN" || month == "MAR" || month == "MAY") days = 31 ;
        if(month == "JUL" || month == "AUG" || month == "OCT" || month == "DEC") days = 31 ;
        if(month == "APR" || month == "JUN" || month == "SEP" || month == "NOV") days = 30 ;
        //assign start day of the month according to inputted day
        if(day == "SUN") d = 1 ;
        if(day == "MON") d = 2 ;
        if(day == "TUE") d = 3 ;
        if(day == "WED") d = 4 ;
        if(day == "THU") d = 5 ;
        if(day == "FRI") d = 6 ;
        if(day == "SAT") d = 7 ;
        //If it is February, the weekend days will always be 8 because each day will occur 4 times
        if (days==28) {
            weekend=8;
        }
        //if it is a 30 day month and the start day is between Sunday and Wednesday (inclusive)
        if (days==30&&1<=d&&d<=4) {
            weekend=8;
        }
        //if it is a 30 day month and the start day is Thursday or Saturday
        if (days==30&&(d==5||d==7)) {
            weekend=9;
        }
        //if it is a 30 day month and the start day is Friday
        if (days==30&&d==6) {
            weekend=10;
        }
        //if it is a 31 day month and the start day is between Sunday and Tuesday (inclusive)
        if (days==31&&1<=d&&d<=3) {
            weekend=8;
        }
        //if it is a 31 day month and the start day is Wednesday or Saturday
        if (days==31&&(d==4||d==7)) {
            weekend=9;
        }
        //if it is a 31 day month and the start day is Thursday or Sunday
        if (days==31&&(d==5||d==6)) {
            weekend=10;
        }
        //print total weekend days
        cout<<weekend<<endl;
    }
}