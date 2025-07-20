class Subject {
public:
	virtual void subscribe(Observer* o) = 0;
	virtual void unsubscribe(Observer* o) = 0;
	virtual void notify(std::string what) = 0;
protected:
	std::list<Observer*> observers;
};

class Observer {
public:
	virtual void attach() = 0;
	virtual void detach() = 0;
	virtual void update(std::string what) = 0;
};

class PacketMon : public Subject {
public:
	PacketMon() : packets(0) {}
	virtual ~PacketMon() {}
	
	void addPacket(int packets) {
		this->packets += packets;
		
		if(packets % 100 == 0)
			notify("hundreds");
		else
			notify("");
	}
	
	int getPackets() const { return packets; }
	
	virtual void subscribe(Observer* o) override {
		observers.push_back(o);
	}
	
	virtual void unsubscribe(Observer* o) override {
		observers.remove(o);
	}
	
	virtual void notify(std::string what) override {
		for(const auto& o : observers) {
			o->update(what);
		}
	}
private:
	int packets;
};

class CPUUsage : public Subject {
public:
	CPUUsage() : use(0) {}
	virtual ~CPUUsage() {}
	
	void update(int howMuch = 1) {
		use += howMuch;
		
		if(use % 10 == 0)
			notify("tens");
		else
			notify("");
	}
	
	int getUsage() const { return use; }
	
	virtual void subscribe(Observer* o) override {
		observers.push_back(o);
	}
	
	virtual void unsubscribe(Observer* o) override {
		observers.remove(o);
	}
	
	virtual void notify(std::string what) override {
		for(const auto& o : observers) {
			o->update(what);
		}
	}

private:
	int use;
};

class MultiMonitor : public Observer {
public:
	MultiMonitor(std::string monitorName, Subject* cpuMonitor, Subject* packetMonitor) : name(monitorName), cpuMonitor(cpuMonitor), packetMonitor(packetMonitor) {
		attach();
	}
	virtual ~MultiMonitor() {
		datach();
	}
	
	virtual void attach() override {
		cpuMonitor->subscribe(this);
		packetMonitor->subscribe(this);
	}
	
	virtual void detach() override {
		cpuMonitor->unsubscribe(this);
		packetMonitor->unsubscribe(this);
	}
	
	virtual void update(std::string what) override {
		auto cpu = dynamic_cast<CPUUsage*>(cpuMonitor);
		auto packet = dynamic_cast<PacketMon*>(packetMonitor);
		
		if(cpu && packet){
			std::cout << "Monitor name: " << name << "\n Current CPU Usage: " << cpu->getUsage() << "\n Current Packets: " << packet->getPackets() << std::endl;
		}
				
		if(what == "hundreds") {
			std::cout << "Packets can be grouped by hundreds" << std::endl;
		}
		
		if(what == "tens") {
			std::cout << "CPU Usage percentage can be grouped by tens" << std::endl;
		}
private:
	std::string name;
	Subject* cpuMonitor;
	Subject* packetMonitor;
};
