using namespace std;

class Item {
private:
  float price;
  string name;
  
public:
  Item(string n, float p) : name(n), price(p) {}
  
  float getPrice() const {
    return price;
  }
  
  string getName() const {
    return name;
  }
};

class Customer {
private:
  string name;
  string surname;
  string address;
  bool is_premium;
  
public:
  Customer(string n, string s, string a, bool p = false) : name(n), surname(s), address(a), is_premium(p) {}
  
  bool isPremium() const {
    return is_premium;
  }
  
  string getName() const {
    return name;
  }
  
  string getSurname() const {
    return surname;
  }
  
  string getAddress() const {
    return address;
  }
  
  void setAddress(string a) {
    address = a;
  }
  
  void setPremium(bool p) {
    is_premium = p;
  }
  
};

class Order {
private:
  Customer& customer;
  list<shared_ptr<Item>> cart;
  
public:
  explicit Order(Customer& customer) : customer(customer) {}
  
  void addItem(shared_ptr<Item> i) {
    cart.push_back(move(i));
  }
  
  void removeItem(shared_ptr<Item> i) {
    for(auto it = cart.begin(); it != cart.end(); ++it){
      if((*it)->getName() == i->getName()) {
          cart.erase(it);
          break;
      }
    } 
  }
  
  float getTotalCost() {
    float total = 0;
    for(const auto& item : cart){
      if(customer.isPremium() && item->getPrice() <= 15)
          total += (item->getPrice() - (item->getPrice() * 0.1));
      else
        total += item->getPrice();
    }
    
    return total;
  }
};
