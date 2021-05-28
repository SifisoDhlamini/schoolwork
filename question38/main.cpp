#include <iostream>
#include <string>
#include <set>

using namespace std;

class Date
{
public:
  Date()
  {
    year = 1;
    month = 1;
    day = 1;
  }
  Date(int y, int m, int d)
  {
    year = y;
    month = m;
    day = d;
  }
  virtual string toString(){
      string d = (day >= 10)? to_string(day): "0" + to_string(day);
      string m = (month >= 10)? to_string(month): "0" + to_string(month);
      string y;
      if(year >= 1000){
          y = to_string(year);
      } else if(year >= 100){
          y = "0" + to_string(year);
      } else if(year >= 10){
          y = "00" + to_string(year);
      } else {
         y = "000" + to_string(year); 
      }
      string date =  m +", "+d+", "+y;
      return date;
  }
  void setDay(int d) {day = d;}
  void setMonth(int m) {month = m;}
  void setYear(int y) {year = y;};
  int getDay() const {return day;}
  int getMonth() const{return month;}
  int getYear() const{return year;}
  // adds the specified number of days to this instance
    int getLastDay(){
        int lastday;
        set<int> thirty = {4, 6, 9, 11};
        set<int> thirtyOne = {1, 3, 5, 7, 8, 10, 12};
        
        if(month == 2){
            lastday = (isLeapYear())? 29 : 28;
        } else if(thirty.find(month) != thirty.end()){
            lastday = 30;
        } else {
            lastday = 31;
        } 
        return lastday;
    }
  void addDays(int d)
  {
    if((day + d) <= getLastDay()){
        day += d;
    } else {
        int remainder = d - (getLastDay() - day);
        addMonths(1);
        while(remainder > getLastDay()){            
            remainder-=getLastDay();
            addMonths(1);            
        }
        day = remainder;      
    }
  }
  void addMonths(int m){
      if(month + m >= 12){
          year+=((month+m)/12);
      }
      month = (month + m) % 12;
      if(day > getLastDay()){
          day = day - getLastDay();
          month++;          
      }
  }
  void addYears(int y){
      year+=y;
  }
  bool isLeapYear(){ return ((this->getYear() % 4 == 0 && this->getYear() % 100 != 0) || this->getYear() % 400 == 0); }
private:
  int year, month, day;
};
int main() {
  int n;
  Date d(2021, 1, 1);
  cin>>n;
  d.addDays(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addMonths(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addYears(n);
  cout<<d.toString()<<endl;
  return 0;
}