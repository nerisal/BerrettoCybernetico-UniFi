class Credential {
private:
	string password;
	string mDate;
	string username;
	
public:
	Credential(string p, string u) : password(p), username(u), mDate(currentDate() // dummy function) {}
	
	void setPassword(string newPass) {
		password = newPass;
		updateDate();
	}
	
	void setUsername(string newUs) {
		username = newUs;
		updateDate();
	}
	
	void updateDate() {
		mDate = currentDate() // Dummy function
	}
	
	string getPassword() const {
		return password;
	}
	
	string getUsername() const {
		return username;
	}
};

class PasswordManager {
private:
	map<string, Credential> database;
	
public:
	void addCredential(string URL, string p, string u) {
		database.try_emplace(URL, Credential(p, u));
	}
	
	void removeCredential(string URL) {
		database.erase(URL);
	}
	
	bool findCredential(string URL) {
		auto it = database.find(URL);
		if(it != database.end())
			return true;
			
		return false;
	}
	
	void setNewCredential(string URL, string newPass) {
		if(findCredential(URL)){
			if(database[URL].getPassword() != newPass)
				database[URL].setPassword(newPass);	
			else
				cerr << "New password should be different from old one" << endl; 
		}
	}
};
