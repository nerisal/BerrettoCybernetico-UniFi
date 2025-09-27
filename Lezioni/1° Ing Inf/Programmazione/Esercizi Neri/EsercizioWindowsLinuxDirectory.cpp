class FSFactory {
public:
	virtual Directory* createDirectory() = 0;
	virtual File* createFile() = 0;
};

class LinuxFile : public File {
public:
	virtual ~LinuxFile() {}
	
	virtual bool create(string aName) override {
		name = aName;
		return true;
	}
	
	virtual bool move(string newName) override {
		name = newName;
		return true;
	}
	
	virtual bool isHidden() const override {
		if(name[0] == '.')
			return true;
			
		return false;
	}
	
	string getName() const {
		return name;
	}
};

class LinuxDirectory : public Directory {
public:
	virtual ~LinuxDirectory() {}
	
	virtual bool create(string aName) override {
		name = aName;
		return true;
	}
	
	virtual bool move(string newName) override {
		name = newName;
		return true;
	} 
	
	virtual void list() override {
		for (auto it = files.rbegin(); it != files.rend(); ++it) {
                    if (!(*it)->isHidden()) {
                        cout << (*it)->getName() << endl;
                    }
              }
	}
};

class WindowsFile : public File {
public:
	virtual ~WindowsFile() {}
	
	virtual bool create(string aName) override {
		name = aName;
		return true;
	}	
	
	virtual bool move(string newName) override {
		name = newName;
		return true;
	}
	
	virtual bool isHidden() {
		return is_hidden;
	}
	
	string getName() const {
		return name;
	}
	
private:
	bool is_hidden = false;
};

class WindowsDirectory : public Directory {
public:
	virtual ~WindowsDirectory() {}
	
	virtual bool create(string aName) override {
		name = aName;
		return true;
	}
	
	virtual bool move(string newName) override {
		name = newName;
		return true;
	}
	
	virtual void list() override {
		for(const auto& file : files) {
		
		    if(!file.isHidden()) {
		    
			cout << file.getName() << endl;
		    }
		}
	}
};

class LinuxFactory : public FSFactory {
public:
	virtual Directory* createDirectory() override {
		LinuxDirectory* product = new LinuxDirectory();
		return product;
	}
	
	virtual File* createFile() override {
		LinuxFile* product = new LinuxFile();
		return product;
	}
};

class WindowsFactory : public FSFactory {
public:
	virtual Directory* createDirectory() override {
		WindowsDirectory* product = new WindowsDirectory();
		return product;
	}
	
	virtual File* createFile() override {
		WindowsFile* product = new WindowsFile();
		return product;
	}
};

#include <list>

using namespace std;

int main() {
	FSFactory* factory;
	
	bool isWindows;
	
	isWindows = false;
	
	if(isWindows) {
		factory = new WindowsFactory();
	}else {
		factory = new LinuxFactory();
	}
	
	// Posso usare auto perché il sistema operativo è deciso a tempo di compilazione.
	auto file = factory->createFile();
	auto dir = factory->createDirectory();
	
	file->create("test.text");
	dir->create("/tmp/foo");
	dir->addFile(*file);
	dir->move("/tmp/bar");
	
	return 0;
}
