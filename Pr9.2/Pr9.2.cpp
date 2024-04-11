#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { KN, IT, ME, FI, TN };

struct Student {
	string prizv;
	int kurs;
	Specialty specialty;
	union {
		int Math;
		int Fizik;
		int Informat;
		int Program;
		int Num_met;
		int Pedagogik;
	};
};

void Create(Student* p, const int n);
void Print(Student* p, const int n);
double Search(Student* p, const int n);
void SearchStudens(Student* p, const int n);
void Sort(Student* p, const int n);
int BinSearch(Student* p, const int n, int kurs, int Math, string prizv);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	cout << "������ ������� ��������: ";
	cin >> n;

	Student* p = new Student[n];

	double proc;
	string prizv;
	int kurs;
	int Math;
	int found;

	int menuItem;
	do {
		cout << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ���� ������ ���� �� ������� �� ������" << endl;
		cout << " [4] - ���� ������� ���� �� � ������ ����� 4 ��� 5" << endl;
		cout << " [5] - ³���������� ����" << endl;
		cout << " [6] - ����� �� ��������, ������, ������� � ����������" << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, n);
			break;
		case 2:
			Print(p, n);
			break;
		case 3:
			proc = Search(p, n);
			cout << "������� ���� �� ������� ��� 3: " << proc << " %" << endl;
			break;
		case 4:
			cout << "�������� � ���� � ������ 4 ��� 5" << endl;
			SearchStudens(p, n);
			break;
		case 5:
			cout << "³��������� ����" << endl;
			Sort(p, n);
			Print(p, n);
			break;
		case 6:
			cout << "������ ����:" << endl;
			cout << " ����: "; cin >> kurs;
			cout << " ������ � ����������: "; cin >> Math;
			cin.ignore();
			cout << " �������: ";
			getline(cin, prizv);
			cin.get();
			cin.sync();
			cout << endl;
			if ((found = BinSearch(p, n, kurs, Math, prizv)) != -1)
				cout << "�������� �������� " << found + 1 << endl;
			else
				cout << "�������� �������� �� ��������" << endl;
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);

	return 0;
}

void Create(Student* p, const int n) {
	int specialty;
	for (int i = 0; i < n; i++) {
		cout << "C������ � " << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << "�������: "; getline(cin, p[i].prizv);
		cout << "����: "; cin >> p[i].kurs;
		cout << "������ � ����������: "; cin >> p[i].Math;
		cout << "������ � ������: "; cin >> p[i].Fizik;
		cout << "������������ (0 - ��, 1 - ��, 2 - ��, 3 - Բ, 4 - �Ҳ): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;

		switch (p[i].specialty)
		{
		case KN:
			cout << "������ � �������������: "; cin >> p[i].Program;
			break;
		case IT:
			cout << "������ � ��������� ������: "; cin >> p[i].Num_met;
			break;
		case ME:
		case FI:
		case TN:
			cout << "������ � ���������: "; cin >> p[i].Pedagogik;
			break;
		}
		cout << endl;
	}
};

void Print(Student* p, const int n) {
	cout << "============================================================================================================"
		<< endl;
	cout << "| � | ������� | ���� | ���������� | Գ���� | ������������ | ������������� | ������� ������ | ��������� |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < n; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(10) << left << p[i].Math << " "
			<< "| " << setw(6) << left << p[i].Fizik << " "
			<< "| " << setw(14) << left << p[i].specialty;

		switch (p[i].specialty)
		{
		case KN:
			cout << "| " << setw(13) << setprecision(2) << fixed << right
				<< p[i].Program << " |" << setw(18) << right << "|"
				<< setw(13) << right << "|" << endl;
			break;
		case IT:
			cout << "| " << setw(15) << right << "|"
				<< setw(16) << setprecision(2) << fixed << right << p[i].Num_met << " |"
				<< setw(13) << right << "|" << endl;
			break;
		case ME:
		case FI:
		case TN:
			cout << "| " << setw(15) << right << "|"
				<< setw(18) << right << "|"
				<< setw(11) << setprecision(2) << fixed << right << p[i].Num_met << " |" << endl;
			break;
		}
	}
	cout << "============================================================================================================"
		<< endl;
	cout << endl;
};

double Search(Student* p, const int n) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].Fizik > 3 && p[i].Informat > 3 && p[i].Math > 3 && p[i].Num_met > 3 && p[i].Pedagogik > 3) {
			k++;
		}
	}
	return 100.0 * k / n;
};

void SearchStudens(Student* p, const int n) {
	for (int i = 0; i < n; i++) {
		if (p[i].Fizik == 4 || p[i].Fizik == 5) {
			cout << setw(3) << right << i + 1
				<< ". " << p[i].prizv << endl;
		}
	}
}

void Sort(Student* p, const int n)
{
	Student tmp;
	for (int i0 = 0; i0 < n - 1; i0++)
		for (int i1 = 0; i1 < n - i0 - 1; i1++)
			if ((p[i1].kurs > p[i1 + 1].kurs)
				||
				(p[i1].Math == p[i1 + 1].Math &&
					p[i1].prizv > p[i1 + 1].prizv))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}

int BinSearch(Student* p, const int n, int kurs, int Math, string prizv) {

	int L = 0, R = n - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].kurs == kurs && p[m].Math == Math && p[m].prizv == prizv)
			return m;
		if ((p[m].kurs < kurs && p[m].prizv < prizv) || (p[m].kurs == kurs && p[m].Math < Math && p[m].prizv == prizv))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;

}