#include <string>
#include <iostream>

//��������� �������� S#-����� �� �����; U#-���� ����� �� �����; D#- ���� ���� �� �����; E-��������� ������
enum state { S1, S2, S3, S4, S5, S6, S7, S8, S9, U1, U2, U3, U4, U5, U6, U7, U8, U9, D1, D2, D3, D4, D5, D6, D7, D8, D9, E };
//����������� ������� u-��������� �����; d-��������� ����; s-���������; e-������
enum commands { u, d, s, e };

//������� ��������� ������������ ������� �� �������� �������� ������ ������ ����� � �� ������
commands converter_input_to_command(std::string& in_call, std::string& out_call, state cur_state, bool& direction_flag);
//�������� �������
state state_machine(commands comand, state cur_state);
//������� ��������� ������
int Error(state current_state, bool direction_flag);