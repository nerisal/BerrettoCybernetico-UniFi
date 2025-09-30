# Dinamica

# Legge oraria del pendolo:
bisogna arrivare alle seguenti formule:
$S(t) = L*\theta(t) = L\theta_{0}\sin(\omega t+\phi)$
$\theta(t)=\omega_{0}\theta_{0}\cos(w_{0}t+\phi)$
$v=L\theta_{0}\omega_{0}\cos(\omega t+\phi)$

Per dimostrarlo si parte dalla formula F = ma = T - mg = ma in quanto T e P (-mg) sono le uniche due forze insieme. Poi si usa l'approssimazione di $\sin(\theta) \approx\theta \; se \;\theta < 10°$

# Teorema dell'Energia Cinetica
## Per il Punto Materiale:
Si parte dalla definizione di lavoro: $dW = F ds$, ma sappiamo che $F = ma = m \frac{dv}{dt}$. Dunque $dW = m \frac{dv}{dt}ds = mvdv$. Integrando fra A e B si ottiene appunto $\frac{1}{2}mv^{2}= E_{k}$.

## Per un Sistema di Punti Materiali:
Si fa allo stesso modo del singolo punto ma si considerano tutte le forze di tutti i punti. Il lavoro delle forze interne però non è nullo. In quanto non diamo per scontato che il corpo sia rigido. Nel caso generale si ha che:
$W^{E}+W^{I}=\Delta E_{k} = E_{k,B}-E_{k,A}$

# Teoremi di Köning
Sono due teoremi, uno per il momento angolare e uno per l'energia cinetica, che mettono in relazione un sistema di riferimento generico rispetto a quello del centro di massa.

## Del momento Angolare
$L=L'+L_{CM}$
Dove L è la risultate. L' è il momento angolare rispetto al CM, e $L_{cm}$ è il momento angolare del CM.

## Dell'energia cinetica
$K = K'+K_{0}$
Dove K è la risultante. K' l'energia cinetica rispetto al CM, e $K_{CM}$ è l'energia cinetica del Centro di Massa.

# Terzo Principio della Dinamica
Ad ogni azione corrisponde una reazione uguale e contraria.

# Prodotto Scalare e Prodotto Vettoriale
Il Prodotto Scalare è un'operazione matematica che si indica col simbolo $v\cdot z$ e restituisce uno scalare (un numero). Questo numero è dato dal prodotto fra il modulo di v, il modulo di z e coseno dell'angolo compreso fra i due: $|v|\cdot|z|\cdot \cos(\theta)$

Il prodotto Vettoriale invece è un'operazione matematica che restituisce un vettore con direzione perpendicolare al piano generato fra i due vettori, verso seguendo la regola della mano destra (vite destrogira) e ha come modulo il prodotto dei vettori in valore assoluto moltiplicato in seno dell'angolo compreso fra i due.

# Prima Equazione Cardinale della Dinamica
## Per il punto materiale:
$F=ma=\frac{dP}{dt}$

## Per i sistemi di punti materiali:
$F^E=ma_{CM}=\frac{dP}{dt}$

# Seconda Equazione Cardinale della Dinamica
## Per il Punto Materiale
$M=\frac{dL}{dt}$

## Per i Sistemi di Punti Materiali
$M^E=\frac{dL}{dt}$
# Equazione dei Gas Ideali
L'equazione dei gas ideali è $pV = nRT$, R è detta costante dei gas ideali. Si dimostra a partire dalle leggi delle trasformazioni dei gas ideali:

## Legge di Boyle: (ovvero delle isoterme)
Durante la trasformazione la temperatura non varia. E sappiamo che $pV=\text{costante}$ Ovvero pressione p e volume V sono inversamente proporzionali fra loro.

## Legge di Volta-Gay-Lussac per le Isobare
Ci dice che se facciamo una trasformazione non facendo variare la pressione: $V= V_{0}(1+\alpha t)$ dove $\alpha$ è una costante di dilatazione termica

## Legge di Volta-Gay-Lussac per le Isocore
Ci dice che, se facciamo una strasformazione senza modificare il volume $P=P_{0}(1+\beta t)$. Dove $\beta$ è un'altra costante di dilatazione termica che nel caso di un gas ideale è uguale ad $\alpha$ e vale $\frac{1}{273,15}°C^{-1}$

Le due formule possono essere riscritte usando i gradi Kelvin come:$$V=V_{0}\alpha T$$
$$P=p_{0}\alpha T$$con $T=\frac{1}{\alpha}t$.

Dimostrazione per l'equazione dei gas ideali:
Si considera un modo per passare da uno stato generico A ad uno stato B. Passando da C prima con una Isocora e poi con una Isoterma. Partiamo usando il volume molare, la temperatura ambiente e si cerca di trovare la pressione. $R=p_{0}V_{0}\alpha$

# Ciclo di Carnot
Si fa fare una trasformazione ciclica che passa per 4 stati, A B C e D. Da A a B si fa una Isoterma alla temperatura T1, da B a C si fa una adiabatica, da C a D si fa una isoterma a temperatura T2 e in fine da D ad A si fa un'altra adiabatica. Si arriva alla conclusione che nel ciclo di Carnot il rendimento $\eta=1-\frac{T_{1}}{T_{2}}$

# Espansione Libera di Un Gas
Fu un'esperimento che condusse Joule nel 1800' e che concluse che in una espansione libera, l'energia interna del gas non varia. Inoltre con questo esperimento si è potuto affermare che l'energia interna di un gas ideale è funzione solo della temperatura.

# Primo Principio della Termodinamica
Se un processo termodinamico effettua uno scambio di Calore e di Lavoro, allora Q e W sono dipendenti dal tipo di trasformazione fatta, mentre la loro differenza è equazione di stato. Ovvero la quantità $\Delta U=Q-W$ è equazione di stato. In quanto dipende solo dallo stato iniziale e dallo stato finale.

# Secondo Principio della Termodinamica
## Enunciato di Kelvin Plank
Non è possibile realizzare alcun processo termico il cui unico risultato è la trasformazione di calore in lavoro.
## Enunciato di Clausius
Non è possibile realizzare alcun processo termico il cui unico risultato  è il trasferimento di una quantità di calore da una fonte T2 a una T1 con T2 < T1.