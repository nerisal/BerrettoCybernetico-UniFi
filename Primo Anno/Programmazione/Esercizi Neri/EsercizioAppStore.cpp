class Observer {
public:
  virtual ~Observer() {}
  virtual attach() = 0;
  virtual deatch() = 0;
  virtual update(int perc, int queue) = 0;
};

class Subject {
public:
  virtual ~Subject() {}
  virtual subscribe(Observer* o) = 0;
  virtual unsubscribe(Observer* o) = 0;
  virtual notify() = 0;
};

class AppIcon : public Observer {
private:
  std::shared_ptr<Subject> subject;
public:
  explicit AppIcon(std::shared_ptr<Subject> s) : subject(s) {
    attach();
  }
  ~AppIcon() override {
    detach();
}
  
  virtual attach() override {
    subject->subscribe(this);
  }
  
  virtual detach() override {
    subject->unsubscribe(this);
  }
  
  virtual update(int perc, int queue) override {
    drawBadge(perc);
    drawPercent(perc);
  }    
  
  void drawBadge(int p) {
    std::cout << p << std::endl:
}

// Stessa cosa per Percent
};

class AppDownloaderViewer : public Observer {
private:
  std::shared_ptr<Subject> subject;
public:
  explicit AppDownloaderViewer (std::share_ptr<Subject> s) : subject(s) {
    attach();
}
~AppDownloader override {
  detach();
}

  virtual attach() override {
    subject->subscribe(this);
  }
  
  virtual detach() override {
    subject->unsubscribe(this);
  }
  
  virtual update(int perc, int queue) override {
    drawBadge(queue);
    drawPercent(perc);
  }  


};

class AppDownloader : public Subject {
private:
  std::unordered_map<std::string name, App a> map_of_apps;
  std::list<Observer> observers;
  
  int queue = 0;
  
public:
  AppDownloader() {}
  ~AppDownloader() {}
  
  void addAppToList(const App& a) {
    map_of_app.insert(a.getName(), a);
    queue++;
  }
  
  void removeAppFromList (const App& a) {
    map_of_app.erase(a.getName());
    queue--;
  }
  
  virtual void subscribe(Observer* o) override {
    observers.push_back(o);
  }
  
  virtual void unsubscrive(Observer *o) override {
    observers.erase(o);
  }
  
  virtual void notify() override {
    for (const auto& o : observers)
      o->update(getCurrentAppPercent(), queue);
  }
  
  // int getCurrentAppPercent
   
  
  
};
