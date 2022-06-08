#include "const.h"

int read_str(std::string& in_call, std::string& out_call);

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	bool direction_flag = 0;//���� ����������� ��������
	char input;//������� ����������� ������
	int er = 0;//���������� ��� ��������� ������
	std::string in_call = "000000000";//������ ������ �����
	std::string out_call = "000000000";//������ �� ������
	state cur_state = S1;//������� ���������
	commands comand = s;//����������� ������ ��������
	std::cout << "������� ����: " << cur_state + 1 << "\n";
	er = read_str(in_call, out_call);
	if (er) return er;
	//���� ������ �����
	while (1) {
		comand = converter_input_to_command(in_call, out_call, cur_state, direction_flag);//��������� ������������ �������
		if (comand == e) {
			er = Error(cur_state, direction_flag);//��������� ������
			return er;
		}
		cur_state = state_machine(comand, cur_state);//��������� ���������
		if (cur_state == E) {
			return -11;
		}
		if ((in_call == "000000000") && (out_call == "000000000")) {//���� ������ ����������
			std::cout << "\n����������?(y/n)\n";
			std::cin >> input;
			if (input == 'n')
				break;
			std::cout << "������� ����: " << cur_state + 1 << "\n";
			er = read_str(in_call, out_call);
			if (er) return er;
		}
	}
	system("pause");
	return 0;
}


int read_str(std::string& in_call, std::string& out_call) {
	std::cout << "������ ������ �����\n";
	std::cin >> in_call;
	if (in_call.size() != 9) {//�������� ������� �����
		std::cout << "������ �����!(������ ����� �� ���������)\n";
		system("pause");
		return 10;
	}
	for (int i = 0; i < in_call.size(); i++) {//�������� ������������ �����
		if ((in_call[i] != '0') && (in_call[i] != '1')) {
			std::cout << "������ �����!(������������ �������)\n";
			system("pause");
			return 11;
		}
	}
	std::cout << "������ ������\n";
	std::cin >> out_call;
	if (out_call.size() != 9) {//�������� ������� �����
		std::cout << "������ �����!(������ ����� �� ���������)\n";
		system("pause");
		return 12;
	}
	for (int i = 0; i < out_call.size(); i++) {//�������� ������������ �����
		if ((out_call[i] != '0') && (out_call[i] != '1')) {
			std::cout << "������ �����!(������������ �������)\n";
			system("pause");
			return 13;
		}
	}
	return 0;
}