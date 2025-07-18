class Observer {
public:
	virtual void attach() = 0;
	virtual void detach() = 0;
	virtual void update(std::string what) = 0;
};

class Subject {
public:
	virtual void subscribe(Observer* o) = 0;
	virtual void unnsubscrive(Observer* o) = 0;
	virtual void notify(std::string what) = 0;
protected:
	std::list<Observer*> observers;
};

class Mailbox : public Subject {
public:
	void addMail(const Mail& newMail) {
		email.push_back(newMail);
		notify("new_mail");
	}
	
	const Mail& lastMail() const {
		return email.back();
	}
	
	void readEmail(int i) {
		if(i>= 0 && i < emails.size()) {
			emails[i].setRead(true);
			std::cout << emails[i].getTitle() << std::endl;
			std::cout << emails[i].getSender() << std::endl;
			std::cout << emails[i].getText() << std::endl;
		}else
			std::cerr << "bad index" << std::endl;
		
		notify("read");
	}
	
	int getNumUnreadEmails() const {
		int i = 0
		for(const auto& mail : emails){
			if(mail.isRead())
				i++;
		}

		return i;	
	}
	
	virtual void subscribe(Observer* o) override {
		observers.push_back(o);
	}
	
	virtual void unsubscribe(Observer* o) override {
		observers.remove(o);
	}
	
	virtual void notify(std::string what) override {
		for(const auto& o : observers)
			o->update(what);
	}
private:
	std::vector<Mail> emails;
};

class GuiNotifier : public Observer {
public:
	GuiNotifier(bool act, Subject* subject) : active(act), subject(subject) {
		attach();
	}
	
	virtual ~GuiNotifier() {
		detach();
	}
	
	virtual void attach() override {
		subject->subscribe(this);
	}
	
	virtual void detach() override {
		subject->unsubscribe(this);
	}
	
	virtual void update(std::string what) override {
		if(what == "new_mail")
			std::cout << "You recived a new email from: " << subject->lastEmail().getSender() << "\n Of object: " << subject->lastEmail().getTitl() << std::endl;
			active = true;
		
		if(what == "read")
			active = false;
	}
private:
	Subject* subject;
	bool active;
};

class IconBadgeMonitor {
public:
	explicit IconBadgeMonitor(Subject* subject) : subject(subject) {
		attach();
	}
	virtual ~IconBadgeMonitor() {
		detach();
	}
	
	virtual void attach() override {
		subject->subscribe(this);
	}
	
	virtual void detach() override {
		subject->unsubscribe(this);
	}
	
	virtual void update(std::string what) override{
		std::cout << subject->getNumUnreadEmails() << std::endl;
	}

private:
	Subject* subject;
};


























