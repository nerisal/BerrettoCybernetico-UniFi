class Date {
private:
  bool is_leap;
  int year;
  int month;
  int day;
  
public:
  Date(int y = 1970, int m = 1, int d = 1) : year(y), month(m), day(d) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
      is_leap = true;
    else 
      is_leap = false;
  }
  
  int getYear() const {
    return year;
  }
  
  int getMonth() const {
    return month;
  }
  
  int getDay() const {
    return day;
  }
  
  void setYear(int y) {
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
      is_leap = true;
    else
      is_leap = false;
      
    year = y;
  }
  
  void setMonth(int m) {
    if(m < 1 || m > 12)
      throw std::out_of_range("The month exceeds the year");
    
    month = m;
  }
  
  void setDay(int d) {
      if(d < 0)
        throw std::out_of_range("Day can't be negative");
      
      if((month == 11 || month == 4 || month == 6 || month == 9) && d >30)
        throw std::out_of_range("Day not defined for current month");
      else if((month == 2)){
        if(!is_leap && d > 29)
          throw std::out_of_range("Day not defined for current month");
      }else if(d > 31)
        throw std::out_of_range("Day not defined for current month");
      
      day = d;
  }
  
  void setDate(int y, int m, int d) {
    setYear(y);
    setMonth(m);
    setDay(d);
  }
  
};
