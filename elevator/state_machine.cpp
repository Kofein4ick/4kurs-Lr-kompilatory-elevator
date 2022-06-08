/********************************/
/*		Управляющие сигналы:	*/
/*		s-остановка				*/
/*		u-движение вверх		*/
/*		d-движение вниз			*/
/********************************/

#include "const.h"

state s_state(commands comand, state cur_state);
state u_state(commands comand, state cur_state);
state d_state(commands comand, state cur_state);

state state_machine(commands comand, state cur_state) {
	switch (cur_state) {

/*********************************************************************************************************************/
/********************************************Состояния стоянки на этажах**********************************************/
	case S1: {
		switch (comand) {
		case u: {
			std::cout << "Поедем вверх с 1 этажа\n";
			return cur_state = U1;
		}
		case d: {
			std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: "<< cur_state<<"\nКоманда: "<<comand<<"\n";
			return cur_state = E;
		}
		case s: {
			std::cout << "Стоим на 1 этаже\n";
			return cur_state = S1;
		}
		}
	}
	case S2: return s_state(comand, cur_state);
	case S3: return s_state(comand, cur_state);
	case S4: return s_state(comand, cur_state);
	case S5: return s_state(comand, cur_state);
	case S6: return s_state(comand, cur_state);
	case S7: return s_state(comand, cur_state);
	case S8: return s_state(comand, cur_state);
	case S9: {
		switch (comand) {
		case u: {
			std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: " << cur_state << "\nКоманда: " << comand << "\n";
			return cur_state = E;
		}
		case d: {
			std::cout << "Поедем вниз с 9 этажа\n";
			return cur_state = D9;
		}
		case s: {
			std::cout << "Стоим на 9 этаже\n";
			return cur_state = S9;
		}
		}
	}

/*********************************************************************************************************************/
/*********************************************Состояния движения вниз*************************************************/
	case D1: {
		switch (comand) {
		case u: {
			std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: " << cur_state << "\nКоманда: " << comand << "\n";
			return cur_state = E;
		}
		case d: {
			std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: " << cur_state << "\nКоманда: " << comand << "\n";
			return cur_state = E;
		}
		case s: {
			std::cout << "Останавливаемся на 1 этаже\n";
			return cur_state = S1;
		}
		}
	}
	case D2: return d_state(comand, cur_state);
	case D3: return d_state(comand, cur_state);
	case D4: return d_state(comand, cur_state);
	case D5: return d_state(comand, cur_state);
	case D6: return d_state(comand, cur_state);
	case D7: return d_state(comand, cur_state);
	case D8: return d_state(comand, cur_state);
	case D9: {
		switch (comand) {
		case u: {
			std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: " << cur_state << "\nКоманда: " << comand << "\n";
			return cur_state = E;
		}
		case d: {
			std::cout << "Едем вниз на 9 этаже\n";
			return cur_state = D8;
		}
		case s: {
			std::cout << "Останавливаемся на 9 этаже\n";
			return cur_state = S9;
		}
		}
	}

/*********************************************************************************************************************/
/*********************************************Состояния движения вверх************************************************/
	case U1: {
		switch (comand) {
		case u: {
			std::cout << "Едем вверх на 1 этаже\n";
			return cur_state = U2;
		}
		case d: {
			std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: " << cur_state << "\nКоманда: " << comand << "\n";
			return cur_state = E;
		}
		case s: {
			std::cout << "Останавливаемся на 1 этаже\n";
			return cur_state = S1;
		}
		}
	}
	case U2: return u_state(comand, cur_state);
	case U3: return u_state(comand, cur_state);
	case U4: return u_state(comand, cur_state);
	case U5: return u_state(comand, cur_state);
	case U6: return u_state(comand, cur_state);
	case U7: return u_state(comand, cur_state);
	case U8: return u_state(comand, cur_state);
	case U9: {
		switch (comand) {
		case u: {
			std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: " << cur_state << "\nКоманда: " << comand << "\n";
			return cur_state = E;
		}
		case d: {
			std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: " << cur_state << "\nКоманда: " << comand << "\n";
			return cur_state = E;
		}
		case s: {
			std::cout << "Останавливаемся на 9 этаже\n";
			return cur_state = S9;
		}
		}
	}
	}
	return E;
}

state s_state(commands comand, state cur_state) {
	switch (comand) {
	case u: {
		std::cout << "Поедем вверх с " << cur_state + 1 << " этажа\n";
		return (state)(cur_state + 9);
	}
	case d: {
		std::cout << "Поедем вниз с " << cur_state + 1 << " этажа\n";
		return (state)(cur_state + 18);
	}
	case s: {
		std::cout << "Стоим на " << cur_state + 1 << " этаже\n";
		return cur_state;
	}
	}
	return E;
}
state d_state(commands comand, state cur_state) {
	switch (comand) {
	case u: {
		std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: " << cur_state << "\nКоманда: " << comand << "\n";
		return cur_state = E;
	}
	case d: {
		std::cout << "Едем вниз на " << cur_state - 17 << " этаже\n";
		return (state)(cur_state - 1);
	}
	case s: {
		std::cout << "Останавливаемся на " << cur_state - 17 << " этаже\n";
		return (state)(cur_state - 18);
	}
	}
}

state u_state(commands comand, state cur_state) {
	switch (comand) {
	case u: {
		std::cout << "Едем вверх на " << cur_state - 8 << " этаже\n";
		return (state)(cur_state + 1);
	}
	case d: {
		std::cout << "Ошибка! Некорректная команда для состояния!\nCостояние: " << cur_state << "\nКоманда: " << comand << "\n";
		return cur_state = E;
	}
	case s: {
		std::cout << "Останавливаемся на " << cur_state - 8 << " этаже\n";
		return (state)(cur_state - 9);
	}
	}
}