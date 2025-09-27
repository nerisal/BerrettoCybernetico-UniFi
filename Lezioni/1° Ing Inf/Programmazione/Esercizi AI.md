Ecco una serie di esercizi che riguardano l'uso dei container STL (`list`, `vector`, `array`, `map`, `unordered_map`) in C++, con diversi livelli di difficoltà e applicazioni pratiche:

---

### **1. Gestione di una Biblioteca (Usando `vector` e `map`)**
Implementa una classe `Library` che gestisce una collezione di `Book`.  
- Ogni `Book` ha un **titolo**, un **autore**, un **anno di pubblicazione** e un **ID univoco**.  
- La `Library` deve:  
  - Aggiungere/rimuovere libri (`addBook`, `removeBook`).  
  - Cercare libri per titolo, autore o ID (`findByTitle`, `findByAuthor`, `findById`).  
  - Ordinare i libri per anno di pubblicazione (`sortByYear`).  
- Usa un `vector` per memorizzare i libri e una `map` (o `unordered_map`) per indicizzare i libri per ID.  
*(Punti: 8)*  

---

### **2. Sistema di Prenotazione (Usando `unordered_map` e `list`)**
Crea una classe `Restaurant` che gestisce prenotazioni:  
- Ogni `Reservation` ha **nome cliente**, **orario**, **numero di persone**.  
- Il ristorante ha un numero massimo di posti (`maxSeats`).  
- Implementa:  
  - `addReservation`: Aggiunge una prenotazione (controllando i posti disponibili).  
  - `cancelReservation`: Rimuove una prenotazione per nome.  
  - `listReservations`: Stampa le prenotazioni in ordine cronologico.  
- Usa una `unordered_map` per cercare prenotazioni per nome e una `list` per mantenerle ordinate per orario.  
*(Punti: 7)*  

---

### **3. Gestione di un Torneo (Usando `vector` e `array`)**
Implementa una classe `Tournament` che simula un torneo a round-robin:  
- Ogni `Player` ha un **nome** e un **punteggio**.  
- Il torneo ha un numero fisso di giocatori (es. 8, usare `array`).  
- I giocatori si affrontano in round consecutivi:  
  - Dopo ogni round, i punteggi vengono aggiornati.  
  - Implementa `playRound` e `getRankings` (ordina i giocatori per punteggio).  
- Usa un `array` per i giocatori e un `vector` per tenere traccia delle partite giocate.  
*(Punti: 9)*  

---

### **4. Rubrica Telefonica (Usando `map` e `list`)**
Crea una classe `AddressBook` che gestisce contatti:  
- Ogni `Contact` ha **nome**, **cognome**, **numero di telefono** e **email**.  
- La rubrica deve:  
  - Aggiungere/rimuovere contatti (`addContact`, `removeContact`).  
  - Cercare per nome/cognome (`findContact`).  
  - Mostrare i contatti in ordine alfabetico (`listAll`).  
- Usa una `map` per indicizzare i contatti per cognome e una `list` per mantenerli ordinati.  
*(Punti: 6)*  

---

### **5. Sistema di Logging (Usando `vector` e `deque`)**
Implementa una classe `Logger` che registra messaggi con timestamp:  
- Ogni `LogEntry` ha **messaggio**, **livello di gravità** (INFO, WARNING, ERROR), e **timestamp**.  
- Il logger deve:  
  - Aggiungere messaggi (`logMessage`).  
  - Mostrare i messaggi più recenti (`getLastLogs`).  
  - Filtrare per livello (`filterByLevel`).  
- Usa un `vector` per memorizzare tutti i log e un `deque` per i messaggi recenti (limite: 100).  
*(Punti: 5)*  

---

### **6. Gestione di un Magazzino (Usando `map` e `vector`)**
Crea una classe `Warehouse` che tiene traccia di prodotti:  
- Ogni `Product` ha **ID**, **nome**, **quantità** e **prezzo**.  
- Il magazzino deve:  
  - Aggiungere/rimuovere prodotti (`addProduct`, `removeProduct`).  
  - Cercare per ID o nome (`findProduct`).  
  - Generare un report ordinato per quantità disponibile (`generateReport`).  
- Usa una `map` per l’accesso rapido per ID e un `vector` per i report ordinati.  
*(Punti: 10)*  

---

### **7. Simulazione di una Coda di Messaggi (Usando `queue` e `priority_queue`)**
Estensione: Usa `list` per implementare una coda personalizzata.  
- Crea una classe `MessageQueue` che gestisce messaggi con priorità:  
  - Ogni `Message` ha **contenuto** e **priorità** (ALTA, MEDIA, BASSA).  
  - La coda deve:  
    - Inserire messaggi (`push`).  
    - Estrarre il messaggio più prioritario (`pop`).  
    - Controllare se la coda è vuota (`isEmpty`).  
- Usa una `priority_queue` (o una `list` con ordinamento manuale).  
*(Punti: 6)*  

---

Ogni esercizio può essere adattato per focalizzarsi su specifici container (es. richiedendo esplicitamente `list` invece di `vector`). Vuoi anche le soluzioni o varianti più complesse?