function[P_woofer, P_tweeter, ZL, ZC] = calcolo_potenze(f)

R = 5;
Rg = 5;
L = 796e-6;
C = 31.8e-6;
Vm = 15;
Veff = Vm / sqrt(2);

%preallocazione
w = zeros(size(f));
ZL = zeros(size(f));
ZC = zeros(size(f));
Zeq = zeros(size(f));
Ztot = zeros(size(f));
V_parallel = zeros(size(f));
I_woofer = zeros(size(f));
I_tweeter = zeros(size(f));
P_woofer = zeros(size(f));
P_tweeter = zeros(size(f));
pfw = zeros(size(f));
pft = zeros(size(f));

for i = 1 : length(f)
    w(i) = 2*pi*f(i);   %vettore delle pulsazioni

    ZL(i) = R + 1i*w(i)*L;  %vettore dell'impedenza del Woofer al variare della pulsazione
    ZC(i) = R + 1/(1i*w(i)*C); %vettore dell'impedenza del Tweeter al variare della pulsazione
    
    Zeq(i) = (ZL(i)*ZC(i))/(ZL(i)+ZC(i)); %vettore dell'impedenza sul parallelo al variare della pulsazione
    Ztot(i) = Rg + Zeq(i);          %vettore dell'impedenza totale al variare della pulsazione
    
    V_parallel(i) = Veff * Zeq(i) / Ztot(i); %formula del partitore per calcolare il V parallelo al variare della pulsazione
    
    I_woofer(i) = V_parallel(i) / ZL(i);    %vettore delle correnti sul Woofer al variare della pulsazione
    I_tweeter(i) = V_parallel(i) / ZC(i);   %vettore delle correnti sul Tweeter al variare della pulsazione
    
    pfw(i) = cos(angle(V_parallel(i))-angle(I_woofer(i)));  %calcolo del fattore di potenza per il woofer
    pft(i) = cos(angle(V_parallel(i))-angle(I_tweeter(i))); %calcolo del fattore di potenza per il tweeter

    P_woofer(i) = abs(I_woofer(i)) * abs(V_parallel(i))*pfw(i); %calcolo della potenza sul woofer al variare della pulsazione   
    P_tweeter(i) = abs(I_tweeter(i))* abs(V_parallel(i))*pft(i); %calcolo della potenza sul tweeter al variare della pulsazione

end