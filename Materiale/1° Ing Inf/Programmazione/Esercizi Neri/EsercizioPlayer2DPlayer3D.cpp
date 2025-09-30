#include <memory>

using namespace std;

class Player3D {
public:
	virtual void move(int new_x, int new_y, int new_z) = 0;
	virtual void selectWeapon(string name) = 0;
	
	virtual ~Player3D() {}
};

class Player2D {
public:
	explicit Player2D(int x = 0, int y = 0) : x(x), y(y) {} 	
	
	void move(int new_x, int new_y) {
		x = new_x;
		y = new_y;
		
		cout << "Position: " << x << ", " << y;
	}
	
	void selectWeapon(int index) {
		switch(index) {
			case 1:
				cout << "You equiped a sword" << endl;
				break;
			case 2:
				cout << "You equiped a morningstar" << endl;
				break;
			case 3:
				cout << "You equiped a bow" << endl;
				break;
			default:
				break;
		}
	}
private:
	int x;
	int y;
};

class Player3DAdapter : public Player3D {
public:	
	explicit Player3DAdapter(unique_ptr<Player2D> adaptee) : adaptee(std::move(adaptee)) {}
	Player3DAdapter() : adaptee(make_unique<Player2D>()) {}
	
	~Player3DAdapter() {}
	
	virtual void move(int new_x, int new_y, int new_z) override {
		adaptee->move(new_x, new_y);
		z = new_z;
		
		cout << ", " << z << endl;
	}
	
	virtual void selectWeapon(string name) override {
		int index;
		
		if(name == "sword")
			index = 1;
		else if(name == "morningstar")
			index = 2;
		else if(name == "bow")
			index = 3;
		else
			throw out_of_range("No weapons with this name");
		
		adaptee->selectWeapon(index);
	}

private:
	int z = 0;
	unique_ptr<Player2D> adaptee;
};
