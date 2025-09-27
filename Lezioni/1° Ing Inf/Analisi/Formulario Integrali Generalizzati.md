Questi criteri si applicano per determinare la convergenza o divergenza di $\int_I f(x) , dx$ quando $f$ è continua sull'intervallo $I$, che può essere limitato con una singolarità o illimitato. Spesso è richiesto che $f(x)$ sia **positiva** sull'intervallo critico per l'applicazione dei criteri di confronto puntuale e asintotico.

### 1. Criterio del Confronto Puntuale

- **Condizioni:** $f, g: I \to \mathbb{R}$ continue e **positive** sull'intervallo $I$.
- **Regola:** Se **$0 \le f(x) \le g(x)$** per ogni $x$ in $I$ (o vicino al punto critico):
    - Se $\int_I g(x) , dx$ **converge** $\implies \int_I f(x) , dx$ **converge**.
    - Se $\int_I f(x) , dx$ **diverge** $\implies \int_I g(x) , dx$ **diverge**.

### 2. Criterio del Confronto Asintotico

- **Condizioni:** $f, g: I \to \mathbb{R}$ continue e **positive** vicino al punto critico (singolarità o infinito). Sia $c$ il punto critico.
    
- **Regola:** Si calcola il limite $\lim_{x \to c} \frac{f(x)}{g(x)} = l$, dove $c$ è il punto critico e $0 \le l \le +\infty$.
    
	- Se **$0 < l < +\infty$** (limite finito e non nullo): 
		-  $\int_I f(x) , dx$ e $\int_I g(x) , dx$ hanno lo **stesso carattere** (entrambi convergono o entrambi divergono).
	-  Se **$l = 0$**: 
	    -  Se $\int_I g(x) , dx$ **converge** $\implies \int_I f(x) , dx$ **converge**.
    - Se **$l = +\infty$**: 
	    - Se $\int_I g(x) , dx$ **diverge** $\implies \int_I f(x) , dx$ **diverge**.
- **Corollari del Confronto Asintotico (con integrali campione)**:
    
    - **Singolarità in un estremo (es. in $b$ su $[a,b)$):** $f: [a,b) \to \mathbb{R}$ continua e positiva. Punto critico $b$. Si confronta con $g(x) = \frac{1}{(b-x)^\alpha}$. Si calcola $\lim_{x \to b^-} (b-x)^\alpha f(x) = l$.
        - **$0 < l < +\infty$**: 
	        - $\int_a^b f(x) , dx$ **converge se e solo se $\alpha < 1$**, **diverge se e solo se $\alpha \ge 1$**. ($f$ è un "infinito di ordine $\alpha$" per $x \to b^-$).
        - **$l = 0$**:
	        - $\int_a^b f(x) , dx$ **converge se $\alpha < 1$**.
        - **$l = +\infty$**: 
	        - $\int_a^b f(x) , dx$ **diverge se $\alpha \ge 1$**. _(Integrale campione $\int_a^b \frac{1}{(x-a)^\alpha} dx$ converge per $\alpha < 1$, diverge per $\alpha \ge 1$)._
    - **Intervallo illimitato (es. $[a,+\infty)$):** $f: [a,+\infty) \to \mathbb{R}$ continua e positiva. Punto critico $+\infty$. Si confronta con $g(x) = \frac{1}{x^\alpha}$. Si calcola $\lim_{x \to +\infty} x^\alpha f(x) = l$.
        - **$0 < l < +\infty$**: 
	        - $\int_a^{+\infty} f(x) , dx$ **converge se e solo se $\alpha > 1$**, **diverge se e solo se $\alpha \le 1$**. ($f$ è un "infinitesimo di ordine $\alpha$" per $x \to +\infty$).
        - **$l = 0$**: 
	        - $\int_a^{+\infty} f(x) , dx$ **converge se $\alpha > 1$**.
        - **$l = +\infty$**: 
	        - $\int_a^{+\infty} f(x) , dx$ **diverge se $\alpha \le 1$**. _(Integrale campione $\int_1^{+\infty} \frac{1}{x^\alpha} dx$ converge per $\alpha > 1$, diverge per $\alpha \le 1$)._

### 3. Criterio della Convergenza Assoluta

- **Condizioni:** $f: I \to \mathbb{R}$ continua sull'intervallo $I$. Non richiede $f$ positiva.
- **Regola:**
    - Se $\int_I |f(x)| , dx$ **converge**, allora $\int_I f(x) , dx$ **converge**.
    - Se $\int_I |f(x)| , dx$ diverge, **non si può concludere nulla** sull'integrale originale con questo criterio.

Questi criteri, in particolare quelli di confronto, sono fondamentali perché permettono di stabilire il carattere (convergenza/divergenza) di un integrale generalizzato confrontandolo con altri integrali di cui il carattere è noto, senza necessariamente dover calcolare esplicitamente l'integrale stesso. Il criterio della convergenza assoluta è utile quando la funzione integranda non ha segno costante.