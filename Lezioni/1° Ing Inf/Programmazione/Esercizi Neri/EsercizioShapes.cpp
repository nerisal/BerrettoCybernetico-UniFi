using namespace std;
#include <cmath>

class Shape {
public:
	virtual double area() const = 0;
	virtual void print() const = 0;
};

class Rettangolo : public Shape {
public:
	explicit Rettangolo(double h = 1, double b = 2) : altezza(h), base(b) {}
	double area() const override;
	void print() const override;
private:
	double altezza;
	double base; 
};

double Rettangolo::area() const {
	return base * altezza;
}

void Rettangolo::print() const {
	cout << "Rettangolo" << endl;
}

constexpr double PI = 3.14;

class Cerchio : public Shape {
public:
	explicit Cerchio(double r = 1) : raggio(r) {}
	double area() const override;
	void print() const override;
private:
	double raggio;
};

double Cerchio::area() const {
	return PI * raggio * raggio;
}

void Cerchio::print() const {
	cout << "Cerchio" << endl;
}

class Triangolo : public Shape {
public:
	explixit Triangolo(int l = 1) : lato(l) {}
	double area() const override;
	void print() const override;
private:
	double lato;
};

double Triangolo::area() const {
	return (lato * lato * sqrt(3))/4;
}

void Triangolo::print() const {
	cout << "Triangolo" << endl;
}

class ShapeFactory {
public:
	static unique_ptr<Shape> createShape(const string& type) {
		if(type == "cerchio")
			return make_unique<Cerchio>(10);
		else if(type == "Rettangolo")
			return make_unique<Rettangolo>(10, 20);
		else
			return make_unique<Triangolo>(10);
	} 
};
















