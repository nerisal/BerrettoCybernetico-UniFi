function [out]=risp_ampiezzafase_es7(w,Vs)
num = + ( -80*Vs )*1i*w;
den = + ( -24800000 )+ ( -40 )*1i*w- ( -0.00104 )*w^2;
out = num/den;
end
