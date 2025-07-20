//
// Created by salvatore on 04/07/18.
//

#ifndef FILEDIRECTORY_DATA_H
#define FILEDIRECTORY_DATA_H


class Data {


private:

    int day, month, year, ora, min, sec;

public:

    Data(){}

    int getDay() const {
        return day;
    }

    void setDay(int day) {
        this->day=day;
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int month) {
        this->month = month;
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }

    int getOra() const {
        return ora;
    }

    void setOra(int ora) {
        this->ora = ora;
    }

    int getMin() const {
        return min;
    }

    void setMin(int min) {
        this->min = min;
    }

    int getSec() const {
        return sec;
    }

    void setSec(int sec) {
        this->sec = sec;
    }
};


#endif //FILEDIRECTORY_DATA_H
