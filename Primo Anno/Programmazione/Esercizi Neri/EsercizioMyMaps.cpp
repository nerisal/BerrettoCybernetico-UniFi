/////////// ESERCIZIO STRANO NON CAPITO

class Subject {
public:
	virtual void subscribe(Observer* o) = 0;
	virtual void unsubscribe(Observer* o) = 0;
	virtual void notify() = 0;
	
protected:
	list<Observer*> observers;
};

class Observer {
public:
	virtual void attach(Subject* d) = 0;
	virtual void detach(Subject* d) = 0;
	virtual void update(Subject* d) = 0;
};

class Device : public Subject {
private:
	string name;
	string ID;
	double latitude;
	double longitude;
	
public:
	Device(string n, string id) : name(name), ID(id) {
		updatePos();
	}
	
	string getName() const {
		return name;
	}
	
	string getId() const {
		return ID;
	}
	
	void setName(string n) {
		name = n;
		notify();
	}
	
	void updatePos() {
		latitude = REALDEVICE::getLatitude() // dummy function;
		longitude = REALDEVICE::getLongitude() // dummy function;
		
		notify();
	}
	
	double getLatitude() const {
		return latitude;
	}
	
	double getLongitude() const {
		return longitude;
	}
	
	virtual void subscribe(Observer* o) override {
		observers.push_back(o);
	}
	
	virtual void unsubscribe(Observer* o) override {
		observers.remove(o);
	}
	
	virtual void notify() override {
		for(const auto& o : observers)
			o->update(this);
	}
};

class Map : public Observer {
private:
	list<Device*> mydevices;
public:
	Map() {}
	~Map() {
		for(const auto& d : mydevices)
			d->unsubscribe(this);
	}
	
	void addDevice(Device* newDevice) {
		mydevices.push_back(newDevice);
		attach(newDevice);
	}
	
	virtual void attach(Subject* d) override {
		d->subscribe(this);
	}
	
	virtual void detach(Subject* d) override {
		d->unsubscribe(this);
	}
	
	void update(Device* d) override {
		print(d);
	}
	
	void print(Device* d) const {
		cout << "Device name: " << d->getName() << " at: " << d->getLatitude() << " " << d->getLongitude() << endl;
	}
};

class Notfication : public Observer {
private:
	list<Device*> mydevices;
	
public:
	Notification() {}
	~Notification() {
		for(const auto& d : mydevices)
			d->unsubscribe(this);
	}
	
	void addDevice(Device* newDevice) {
		mydevices.push_back(newDevice);
		attach(newDevice);
	}
	
	virtual void attach(Subject* d) override {
		d->subscribe(this);
	}
	
	virtual void detach(Subject* d) override {
		d->unsubscribe(this);
	}
	
	void update(Subject* d) override {
		cout << "The devive " << d->getName() << " changed position" << endl;
	}
};
























