class TelephoneNumber() {
private:
	int prefix();
	int number();
	
public:
	TelephoneNumber(int pr, int nb) : prefix(pr), nb(number) {}
	~TelephoneNumber() {}
	
	int getNumber() {
	  return number;
	}
};

class Address() {
    std::string address_type;
    std::string address_name;
    int civic;
    
public:
  Address(std::string at, std::string an, int c) : address_type(at), address_name(an), civic(c) {}
  ~Address() {}
  
  std::string get_address_type() {
    return address_type;
  }
  
  std::string get_address_name() {
    return address_name;
  }
  
  int get_civic() {
    return civic;
  }
};

class Person () {
private: 
  std::string title;
  std::string name;
  std::string surname;
  
public:
  Person(std::string t, std::strin n, std::string s) : title(t), name(n), surname(s) {}
  ~Person() {}
  
  std::string get_title() {
    return title;
  }
  
  std::string get_name() {
    return name;
  }
  
  std::string get_surname() {
    return surname;
  }
};

class Contact : public Person {
private:
  std::list<pair<std::string, std::unique_ptr<TelephoneNumber>>> telephones;
  std::list<pair<std::string, std::unique_ptr<Address>> addresses;

  public:
    Contact(std::string t, std::string n, std::string s) : Person(t, n, s) {}
    ~Contact();
    
    void addTelephoneNumber(std::string type, int prefix, int number) {
      auto tp = std::make_unique<TelephoneNumber>(prefix, number);
      telephone.pushback(std::make_pair(type, std::move(tp)));
    }
    
    void addAddress(std::string place, std::string address_type, std::string address_name, int civic){
      std::unique_ptr<Address> ad (address_type, address_name, civi);
      address.push_back(std::make_pair(place, std::move(ad)));
    }
    
};
 





















