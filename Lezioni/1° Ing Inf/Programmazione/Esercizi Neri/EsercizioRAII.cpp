// EsercizioRiscritturaRAII
class Buffer {
public:
	Buffer(int size) : size(size) {}
	
	// Implemento il costruttore di copia
	Buffer(const Buffer& original) : size(original.getSize()) {
		if(original.buffer != nullptr){
			allocate();
			for(int i = 0; i < size; i++) {
				buffer[i] = original.buffer[i];
			}
		}
	}
	
	// Posso accedere direttamente ai metodi privati di right perché right e this sono della stessa classe
	// Quindi possono accedere ai rispettivi metodi privati.
	const Buffer& operator=(const Buffer& right) {
		if(this != right){
			this->size = buffer.getSize;
			
			if(right.buffer != nullptr) {
				if(buffer == nullptr) {
					allocate();
				}
				for(int i = 0; i < size; i++)
					buffer[i] = right.buffer[i];
			}	
		}
		
		return this;
	}
	
	
	// Si aggiunge il distruttore
	~Buffer() {
		if(buffer != nullptr)
		// Se ho istanziato un array devo eliminarlo usado delete[] 
			delete[] buffer;
	}
	// Il resto della classe rimane invariato.
};


// Si riscrive con l'idioma RAII
class Buffer {
public:
	// Nel costruttore inizializzo il buffer per via dell'idioma RAII
	Buffer(int size) : size(size) {allocate();}
	
	void allocate() {
		// Per creare un array grezzo con gli unique_ptr devo usare nel tipo <type[]>
		// Ad esempio se fosse un array di interi avrei std::unique_ptr<int[]> 
		// Ricordarsi che la funzione std::make_unique si usa come sotto. Passo come argomenti
		// Gli argomenti che avrei passato all'oggetto che sto cercando di creare
		buffer = std::make_unique<char[]>(size);
	}		
	
	// Non serve più creare un distruttore
	// Serve comunque creare il costruttore di copia
	Buffer(const Buffer& original) {
		size = original.size;
		
		allocate();
		
		for(int i = 0; i < size; i++){
			buffer[i] = original.buffer[i];
		} 
	}
	
	// L'operatore di assegnazione restituisce un riferimento all'oggetto
	// this è un puntatore. Mentre Right è un riferimento. Se voglio paragonarli devo usare l'operatore * 
	// per analizzare l'indirizzo del puntatore
	Buffer& operator=(const Buffer& right) {
		if(this != &right){
			this->size = buffer.size;
			for(int i = 0; i < size; i++)
				buffer[i] = right.buffer[i];	
		}
		
		// Devo ritornare un riferimento. Essendo this un puntatore devo usare *puntatore.
		return *this;
	}
	
	
private:
	std::unique_ptr<char[]> buffer;
	int size;
}


// Utilizzo nella classe Main
#import "Buffer.h"

int main() {
	int s = 0;
	char c;
	
	cout << "Inserisci un valore: " << endl;
	cin >> s;
	
	Buffer buff(s);
	
	for(int i = 0; i < s; i++){
		cout << "Inserisci un carattere: ";
		cin >> c;
		
		buff.setCharAt(i, c);
		
	}
	
	return 0;
}





