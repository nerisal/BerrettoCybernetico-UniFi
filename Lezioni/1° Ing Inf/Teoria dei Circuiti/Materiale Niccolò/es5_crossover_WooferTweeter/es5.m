%plotta la risposta in frequenza del filtro dell'esercizio 5
num = [-8e-7 4e-3 5];
den = [-1.6e-6 8e-3 0];
f = linspace(1, 15e3, 1000); 
w = f*2*pi;
H = zeros(size(f));

for i=1 : length(f)
    H(i) = risp_frequenzaTW(w(i));
end

figure;
subplot(2,1,1);
plot(f,abs(H));
xline(1e3, '--r', 'f_c = 1kHz');
grid on;
xlabel("Frequenza (Hz)");
ylabel("Ampiezza");
title("Risposta in ampiezza:");

subplot(2,1,2);
plot(f, angle(H)*180/pi);
xline(1e3, '--r', 'f_c = 1kHz');
xlabel("Frequenza (Hz)");
ylabel("Fase");
title("Risposta in fase:");
grid on;