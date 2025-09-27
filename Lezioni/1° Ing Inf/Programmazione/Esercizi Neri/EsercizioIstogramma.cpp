enum ViewMode {
	PERC,
	ABS,
};

class Histogram {
private:
	vector<pair<string, int>> elements;
	int num_el;
	ViewMode view_mode;
public:
	explicit Histogram(int n) : num_el(n) {
		string name;
		
		for(int i = 0; i < num_el; i++){
			cout << "Insert[ " << i << " ]";
			cin >> static_cast<string>(name);
			
			elements.emplace_back(make_pair(name, 0));
		}
	}
	
	void setValue(int pos, int val) {
		if(elements.size() > pos)
			elements[pos].second = val;
		else
			throw out_of_bound("Exeed vector size");
	}
	
	int getValueAt(int pos){
		if(elements.size() > pos)
			elements[pos].second = val;
		else
			throw out_of_bound("Exeed vector size");
	}
	
	void setViewMode(ViewMode vm) {
		view_mode = vm;
	}
	
	void print() {
		if(view_mode == PERC){
			int total = 0;
			
			for(int i = 0; i < elements.size(); i++) {
				total += elements[i].second;
			}
			
			for(int i = 0; i < elements.size(); i++) {
				cout << elements[i].first << ": ";
				for(int j = 0; j < (elements[i].second * 100 / total); j++){
					cout << "▮";
				}
				
				cout << " " << elements[i].second << endl;
			}
		}
		else if(view_mode == ABS) {
		for(int i = 0; i < elements.size(); i++) {
				cout << elements[i].first << ": ";
				for(int j = 0; j < elements[i].second; j++){
					cout << "▮";
				}
				
				cout << " " << elements[i].second << endl;
			}
		}
	}
};
