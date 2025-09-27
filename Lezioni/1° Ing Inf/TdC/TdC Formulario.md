# Relazioni Costitutive
## Resistore
**Legge di Ohm**: La legge di Ohm è la relazione costitutiva di un resistore. 
$$v = Ri$$
Il resistore è un elemento lineare.
La resistenza $R$ si può esprimere anche come: $$R = \rho \frac{ l}{A}$$ Dove $\rho$ è una costante di resistenza elettrica dipendente dal materiale. $l$ è la lunghezza del filo e $A$ è l'area della sezione del filo.

Invece che usare la *Resistenza* è possibile utilizzare la *Conduttanza* indicata con la lettera $G$ e definita come $\frac{1}{R}$. L'unità di misura della conduttanza è il Siemen *\[S]*
Ovvero si ottiene la legge di Ohm: $$i = \frac{1}{R} v = Gv$$
Il resistore è un elemento passivo perché non può mai rilasciare energia nel sistema ma solamente assorbirla. Questo si può vedere dalla potenza, che sarà sempre negativa.

## Connessioni in Serie e in Parallelo
### Resistori:
Se ho dei resistori connessi in serie la resistenza equivalente è uguale alla somma di tutte le resistenze. Se ho dei resistori in parallelo la resistenza equivalente è uguale alla somma di tutte le conduttanze.

### Generatori:
**Per i generatori di tensione:** Se sono in *serie* allora la tensione generata è uguale alla somma di tutti i singoli generatori di tensione. 

**Per i generatori di corrente:** Se sono in *parallelo* allora la tensione generata è uguale alla somma di tutti i singoli generatori di corrente.

Se parliamo di generatori ideali allora per far valere la legge di Kirchhoff deve essere che non possono esistere due generatori di tensione ideali con valori diversi posizionati in parallelo. Non possono esistere due generatori ideali di corrente con valori diversi posizionati in serie. 
Se invece i generatori (di tensione o di corrente) sono ideali (ovvero possiedono un resistore interno) allora possono essere collegati in qualsiasi modo a prescindere dal valore.

## Analisi Nodale
| Analisi Nodale - Algoritmo 1                                                                              |
| --------------------------------------------------------------------------------------------------------- |
| 1. Si sceglie un nodo qualsiasi che fungerà da riferimento                                                |
| 2. Si applica la Legge di Kirchhoff per le Correnti a tutti i nodi tranne che a quello scelto in partenza |
| 3. Si esprimono tutte le correnti dei resistori in funzione delle tensioni di nodo.                       |
