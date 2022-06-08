#include "const.h"

commands convert_func_s_d(int num_floor, std::string& in_call, std::string& out_call, bool& direction_flag);
commands convert_func_s_u(int num_floor, std::string& in_call, std::string& out_call, bool& direction_flag);
commands convert_func_d(int num_floor, std::string& in_call, std::string& out_call, bool& direction_flag);
commands convert_func_u(int num_floor, std::string& in_call, std::string& out_call, bool& direction_flag);

commands converter_input_to_command(std::string& in_call, std::string& out_call, state cur_state, bool& direction_flag) {
	commands comand;
	switch (direction_flag) {
/*********************************************************************************************************************/
/********************************************Направление движения:вниз***********************************************/
	case 0: {
		switch (cur_state) {
/*********************************************************************************************************************/
/********************************************Состояния стоянки на этажах**********************************************/
		case S1: {
			if (in_call != "000000000") {
				if ((in_call[0] == '1') || (out_call[0] == '1')) {//Нажата кнопка текущего этажа
					comand = s;
					in_call[0] = '0';
					out_call[0] = '0';
					return comand;
				}
				for (int i = 1; in_call.size(); i++) {//Нажата кнопка вызова вверх
					if (in_call[i] == '1') {
						direction_flag = 1;
						comand = u;
						return comand;
					}
				}
			}
			if (out_call != "000000000") {
				if (out_call[0] == '1') {//Нажата кнопка текущего этажа
					comand = s;
					out_call[0] = '0';
					return comand;
				}
				for (int i = 1; out_call.size(); i++) {//Нажата кнопка вызова вверх
					if (out_call[i] == '1') {
						direction_flag = 1;
						comand = u;
						return comand;
					}
				}
			}
			comand = s;
			return comand;
		}
		case S2: return convert_func_s_d(1, in_call, out_call, direction_flag);
		case S3: return convert_func_s_d(2, in_call, out_call, direction_flag);
		case S4: return convert_func_s_d(3, in_call, out_call, direction_flag);
		case S5: return convert_func_s_d(4, in_call, out_call, direction_flag);
		case S6: return convert_func_s_d(5, in_call, out_call, direction_flag);
		case S7: return convert_func_s_d(6, in_call, out_call, direction_flag);
		case S8: return convert_func_s_d(7, in_call, out_call, direction_flag);
		case S9: {
			if (in_call != "000000000") {
				if ((in_call[8] == '1') || (out_call[8] == '1')) {//Нажата кнопка текущего этажа
					comand = s;
					in_call[8] = '0';
					out_call[8] = '0';
					return comand;
				}
				for (int i = 0; i < 8; i++)//Нажата кнопка вызова вниз
					if (in_call[i] == '1') {
						comand = d;
						return comand;
					}
			}
			if (out_call != "000000000") {//Нажата кнопка текущего этажа
				if (out_call[8] == '1') {
					comand = s;
					out_call[8] = '0';
					return comand;
				}
				for (int i = 0; i < 8; i++)//Нажата кнопка вызова вниз
					if (out_call[i] == '1') {
						comand = d;
						return comand;
					}
			}
			comand = s;
			return comand;
		}

/*********************************************************************************************************************/
/**********************************************Состояния движения вниз************************************************/
		case D1: return s;
		case D2: return convert_func_d(1, in_call, out_call, direction_flag);
		case D3: return convert_func_d(2, in_call, out_call, direction_flag);
		case D4: return convert_func_d(3, in_call, out_call, direction_flag);
		case D5: return convert_func_d(4, in_call, out_call, direction_flag);
		case D6: return convert_func_d(5, in_call, out_call, direction_flag);
		case D7: return convert_func_d(6, in_call, out_call, direction_flag);
		case D8: return convert_func_d(7, in_call, out_call, direction_flag);
		case D9: return convert_func_d(8, in_call, out_call, direction_flag);

/*********************************************************************************************************************/
/*********************************************Состояния движения вверх************************************************/
		case U1: return e;
		case U2: return e;
		case U3: return e;
		case U4: return e;
		case U5: return e;
		case U6: return e;
		case U7: return e;
		case U8: return e;
		case U9: return e;
		}
		break;
	}
/*********************************************************************************************************************/
/********************************************Направление движения:вверх***********************************************/
	case 1: {
		switch (cur_state) {
/*********************************************************************************************************************/
/********************************************Состояния стоянки на этажах**********************************************/
		case S1: {
			if (in_call != "000000000") {

				if ((in_call[0] == '1') || (out_call[0] == '1')) {//Нажата кнопка текущего этажа
					comand = s;
					in_call[0] = '0';
					out_call[0] = '0';
					return comand;
				}

				for(int i=1;i<in_call.size();i++)//Нажата кнопка вызова вверх
					if (in_call[i] == '1') {
						comand = u;
						return comand;
					}
			}
			if (out_call != "000000000") {
				if (out_call[0] == '1') {//Нажата кнопка текущего этажа
					comand = s;
					out_call[0] = '0';
					return comand;
				}

				for (int i = 1; i < out_call.size(); i++)//Нажата кнопка вызова вверх
					if (out_call[i] == '1') {
						comand = u;
						return comand;
					}
			}
			comand = s;
			return comand;
		}

		case S2: return convert_func_s_u(1, in_call, out_call, direction_flag);
		case S3: return convert_func_s_u(2, in_call, out_call, direction_flag);
		case S4: return convert_func_s_u(3, in_call, out_call, direction_flag);
		case S5: return convert_func_s_u(4, in_call, out_call, direction_flag);
		case S6: return convert_func_s_u(5, in_call, out_call, direction_flag);
		case S7: return convert_func_s_u(6, in_call, out_call, direction_flag);
		case S8: return convert_func_s_u(7, in_call, out_call, direction_flag);
		case S9: {
			if (in_call != "000000000") {
				if ((in_call[8] == '1') || (out_call[8] == '1')) {//Нажата кнопка текущего этажа
					comand = s;
					in_call[8] = '0';
					out_call[8] = '0';
					return comand;
				}
				for(int i=0;i<8;i++)//Нажата кнопка вызова вниз
					if (in_call[i] == '1') {
						comand = d;
						direction_flag = 0;
						return comand;
					}
			}
			if (out_call != "000000000") {
				if (out_call[8] == '1') {//Нажата кнопка текущего этажа
					comand = s;
					out_call[8] = '0';
					return comand;
				}

				for (int i = 0; i < 8; i++)//Нажата кнопка вызова вниз
					if (out_call[i] == '1') {
						comand = d;
						direction_flag = 0;
						return comand;
					}
			}
			comand = s;
			return comand;
		}


/*********************************************************************************************************************/
/*********************************************Состояния движения вниз************************************************/
		case D1: return e;
		case D2: return e;
		case D3: return e;
		case D4: return e;
		case D5: return e;
		case D6: return e;
		case D7: return e;
		case D8: return e;
		case D9: return e;

/*********************************************************************************************************************/
/*********************************************Состояния движения вверх************************************************/
		case U1: return convert_func_u(0, in_call, out_call, direction_flag);
		case U2: return convert_func_u(1, in_call, out_call, direction_flag);
		case U3: return convert_func_u(2, in_call, out_call, direction_flag);
		case U4: return convert_func_u(3, in_call, out_call, direction_flag);
		case U5: return convert_func_u(4, in_call, out_call, direction_flag);
		case U6: return convert_func_u(5, in_call, out_call, direction_flag);
		case U7: return convert_func_u(6, in_call, out_call, direction_flag);
		case U8: return convert_func_u(7, in_call, out_call, direction_flag);
		case U9: return s;
		}
		break;
	}
	}
	return e;
}


commands convert_func_s_d(int num_floor, std::string& in_call, std::string& out_call,bool& direction_flag) {
	if (in_call != "000000000") {
		if ((in_call[num_floor] == '1') || (out_call[num_floor] == '1')) {//Нажата кнопка текущего этажа
			in_call[num_floor] = '0';
			out_call[num_floor] = '0';
			return s;
		}
		for (int i = 0; i < num_floor; i++)//Нажата кнопка вызова вниз
			if (in_call[i] == '1') {
				return d;
			}

		for (int i = num_floor+1; i < in_call.size(); i++)//Нажата кнопка вызова вверх
			if (in_call[i] == '1') {
				direction_flag = 1;
				return u;
			}

	}
	if (out_call != "000000000") {//Нажата кнопка текущего этажа
		if (out_call[num_floor] == '1') {
			out_call[num_floor] = '0';
			return s;
		}
		for (int i = 0; i < num_floor; i++)//Нажата кнопка вызова вниз
			if (out_call[i] == '1') {
				return d;
			}
		for (int i = num_floor+1; i < out_call.size(); i++)//Нажата кнопка вызова вверх
			if (out_call[i] == '1') {
				direction_flag = 1;
				return u;
			}
	}
	return s;
}

commands convert_func_s_u(int num_floor, std::string& in_call, std::string& out_call, bool& direction_flag) {
	commands comand;
	if (in_call != "000000000") {
		if (in_call[num_floor] == '1') {//Нажата кнопка текущего этажа
			comand = s;
			in_call[num_floor] = '0';
			return comand;
		}
		for (int i = num_floor+1; i < in_call.size(); i++)//Нажата кнопка вызова вверх
			if (in_call[i] == '1') {
				comand = u;
				return comand;
			}
		for (int i = 0; i < num_floor; i++)//Нажата кнопка вызова вниз
			if (in_call[i] == '1') {
				comand = d;
				if (out_call[num_floor] == '1') {//Нажата кнопка текущего этажа
					comand = s;
					out_call[num_floor] = '0';
				}
				direction_flag = 0;
				return comand;
			}
	}
	if (out_call != "000000000") {
		if (out_call[num_floor] == '1') {//Нажата кнопка текущего этажа
			comand = s;
			out_call[num_floor] = '0';
			return comand;
		}
		for (int i = num_floor+1; i < out_call.size(); i++)//Нажата кнопка вызова вверх
			if (out_call[i] == '1') {
				comand = u;
				return comand;
			}
		for (int i = 0; i < num_floor; i++)//Нажата кнопка вызова вниз
			if (out_call[i] == '1') {
				comand = d;
				direction_flag = 0;
				return d;
			}
	}
	comand = s;
	return comand;
}

commands convert_func_d(int num_floor, std::string& in_call, std::string& out_call, bool& direction_flag) {
	commands comand;
	if (in_call != "000000000") {
		if ((in_call[num_floor] == '1') || (out_call[num_floor] == '1')) {//Нажата кнопка текущего этажа
			comand = s;
			return comand;
		}
		for (int i = 0; i < num_floor; i++)//Нажата кнопка вызова вниз
			if (in_call[i] == '1') {
				comand = d;
				return comand;
			}
	}
	if (out_call != "000000000") {
		if (out_call[num_floor] == '1') {//Нажата кнопка текущего этажа
			comand = s;
			return comand;
		}
		for (int i = 0; i < num_floor; i++)//Нажата кнопка вызова вниз
			if (out_call[i] == '1') {
				comand = d;
				return comand;
			}
	}
	comand = s;
	return comand;
}

commands convert_func_u(int num_floor, std::string& in_call, std::string& out_call, bool& direction_flag) {
	commands comand;
	if (in_call != "000000000") {
		if (in_call[num_floor] == '1') {//Нажата кнопка текущего этажа
			comand = s;
			return comand;
		}
		for (int i = num_floor+1; i < in_call.size(); i++)//Нажата кнопка вызова вверх
			if (in_call[i] == '1') {
				comand = u;
				return comand;
			}
	}
	if (out_call != "000000000") {
		for (int i = num_floor+1; i < out_call.size(); i++)//Нажата кнопка вызова вверх
			if (out_call[i] == '1') {
				comand = u;
				return comand;
			}
	}
}