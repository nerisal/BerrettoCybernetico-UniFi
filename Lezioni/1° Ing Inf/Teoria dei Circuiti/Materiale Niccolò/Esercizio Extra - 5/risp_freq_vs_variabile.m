function [out]=risp_freq_vs_variabile(w,V1)
num = + ( +5*V1 )+ ( +0.0016*V1 )*1i*w- ( +1.3E-7*V1 )*w^2;
den = + ( +10 )+ ( +0.0032 )*1i*w- ( +2.5E-7 )*w^2;
out = num/den;
end