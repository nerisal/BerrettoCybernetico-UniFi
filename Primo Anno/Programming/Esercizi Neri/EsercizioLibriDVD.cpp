#include <iostream>
#include <list>
#include <string>

using namespace std;

class LibraryElement {
public:
	virtual void print() const = 0;
};

class Book : public LibraryElement {
public:
	Book(string title, string author, string publisher, int pages) : title(title), author(author), publisher(publisher), pages(pages) {}
	
	virtual void print() const override {
		cout << "Book: "<< title << " by " << author << ". Published by " << publisher << ". Pages: " << pages << endl;
	}
private:
	string author;
	string title;
	string publisher;
	int pages;
};

class Dvd : public LibraryElement {
public:
	Dvd(string title, string director, int lenght) : title(title), director(director), length(length) {}
	
	virtual void print() const override {
		cout << "DVD: " << title << " directed by " << director << ". Length" << length << endl;
 	}
private:
	string title;
	string director;
	int length;
};

class Library {
private:
	list<shared_ptr<LibraryElement>> library;

public:
	void add(shared_ptr<LibraryElement> element) {
		library.push_back(element);
	}
	
	void remove(unique_ptr<LibraryElement> element) {
		for(auto it = library.begin(); it != library.end(); ++it){
			if(it->get() == element.get())
				library.erase(it);
		}
	
	}
	
	void print() {
		for(const auto element : library) {
			element->print();
		}
	}
}
