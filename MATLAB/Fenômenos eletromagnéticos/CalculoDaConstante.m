function constanteK = CalculoDaConstante(Distancia, Angulo, KT, carga)
%UNTITLED3 Summary of this function goes here
%   Detailed explanation goes here
    constanteK = (KT.*Angulo.*(Distancia.^2))./(carga.^2);
end

