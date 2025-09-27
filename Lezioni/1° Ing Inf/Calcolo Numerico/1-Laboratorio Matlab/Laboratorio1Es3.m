a = 2;
b = 10^-2;

E1 = (a * b + sqrt(3 + b))/(a^2 + b^2);
E2 = -pi/2*exp(-a)+(3/2)*cos(b);
E3 = (1/2)*log(abs((1+sin(a))/(1-sin(a))));

disp(E1);
disp(E2);
disp(E3);