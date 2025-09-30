# Floating e Precisione
Gli errori generalmente possono essere di due tipi:
**Errori di Arrotondamento:** quando si ha una precisione finita
**Errori di Approssimazione:** quando si hanno degli errori per discretizzazione oppure errori di troncamento.

La rappresentazione numerica spesso avviene tramite l'utilizzo della notazione detta "A virgola mobile normalizzata". Questa notazione è definita da *m* cifre riservate alla mantissa ovvero l'insieme numerico $a_{n}$, dalla base di numerazione (decimale, esadecimale, binaria, etc) e dalla caratteristica ovvero l'esponente della base che determina l'ordine di grandezza. Un numero in virgola mobile ha le seguenti caratteristiche: $$\pm a_{0}.a_{1}a_{2}\dots a_{m}a_{m+1}\dots{\beta}^{\pm c} \; con\; a_{0}\neq 0$$
Data un qualsiasi calcolatore, avrò una certa precisione finita. Ad esempio avrò un limite sulla caratteristica ovvero sull'ordine di grandezza. Ad esempio, se la mia caratteristica è $c=1$ allora vorrà dire che il mio esponente $\in [-9, 9]$. Dunque dico che se ho **UNDERFLOW** se ho un numero con ordine di grandezza $<-9$, ad esempio $-10 \;oppure -40$. Mentre dirò che ho un **OVERFLOW** se l'ordine di grandezza è $> 9$ ad esempio $10 \; oppure\;  50$

I numeri di macchina sono tutti quei numeri che possono essere rappresentati perfettamente (senza nessun troncamento o arrotondamento) all'interno di un dato calcolatore.

La precisione di macchina è definita come l'errore relativo che dato un numero "vero" e la sua rappresentazione di macchina (floating) si commette. Dunque per definizione $$
\epsilon_{m} = \frac{|x - \mathrm{fl}(x)|}{|x|} = 
\begin{cases}
\frac{1}{2} \beta^{1 - m} & \text{se opero per arrotondamento} \\
\beta^{1 - m} & \text{se opero per troncamento}
\end{cases} \;, \forall x\neq 0$$
Nel calcolo con l'aritmetica finita non valgono sempre la proprietà associativa e distributiva. Questo perché sommare (o fare qualsiasi altra operazione) un numero molto piccolo con uno molto più grande quando abbiamo una limitazione sulla rappresentazione, rischia di rendere il numero con l'ordine di grandezza più piccolo meno non apprezzabile. Per questo le operazioni fra numeri in aritmetica finita vengono svolti dando la precedenza ai numeri con la precisione più piccola.  

# Risoluzione di sistemi
**Scomposizione nella Matrice LU:** una matrice A è scomponibile nel prodotto fra matrice L (triangolare inferiore) e la matrice U (triangolare superiore) se $\det(A_{k})\neq 0 \; \forall k=1:n$. Ovvero tutti i determinanti delle sottomatrici da 1 a n non sono nulli. 

L è la matrice triangolare inferiore che ha 1 sulla diagonale e sotto tutti i moltiplicatori che annullano quell'elemento nei passaggi del metodo di Gauss. La matrice U invece è quella matrice triangolare superiore che per elementi gli stessi elementi di A nelle stesse posizioni diverse da O.

# Interpolazione

Quando si fa interpolazione:
- L'interpolazione si fa quando so che i miei dati non sono effetti da errore
- Quando il numero di punti non è troppo grande

Dati $\{(x_{i}, y_{i})\}_{i=0}^n$ punti ovvero $n+1$ punti. Si ha che è detto *polinomio interpolante* quel polinomio $p(x)$ di grado *al più* $n$, ovvero di $grado(p(x))\leq n$, tale che: $$p(x_{i}) = y_{i} \forall i=0:n $$
Inoltre dati una serie di coppie di punti, l'esistenza del polinomio interpolante è data dal fatto che l'insieme delle ascisse dei punti è distinto. Ovvero $\{x_{0},x_{1},\dots,x_{n}\}$$$x_{i}\neq x_{j} \quad \forall i\neq j$$
## Metodi Monomiale
Si usa la **Base monomiale:** $\{1,x,x^2,\dots,x^n\}$
Dunque il polinomio che stiamo cercando sarà nella forma:
$p(x)=\sum_{i=0}^{n} a_{i}x^{i} \implies a_{0}+a_{1}x_{1}+a_{2}x^2+\dots a_{n}x^n$
Lo svantaggio di questo metodo è che bisogna risolvere n equazioni in n incognite, che potrebbe essere mal condizionato.


## Metodo di Newton
**Base di Newton:** $\{1, (x-x_{0}), (x-x_{0})(x-x_{1}),\dots,(x-x_{0})(x-x_{1})\dots(x-x_{n})\}$
Dunque il polinomio che stiamo cercando sarà nella forma:
$p(x)= a_{0}+a_{1}(x-x_{0})+a_{2}(x-x_{0})(x-x_{1})+\dots+a_{n}(x-x_{0})(x-x_{1})\dots(x-x_{n})$

Il vantaggio di questo metodo è che è facile aggiungere un punto. Infatti nella tavola delle differenze divise è sufficiente aggiungere un nuovo punto in fondo e svolgere i nuovi calcoli in più. Ciò che ho fatto prima però resta valido.


## Metodo di Lagrange
**Base di Lagrange:** $\{l_{0}(x), l_{1}(x),\dots ,l_{n}(x)\}$.
Dove $l_{i}(x_{j})$ è un polinomio tale che è uguale a zero se $i\neq j$. Ed è uguale a 1 se $i=j$
Dunque si ha che $p(x_{i})=l_{i}(x)y_{i}$ e che 
$$\begin{cases}
p(x_{0})=y_{0}=a_{0}l_{0}(x_{0}) = a_{0} \\
p(x_{1})=y_{1}=a_{1}l_{1}(x_{1}) = a_{1} \\
\vdots \\
p(x_{n})=y_{n}=a_{n}l_{n}(x_{n}) = a_{n}
\end{cases}$$
e in fine si sa che 
$$
l_{i}(x)=\frac{
  \prod_{j \ne i} (x - x_j)
}{
  \prod_{j \ne i} (x_i - x_j)
}
$$
Il metodo di Lagrange è vantaggioso perché due insiemi di punti che hanno le stesse ascisse hanno stessi polinomi in base di Lagrange. Inoltre se la $f(x_{i})=0$ non bisogna calcolare il polinomio di Lagrange in quel punto. Non consente di aggiungere punti facilmente.

# Approssimazione
Dato un generico polinomio di grado m e un insieme finito di punti, si definisce vettore dei residui:
$$E=
\begin{pmatrix}
    y_{0}- p(x_{0})\\
    y_{1}-p(x_{1} ) \\
\vdots \\
y_{n}-p(x_{n})
\end{pmatrix}

$$
Ovvero la differenza di quota fra l'ordinata del punto e il valore assunto dal mio polinomio in quel punto. 
Dato questo vettore io posso trovare la norma in vari modi. Norma 1, Norma Infinito e Norma 2.

Risolvere il problema nel senso dei minimi quadrati significa trovare quei coefficienti $a_{i}$ tale che la **Norma Due al Quadrato di E sia minima**. Si fa risolvendo il sistema:
$$M^{T} M z = M^{T}b$$ dove z è il vettore dei coefficienti.

# Norme Vettoriali:

Dato un vettore $V = [x_{0}, x_{1},\dots ,x_{n}]$ si ha che:
**La norma 1:** somma degli elementi ognuno in valore assoluto
**La norma $_{\infty}$:** massimo degli elementi di V in valore assoluto
**La norma 2:** Radice quadrata della somma degli elementi al quadrato.

# Norme Matriciali:
Data una matrice M
**Norma 2:** formula complicata che include gli autovettori. $\sqrt{max |\lambda M^TM|}$. Non penso che si userà.
**Norma$_{\infty}$:** massimo della somma dei singoli elementi in valore assoluto su una singola *riga*
**Norma 1:** massimo della somma dei singoli elementi in valore assoluto su una singola *colonna*

# Formula di Quadratura
Data la funzione $\int_{a}^{b}f(x)dx$
## Semplici:
Si approssima un intero integrale su un intervallo (a, b)
**Formula del punto medio:** si approssima l'integrale con l'area sotto al grafico nel punto medio. $$I_{M}=(b-a)f\left( \frac{a+b}{2} \right)$$ **Formula dei trapezi:** Si approssima l'integrale con il trapezio costruito sugli estremi dell'intervallo. La sua formula è: $$I_{T}=\frac{b-a}{2}(f(a)+f(b))$$
**Formula di Simpson:** si approssima la funzione con la parabola passante per i due estremi. La formula sarà:
$$I_{S}= \frac{b-a}{6}\left( f(a)+f(b)+4f\left( \frac{a+b}{2} \right) \right)$$
Di tutte queste formule esiste una variante detta **composita**. Nelle formule di quadratura composite si considera l'intervallo \[a,b] diviso in n sottointervalli di uguale estensione e si applica la formula in ognuno di quei punti.

## Formule di Quadrature Composite
**Quadratura Composita dei Trapezi:** $$I_{T,m} = \frac{b-a}{2m}\left(  f(x_{0})+f(x_{m})+\sum_{i=1}^{m-1}f(x_{i})  \right)$$
**Quadratura Compsita di Simpson:** $$I_{S,m}=\frac{b-a}{6m}\left( f(x_{0})+f(x_{2m})+4\sum_{i=1}^{m}f(x_{2i-1}) + 2\sum_{i=1}^{m-1}f(x_{2i})\right)$$

## Formule degli errori:
Esistono infine delle formule per determinare l'errore che si commette. Il problema è che queste formule dipendo da dei parametri: $\tau, \sigma,\zeta$ che non sono solitamente note:

- Punto medio: $R_{0}= \frac{1}{3}f^{II}(\sigma)\left( \frac{b-a}{2} \right)^2$
- Trapezi: $R_{1}=-\frac{1}{12}f^{II}(\tau)(b-a)^3$
- Simpson: $R_{2}=-\frac{1}{90}f^{IV}(\zeta)\left( \frac{b-a}{2} \right)^5$

# Equazioni non Lineari
Le equazioni non lineari sono tutte quelle equazioni che non hanno un metodo diretto di calcolare la soluzione. Si procede dunque per interazione e approssimazione.

Per trovare una soluzione di un'equazione non lineare si usano dei metodi iterativi che generano una successione che se è convergente portano a trovare una soluzione x*.

**Tipi di convergenza:** la convergenza di una soluzione può essere:
- globale se la scelta della $x_{0}$ iniziale non determina la convergenza della serie
- locale se la scelta della $x_{0}$ iniziale può o meno determinare la convergenza o divergenza della serie.

**Criteri di arresto:** 
Idealmente un processo iterativo può ripetersi fino a trovare una soluzione esatta. Ma nella realtà questo non è possibile. Occorre dunque definire dei criteri d'arresto per poter definire correttamente un algoritmo.
**I criteri di arresto più comuni sono:**
- Numero limite di iterazioni: mi fermo dopo che $k < kMax$. Questo garantisce che l'algoritmo si interrompa anche in caso di divergenza.
- Tolleranza assoluta: definisco quanto mi sono avvicinato alla soluzione (errore) in termini assoluti. Quando l'errore diventa più piccolo di una tolleranza che ho deciso mi accontento e mi fermo.
- Tolleranza relativa: definisco quanto mi sono avvicinato alla soluzione in termini relativi. 
- Tolleranza mista: a metà fra l'errore assoluto e quello relativo. Questa tolleranza mista è simile a quella assoluta in un intorno piccolo, mentre somiglia a quella relativa in un intervallo grande.