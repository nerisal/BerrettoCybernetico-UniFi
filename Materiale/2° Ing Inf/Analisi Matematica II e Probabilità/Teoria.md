# Limiti per Funzioni in $\mathbb{R}^n$

Per definire il limite di funzione in $\mathbb{R}^n$ occorre prima definire il concetto di intorno in più dimensioni. 

Si definisce "palla" o più in generale *ipersfera* il luogo geometrico dei punti la cui distanza da un punto fissato $c$ è minore di $r$. Ovvero:
$$B_{r}(c) = {x \in \mathbb{R}^{n} : || x-c || < r }$$
dove la norma $|| x ||$ rappresenta la distanza e viene generalizzata con il valore assoluto.
In questo caso, essendo che la distanza non può essere uguale al raggio $r$, l'ipersfera si dice aperta. 
Equivarrebbe a:
- Un intervallo aperto in $\mathbb{R}^1$
- Un disco senza la circonferenza in $\mathbb{R}^2$
- Una sfera senza superficie in $\mathbb{R}^3$
-  etc...

In analisi II è difficile calcolare con precisione un limite. Quello che si può fare però è utilizzare dei criteri di esistenza per determinare se il limite c'è oppure no.
## Criterio di non esistenza del limite
Si sviluppa in due rami;
1. Se esiste una curva / cammino lungo la quale il limite di $f(x_{0})$ $\nexists$ allora il limite di $f(x_{0},y_{0})$ $\nexists$ 
2. Se esistono due curve / cammini lungo le quali i limiti di $f(x_{0})$ esistono ma sono diversi allora il limite di $f(x_{0},y_{0})$ $\nexists$

per restringersi ad una curva si prende $y = mx$ oppure $y = mx^2$ e così via. Quando si utilizza questo metodo è comodo partire prima dagli assi: $x = 0$ e $y = 0$ per poi passare alle bisettrici e così via. L'obiettivo è cercare di bilanciare gli esponenti delle x e delle y all'interno delle funzioni.

## Tecniche di Risoluzione
Per studiare la non esistenza di un limite si può cercare di semplificare la funzione arrivando nella forma $f(x)= g(h(x,y))$

Altrimenti, se la funzione lo permette si cerca di spezzare il limite in due e studiarle separatamente

Un altra tecnica per semplificare la funzione è utilizzare le coordinate polari, e passare, nei casi comodi in cui conviene applicare questo metodo, da una funzione in due variabili ad una in una sola variabile che è $\theta$. Conviene applicare questo metodo quando $x$ e $y$ hanno lo stesso grado. Si possono utilizzare le identità fondamentali della goniometria. 
$$\begin{cases}
x = \rho \cos \theta\\ \\
y = \rho \sin \theta
\end{cases}
$$
con $\rho = \sqrt{x^{2+y^{2}},} \tan \theta = \frac{y}{x}$

Si possono anche usare le maggiorazioni per poi usare il teorema del confronto (dei carabinieri) per capire come si comporta la funzione.

# Calcolo Differenziale
Si definisce derivata parziale, l'incremento di una funzione $f(x,y)$ una volta che si è fissato una della due variabili. Si usa il simbolo $\partial$ per indicare questa operazione. Ovvero: $$\frac{\partial f}{\partial f}(x_{0},y_{0})= \lim_{ h \to 0 } \frac{f(x_{0}+h,f_{0})-f(x_{0},y_{0})}{h}$$
Altre notazioni includono: 
$$\begin{align}
&f_{x} \quad \partial_{x}f \quad D_{x}f \quad D_{I}f
\end{align} \\
$$

Ad esempio se voglio fare la derivata parziale di $f_{x}$ rispetto ad $y$ utilizzerò la seguente notazione: $$\frac{\partial f}{\partial y}(x_{0}, y_{0})$$
Inoltre definisco gradiente il vettore che ha per componenti le derivate parziali della funzione $f_{x_{0}}$ e si indica col simbolo $\nabla$:
$$\nabla f(x_{0}, y_{0}) = (f_{x}(x_{0},y_{0}), f_{y}(x_{0},y_{0}))$$

In generale una funzione si dice differenziabile in $x_{0}$ se esiste $\alpha \in \mathbb{R} \quad t.c. \quad f(x_{0}+h) = f(x_{0}) + \alpha h + o(h)$

Da qui si ricava il teorema che ci dice che se una funzione $f$ è derivabile in $x_{0}$ allora è anche differenziabile in $x_{0}$ e viceversa.

Preso il concetto di derivata parziale possiamo dire che $f$ è derivabile in un punto $x_{0}$ se in quel punto esistono tutte quante le derivate parziali.

In analisi II non è vero che la derivabilità implica la continuità di una funzione e non implica neanche l'esistenza del piano tangente.

## Differenziabilità
Il differenziale di una funzione coincide con l'incremento calcolato lungo la retta tangente.

Sia $f: A \subseteq \mathbb{R}^{n}\to \mathbb{R}$ con $A$ aperto e sia $x_{0}\in A$. Allora si dice che $f$ è differenziabile in $x_{0}$ se $\exists$ un vettore $a\in \mathbb{R}^n$ tale che $$f(x_{0}+h)-f(x_{0})=ah + o(|h|) \quad per \quad h \to 0$$ 

Che in maniera più semplice diventa: Se $f$ è differenziabile in $x_{0}$ allora $f$ è anche derivabile in $x_{0}$ e il vettore $a$ che compare nella formula precedente è il *gradiente* di f calcolato in $x_{0}$: $$a = \nabla f(x_{0})$$$f$ è anche continua in $x_{0}$
  
Considerata la funzione $f(x)=f(x_{0})+\alpha(x-x_{0})+o(||x-x_{0}||)$ si ha che $f(x_{0})+\alpha(x-x_{0})$ definisce quello che è chiamato *iperpiano tangente*.

Si conclude che se $f$ è differenziabile in $x_{0}$ allora $f$ è derivabile e $\alpha = \nabla f(x_{0})$ e che $f$ è continua in $x_{0}$. **Questo teorema è stato dimostrato**

>[!important]
>La differenziabilità implica la continuità. Ma non è vero che la continuità implica la differenziabilità.
>
>E allo stesso modo. Non è vero che la derivabilità implica la differenziabilità
>
>**Ricordarsi dei controesempi da poter mostrare**

## Teorema del Differenziale Totale
Data $f:A\subseteq \mathbb{R}^2\to \mathbb{R}$ con $A$ aperto. Se è vero che le derivate parziali di f sono definite e sono anche continue in $A$ allora $f$ è differenziabile in A. Non vale il viceversa.

## Derivate Direzionali
Essenzialmente è l'estensione del concetto di derivata parziale anche ad altre rette che non siano gli assi e restituisce il tasso di incremento di $f$ in $v$ in $x_{0}$ 
La definizione è: $$\frac{\partial f}{\partial v} = D_{v}f(x_{0})= \lim_{ t \to \infty } \frac{f(x_{0}+tv)-f(x_{0})}{t}$$ purché questo limite esista finito.

Nota: geometricamente $D_{v}f(x_{0})$ rappresenta il tasso di variazione istantanea di f muovendosi da $x_{0}$ lungo la direzione unitaria di $v$
$$D_{v}^{\pm}f(x_{0}) = \lim_{ t \to 0^{\pm}}\frac{f(x_{0}+tv)-f(x_{0})}{t} $$

## Teorema del Gradiente
Sia $f:A\to \mathbb{R}$ con $A$ aperto. Sia inoltre $f$ differenziabile in $x_{0}$. Allora si sa che per ogni versore $v$ esiste la derivata direzionale $D_{v}f(x_{0})$ e inoltre vale l'identità: $$D_{v}f(x_{0}) = \nabla f(x_{0})\cdot v = \sum^{n}_{i=1}\frac{\partial f}{\partial x_{i}}(x_{0})v_{i}$$

Ovvero: la derivata direzionale è il prodotto scalare del gradiente con il versore direzione derivato. Tutte le derivate direzionali risultano combinazioni lineari delle derivate parziali.
**La formula del gradiente è stata dimostrata**

Un altro Teorema ci dice che se ho due funzioni f e g che sono derivabili allora ho delle proprietà lineari che valgono per i loro gradienti.


