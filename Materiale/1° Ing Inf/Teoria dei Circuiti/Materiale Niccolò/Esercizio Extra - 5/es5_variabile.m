%plotta la risposta in frequenza del filtro dell'esercizio 5 CON GENERATORE
%VARIABILE
f = linspace(1, 15e3, 1000); %spettro delle frequenze udibili
w = f*2*pi;
H = zeros(size(f));
Vs = 120;    %---NOTA--- in questa versione, il valore della tensione fornita dall'amplificatore viene scelto da qui

for i=1 : length(f)
    H(i) = risp_freq_vs_variabile(w(i), Vs);  %calcolo della risposta in frequenza tramite funzione generata da SapWin
end                         

figure;
subplot(2,1,1);
plot(f,abs(H));    
grid on;
xlabel("Frequenza (Hz)");
ylabel("Ampiezza");
title("Risposta in ampiezza:");

subplot(2,1,2);
plot(f, angle(H)*180/pi);      
xlabel("Frequenza (Hz)");
ylabel("Fase (°)");
title("Risposta in fase:");
grid on;