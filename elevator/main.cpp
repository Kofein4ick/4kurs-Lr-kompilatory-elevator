#include "const.h"

int read_str(std::string& in_call, std::string& out_call);

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	bool direction_flag = 0;//флаг направления движения
	char input;//входной управляющий символ
	int er = 0;//переменная для обработки ошибок
	std::string in_call = "000000000";//кнопки внутри лифта
	std::string out_call = "000000000";//кнопки на этажах
	state cur_state = S1;//текущее состояние
	commands comand = s;//управляющий символ автомата
	std::cout << "Текущий этаж: " << cur_state + 1 << "\n";
	er = read_str(in_call, out_call);
	if (er) return er;
	//цикл работы лифта
	while (1) {
		comand = converter_input_to_command(in_call, out_call, cur_state, direction_flag);//получение управляющего символа
		if (comand == e) {
			er = Error(cur_state, direction_flag);//обработка ошибки
			return er;
		}
		cur_state = state_machine(comand, cur_state);//изменение состояния
		if (cur_state == E) {
			return -11;
		}
		if ((in_call == "000000000") && (out_call == "000000000")) {//если вызовы обработаны
			std::cout << "\nПродолжить?(y/n)\n";
			std::cin >> input;
			if (input == 'n')
				break;
			std::cout << "Текущий этаж: " << cur_state + 1 << "\n";
			er = read_str(in_call, out_call);
			if (er) return er;
		}
	}
	system("pause");
	return 0;
}


int read_str(std::string& in_call, std::string& out_call) {
	std::cout << "Кнопки внутри лифта\n";
	std::cin >> in_call;
	if (in_call.size() != 9) {//проверка размера ввода
		std::cout << "Ошибка ввода!(Размер ввода не корректен)\n";
		system("pause");
		return 10;
	}
	for (int i = 0; i < in_call.size(); i++) {//проверка корректности ввода
		if ((in_call[i] != '0') && (in_call[i] != '1')) {
			std::cout << "Ошибка ввода!(Некорректные символы)\n";
			system("pause");
			return 11;
		}
	}
	std::cout << "Кнопки этажей\n";
	std::cin >> out_call;
	if (out_call.size() != 9) {//проверка размера ввода
		std::cout << "Ошибка ввода!(Размер ввода не корректен)\n";
		system("pause");
		return 12;
	}
	for (int i = 0; i < out_call.size(); i++) {//проверка корректности ввода
		if ((out_call[i] != '0') && (out_call[i] != '1')) {
			std::cout << "Ошибка ввода!(Некорректные символы)\n";
			system("pause");
			return 13;
		}
	}
	return 0;
}