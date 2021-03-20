#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Admin
{
	string user_id;
	string passward;
	string name;
public:
	Admin(string user_id, string passward, string name) {
		this->user_id = user_id;
		this->passward = passward;
		this->name = name;
	}

	int writeFile(string fileName) {
		ofstream out;
		out.open(fileName);
		out << user_id << endl;
		out << passward << endl;
		out << name << endl;
		if (out) {
			out.close();
			return 1;
		}
		else return 0;
	}

	void Register() {
		string fileName = user_id + ".txt";
		ofstream out;
		out.open(fileName);
		bool check = writeFile(fileName);
		if (check) cout << "Registraton successful" << endl;
		else cout << "Registration unsuccessful" << endl;
	}
};

void readFile(string Pass, string fileName) {
	ifstream in;
	in.open(fileName);
	string UI, U_pass;
	in >> UI;
	in >> U_pass;
	if (Pass == U_pass) cout << "Welcome !!" << endl;
	else cout << "Invalid passward" << endl;
}

void Login(string UI, string Pass) {
	string fileName = UI + ".txt";
	ifstream in;
	in.open(fileName);
	if (in) {
		in.close();
		readFile(Pass, fileName);
	}
	else cout << "Not registered yet." << endl;
}

int main()
{
	cout << "Enter 1: For login.\nEnter 2: For registration.\nEnter 0: For exit." << endl;

	int choice;

	cout << "Enter your choice: "; cin >> choice;

	while (choice != 0) {

		if (choice == 1) {
			string UI;
			string Pass;
			string Name;
			cout << "Enter your User Id: "; cin >> UI;
			cout << "Enter your Passward: "; cin >> Pass;
			Login(UI, Pass);
		}
		else if (choice == 2) {
			string UI;
			string Pass;
			string Name;
			cout << "Enter your User Id: "; cin >> UI;
			cout << "Enter your Passward: "; cin >> Pass;
			cout << "Enter your Name: "; cin >> Name;
			Admin A(UI, Pass, Name);
			A.Register();
		}
		else cout << "Invalid choice." << endl;
		cout << "Enter your choice: "; cin >> choice;
	}

	return 0;
}