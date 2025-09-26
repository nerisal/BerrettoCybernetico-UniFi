# Topologia
## Insieme:
Un insieme si dice:
- **Aperto** se i punti di bordo non fanno parte dell'insieme. Ad esempio l'insieme $B_{r}=\{|x-x_{0}|<r\}$
- **Chiuso** se i punti di bordo fanno parte dell'insieme.

>[!note]
>Un insieme può essere né aperto e né chiuso come si vede da questo esempio: $$E=\{(x,y) \in \mathbb{R}^2:x^2+y^2\leq 1\text{ e }y<x^2\}$$

- **Limitato** se posso definire una sfera di raggio finito che contiene l'intero insieme. 
## Punti di un sottoinsieme:
Considerato il sottoinsieme $E$ di $\mathbb{R}^n$ e un punto $x_{0} \in \mathbb{R}$ si dice:
- **Interno** a $E$ se esiste un intorno sferico di $x_{0}$ interamente contenuto in $E$. Ovvero è possibile considerare un intorno di quel punto che non esce dai confini dell'insieme
- **Esterno** a $E$ se esiste un intorno sferico di $x_{0}$ interamente contenuto in $E^c$. Ovvero è possibile considerare un intorno di quel punto che rimane esterno ad E (Ovvero è interno al complementare di E).
- **Frontiera** se, preso un qualsiasi intorno sferico di $x_{0}$, è inevitabile prendere sia punti esterni che interni ad $E$. Il punto $x_{0}$ che è di frontiera può appartenere oppure no a $E$. Dipende se $E$ è un insieme aperto (i punti di bordo *non* fanno parte dell'insieme) o un insieme chiuso (i punti di bordo fanno parte dell'insieme) ovvero 

Dato un insieme solo una di queste tre condizione può verificarsi.21

## Connesso per archi:
Un insieme si dice connesso per archi se, per ogni coppia di punti $x, y \in E$, esiste un arco di curva continuo contenuto in $E$ che ha per estremi $x$ e $y$. Ovvero $E$ è composto da un pezzo solo.

![[insieme_connesso_per_archi_grafico.png]]

## Derivata Parziale:
Non posso definire l'incremento simultaneo di due variabili per una funzione a più variabili. Per ovviare a questo problema, fisso una delle due variabili ed incremento l'altra. 

Si definisce derivata parziale, l'incremento di una funzione $f(x,y)$ una volta che si è fissato una della due variabili. Si usa il simbolo $\partial$ per indicare questa operazione. 

Ad esempio la derivata parziale di $f$ rispetto alla variabile $x$ si scrive come: $$\frac{\partial f}{\partial x}(x_{0},y_{0})= \lim_{ h \to 0 } \frac{f(x_{0}+h,y_{0})-f(x_{0},y_{0})}{h}$$
mentre rispetto alla variabile $y$:
$$\frac{\partial f}{\partial y}(x_{0},y_{0})= \lim_{ k \to 0 } \frac{f(x_{0},y_{0}+k)-f(x_{0},y_{0})}{k}$$

In $\mathbb{R}^n$ con $n\geq 3$ cambio la notazione per le derivate ma il concetto rimane il medesimo.

Altre notazioni includono: 
$$\begin{align}
&f_{x} \quad \partial_{x}f \quad D_{x}f \quad D_{I}f
\end{align} \\
$$


## Gradiente:
Definisco gradiente il vettore che ha per componenti le derivate parziali della funzione $f_{x_{0}}$ e si indica col simbolo $\nabla$ chiamato *Nabla*:
$$\nabla f(x_{0}, y_{0}) = (f_{x}(x_{0},y_{0}), f_{y}(x_{0},y_{0}))$$

## Funzione Derivabile:
Una funzione è detta derivabile in un punto $x_{0}$ se esistono tutte quante le sue derivate parziali in quel punto.

## Piano Tangente:


# Teoremi
## Teorema di Weierstrass
#non_dimostrato

**Enunciato:** Sia $E\subset \mathbb{R}^2$ un insieme chiuso e limitato e $f:E\to \mathbb{R}$ è continua. Allora $f$ ammette massimo e minimo in $E$, ossia esistono $x_{m}, x_{M}\in E$ tali che: $$f(x_{m})\leq f(x) \leq f(x_{M}) \text{ } \forall x \in E$$
Praticamente mi sta dicendo che se $f$ è una funzione continua e limitata in uno spazio allora è dotata di massimo e di minimo in quell'intervallo.

## Teorema degli Zeri
#non_dimostrato 
**Enunciato:** Sia $E$ un insieme connesso per archi in $\mathbb{R}^2$ e $f:E\to \mathbb{R}$ sia continua in $E$. Presi due punti $x \text{ e } y$ tali che $f(x) \cdot f(y)<0$ allora significa che esiste un punto $z$ in cui $f$ si annulla. Ovvero lungo l'arco che congiunge i due punti presi in considerazione, c'è un punto in cui l'arco si annulla. 

*Ricorda:* i punti sono in $\mathbb{R}^n$ dunque sono definiti da $n$ coordinate.


prova