#include <memory>
#inlcude <string>
#include <iostream>
#include <vector>

using namespace std;

class Vehicle {
public:
	virtual void print() const = 0;
	virtual float calculateCost() = 0;
	
	virtual ~Vehicle() {}
	
protected:
	string plate;
	int number_of_seats;
	float mult;
	float baseTariff;
};

class Car : public Vehicle {
public:
	Car(string p, int ns, float mult) : plate(p), number_of_seats(ns), mult(mult), baseTariff(50) {}
	
	virtual void print() const override {
		cout << "Car of plate: " << plate << " Number of seats " << number_of_seats << endl;
	}
	
	virtual float calculateCost() override {
		float cost = baseTariff + number_of_seats * mult;
		return cost;
	}
};

class Motorcycle : public Vehicle {
public:
	Motorcycle(string p, int ns) : plate(p), number_of_seats(ns), mult(1), baseTariff(25) {}
	
	virtual void print() const override {
		cout << "Motorcycle of plate: " << plate << " Number of seats " << number_of_seats << endl;
	}
	
	virtual float calculateCost() override {
		float cost = baseTariff * mult;
		return cost;
	}
};

class Truck : public Vehicle {
public:
	Truck(string p, int ns, float mult, float volume) : plate(p), number_of_seats(ns), number_of_seats(ns), mult(mult), volume(volume), baseTariff(70) {}
	
	virtual void print() const override {
		cout << "Truck of plate: " << plate << " Number of seats " << number_of_seats << endl;
	}
	
	virtual float calculateCost() override {
		float cost = baseTariff + mult * volume;
		return cost;
	}
private:
	float volume;
};

float calcTotalAmount(vector<shared_ptr<Vehicle>> landed) {
	float total = 0;
		
	for(const auto& v : landed){
		total += v->calculateCost();
	}
		
	return total;
}

