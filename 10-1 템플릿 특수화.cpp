#include<iostream>
#include<string>
using namespace std;
/*
	���ø� Ư��ȭ : Ư���� ��Ȳ�� ���� ������ �Լ� ���ø����� ����� ó���ϴ� ���
		����� Ư��ȭ : ��� ���ø� �Ű������� Ư�� ������ �������� �����ϴ� ���
		�κ� Ư��ȭ : �Ϻ� ���ø� �Ű������� Ư�� ������ �������� �����ϴ� ���
		�Լ� ���ø������� ����� Ư��ȭ�� ��� ����
*/

template <typename T>
T data_sum(T operand1, T operand2) {
	return operand1 + operand2;
}

template<>
double data_sum(double operand1, double operand2) {
	return (int)operand1 + (int)operand2;
}

int main() {
	int data1 = 3, data2 = 5;
	double data3 = 4.5, data4 = 8.9;

	cout << "������ ������ �� : " << data_sum(data1, data2) << endl;
	cout << "�Ǽ��� ������ �� : " << data_sum(data3, data4) << endl;
	return 0;
}