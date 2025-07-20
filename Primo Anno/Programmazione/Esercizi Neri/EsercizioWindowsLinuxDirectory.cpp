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
	}
	
	virtual bool move(string newName) override {
		name = newName;
	}
	
	virtual bool isHidden() const override {
		if(name[0] = '.')
			return true;
			
		return false;
	}
	
	string getName() const {
		return name;
	}
};

class LinuxDirectory() : public Directory {
public:
	virtual ~LinuxDirectory() {}
	
	virtual bool create(string aName) override {
		name = aName;
	}
	
	virtual bool move(string newName) override {
		name = newName;
	} 
	
	virtual void list() override {
		for(auto it = list.end(); it != list.begin(); --it){
			if(!(*it).isHidden())
				cout << (*(prev(it, 1))).getName() << endl;
		}
	}
};

class WindowsFile() : public File {
public:
	virtual ~WindowsFile() {}
	
	virtual bool create(string aName) override {
		name = aName;
	}	
	
	virtual bool move(string newName) override {
		name = newName;
	}
	
	virtual bool isHidden() {
		return isHidden;
	}
	
	string getName() const {
		return name;
	}
	
private:
	bool isHidden = false;
};

class WindowsDirectory : public File {
public:
	virtual ~WindowsDirectory() {}
	
	virtual bool create(string aName) override {
		name = aName;
	}
	
	virtual bool move(string newName) override {
		name = newName;
	}
	
	virtual void list() override {
		for(const auto& file : files)
			cout << file.getName() << endl;
	}
};

class LinuxFactory : public FSFactory {
public:
	virtual Directory* createDirectoryHandler() override {
		LinuxDirectory* product = new LinuxDirectory();
		return product;
	}
	
	virtual File* createFileHandler() override {
		LinuxFile* product = new LinuxFile();
		return product;
	}
};

class WindowsFactory : public FSFactory {
public:
	virtual Directory* createDirectoryHandler() override {
		WindowsDirectory* product = new WindowsDirectory();
		return product;
	}
	
	virtual LinuxFactory createFileHandler() override {
		WindowsFile* product = new WindowsFile();
		return product;
	}
};

#include <list>
#include <stdlib>

using namespace std;

int main() {
	FSFactory* factory;
	File* file;
	Directory* dir;
	
	bool isWindows;
	
	isWindows = false;
	
	if(isWindows) {
		static_cast<WindowsFactory*>(factory) = new WindowsFactory();
	}else {
		static_cast<LinuxFactory*>(factory) = new LinuxFactory();
	}
	
	// Posso usare auto perché il sistema operativo è deciso a tempo di compilazione.
	auto file = factory->createFileHandler();
	auto dir = factory->createDirectoryHandler();
	
	file->create("test.text");
	dir->create("/tmp/foo");
	dir->addFile(*file);
	dir->move("/tmp/bar");
	
	
}

