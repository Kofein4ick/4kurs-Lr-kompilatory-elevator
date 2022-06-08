/********************************/
/*		����������� �������:	*/
/*		s-���������				*/
/*		u-�������� �����		*/
/*		d-�������� ����			*/
/********************************/

#include "const.h"

state s_state(commands comand, state cur_state);
state u_state(commands comand, state cur_state);
state d_state(commands comand, state cur_state);

state state_machine(commands comand, state cur_state) {
	switch (cur_state) {

/*********************************************************************************************************************/
/********************************************��������� ������� �� ������**********************************************/
	case S1: {
		switch (comand) {
		case u: {
			std::cout << "������ ����� � 1 �����\n";
			return cur_state = U1;
		}
		case d: {
			std::cout << "������! ������������ ������� ��� ���������!\nC��������: "<< cur_state<<"\n�������: "<<comand<<"\n";
			return cur_state = E;
		}
		case s: {
			std::cout << "����� �� 1 �����\n";
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
			std::cout << "������! ������������ ������� ��� ���������!\nC��������: " << cur_state << "\n�������: " << comand << "\n";
			return cur_state = E;
		}
		case d: {
			std::cout << "������ ���� � 9 �����\n";
			return cur_state = D9;
		}
		case s: {
			std::cout << "����� �� 9 �����\n";
			return cur_state = S9;
		}
		}
	}

/*********************************************************************************************************************/
/*********************************************��������� �������� ����*************************************************/
	case D1: {
		switch (comand) {
		case u: {
			std::cout << "������! ������������ ������� ��� ���������!\nC��������: " << cur_state << "\n�������: " << comand << "\n";
			return cur_state = E;
		}
		case d: {
			std::cout << "������! ������������ ������� ��� ���������!\nC��������: " << cur_state << "\n�������: " << comand << "\n";
			return cur_state = E;
		}
		case s: {
			std::cout << "��������������� �� 1 �����\n";
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
			std::cout << "������! ������������ ������� ��� ���������!\nC��������: " << cur_state << "\n�������: " << comand << "\n";
			return cur_state = E;
		}
		case d: {
			std::cout << "���� ���� �� 9 �����\n";
			return cur_state = D8;
		}
		case s: {
			std::cout << "��������������� �� 9 �����\n";
			return cur_state = S9;
		}
		}
	}

/*********************************************************************************************************************/
/*********************************************��������� �������� �����************************************************/
	case U1: {
		switch (comand) {
		case u: {
			std::cout << "���� ����� �� 1 �����\n";
			return cur_state = U2;
		}
		case d: {
			std::cout << "������! ������������ ������� ��� ���������!\nC��������: " << cur_state << "\n�������: " << comand << "\n";
			return cur_state = E;
		}
		case s: {
			std::cout << "��������������� �� 1 �����\n";
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
			std::cout << "������! ������������ ������� ��� ���������!\nC��������: " << cur_state << "\n�������: " << comand << "\n";
			return cur_state = E;
		}
		case d: {
			std::cout << "������! ������������ ������� ��� ���������!\nC��������: " << cur_state << "\n�������: " << comand << "\n";
			return cur_state = E;
		}
		case s: {
			std::cout << "��������������� �� 9 �����\n";
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
		std::cout << "������ ����� � " << cur_state + 1 << " �����\n";
		return (state)(cur_state + 9);
	}
	case d: {
		std::cout << "������ ���� � " << cur_state + 1 << " �����\n";
		return (state)(cur_state + 18);
	}
	case s: {
		std::cout << "����� �� " << cur_state + 1 << " �����\n";
		return cur_state;
	}
	}
	return E;
}
state d_state(commands comand, state cur_state) {
	switch (comand) {
	case u: {
		std::cout << "������! ������������ ������� ��� ���������!\nC��������: " << cur_state << "\n�������: " << comand << "\n";
		return cur_state = E;
	}
	case d: {
		std::cout << "���� ���� �� " << cur_state - 17 << " �����\n";
		return (state)(cur_state - 1);
	}
	case s: {
		std::cout << "��������������� �� " << cur_state - 17 << " �����\n";
		return (state)(cur_state - 18);
	}
	}
}

state u_state(commands comand, state cur_state) {
	switch (comand) {
	case u: {
		std::cout << "���� ����� �� " << cur_state - 8 << " �����\n";
		return (state)(cur_state + 1);
	}
	case d: {
		std::cout << "������! ������������ ������� ��� ���������!\nC��������: " << cur_state << "\n�������: " << comand << "\n";
		return cur_state = E;
	}
	case s: {
		std::cout << "��������������� �� " << cur_state - 8 << " �����\n";
		return (state)(cur_state - 9);
	}
	}
}