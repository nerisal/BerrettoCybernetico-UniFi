>[!info]
>Limite al variare di $\alpha$ a pagina 76 delle slide
# Logica

## Tabella generale

|  p  |  q  | non p | non q | non(p e q) | p e q | p o q | p <=> q | p => q |
|:---:|:---:|:-----:|:-----:|:----------:|:-----:|:-----:|:-------:|:------:|
|  V  |  V  |   F   |   F   |     F      |   V   |   V   |    V    |   V    |
|  V  |  F  |   F   |   V   |     V      |   F   |   V   |    F    |   F    |
|  F  |  V  |   V   |   F   |     V      |   F   |   V   |    F    |   V    |
|  F  |  F  |   V   |   V   |     V      |   F   |   F   |    V    |   V    |

## Tabella dei quantificatori
- non ( p(x) e q(x)) = non p(x) o non q(x)
- non ( p(x) o q(x)) = non p(x) e non q(x)
- non ( non p(x)) = p(x)
- non ( ∀x : p(x)) = ∃x : non p(x)
- non ( ∃x : p(x)) = ∀x : non p(x)
- non (∀x : p(x) => q(x)) = ∃x : p(x) e non q(x)

## Notazioni
- A = B significa x ∈ A <=> x ∈ B
- A ⊆ B significa ∀x ∈ A : x ∈ B
- A ⊂ B significa ∀x ∈ A : x ∈ B e ∃y ∈ B, y !∈ A

# Funzioni
## Generale
f ∘ g significa f(g(x))

## Gerarchia degli infiniti
$\log_{a}{n} < n^\alpha < a ^ n < n! < n^n$

## Asintoti
### Asintoto Orizzontale
$\lim_{ x \to \pm\infty }{f(x)}$
### Asintoto Obliquo
$\lim_{ x \to \pm\infty }{\frac{f(x)}{x} = m}$  esiste ed è finito
$\lim_{ x \to \pm\infty }{f(x) - mx = q}$ esiste ed è finito

## Funzioni invertibili
Se una funzione è strettamente monotona allora è invertibile e la sua inversa è strettamente monotona, ma non è vero che una funzione invertibile sia per forza monotona.

Se una funzione è continua e iniettiva allora è strettamente monotona.



$$\lim_{ n \to \infty }{a^n}={\begin{cases} \
\infty &\text{se} &a>1 \\
1 & \text{se} & a = 1 \\
0 & \text{se} & a \leq |a| \leq 1 \\
\nexists & \text{se} & a \leq -1\\
\end{cases}}$$

$$\lim_{ n \to \infty }{n^a}={\begin{cases} \
+ \infty &\text{se} &a>0 \\
1 & \text{se} & a = 0 \\
0 & \text{se} & a \leq 0 \\
\end{cases}}$$