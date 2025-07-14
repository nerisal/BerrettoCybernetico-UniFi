#include "Date.h"


class File {
private:
	Date creation_date;
	Date modification_date;
	Date latest_access_date;
	
	std::string name;
	std::string ext;
	
public:
	File(std::string n, std::string ext, Date cd) : name(n), ext(ext), creation_date(cd), modification_date(cd), latest_access_date(cd) {}
	
	void OnFileAccess() {
		latest_access_date = Date::Now();
	} 
	
	void OnFileModified() {
		modification_date = Date::Now();
	}
	
	void SetFileName(std::string n) {
		name = n;
		onFileModified();
	}
	
	bool operator<=(const File& right) {
		if(this.creation_date <= right.creation_date){
			return true;
		}	
		else{
			return false;
		}
	}
	
	// Altre funzionalità
};

class Date {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
public:
	Date(int y, int m, int d, int h, int min, int sec) : year(y), month(m), day(d), hour(h), minute(min), second(sec) {}
		
	bool operator<=(const Date& right) const{
		if(year != right.year)
			return year < right.year;
		if(month != right.month)
			return month < right.month;
		if(day != right.day)
			return day < right.day;
		if(hour != right.hour)
			return hour < right.hour;
		if(minute != right.minute)
			return minute < right.minute;
			
		return second <= right.second;
	
	
	}
	
	// In questo caso si può usare un membro statico perché è una funzione comune a tutte le classi che restituisce un oggetto
	// Si può fare senza problemi perché la classe non gestisce risorse
	static Date Now(){
		// Metodi per assegnare l'anno il mese, il giorno, e l'orario corretto.
		
		// Data fittizia
		return Date(2025, 7, 8, 10, 32, 2);
	}
};
