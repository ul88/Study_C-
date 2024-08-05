#include<iostream>
#include<string>
using namespace std;

/*
�Լ� ü�̴� : ���� �Լ��� ���̾� ȣ���ϴ� ���
 �̷��� ��Ÿ���� �ڵ带 �����ϰ� �����, ȣ�� ������ ���������� ǥ���Ѵ�.

��� �Լ� ü�̴��� ������ ������ ��ȯ ������ ���۷����� �����ϰ�
return���� this�����͸� Ȱ���Ͽ� ���� �� �ִ�.

���� ���۷����� �ƴ϶� �����ͷ� �����ϸ�
func1().func2().func3()�� �ƴ϶� func1()->func2()->func3()���� �ۼ��ؾ��Ѵ�.
*/

class bank {
public:
	bank(string bank_name) : bank_name(bank_name) { safe = 0; }

	string get_bank_name() { return bank_name; }
	int get_safe() { return safe; }

	void use_counter(int _in, int _out);
	void transfer_account(int safe);
	void reset_account();
	bank& deposit_interest(int interest);
	bank& withdraw_utility(int utility);
	bank& withdraw_tax(int tax);
private:
	string bank_name;
	int safe;
};

void bank::use_counter(int _in, int _out) {
	safe += _in;
	safe -= _out;
	cout << bank_name << "ó�� - �Ա�: " << _in << ", ���: " << _out<<endl;
}

void bank::transfer_account(int safe) {
	this->safe = safe;
	cout << bank_name << "���� ���� �̵�: " << this->safe << endl;
}

void bank::reset_account() {
	safe = 0;
	cout << bank_name << " ���°� �ʱ�ȭ �Ǿ����ϴ�." << endl;
}

bank& bank::deposit_interest(int interest) {
	safe += interest;
	cout << bank_name << " ���� ����: " << interest << endl;
	return *this;
}

bank& bank::withdraw_utility(int utility) {
	safe -= utility;
	cout << bank_name << " ������ ����: " << utility << endl;
	return *this;
}

bank& bank::withdraw_tax(int tax) {
	safe -= tax;
	cout << bank_name << " ���� ����: " << tax << endl;
	return *this;
}

int main() {
	bank rich_bank("������ ����"), global_bank("������ ����");
	rich_bank.use_counter(50, 10);
	global_bank.transfer_account(rich_bank.get_safe());
	rich_bank.reset_account();

	global_bank.deposit_interest(10).withdraw_utility(1).withdraw_tax(2);
	cout << endl;
	cout << global_bank.get_bank_name() << "�ܾ�: " << global_bank.get_safe() << endl;
}