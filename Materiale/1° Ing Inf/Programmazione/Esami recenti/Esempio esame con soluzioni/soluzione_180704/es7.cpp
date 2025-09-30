#include <iostream>
#include <string>
#include <exception>
#include <map>

// NOTE: for the written examination it is not necessary
// to check the validity of the date (a struct is acceptable)
// for the oral examination it is better if it is done
class Date {
public:
    explicit Date(int d=1, int m=1, int y=1970) : day(d), month(m), year(y) {
        checkValidDate();
    }

    std::string to_string() const {
        return  std::to_string(day)+"/"+std::to_string(month)+"/"+std::to_string(year);
    }

    int getDay() const {
        return day;
    }

    void setDay(int day) {
        Date::day = day;
        checkValidDate();
    }

    int getMonth() const {
        return month;
    }

    void setMonth(int month) {
        Date::month = month;
        checkValidDate();
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        Date::year = year;
        checkValidDate();
    }

private:
    void checkValidDate();
    bool isValidDate() const;
    bool isLeapYear() const;
    int day, month, year;    // can use old enum for month, they are converted implicitly to ints
};

void Date::checkValidDate() {
    if (!isValidDate()) {
        std::string badDate = to_string();
        throw std::out_of_range("Bad date: "+badDate);
    }
}

bool Date::isValidDate() const {
    if(month<=0 || month>12 || day<=0 || day>31)
        return false;
    if(day>30 && ((month==4) || (month==6) || (month==9) || (month==11)) )
        return false;
    if(month==2 && ((day>28 && !isLeapYear()) || (day>29 && isLeapYear())) )
        return false;
    return true;
}

bool Date::isLeapYear() const {
    if( ((year%4 == 0) && (year%100 != 0)) || (year%400 == 0) )
        return true;
    else
        return false;
}

class File {
public:
    explicit File(const std::string &name="", const std::string &ext="", const Date &creation=Date(), const Date &modification=Date(),
         const Date &access=Date()) : name(name), ext(ext), creation(creation), modification(modification), access(access) {}
    virtual void show() const {
        std::cout << "File: " << name << "." << ext << " Created: " << creation.to_string() << std::endl;
    }
    virtual ~File() {}
    std::string getName() const {
        return name;
    }
protected:
    std::string name, ext;
    Date creation, modification, access;
};

class Directory : public File {
public:
    Directory(const std::string &name, const Date &creation, const Date &modification,
              const Date &access) : File(name, "", creation, modification, access) {}

    void show() const override {
        std::cout << "Directory: " << name << " Created: " << creation.to_string() << std::endl;
        for(auto item : elements) {
            std::cout << "\t";
            item.second->show();
        }
    }
    void add(File* item) {
        elements.insert(std::make_pair(item->getName(), item));
    }
    void remove(File* item) {
        auto itr = elements.find(item->getName());
        if (itr != elements.end()) {
            std::cout << "Deleted: " << item->getName() << std::endl;
            delete itr->second;
            elements.erase(itr);
        }
    }
    // NOTE: check if the assignment requires to implement or just justify if these methods are needed
    // for the oral examination it is better to implement them
    virtual ~Directory() { // XXX questionable wether destruction of a Directory object requires to erase it... anyway...
        clearDirectory(); // use helper method: it's going to be used again
    }

    Directory(const Directory& right) {
        copyDirectory(right); // use helper method: it's going to be used again
    }

    Directory& operator=(const Directory& right) {
        if( this != &right) {
            clearDirectory();
            copyDirectory(right);
        }
        return *this;
    }

private:
    std::map<std::string, File*> elements;

    // helper methods
    void clearDirectory() {
        for(auto itr : elements) {
            delete itr.second;
        }
        elements.clear();
    }

    void copyDirectory(const Directory &right) {
        name = right.name;
        ext = right.ext;
        creation = right.creation;
        modification = right.modification;
        access = right.access;
        for(auto itr : right.elements) {
            Directory* dirPtr = dynamic_cast<Directory*>(itr.second);
            if(dirPtr)
                elements.insert(make_pair(itr.first, new Directory(*dirPtr)));
            else
                elements.insert(make_pair(itr.first, new File(*itr.second)));
        }
    }
};

int main() {
    Date d1(1, 7, 2018);
    Date d2(6, 7, 2018);
    File* f1 = new File("foo", "txt", d1, d1, d2);
    File* f2 = new File("bar", "jpg", d2, d2, d2);
    Directory* dir1 = new Directory("/tmp", d1, d2, d2);
    dir1->add(f1);
    dir1->add(f2);
    dir1->show();
    Directory* dir2 = new Directory("/tmp/foobar", d2, d2, d2);
    File* f3 = new File("fizz","doc", d2, d2, d2);
    dir2->add(f3);
    dir1->add(dir2);
    dir1->show();
    dir1->remove(f2);
    dir1->show();

    Directory* dirCC = new Directory(*dir1); // copy constructor
    dirCC->show();
    File* f4 = new File("buzz","xls", d2, d2, d2);
    dirCC->add(f4);
    *dir1 = *dirCC; // operator=
    delete dirCC; // Directory destructor
    dir1->show();

    delete dir1; // Directory destructor
}