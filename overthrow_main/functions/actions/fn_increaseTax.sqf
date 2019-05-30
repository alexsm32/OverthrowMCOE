private _rate = server getVariable ["taxrate",0];
_rate = _rate + 5;
if(_rate > 100) then {_rate = 100};
server setVariable ["taxrate",_rate,true];
hint format["Los impuestos son ahora del %1%2",_rate,"%"];
