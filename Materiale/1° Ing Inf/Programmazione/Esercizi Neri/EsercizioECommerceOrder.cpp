#include <iostream>
#include <list>



using namespace std;

class Product {
private:
	float price;
	string name;
public:
	Product(string n, float p) : name(n), price(p) {}
	
	float getPrice() const {
		return price;
	}
	
	string getName() const {
		return name;
	}
	
	bool operator==(const Product& other) const {
		if(price == other.price && name == other.name)
			return true;
		
		return false;
	}
};

class OrderItem {
private:
	Product product;
	int quantity;
public:
	OrderItem(Product p, int q) : product(p), quantity(q) {}
	
	const Product& getProduct() const {
		return product;
	}
	
	int getQuantity() const {
		return quantity;
	}
	
	bool operator==(const OrderItem& other) const {
		if(product == other.product && quantity == other.quantity)
			return true;
			
		return false;
	}
};

class Order {
private:
	float total;
	list<OrderItem> basket;
	
public:
	Order() : total(0) {}
	
	void calculateTotalCost() {
		total = 0;
		for(const auto& item : basket) {
			total += item.getProduct().getPrice() * item.getQuantity();
		}
	}
	
	float getTotal() const {
		return total;
	}
	
	void printBasket() const {
		for(const auto& item : basket) {
			cout << item.getProduct().getName() << " x" << item.getQuantity() << " total: " << (item.getProduct().getPrice() * item.getQuantity()) << endl;
		}
	}
	
	void addToBasket(OrderItem item) {
		basket.push_back(item);
	}
	
	void addToBasket(Product p, int q) {
		basket.emplace_back(p, q);
	}
	
	void removeFromBasket(OrderItem item) {
		basket.remove(item);
	}
	

};

class Customer {
private:
	string name;
	string surname;
	list<Order> history;
	
public:
	Customer(string n, string s) : name(n), surname(s) {}
	
	void printHistory() const {
		for(const auto& order : history)
			order.printBasket();
	}
	
	void addOrder(Order newOrder) {
		history.push_back(newOrder);
	}
	
	void addOrder() {
		history.emplace_back();
	}
};
