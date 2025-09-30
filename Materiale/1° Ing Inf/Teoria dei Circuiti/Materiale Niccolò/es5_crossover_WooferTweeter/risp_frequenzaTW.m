function [out]=risp_frequenzaTW(w)
num = + ( +5 )+ ( +0.0016 )*1i*w- ( +1.3E-7 )*w^2;
den = + ( +10 )+ ( +0.0032 )*1i*w- ( +2.5E-7 )*w^2;
out = num/den;
end
