prec = 1;
a = 1 + prec;
while(a > 1)
    prec = 0.5 * prec;
    a = 1 + prec;

end
prec = 2 * prec;
disp("Errore calcolato: " + prec);
disp("Errore di Matlab: " + eps);