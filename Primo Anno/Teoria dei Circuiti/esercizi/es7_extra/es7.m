% plotta la risposta in ampiezza e fase del circuito in funzione della frequenza (Hz)

% Frequenza logaritmica da 1 kHz a 1 MHz 
f = logspace(3, 6, 1000);  % vettore spaziato logaritmicamente contentente 1000 punti tra 10^3 e 10^6
w = 2 * pi * f;            % pulsazione rad/s
Vs = 1;                    % Ampiezza del segnale in ingresso

% pre-generazione vettore risposta 
H = zeros(size(f));

% calcolo della funzione di trasferimento per ciascuna frequenza
for k = 1:length(f)
    H(k) = risp_ampiezzafase_es7(w(k), Vs);
end

% Calcolo risposta in ampiezza (in dB) e fase (in gradi)
ampiezza_dB = 20 * log10(abs(H));   %normalizzato a 0 dB => modulo unitario. Fonte: Manuale di Elettronica e El.Tecnica - Ortolani e Venturi
fase_deg = angle(H) * (180/pi);     %angle(H) resituisce argtan[Im(H)/Re(H)] in radianti. Moltiplicando per 180/pi lo porto in gradi


% Plot del modulo in dB e della fase in gradi
figure;
subplot(2,1,1); %permette, in un unica figura, di dividere lo spazio in due grafici separati
semilogx(f, ampiezza_dB, 'b', 'LineWidth', 2);  %plotta il grafico secondo una scala logaritmica sulle x (le y sono lineari)
line([10^3, 10^6], [-3, -3], 'LineStyle', '--');    %plotta la retta y = -3db
grid on;
xlabel('Frequenza f, [Hz]');
ylabel('Risposta in ampiezza M(w), [dB]');
title('Risposta in ampiezza');
hold on;

maxM=max(ampiezza_dB);


subplot(2,1,2);     %2° grafico
semilogx(f, fase_deg, 'r', 'LineWidth', 2);
hold on;
grid on;
line([10^3, 10^6], [0, 0], 'LineStyle', '--');
xlabel('Frequenza f, [Hz]');
ylabel('Risposta in fase \Phi, [°]');
title('Risposta in fase');
