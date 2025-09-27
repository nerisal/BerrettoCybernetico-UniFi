# Legge della Sovrapposizione degli Effetti
Quando devo determinare una corrente o una tensione e il circuito non rientra in nessun caso semplificabile posso sempre ricorrere alla legge di sovrapposizione degli effetti. Procedo lasciando solo un generatore indipendente acceso alla volta e spegnendo tutti gli altri.
>[!important] 
>Un generatore di tensione diventa un corto circuito. Mentre un generatore di corrente diventa un circuito aperto. 

In fine posso sommare le varie tensioni insieme (o correnti) per calcolare quella totale del sistema. 

>[!note] 
>Non posso fare la stessa cosa con le potenze. Non vale la sovrapposizione per le potenze erogate o assorbite. Devo calcolare la potenza totale usando la tensione o la corrente totale.


# Legge delle Maglie
Posso considerare la corrente che scorre in ognuna delle maglie in modo separato e risolvere il sistema. Per farlo si  considera una corrente con senso arbitrario. 
Ogni equazione sarà composta dal termine I (corrente) della maglia moltiplicato per i resistori che attraversa. Poi dovrò sommare o sottrarre le altre correnti con cui condivide i resistori. Se Nella maglia è presente un generatore di tensione dovrò sottrarlo se è concorde e sommarlo se è discorde. Tutta questa equazione è uguale a zero.

# Teoremi di Thevenin e Norton
Per calcolare la resistenza equivalente di Thevenin è sufficiente spegnere tutti quanti i generatori indipendenti (azzerare seguendo le regole appropriate) e calcolare la resistenza equivalente del circuito. 

La corrente equivalente di Norton segue la seguente formula $$I_{n} = \frac{V_{th}}{R_{eq}}$$