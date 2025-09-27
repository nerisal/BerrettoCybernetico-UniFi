# Definizioni
## Topologia
### Insieme:
Un insieme si dice:
- **Aperto** se i punti di bordo non fanno parte dell'insieme. Ad esempio l'insieme $B_{r}=\{|x-x_{0}|<r\}$
- **Chiuso** se i punti di bordo fanno parte dell'insieme.

>[!note]
>Un insieme può essere né aperto e né chiuso come si vede da questo esempio: $$E=\{(x,y) \in \mathbb{R}^2:x^2+y^2\leq 1\text{ e }y<x^2\}$$

- **Limitato** se posso definire una sfera di raggio finito che contiene l'intero insieme. 
### Punti di un sottoinsieme:
Considerato il sottoinsieme $E$ di $\mathbb{R}^n$ e un punto $x_{0} \in \mathbb{R}$ si dice:
- **Interno** a $E$ se esiste un intorno sferico di $x_{0}$ interamente contenuto in $E$. Ovvero è possibile considerare un intorno di quel punto che non esce dai confini dell'insieme
- **Esterno** a $E$ se esiste un intorno sferico di $x_{0}$ interamente contenuto in $E^c$. Ovvero è possibile considerare un intorno di quel punto che rimane esterno ad E (Ovvero è interno al complementare di E).
- **Frontiera** se, preso un qualsiasi intorno sferico di $x_{0}$, è inevitabile prendere sia punti esterni che interni ad $E$. Il punto $x_{0}$ che è di frontiera può appartenere oppure no a $E$. Dipende se $E$ è un insieme aperto (i punti di bordo *non* fanno parte dell'insieme) o un insieme chiuso (i punti di bordo fanno parte dell'insieme) ovvero 

Dato un insieme solo una di queste tre condizione può verificarsi.
### Connesso per archi:
Un insieme si dice connesso per archi se, per ogni coppia di punti $x, y \in E$, esiste un arco di curva continuo contenuto in $E$ che ha per estremi $x$ e $y$. Ovvero $E$ è composto da un pezzo solo.

![[insieme_connesso_per_archi_grafico.png]]

### Insieme Cono
$A \subseteq \mathbb{R}^n$ è detto **cono** se è vero che: $$x \in A \implies tx \in A, \forall t >0$$

In altre parole il cono è un insieme che è chiuso rispetto alle dilatazioni positive dall'origine. Ovvero, se un punto appartiene al cono, allora anche tutta la semiretta che parte dall’origine e passa per quel punto appartiene al cono. Non è necessario che l'origine appartenga al cono.

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

>[!note] Derivate Parziali e Derivate Direzionali
>Si nota che le Derivate Parziali sono delle Particolari [[#Derivate Direzionali]] in cui il versore $v$ corrisponde con i versori canonici $e_{i}$

## Gradiente:
Definisco gradiente il vettore che ha per componenti le derivate parziali della funzione $f_{x_{0}}$ e si indica col simbolo $\nabla$ chiamato *Nabla*:
$$\nabla f(x_{0}, y_{0}) = (f_{x}(x_{0},y_{0}), f_{y}(x_{0},y_{0}))$$

## Funzione Derivabile:
Una funzione è detta derivabile in un punto $x_{0}$ se esistono tutte quante le sue derivate parziali in quel punto.

## Piano Tangente:
Per arrivare alla definizione di piano tangente si considera una funzione che si trova in $\mathbb{R}^3$. Se prendiamo questa funzione consideriamo le curve che si ottengono sezionando il grafico con due piani passanti da $x_{0}$ e $y_{0}$ si ottiene un punto di intersezione $$P=\begin{bmatrix}
x_{0} \\
y_{0} \\
f(x_{0},y_{0})
\end{bmatrix}$$
Ebbene, possiamo considerare le dure rette tangenti alle curve ottenute per sezionamento che sono:
$$r_{x} = \begin{cases}
z=f(x_{0},y_{0})+ \frac{\partial f}{\partial x}(x_{0},y_{0})(x-x_{0}) \\
y=y_{0}
\end{cases}$$
e
$$r_{y} = \begin{cases}
z=f(x_{0},y_{0})+ \frac{\partial f}{\partial y}(x_{0},y_{0})(y-y_{0}) \\
x=x_{0}
\end{cases}$$
sapendo che in $\mathbb{R}^3$ per due rette passa un unico piano, possiamo concludere che l'equazione del piano generato dalle due rette $r_{x}$ e $r_{y}$ è il piano di equazione:
$$z = f(x_{0},y_{0})+\frac{\partial f}{\partial x}(x_{0},y_{0})(x-x_{0})+\frac{\partial f}{\partial y}(x_{0},y_{0})(y-y_{0})$$
tale piano è passante per il punto $P$. 

![[piano_tangente_grafico.png]]

>[!important] Precisazione sul termine tangente
>Dalla sola condizione di derivabilità di $f(x,y)$ non c'è nessuna garanzia che il piano che si ottiene sia effettivamente tangente al grafico. Esiste infatti la possibilità che nel punto $P$, $f$ non sia continua. 
>L'equazione illustrata sopra ci restituisce il piano tangente solo a patto che questo esista. Per assicurarsi che un piano sia effettivamente tangente occorre introdurre il concetto di differenziabilità.

## Differenziabilità in due variabili
In $\mathbb{R}^2$ l'incremento della della funzione coincide con l'incremento della retta tangente più un infinitesimo. In più variabili si ha che l'incremento di $f$ è uguale all'incremento calcolato lungo il piano tangente con l'aggiunta di un infinitesimo (*o-piccolo* $o(h, k)$) di ordine superiore rispetto alla lunghezza dell'incremento delle variabili indimendenti.

$$\begin{align}
\overbrace{f(x_{0}+h,y_{0}+k)-f(x_{0},y_{0})}^{\text{1.}}=
\underbrace{\frac{\partial f}{\partial x}(x_{0},y_{0})h+\frac{\partial f}{\partial y}(x_{0},y_{0})k}_{\text{2.}}+
\overbrace{o(\sqrt{ h^2+k^{2 }})}^{\text{3.}} \\

\text{ con }(h,k)\to(0,0)
\end{align}$$
dove:
1. è l'incremento della funzione 
2. è l'incremento lungo il piano tangente, ovvero lungo le due rette che lo costituiscono
3. è l'errore definito da o piccolo. Dove per definizione vale: $\lim_{ (h,k) \to (0,0)} \frac{o(\sqrt{h^{2}+k^2 })}{\sqrt{ h^2+k^2 }}=0$

Se si verifica la condizione di differenziabilità in $x_{0},y_{0}$ allora la funzione è dette differenziabile in quei punti.

>[!note] Implicazioni #dimostrato
Considerata una funzione $f$ in un punto $P$ sappiamo che:
Se la funzione è *differenziabile* in quel punto allora è anche *derivabile* e *continua*.  
>Se è *continua* non è detto che sia né *differenziabile* né *derivabile*.  
>Se è *derivabile* (parzialmente, in $\mathbb{R}^n$) non è detto che sia *differenziabile* né *continua*.  
>In $\mathbb{R}$ invece, se è *derivabile* allora è automaticamente *continua*.
> $$\text{Differenziabilità} \implies \begin{matrix} \text{Continuità}\\ \text{Derivabilità}\end{matrix}$$

## Derivate Direzionali
Le derivate direzionali sono l'estensione del concetto di [[#Derivata Parziale]] alle altre direzioni. Le derivate parziali infatti misurano la velocità di variazione solo lungo gli assi. Mentre con il concetto di *derivata direzionale* si vuole analizzare la velocità di variazione anche per le altre direzioni.

Si consideri dunque che dato un versore qualsiasi $v$ posso considerare la direzione generica come: $$x = x_{0} +tv \text{ e l'incremento come } f(x_{0}+tv)-f(x_{0})$$Posso ora definire la derivata direzionale come il seguente limite: $$\frac{\partial f}{\partial v}(x_{0})=D_{v}f(x_{0})= \lim_{ t \to 0 } \frac{f(x_{0}+tv)-f(x_{0})}{t}$$ inoltre posso chiamare $f(x_{0}+tv) = g(t)$ e $f(x_{0})=g(0)$. Dunque la derivata parziale rispetto al versore $v$ è uguale alla derivata prima (in senso classico) della funzione $g(t)$. In linguaggio matematico: $$D_{v}f(x_{0})= g'(0)$$

>[!important] Proprietà delle derivate direzionali:
>1.  $f(x_{0}+tv) = g(t)$ e $f(x_{0})=g(0)$
>2. $v = e_{i} \quad e_{1}=(1,0)f_{x} \quad e_{2}=(0,1)f_{y}$
>3. $\frac{\partial f}{\partial (_-v)}(x_{0})=-\frac{\partial f}{\partial v}(x_{0})$. La derivata direzionale rispetto all'opposto del versore è uguale all'opposto della derivata direzionale rispetto al versore.
>4. Se $\boxed{n =1}$ allora $\begin{matrix}v=1 & D_{v}f(x_{0})=f'(x_{0}) \\ v = -1  & D_{v}f(x_{0})=-f'(x_{0})\end{matrix}$
>5. Se $\boxed{n = 2}$ allora $v = (\cos(\theta), \sin(\theta))$

## Derivate di Ordine Superiore al Primo
Il concetto è analogo a quello studiato in analisi I.
Si suppone che la funzione $f_{x}$ che esprime la derivata parziale di $f$ rispetto a $x$ sia anch'essa derivabile. Allora possiamo calcolare anche le derivate successive utilizzando quest notazione: $$\frac{\partial^2f}{\partial x^2}=\frac{\partial}{\partial x}\left(\frac{\partial f}{\partial x} \right) \text{ oppure con } \frac{\partial^2f}{\partial y \partial x}=\frac{\partial}{\partial y}\left(\frac{\partial f}{\partial x} \right)$$
analoga per le $y$.

### Derivate miste
Le derivate miste sono un particolare tipo di derivate di ordine superiore al primo. Si ottengono derivando una funzione a più variabili rispetto a una variabile dopo averla già derivata rispetto a un’altra variabile.  

In altre parole:  
- prima si calcola la derivata parziale rispetto a $x$ e poi quella rispetto a $y$:  
$f_{xy}(x,y) = \frac{\partial}{\partial y}\left(\frac{\partial f}{\partial x}(x,y)\right)$
- oppure prima rispetto a $y$ e poi rispetto a $x$:  
$f_{yx}(x,y) = \frac{\partial}{\partial x}\left(\frac{\partial f}{\partial y}(x,y)\right)$

Il [[#Teorema di Schwarz]] ci dice quando derivate miste opposte sono uguali.

## Funzioni Omogenee
Preso $A$ [[#Insieme Cono| cono]] di $\mathbb{R}^n$, $\alpha \in \mathbb{R}$. La funzione $f : A \to \mathbb{R}$ si dice omogenea di grado $\alpha$ su $A$: $$f(tx) = t^{\alpha} f(x) \quad \forall x \in A, \forall t >0$$
# Teoremi
## Teorema di Weierstrass
#non_dimostrato

**Enunciato:** Sia $E\subset \mathbb{R}^2$ un insieme chiuso e limitato e $f:E\to \mathbb{R}$ è continua. Allora $f$ ammette massimo e minimo in $E$, ossia esistono $x_{m}, x_{M}\in E$ tali che: $$f(x_{m})\leq f(x) \leq f(x_{M}) \text{ } \forall x \in E$$
Praticamente mi sta dicendo che se $f$ è una funzione continua e limitata in uno spazio allora è dotata di massimo e di minimo in quell'intervallo.

## Teorema degli Zeri
#non_dimostrato 

**Enunciato:** Sia $E$ un insieme connesso per archi in $\mathbb{R}^2$ e $f:E\to \mathbb{R}$ sia continua in $E$. Presi due punti $x \text{ e } y$ tali che $f(x) \cdot f(y)<0$ allora significa che esiste un punto $z$ in cui $f$ si annulla. Ovvero lungo l'arco che congiunge i due punti presi in considerazione, c'è un punto in cui l'arco si annulla. 

*Ricorda:* i punti sono in $\mathbb{R}^n$ dunque sono definiti da $n$ coordinate.

## Teorema del Differenziale Totale (Condizione Sufficiente)
#non_dimostrato 

**Enunciato:** Sia $f$ una funzione definita in $A \subseteq \mathbb{R}^{n}\to \mathbb{R}$, $A$ aperto e $x_{0} \in A$. Se le derivate parziali di $f$ esistono e sono continue in $x_{0}$ allora $f$ è *differenziabile* in $x_{0}$. Per estensione, se le derivate parziali della funzione esistono e sono continue in tutto $A$ allora anche $f$ è *differenziabile* in tutto $A$.

$$f \in C^{1}(A)\implies f \text{ differenziabile in } A$$
>[!note] Notazione
>$C^1(A)$ indica che le derivate parziali esistono e sono continue in $A$

## Teorema/Formula del Gradiente
#dimostrato 
**Enunciato:** Sia $f: A \to \mathbb{R}$, $A$ aperto e $f$ differenziabile in $x_{0} \in A$. Allora per ogni versore $v$ esiste la derivata direzionale $D_{v}f(x_{0})$ e vale l'identità: $$D_{v}f(x_{0})=\nabla f(x_{0})\cdot v=\sum^{n}_{i=1}\frac{\partial f}{\partial x_{i}}(x_{0})v_{i}$$
Per noi comuni mortali significa che, se sono verificate le condizioni del teorema, posso esprimere tutte le derivate direzionali come combinazione lineare delle derivate parziali. Ovvero le derivate direzionali sono uguali al prodotto scalare fra le derivate parziali e il versore.

**Corollario:** Un punto in cui il gradiente esiste ma è diverso da $(0,0)$ *non* può essere di massimo o di minimo locale. Infatti spostandosi di poco lungo la direzione del gradiente la funzione scala, vado nella direzione opposta la f scende. In altre parole il gradiente di f, essendo un vettore, indica sempre la direzione di massimo accrescimento. Dunque se andiamo nel verso opposto al gradiente andremo in direzione della minima derivata direzionale. Le derivate direzioni in direzione ortogonale al gradiente sono nulle.

## Teorema sul Calcolo delle Derivate
#non_dimostrato 
**Enunciato:** Date $f,g: \mathbb{R}^{n}\to \mathbb{R}$ e $\alpha, \beta\in \mathbb{R}$ costanti. Vale:
$$\begin{matrix}
\nabla (\alpha f+\beta g)=\alpha \nabla f+\beta \nabla g \\
\nabla (fg)=g\nabla f+f\nabla g \\
\nabla\left( \frac{f}{g} \right)=\frac{g\nabla f-f\nabla g}{g^2}
\end{matrix}$$
Queste formule sono analoghe a quelle dell'analisi I, solo che si usano i gradienti.

## Teorema della Derivazione di Funzioni Composte
#non_dimostrato 
Il teorema si divide in due parti:
**Enunciato 1:** Siano $f:A \subseteq \mathbb{R}^{n}\to \mathbb{R}$ e $g:I \subseteq \mathbb{R}^{n}\to \mathbb{R}$ e si suppone che esista una funzione $h(x)=g(f(x))$ e che questa sia definita in un intorno di $x_{0}$. Se la funzione $f$ è differenziabile in $x_{0}$ e $g$ è derivabile in $f(x)$. Allora la funzione composta $h = g \circ f$ è anch'essa differenziabile in $x_{0}$ e vale la stessa proprietà dell'analisi I: $$\nabla h(x_{0})= g'(f(x_{0}))\nabla f(x_{0}))$$
**Enunciato 2:** Siano $f:A \subseteq \mathbb{R}^{n}\to \mathbb{R}$ e $r:I \subseteq \mathbb{R}^{n}\to \mathbb{R}$ e si suppone che esista una funzione $g(t)=f(r(t))$ che sia definita in un intorno di $t_{0}$. Se $r$ è derivabile in $t_{0}$ e $f$ è differenziabile in $r(t_{0})$ allora la vale che la funzione composta è derivabile in $t_{0}$ e ho che: $$g'(t_{0})= \nabla f(r(t_{0})) \cdot r'(t_{0})=\sum^{n}_{i=1}{\frac{\partial f}{\partial x_{i}}(r(t_{0}))r'_{i}(t_{0})}$$
>[!note] Applicazioni del Teorema
>Il teorema può essere utilizzato per:
>- Calcolare il gradiente di una funzione radiale
>- Analizzare l'ortogonalità del gradiente con le curve di livello

## Teorema di Schwarz 
#non_dimostrato 
**Enunciato:** Se le derivate miste per certi indici, per un punto $x_{0}$ esistono e sono anche continue allora esse coincidono con $x_{0}$.

Ovvero: $$f_{xy}=f_{yx} \quad f_{yz}= f_{zy} \quad \dots$$

Questo teorema resta valido anche per funzioni che sono derivabili $3$ volte con derivate terze continue: $$f_{xxy}=f_{xyx}=f_{yyx}$$