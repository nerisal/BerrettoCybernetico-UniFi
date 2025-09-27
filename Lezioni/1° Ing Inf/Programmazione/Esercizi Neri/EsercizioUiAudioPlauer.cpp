class Observer {
public:
	virtual void attach() = 0;
	virtual void detach() = 0;
	virtual void update() = 0;
};

class Subject {
public:
	virtual void subscribe(Observer* o) = 0;
	virtual void unsubscribe(Observer* o) = 0;
	virtual void notify() = 0;
protected:
	std::list<Observer*> observers;
};

class UI : public Observer {
public:
	UI(std::shared_ptr<Player> player) : player(player) {
		attach();
	}
	virtual ~UI() {
		detach();
	}
	
	void printUI() const {
		std::cout << "Player's health: " << player->getHealt() << std::endl;
	}
	
	virtual void attach() override {
		player->subscribe(this);
	}
	
	virtual void detach() override {
		player->unsubscribe(this);
	}
	
	virtual void update() override {
		printUI();
	}
	
private:
	std::shared_ptr<Player> player;
};

class AudioManager : public Observer {
public:
	AudioManager(std::shared_ptr<Player> player) : player(player) {
		attach();
	}
	
	virtual ~AudioManager() {
		detach();
	}
	
	void play() const {
		if(player->getStatus() == "healed"){
			std::cout << "Happy music played" << std::endl;
		}
		
		if(player->getStatus() == "damaged") {
			std::cout << "Sad music played" << std::endl;
		}
	}
	
	std::string getStatus() const {
		return status;
	}
	
	virtual void attach() override {
		player->subscribe(this);
	}
	
	virtual void detach() override {
		player->unsubscribe(this);
	}
	
	virtual void update() override {
		play();
	}
private:
	std::shared_ptr<Player> player;
};

class Player : public Subject {
private:
	int health;
	int posX, posY;
	std::string status;
public:
	Player(int h) : health(h), posX(0), posY(0), status("") {}
	
	int getHealth() const {return health;}
	
	void receivedDamage(int damage) {
		health -= damage; 
		status = "damaged";
		notify();
	}
	
	void useStimPack(int healing) {
		health += healing;
		status = "healed";
		notify();
	}
	
	void move(int x, int y) {
		posX += x;
		posY += y;
	}
	
	void fight(Player& enemy) {
		enemy.receiveDamage(10);
	}
	
	virtual void subscribe(Observer* o) override {
		observers.push_back(o);
	}
	
	virtual void unsubscribe(Observer* o) override {
		observers.remove(o);
	}
	
	virtual void notify() override {
		for(const auto& o : observers)
			o->update();
	}
};


