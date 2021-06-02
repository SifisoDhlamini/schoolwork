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
      string date =  m +"/"+d+"/"+y;
      return date;
  }
  void setDay(int d) {day = d;}
  void setMonth(int m) {month = m;}
  void setYear(int y) {year = y;};
  int getDay() const {return day;}
  int getMonth() const{return month;}
  int getYear() const{return year;}
  // adds the specified number of days to this instance
    int getLastDay() const{
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
   bool isLeapYear() const{ return ((this->getYear() % 4 == 0 && this->getYear() % 100 != 0) || this->getYear() % 400 == 0); }
private:
  int year, month, day;
};

class TimeSpan
{
public:
  TimeSpan(): year(0), month(0), day(0){}
  TimeSpan(int y, int m, int d){
      year = y;
      month = m;
      day = d;
  }
  int toTotalDays(){ return day; }
  
  int year, month, day;
};

class DateTime : public Date
{
public:
  DateTime() : Date() { }
  DateTime(int y, int m, int d) : Date(y, m, d) { }
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
  
  TimeSpan operator-(const DateTime &dt) const // return a TimeSpan object represents a time interval
  {
    DateTime *date_time = new DateTime(){}
    DateTime *sd = new DateTime(Date()){ 
        startDate(first.getYear(), first.getMonth()), first.getDay();
        endDate(last.getYear(), last.getMonth(), last.getDay();
    }
      
      bool isGreater = true;
      if(getYear() < dt.getYear()){
          isGreater = false;
      } else if(getYear() == dt.getYear() && getMonth() < dt.getMonth()){
          isGreater = false;
      } else if(getYear() == dt.getYear() && getMonth() == dt.getMonth() && getDay() < dt.getDay()){
          isGreater = false;
      }       
      
    if(!(isGreater)){
        return (dt - *this);
    } else {
        while(getYear() > sd->getYear()){
            if(getMonth() <= sd->getMonth()){
                int daysToAdd = (sd->isLeapYear()) ? 366 : 365;
                date_time->setDay(date_time->getDay()+ daysToAdd);
                sd->addDays(daysToAdd); 
            } else if(getMonth() >= sd->getMonth()){
                   int daysToAdd = sd->getLastDay(); 
                    sd->addDays(daysToAdd);
                    date_time->setDay(date_time->getDay() + daysToAdd);
            }                           
        }
        
        while(getMonth() != sd->getMonth()){
                int daysToAdd;
                if(getMonth() > sd->getMonth()){
                    daysToAdd = sd->getLastDay() - sd->getDay() + getDay();
                } else {
                    daysToAdd = getLastDay() - getDay() + sd->getDay();
                }
                date_time->setDay(date_time->getDay()+ daysToAdd);
                sd->addDays(daysToAdd); 
        } 
       
       if(sd->getDay() != getDay()){
           cout<<sd->toString()<<endl;
           int daysToAdd = getDay() - sd->getDay();
           sd->addDays(daysToAdd);
           date_time->setDay(date_time->getDay() + daysToAdd);
           cout<<sd->toString()<<endl;
       } 
               
    }
    TimeSpan *p = new TimeSpan(date_time->getYear(), date_time->getMonth(), date_time->getDay());
    return *p;
  }
private:
  Date startDate;
  Date endDate;
};

int main() {
  
  return 0;
}