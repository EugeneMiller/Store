#include <iostream>
#include "Secure.h"
using namespace std;
#define PASS_SIZE 10
int main() {
	FILE* auth_file;//��������� �� ���� � ��������
	setlocale(LC_ALL, "Ru");
	char auth_file_name[] = { "auth.txt" };
	char  pass[PASS_SIZE];
	//�������� ������ ������ � ���������� � ����
	if (fopen_s(&auth_file, auth_file_name, "r")) {
		//���� ������ ������
		cout << "������� ������ ��������������";
		cin >> pass;
		if (fopen_s(&auth_file, auth_file_name, "w"))
			cout << "������ ������ � ���� " << auth_file_name;
		else {
			fputs(code_str(pass, PASS_SIZE), auth_file);
			fclose(auth_file);
		}
	}
	else {
		fgets(pass,PASS_SIZE, auth_file);
		fclose(auth_file);
	}

}