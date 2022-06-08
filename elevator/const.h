#include <string>
#include <iostream>

//состо€ни€ автомата S#-стоит на этаже; U#-едет вверх на этаже; D#- едет вниз на этаже; E-обработка ошибок
enum state { S1, S2, S3, S4, S5, S6, S7, S8, S9, U1, U2, U3, U4, U5, U6, U7, U8, U9, D1, D2, D3, D4, D5, D6, D7, D8, D9, E };
//управл€ющие символы u-двигатьс€ вверх; d-двигатьс€ вниз; s-остановка; e-ошибка
enum commands { u, d, s, e };

//функци€ получени€ управл€ющего символа из значений массивов кнопок внутри лифта и на эатажх
commands converter_input_to_command(std::string& in_call, std::string& out_call, state cur_state, bool& direction_flag);
//конечный автомат
state state_machine(commands comand, state cur_state);
//функци€ обработки ошибок
int Error(state current_state, bool direction_flag);