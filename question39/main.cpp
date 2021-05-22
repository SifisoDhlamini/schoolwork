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
            lastday = (isLeapYear(*this))? 29 : 28;
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
  static bool isLeapYear(const Date &d){ return ((d.getYear() % 4 == 0 && d.getYear() % 100 != 0) || d.getYear() % 400 == 0); }
private:
  int year, month, day;
};
class DateTime : public Date
{
public:
  virtual string toString() // "mm/dd/yyyy HH:MM:SS"
  {
      string d = (getDay() >= 10)? to_string(getDay()): "0" + to_string(getDay());
      string m = (getMonth() >= 10)? to_string(getMonth()): "0" + to_string(getMonth());
      string h = (hour >= 10)? to_string(hour): "0" + to_string(hour);
      string min = (minute >= 10)? to_string(minute): "0" + to_string(minute);
      string s = (second >= 10)? to_string(second): "0" + to_string(second);
      string y;
      if(getYear() >= 1000){
          y = to_string(getYear());
      } else if(getYear() >= 100){
          y = "0" + to_string(getYear());
      } else if(getYear() >= 10){
          y = "00" + to_string(getYear());
      } else {
         y = "000" + to_string(getYear()); 
      }
      string dateTime =  m + "/" +d +"/" + y + " " + h + ":" + min + ":" + s;
      return dateTime;
  }
  DateTime() : Date()
  {
    hour = 0;
    minute = 0;
    second = 0;
  }
  DateTime(int y, int m, int d, int hh = 0, int mm = 0, int ss = 0) : Date(y, m, d)
  {
    hour = hh;
    minute = mm;
    second = ss;
  }
  void setHour(int h){ hour = h;}
  void setMinute(int m){ minute = m;}
  void setSecond(int s){ second = s;}
  int getHour() const{return hour;}
  int getMinute() const{return minute;}
  int getSecond() const{return second;}
  void addHours(int h){
    if((hour + h) < 24){
        hour += h;
        } else {
            int remainder = h - (24 - hour);
            addDays(1);
            while(remainder >= 24){            
                remainder-=24;
                addDays(1);            
            }
        hour = remainder;      
        }
    }
  void addMinutes(int m){
    if((minute + m) < 60){
        minute += m;
        } else {
            int remainder = m - (60 - minute);
            addHours(1);
            while(remainder >= 60){            
                remainder-=60;
                addHours(1);            
            }
        minute = remainder;      
    }
  }
  void addSeconds(int s){
    if((second + s) < 60){
        second += s;
    } else {
        int remainder = s - (60 - second);
        addMinutes(1);
        while(remainder >= 60){            
            remainder-=60;
            addMinutes(1);            
        }
        second = remainder;      
    }
  }
private:
  int hour, minute, second;
};
int main() {
  int n;
  DateTime d(2021, 1, 1);
  cin>>n;
  d.addHours(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addMinutes(n);
  cout<<d.toString()<<endl;
  cin>>n;
  d.addSeconds(n);
  cout<<d.toString()<<endl;
  return 0;
}