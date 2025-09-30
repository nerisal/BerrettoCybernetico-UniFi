function[P_woofer, P_tweeter] = calcolo_potenze_es5(f)
R = 5;
Rg = 5;
L = 796e-6;
C = 31.8e-6;
Vm = 15;
Vrms = Vm / sqrt(2);
w = zeros(size(f));
ZL = zeros(size(f));
ZC = zeros(size(f));
Zeq = zeros(size(f));
Ztot = zeros(size(f));
V_parallel = zeros(size(f));
V_Rw = zeros(size(f));
V_Rt = zeros(size(f));
P_woofer = zeros(size(f));
P_tweeter = zeros(size(f));

for i = 1 : length(f)
    w(i) = 2*pi*f(i);

    ZL(i) = R + 1i*w(i)*L;
    ZC(i) = R + 1/(1i*w(i)*C);
    
    Zeq(i) = 1 / (1/ZL(i) + 1/ZC(i));
    Ztot(i) = Rg + Zeq(i);
    
    V_parallel(i) = Vrms * Zeq(i) / Ztot(i);
    
    V_Rw(i) = V_parallel(i) * (R / ZL(i));
    V_Rt(i) = V_parallel(i) * (R / ZC(i));
    
    P_woofer(i) = abs(V_Rw(i))^2 / R;
    P_tweeter(i) = abs(V_Rt(i))^2 / R;
end
