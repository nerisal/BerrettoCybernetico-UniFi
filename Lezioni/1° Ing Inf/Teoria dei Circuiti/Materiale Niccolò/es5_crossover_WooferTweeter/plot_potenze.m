f = linspace(0, 5e3);
[P_woo, P_twe] = calcolo_potenze_es5(f);

figure;
subplot(2,1,1);
plot(f,P_woo, "g");
xline(1e3, "--r", "1kHz");
grid on;
xlabel("Frequenza (Hz)");
ylabel("Potenza attiva Woofer (W)");
title("Woofer");
subplot(2,1,2);
plot(f, P_twe, "b");
xline(1e3, "--r", "1kHz");
grid on;
xlabel("Frequenza (Hz)");
ylabel("Potenza attiva Tweeter (W)");
title("Tweeter");