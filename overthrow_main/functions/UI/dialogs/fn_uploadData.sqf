if (dialog) then {
  closeDialog 0;
};

createDialog "OT_dialog_upload";

params [
  ["_data","ERROR"],
  ["_editBox",((findDisplay 49558) displayCtrl 1)],
  ["_legalText",((findDisplay 49558) displayCtrl 5)]
];

if (_data isEqualTo "ERROR") exitWith {
  closeDialog 0;
  diag_log "UPLOAD DIALOG encountered an error with data transmited";
};

_editData = str _data;
_editData = [_editData,"<NULL-object>","objNull"] call OT_fnc_findReplace;
_editData = [_editData,",any]",",nil]"] call OT_fnc_findReplace;

_editBox ctrlSetText _editData;
_editBox ctrlSetTooltip "Copia y pega estos datos";

_legalText ctrlSetStructuredText parseText format["<t font='PuristaMedium'>Usa estos datos para guardar tu partida externamente.<br/>Para cargar este progreso pega el contenido en la ventana LOAD. Tu steamid se guarda en este archivo.</t>",getPlayerUID player];
[_legalText] call BIS_fnc_ctrlFitToTextHeight;
