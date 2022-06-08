#include "const.h"

int Error(state current_state,bool direction_flag) {
	std::cout << "Ошибка! Некорректная ситуация!\n";
	if(direction_flag)
		switch (current_state) {
		case D1:return 1;
		case D2:return 2;
		case D3:return 3;
		case D4:return 4;
		case D5:return 5;
		case D6:return 6;
		case D7:return 7;
		case D8:return 8;
		case D9:return 9;
		}
	else 
		switch (current_state) {
		case U1: return -1;
		case U2: return -2;
		case U3: return -3;
		case U4: return -4;
		case U5: return -5;
		case U6: return -6;
		case U7: return -7;
		case U8: return -8;
		case U9: return -9;
		}
	return -10;
}