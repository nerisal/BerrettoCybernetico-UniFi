
# 1.
Funzione che riceve da tastiera valori interi fino a quando il prodotto degli ultimi due valori inseriti non è uguale al valore del terz'ultimo valore inserito.

```c
#include <stdio.h>

int main() { 

int primo;
int secondo;
int terzo;
int prodotto;



printf("Inserisci il primo valore: ");
scanf("%d", &primo);
printf("Inserisci il secondo valore: ");
scanf("%d", &secondo);
printf("Inserisci il terzo valore: ");
scanf("%d", &terzo);

while(0 < 1) {
	
	if((terzo * secondo) == primo) {
		printf("Il prodotto fra gli ultimi due è uguale al terz'ultimo inserito");
		break;
	} else {
		int tmp;
		printf("Inserisci un nuovo valore: ");
		scanf("%d", &tmp);

		primo = secondo;
		secondo = terzo;
		terzo = tmp;
	}
}

return 0;
}
```



Nella soluzione 1 si utilizza un array di N elementi come memoria degli ultimi N valori inseriti 

```c

// Va scritto il prototipo della funzione
void function(int N){
	int value;
	int count;
	int *V;
	
	V = (int *) malloc(sizeof(int) * N);

	// Con questo ciclo si inizializza un array che contiene i primi 3 valori iniziali.
	for(count = 0; count < N - 1; count++){
		printf("\nInserisci valore: ");
		scanf("%d", &V[count]); // Questo ciclo legge i primi N - 1 valori dell'array
	}

	do {
		printf("\nInserisci valore: ");
		scanf("\d", &V[count]);
		
		// Molto importante!!
		count = (count + 1) % N; // Questo si usa per avere una circolarità all'interno dell'array
		
		
	}while(!is_costant(V, N));
}

bool is_costant(int * V, int N){
	bool sum;
	
	for(int count = 0; count < N; count++){
		sum = &V[count] == &V[count + 1];
	}

return sum;
}
```
