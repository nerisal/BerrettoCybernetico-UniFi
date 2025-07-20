class Book {
private:
	std::string title;
	std::string author;
	int pub_year;
	std::string id;	
public:
	Book(std::string t, std::string a, int py, std::string id) : title(t), author(a), pub_year(py), id(id) {}
	~Book() {}
	
	std::string getTitle() {
		return title;
	}
	
	str::string getAuthor() {
		return author;
	}
	
	int getPubYear() {
		int pub_year;
	}	
	
	std::string getID() {
		return ID;
	}
};

class Library {
private:
	std::map<std::string, std::shared_ptr<Book>> library;
	
public:
	void addBook(std::shared_ptr<Book> book);
	void removeBook(std::string id);
	
	bool findByTitle(std::string t);
	bool findByAuthor(std::string a);
	bool findById(std::string id); 
};

void Library::addBook(std::shared_ptr<Book> book) {
	library.insert(std::make_pair(book->getID, book);
}

void Library::removeBook(std::string id){
	library.erase(id);
}

bool Library::findByTitle(std::string t) {
	for(const auto& book : library){
		if(book.second->getTitle() == t)
			return true;
	}
	
	return false;
}

bool Library::findByAuthor(std::string a) {
	std::vector<std::shared_ptr<Book>> result;
	
	for(const auto& book : library) {
		if(book.second->getAuthor() == a)
			result.push_back(book.second);
	}
	
	return result;
}

bool Library::findById(std::string id) {
	return library.contains(id);
}
