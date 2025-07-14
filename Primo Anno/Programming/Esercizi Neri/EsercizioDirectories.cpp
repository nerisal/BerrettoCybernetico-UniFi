#include <memory>
#include <string>
#include <iostream>
#include <map>

using namespace std;
class DiskElement {
	virtual void print() = 0;
	virtual string getName() = 0;
};

class DiskFile : public DiskElement {
public:
	DiskFile(string n = "unnamed", int s, bool w) : name(n), size(s), writeable(w) {}
	virtual void print() override;
	
	string getName() override {
		return name;
	}
	
private:
	string name;
	int size;
	bool writeable;
};

void DiskFile::print() {
	cout << name << " - size: " << size << " Is writeable: ";
	if(writeable)
		cout << "true" << endl;
	else
		cout << "false" << endl; 
}

class DiskDirectory : public DiskElement {
public:
	DiskDirectory(string n) : name(n) {}
	
	virtual void print() override;
	
	string getName() override {
		return name;
	}
	
	void list();
	void add(shared_ptr<DiskElement> e);
	void remove(string n);
	
private:
	map<string,shared_ptr<DiskElement>> content;
	string name;
};

void DiskDirectory::list() {
	cout << name << endl;
	for(const auto& [key, value] : content){
		 cout << value->getName() << endl;
	}
}

void DiskDirectory::print() {
	cout << "Folder name: " << name;
}

void DiskDirectory::add(shared_ptr<DiskElement> e) {
	string name = e->getName();
	
	content.try_emplace(name, e);
}

void DiskDirectory::remove(string n) {
	content.erase(n);
}




