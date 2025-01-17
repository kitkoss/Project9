#include <iostream>
#include <Windows.h>
#include <string>
#include <limits>
#include <iomanip>
#if defined (max)
#undef max
#endif 
bool isAdmin = false;
int userCount = 2;
std::string* loginArr = new std::string[userCount]{ "admin", "user" };
std::string* passwordArr = new std::string[userCount]{ "admin", "user" };


int size = 10;
int* idArr = new int[size];
int* countArr = new int[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];



void Start();
bool Login();
void ShopUserMenu();
void ShopAdminMenu();
void CreateStaticStorage();
void ShowStorage();
void RefiStorage();
void WriteOffFrontStorage();
void ChangePrice();
void ChangeStaff();
void AddEmployee();

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);

template<typename ArrType>
void PrintArr(ArrType dynmicArr, int size);

int main() {
	Start();

	delete[]loginArr;
	delete[]passwordArr;
	delete[]idArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]nameArr;

	return 0;
}
void Start() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	std::cout << "\n\n\t\t\tRoyal Auto\n\n\n";
	if (Login() == true) {
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
	}
	if (isAdmin == true) {
		std::string choose;


		do {
			std::cout << "������������ ������� ����� ��� ������� �����?\n";
			std::cout << "1 - ������� �����\n2 - ������� �����\n\n����:";
			std::getline(std::cin, choose, '\n');
		} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 50);
		if (choose == "1") {
			CreateStaticStorage();
		}
		else {
			//�������� ������������� ������
		}
		ShopAdminMenu();
	}
	else {
		CreateStaticStorage();
		ShopUserMenu();
	}

}
bool Login() {
	while (true) {
		std::string login, pass;
		std::cout << "������� �����: ";
		std::getline(std::cin, login, '\n');
		std::cout << "������� ������: ";
		std::getline(std::cin, pass, '\n');

		for (int i = 1; i < userCount; i++) {
			if (login == loginArr[0] && pass == passwordArr[0]) {
				std::cout << "����� ���������� " << loginArr[0] << '\n';
				isAdmin = true;
				return true;
			}
			else if (login == loginArr[i] && pass == passwordArr[i]) {
				std::cout << "����� ���������� " << loginArr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "������� ������ ����� ��� ������!\n\n";

	}
}
void ShopUserMenu() {
	std::string choose{};
	while (true) {
		do {
			std::cout << "1. �����\n";
			std::cout << "2. ������� �����\n";
			std::cout << "3. �����\n";
			std::cout << "4. �����\n";
			std::cout << "5. �����\n";
			std::cout << "0. �����\n";

			std::cout << "�����: ";
			std::getline(std::cin, choose, '\n');
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 53);
		if (choose == "1") {

		}
		else if (choose == "2") {

		}
		else if (choose == "3") {

		}
		else if (choose == "4") {

		}
		else if (choose == "5") {

		}
		else if (choose == "0") {

		}
	}
}
void ShopAdminMenu() {
	std::string choose{};
	while (true) {
		do {
			std::cout << "\n\t\t����\n";
			std::cout << "1. ������ �������\n";
			std::cout << "2. ������� �����\n";
			std::cout << "3. ��������� �����\n";
			std::cout << "4. ������� �� ������\n";
			std::cout << "5. �������� ����\n";
			std::cout << "6. �������� �����\n";
			std::cout << "7. �������� ����������\n";
			std::cout << "8. ����� � �������\n";
			std::cout << "0. ������� �����\n\n";

			std::cout << "�����: ";
			std::getline(std::cin, choose, '\n');
		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56);
		if (choose == "1") {

		}
		else if (choose == "2") {
			ShowStorage();
		}
		else if (choose == "3") {
			RefiStorage();
		}
		else if (choose == "4") {
			WriteOffFrontStorage();
		}
		else if (choose == "5") {
			ChangePrice();
		}
		else if (choose == "6") {

		}
		else if (choose == "7") {
			ChangeStaff();
		}
		else if (choose == "8") {

		}
		else if (choose == "0") {

		}
	}
}
void CreateStaticStorage() {
	const int staticSize = 10;
	int idStaticArr[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };

	std::string nameStaticArr[staticSize]{
		"Chevrolet Corvette (C6)", "Chevrolet Silverado", "Chevrolet El Camino", "Mercedes Benz AMG GT", "Cadillac CT5-V Blackwing",
		"Dodge Charger SRT Hellcat", "Ferrari 812 Superfast",
		"Rolls-Royce Wraith", "Mercedes-Benz G63", "������ ���"
	};
	int countStaticArr[staticSize]{ 10,17,8,11,23,27,12,14,5,3 };
	double priceStaticArr[staticSize]{ 149.0, 299.0, 459.0, 49999.0, 74999.0, 99.0, 49.0, 99999.0, 2999.0, 3999.0 };
	SetArr(idStaticArr, idArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(countStaticArr, countArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);

}
void ShowStorage() {
	std::cout << "ID\t��������\t\t\t����\t���-��\n\n";
	for (int i = 0; i < size; i++) {
		std::cout << idArr[i] << "\t" << std::left << std::setw(30) << nameArr[i] << "\t"
			<< priceArr[i] << "\t" << countArr[i] << "\n";
	}
}
void RefiStorage() {
	std::string idStr;
	do {


		std::cout << "\n���������� ������\n������� id ������: " << '\n';
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0) {
			break;
		}
	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);

	int id = std::stoi(idStr);
	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << " ���-�� " << countArr[id - 1] << "\n\n";

	int add{};
	do {
		std::cout << "������� ���-�� ������ ��� ����������: ";
		std::cin >> add;
	} while (add < 0 || add > MAXINT - countArr[id - 1]);

	countArr[id - 1] += add;
	std::cout << "����� " << nameArr[id - 1] << " ������� ��������\n\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	system("pause");
}
void WriteOffFrontStorage() {
	std::string idStr;
	do {


		std::cout << "\n�������� ������\n������� id ������: " << '\n';
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0) {
			break;
		}
	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);

	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << " ���-�� " << countArr[id - 1] << "\n\n";

	int del{};
	do {
		std::cout << "������� ���-�� ������ ��� ��������: ";
		std::cin >> del;
	} while (del < 0 || del > countArr[id - 1]);

	countArr[id - 1] -= del;
	std::cout << "����� " << nameArr[id - 1] << " ������� ������\n\n";
	system("pause");

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void ChangePrice() {
	std::string idStr;
	do {


		std::cout << "\n��������� ����\n������� id ������: " << '\n';
		std::getline(std::cin, idStr, '\n');

		if (idStr.size() == 2 && std::stoi(idStr) <= size && std::stoi(idStr) > 0) {
			break;
		}
	} while (idStr.size() > 1 || std::stoi(idStr) < 1 || std::stoi(idStr) > size);

	int id = std::stoi(idStr);

	std::cout << idArr[id - 1] << "\t" << nameArr[id - 1] << " ������� ����: " << priceArr[id - 1] << "\n\n";

	double newPrice{};
	do {
		std::cout << "������� ����� ����: ";
		std::cin >> newPrice;
	} while (newPrice < 0 || newPrice > MAXINT);

	priceArr[id - 1] = newPrice;
	std::cout << "������ " << nameArr[id - 1] << " ������� �������� ����� ����: " << newPrice << '\n\n';
	system("pause");
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void ChangeStaff() {
	std::string choose;
	std::cout << "��������� ��������� ��������\n\n";
	do {
		std::cout << "1 - �������� ������ �����������\n 2 - �������� ����� � ������\n3 - ������� �������� ����������\n\n����: ";
		std::getline(std::cin, choose, '\n');
	} while (choose.size() > 1 || choose[0] < 49 || choose[0] > 51);
	if (choose == "1") {

	}
	else if (choose == "2") {

	}
	else if (choose == "3") {

	}
	else if (choose == "0") {

	}
	else {
		std::cerr << "\nChangeStaffError\n\n";
	}
}
void AddEmployee() {
	std::string* tempLogin = new std::string[userCount];
	std::string* tempPass = new std::string[userCount];
	for (int i = 0; i < userCount; i++) {
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}
	delete[]loginArr;
	delete[]passwordArr;
	userCount++;
	std::string* loginArr = new std::string[userCount];
	std::string* passwordArr = new std::string[userCount];
	for (int i = 0; i < userCount - 1; i++) {
		tempLogin[i] = loginArr[i];
		tempPass[i] = passwordArr[i];
	}

	std::string newLogin, newPass;
	std::cout << "������� ����� ������ ����������: ";
	std::getline(std::cin, newLogin, '\n');
	std::cout << "������� ������ ������ ����������: ";
	std::getline(std::cin, newPass, '\n');

	loginArr[userCount - 1] = newLogin;
	passwordArr[userCount - 1] = newPass;
	delete[]tempLogin;
	delete[]tempPass;

	for (int i = 0; i < userCount; i++) {
		std::cout << loginArr[i] << " " << passwordArr[i] << '\n';
	}
}

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size) {
	for (int i = 0; i < size; i++) {
		dynamicArr[i] = staticArr[i];
	}
}
template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << dynamicArr[i] << "";
	}
	std::cout << "\n";
}