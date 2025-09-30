# Logica

I connettivi logici sono la **negazione (non)**, **congiunzione (e)**, **disgiunzione (o)**, **implicazione (=>)**, **doppia implicazione (<=>)**. 

Effettuare la contronominale di una proposizione significa trovare la sua contropositiva. Ad esempio: "Piove implica che la strada è bagnata" la contronominale è "Se la strada non è bagnata allora non piove." Si noti come si è effettuato lo scambio in termini di ordine della proposizione. 

Per fare la contronominale si negano prima gli addendi e poi si scambiano. Da notare che la negazione del "Per ogni" è Esiste e la negazione del "Esiste" è il "Per Ogni".

Fare l'implicazione significa che "Se la prima è vera allora anche la seconda lo è. Se la prima è falsa, della seconda non mi interessa". La doppia implicazione invece vuole che entrambe abbiano lo stesso valore. 

# Funzioni ad una variabile

**Iniettiva:** una funzione si dice iniettiva se ad ogni elemento $x \in X$ corrispondono diverse immagini.

**Suriettiva**: una funzione si dice suriettiva se $\forall y \in Y \exists x \in X: f(x) = y$
**Biunivoca o Biettiva:** se è sia Iniettiva che Suriettiva

## Monotonia
Una funzione si dice monotona se è monotona crescente o decrescente. 
- Si dice crescente se dato x1 >= x2, f(x1) >= f(x2) per ogni x
- Si dice decrescente se dato x1 <= x2, f(x1) <= f(x2) per ogni coppia di x

Una funzione si dice strettamente monotona crescente o decrescente se si esclude il caso di uguaglianza dalla monotonia generale.

Una funzione che è strettamente crescente o decrescente è invertibile.

## Funzione Limitata
Una funzione si dice limitata superiormente se Esiste M finito >= di f(x) per ogni x appartenente al suo dominio. In tal caso M è detto maggiorante di A.

Una funzione si dice limitata inferiormente se Esiste m finito <= di f(x) per ogni x appartenente al suo dominio. in tal caso m è detto minorante di A.

In generale una funzione si dice limitata se è sia superiormente che inferiormente limitata.

A differenze del maggiorante, il massimo di una funzione è un valore che è sia un maggiorante che un punto appartenente all funzione. (siamo nel caso limite M = f(x)), 

# Calcolo Differenziale
Una funzione f(x) si dice derivabile in un punto se esiste $$\\lim_{ h \to 0} \frac{f(x_{0}+h) -f(x)}{h}$$ che con la sostituzione $x = x+h$ diventa $$\\lim_{ x \to x_{0}} \frac{f(x) -f(x_{0})}{x-x_{0}}$$

Il significato geometrico del rapporto incrementale è quello del coefficiente angolare dunque, l'equazione della retta tangente ad una funzione f(x) in un punto x0 è:
$$y = f(x) +f(x_{0})(x-x_{0})$$


# Funzioni Concave e Convesse

Una funzione è detta concava se il suo sopragrafico (insieme di punti dello spazio che si trovano sopra al grafico) è un insieme concavo di punti. Ovvero, presi qualsiasi coppia di punti di questo spazio, la corda che gli unisce rimane all'interno del grafico.
Una funzione si dice concava se il suo sopragrafico è un insieme concavo. Ovvero esiste almeno una corda che unisce da una coppia di punti del sopragrafico che è esterna a tale spazio.
Esistono funzioni che non sono né concave né convesse. Ad esempio una qualsiasi funzione che al suo interno contiene una cuspide o un flesso a tangente verticale.

Una funzione è detta strettamente crescente se il suo grafico non ha alcuna linea spezzata.

**Relazione con le derivate:** dove una funzione è concava -> la derivata prima è decresente -> la derivata seconda è < 0

dove una funzione è convessa -> la derivata prima è crescente -> la derivata seconda è > 0. 

Dove la funzione cambia concavità la derivata seconda è = 0. 

# Teorema di de l'Hopital
Non va saputo dimostrare ma è importante ricordarsi i contesti in cui può essere applicato:
- Il limite deve essere $\frac{0}{0} \lor \frac{\infty}{\infty}$
- La funzione di partenza deve essere nella forma $\frac{f(x)}{g(x)}$
- deve essere $g(x)\neq 0$
- deve esistere il limite $\frac{f'(x)}{g'(x)}$

Se queste condizioni sono verificate allora il limite di f(x)/g(x) = f'(x)/g'(x)

# Approssimazione Polinomiale
Consiste nell'approssimare una funzione ad un polinomio per un intorno sufficientemente stretto di un punto. Abbiamo già visto come la tangente di una funzione in punto approssima correttamente la funzione stessa per un intorno di quel punto. 

Definizione di o-piccolo: se $f(x) = o(g(x))$ significa che f(x) è un infinitesimo di ordine più piccolo di g(x). La notazione di o-piccolo ha senso solo quando si parla di infinitesimi. Anche perché abbiamo definito l'o-piccolo come l'errore di approssimazione che si commette quando si approssima una funzione complessa con quella di un polinomio. $\epsilon(x - x_{0})$ che appunto tende a zero man mano che x si avvicina a x0.

In generale o(x) va a 0 più velocemente di x. Questo perché per definizione f(x) = o(g(x)) significa che $$\lim_{ x \to 0 }\frac{f(x) }{g(x)}= 0$$. 

Da questo si ricava la definizione di asintotico. Una funzione si dice asintotica ad un altra funzione se f(x) = g(x) + o(g(x)). Dove l'ordine di infinitesimo è dato dal più piccolo ordine che compone g(x).

Nell'algebra degli o piccoli vale che: nella somma o sottrazione vince l'o piccolo più piccolo in quanto porta con sé maggiori informazioni sull'ordine.
Il prodotto fra una funzione e un o piccolo oppure il prodotto fra due o piccoli è uguale all'o piccolo del prodotto delle due funzioni.

# Integrali:
Sono un modo per calcolare precisamente l'area di un grafico. 
Somma di **Cauchy-Riemann**:

**Teorema di Riemann:** se una funzione f(x) è continua in un intervallo \[a, b] allora è ivi anche integrabile. Da notare che la funzione deve essere continua anche nei punti di estremo dell'intervallo.
Questo teorema può essere esteso anche alle discontinuità di tipo di SALTO.
Queste sono condizioni sufficienti. 

**Proprietà degli integrali:**
- *Linearità* Se c'è uno scalare a moltiplicare una funzione f(x) che è integrata, posso portare fuori lo scalare a moltiplicare tutto l'integrale
- *Additività* Se c è un punto compreso in \[a, b] allora posso spezzare l'integrale in due con c nel mezzo.

La convenzione vuole che si metta l'estremo superiore sia più grande dell'estremo inferiore a.

Se f(x) > g(x) allora anche gli integrali fra gli stessi punti avranno lo stesso carattere delle due funzioni di partenza. Ovvero l'integrale di f sarà maggiore dell'integrale di g(x).

**Primitiva:** se ho una funzione f che va da un intervallo I ad R allora F derivabile si dice primitiva di F se $F'(x) = f(x)$ Le primitive di una funzione sono infinite. Questo perché facendo la derivata di F, sto considerando solo la sua variazione ma non ad esempio la sua posizione verticale. Dunque si ha che Le primitive di una funzione di f(x) sono tutte le funzioni F(x) + c tali che la condizione sopra è verificata. Il +c determina appunto l'infinità di funzioni che soddisfano tale condizione.

Il primo teorema fondamentale del calcolo integrale ci dice che: $$\int_a^b    f(x)\,dx=F(b)-F(a)$$

La notazione di Integrale indefinito $\int$ indica l'insieme di tutte le primitive di una funzione. Ovvero $\int f(x)=F(x)+c$