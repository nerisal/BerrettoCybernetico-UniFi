A = [2,2;2,2];
B = [1,2;3,4];
b = [5;6];

disp("A + B: ");
A + B

disp("A - B: ");
A - B

disp("A * B: ");
A * B

disp("A .* B: ")
A .* B

disp("A * b: ");
A * b

I = eye(2);
C = (A.^2).*I;
C

A*A

disp("Numero di condizionamento: ");
cond(B)

b = [1;1];

x = B \ b;
x