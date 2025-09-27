%plotta le potenze sui rami del tweeter e del woofer
f = linspace(0, 5e3);
[P_woo, P_twe, ZL, ZC] = calcolo_potenze(f);
plotz = true;   %fa plottare anche i moduli e la fase delle impedenze dei rami del tweeter e woofer

figure;
subplot(2,1,1);
plot(f,P_woo, "g");
xline(1e3, "--r", "1kHz");
grid on;
hold on;
P0_w = interp1(f,P_woo, 500);
P1_w = interp1(f, P_woo, 2000);
plot(500, P0_w, ".", LineWidth=3, MarkerSize=8, Color="black");
hold on;
plot(2000, P1_w,".", LineWidth=3, MarkerSize=8, Color="black");
xlabel("Frequenza (Hz)");
ylabel("Potenza attiva Woofer (W)");
title("Potenza convertita dal Woofer");

subplot(2,1,2);
plot(f, P_twe, "b");
xline(1e3, "--r", "1kHz");
grid on;
hold on;
P0_t = interp1(f,P_twe, 500);
P1_t = interp1(f, P_twe, 2000);
plot(500, P0_t, ".", LineWidth=3, MarkerSize=8, Color="black");
hold on;
plot(2000, P1_t, ".", LineWidth=3, MarkerSize=8, Color="black");
xlabel("Frequenza (Hz)");
ylabel("Potenza attiva Tweeter (W)");
title("Potenza convertita dal Tweeter");

if(plotz == true)   %decide se plottare o no i moduli e le fasi delle impedenze
    figure;
    subplot(2,1,1);
    plot(f, abs(ZL), "g");
    hold on;
    plot(f, angle(ZL)*180/pi, "black");
    xline(1e3, "--r", "1kHz");
    title("Impedenza Woofer: verde = modulo, nero = fase");
    xlabel("Frequenza (Hz)");
    grid on;
    subplot(2,1,2);
    plot(f, abs(ZC), "b");
    hold on;
    plot(f, angle(ZC)*180/pi, "black");
    xline(1e3, "--r", "1kHz");
    title("Impedenza Tweeter: blu = modulo, nero = fase");
    xlabel("Frequenza (Hz)");
    grid on;
end