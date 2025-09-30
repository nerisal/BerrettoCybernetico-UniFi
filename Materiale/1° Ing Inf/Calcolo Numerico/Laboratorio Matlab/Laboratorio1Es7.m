disp("Primo vettore: ");
i = 20;
%Si può usare anche la funzione zeros() per creare una funzione di tutti
%zeri. Altrimenti anche ones();
z = size(i);
for c = 1:i
    z(c) = c;
end
disp(z.');

disp("Secondo vettore: ");
i = 100;
v = size(i);
for c = 1:i
   
    v(c)= 10^-3;
     v(1) = 3;
end
disp(v.');

disp("Terzo vettore: ");
n = 21;
w = size(n);
a = 0;
h = 1 / (n - 1);
for k = 1:n
    w(k)=a +(k - 1)*h;
end
disp(w.');