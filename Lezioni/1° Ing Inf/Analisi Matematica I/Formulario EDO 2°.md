Un'equazione differenziale lineare del secondo ordine a coefficienti costanti ha la forma generale: $ax''(t) + bx'(t) + cx(t) = f(t)$ dove $a, b, c$ sono costanti reali ($a \neq 0$) e $f(t)$ è una funzione continua definita su un intervallo $I$. L'incognita è la funzione $x(t)$.

L'integrale generale (o soluzione generale) di un'equazione differenziale lineare completa è dato dalla somma dell'integrale generale dell'equazione omogenea associata e di una soluzione particolare dell'equazione completa. Cioè: $x(t) = x_0(t) + x_p(t)$ dove $x_0(t)$ è l'integrale generale dell'equazione omogenea associata ($ax'' + bx' + cx = 0$) e $x_p(t)$ è una soluzione particolare dell'equazione completa ($ax'' + bx' + cx = f(t)$).

Ecco i passaggi per trovare la soluzione generale:

**Passaggio 1: Risolvere l'equazione omogenea associata** Si considera l'equazione omogenea associata, ponendo $f(t) = 0$: $ax''(t) + bx'(t) + cx(t) = 0$

**Passaggio 2: Trovare le radici dell'equazione caratteristica** Si cerca una soluzione dell'equazione omogenea del tipo $x(t) = e^{\lambda t}$. Sostituendo questa forma nell'equazione omogenea, si ottiene l'equazione caratteristica: $a\lambda^2 + b\lambda + c = 0$ Questa è un'equazione algebrica di secondo grado in $\lambda$.

Si calcola il discriminante $\Delta = b^2 - 4ac$. Le radici $\lambda$ dipendono dal segno di $\Delta$:

- **Caso 1: $\Delta > 0$** Ci sono due radici reali distinte, $\lambda_1$ e $\lambda_2$. Le soluzioni dell'equazione omogenea sono $e^{\lambda_1 t}$ e $e^{\lambda_2 t}$. Queste sono linearmente indipendenti. L'integrale generale dell'omogenea è: $x_0(t) = c_1 e^{\lambda_1 t} + c_2 e^{\lambda_2 t}$, dove $c_1, c_2 \in \mathbb{R}$.
    
- **Caso 2: $\Delta = 0$** C'è una radice reale doppia, $\lambda = -b/(2a)$. Due soluzioni linearmente indipendenti sono $e^{\lambda t}$ e $t e^{\lambda t}$. L'integrale generale dell'omogenea è: $x_0(t) = c_1 e^{\lambda t} + c_2 t e^{\lambda t}$, dove $c_1, c_2 \in \mathbb{R}$.
    
- **Caso 3: $\Delta < 0$** Ci sono due radici complesse coniugate, $\lambda_{1,2} = \alpha \pm i\beta$, dove $\alpha = -b/(2a)$ e $\beta = \sqrt{|\Delta|}/(2a)$. Due soluzioni reali linearmente indipendenti si possono ottenere da $e^{(\alpha \pm i\beta)t}$ e sono $e^{\alpha t} \cos(\beta t)$ e $e^{\alpha t} \sin(\beta t)$. L'integrale generale dell'omogenea è: $x_0(t) = e^{\alpha t} (c_1 \cos(\beta t) + c_2 \sin(\beta t))$, dove $c_1, c_2 \in \mathbb{R}$.
    

**Passaggio 3: Trovare una soluzione particolare dell'equazione completa ($x_p(t)$)** Per trovare una soluzione particolare $x_p(t)$ dell'equazione completa $ax''(t) + bx'(t) + cx(t) = f(t)$, si possono usare principalmente due metodi: il Metodo di Somiglianza o il Metodo di Variazione delle Costanti.

- **Metodo di Somiglianza** Questo metodo è applicabile quando la funzione $f(t)$ ha forme specifiche, come polinomi, esponenziali, seni, coseni o loro combinazioni. È spesso più semplice da usare del Metodo di Variazione delle Costanti, ma non è generale. Si basa sull'idea di "indovinare" la forma di $x_p(t)$ basandosi sulla forma di $f(t)$, aggiustandola se la forma "indovinata" è già una soluzione dell'omogenea. Le fonti forniscono delle tabelle o regole per la forma di $x_p(t)$ data la forma di $f(t)$. Ad esempio:
    
    - Se $f(t) = P_n(t)$ (polinomio di grado $n$), si cerca $x_p(t) = Q_n(t)$ (polinomio di grado $n$) se 0 non è radice dell'equazione caratteristica. Se 0 è radice (con molteplicità 1 o 2), si moltiplica per $t$ o $t^2$ rispettivamente.
    - Se $f(t) = P_n(t) e^{\alpha t}$, si cerca $x_p(t) = Q_n(t) e^{\alpha t}$ se $\alpha$ non è radice. Se $\alpha$ è radice (con molteplicità 1 o 2), si moltiplica per $t$ o $t^2$.
    - Se $f(t) = P_n(t) e^{\alpha t} \cos(\beta t)$ o $P_n(t) e^{\alpha t} \sin(\beta t)$, si cerca $x_p(t) = e^{\alpha t} (Q_n(t) \cos(\beta t) + R_n(t) \sin(\beta t))$ se $\alpha + i\beta$ non è radice. Se $\alpha + i\beta$ è radice, si moltiplica per $t$. Una volta "indovinata" la forma, si sostituisce $x_p(t)$ e le sue derivate nell'equazione completa per determinare i coefficienti incogniti nel polinomio $Q_n(t)$ o $R_n(t)$. Questo metodo può essere applicato anche se $f(t)$ è una somma di termini di queste forme, grazie al Principio di Sovrapposizione (la soluzione particolare per la somma è la somma delle soluzioni particolari per ogni termine).
- **Metodo di Variazione delle Costanti** Questo metodo è più generale e funziona per qualsiasi $f(t)$ continua, ma è spesso più laborioso. Si parte dalle due soluzioni linearmente indipendenti dell'omogenea, $x_1(t)$ e $x_2(t)$, tali che $x_0(t) = c_1 x_1(t) + c_2 x_2(t)$. Si cerca una soluzione particolare della forma: $x_p(t) = c_1(t) x_1(t) + c_2(t) x_2(t)$ dove $c_1(t)$ e $c_2(t)$ sono funzioni incognite da determinare. Questo porta a risolvere il seguente sistema lineare per le derivate $c_1'(t)$ e $c_2'(t)$: $c_1'(t) x_1(t) + c_2'(t) x_2(t) = 0$ $c_1'(t) x_1'(t) + c_2'(t) x_2'(t) = f(t)/a$ Questo sistema ha una soluzione unica poiché il determinante della matrice dei coefficienti è il Wronskiano di $x_1$ e $x_2$, che è diverso da zero per soluzioni linearmente indipendenti. Si possono usare metodi come la regola di Cramer per risolverlo. Una volta trovate $c_1'(t)$ e $c_2'(t)$, si ottengono $c_1(t)$ e $c_2(t)$ per integrazione. $c_1(t) = \int c_1'(t) dt$ e $c_2(t) = \int c_2'(t) dt$ Infine, si costruisce $x_p(t) = c_1(t) x_1(t) + c_2(t) x_2(t)$.
    

**Passaggio 4: Scrivere la soluzione generale dell'equazione completa** La soluzione generale dell'equazione differenziale completa è la somma dell'integrale generale dell'omogenea ($x_0(t)$) e della soluzione particolare trovata ($x_p(t)$): $x(t) = x_0(t) + x_p(t)$ $x(t) = (\text{soluzione omogenea}) + (\text{soluzione particolare della completa})$

Questo integrale generale contiene le due costanti arbitrarie $c_1$ e $c_2$ provenienti dalla soluzione omogenea. Per determinare univocamente queste costanti, sono necessarie condizioni aggiuntive, tipicamente sotto forma di condizioni iniziali (Problema di Cauchy) o al contorno.

Spero questo formulario basato sui sorgenti ti sia utile!