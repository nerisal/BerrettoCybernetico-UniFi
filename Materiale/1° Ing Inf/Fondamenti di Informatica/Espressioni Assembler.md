
# Add
*add a, b, c*. Scrive in a la somma di b + c;
*add a, b, 0*. Scrive in a il valore di b

# Sub
*sub a, b, c*. Scrive in a la differenza b - c;

>[!info]
>x = a + b + c;
>
>In assembler diventa:
>add tmp, a, b;
>add x, tmp, c;

>[!info]
>Solitamente si fa uso dei registri che sono indicati con il simbolo $. Nel R4000 sono presenti 32 registri fissi. Il primo è $0 e contiene il numero 0.

# Load-Word
lw \$x, Base\[$y]
carica nel registro $x il contenuto della parola contenuto nella locazione numero Base + $y

# Store-Word
sw \$x, Base\[$y]
scrive nel registro $x il contenuto della parola contenuto nella locazione numero Base + $y

# Addi
si usa per sommare una costante

# Beq
beq $x, $y, label;
se $x = $y allora si passa a label

# Slt
slt $x, $y, $z;
se $y < $z allora $x = 1
se $y >= $z allora $x = 0

# J (jump)
j label
Passa il controllo all'etichetta label

```c

int main()
{


}

```