// oopC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//                           Project 1
//                     LOGIN MANAGMENT SYSTEM
//  Features : 
//               - Register User
//               - login user
//               - Show user List
//               - Search user
//               - Delete user
//               - Exist

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class User {
private:
	string username, password;
public:
	User(string name, string pass) {
		username = name;
		password = pass;
	}
	string getUsername() {
		return username;
	}
	string getpassword() {
		return password;
	}

};
class usermanager {
private:
	vector<User> users; // creating object of vector
public:
	void RegisterUser() {
		string username, password;
		cout << "Enter UserName: " << endl;
		cin >> username;
		cout << "Enter Password: " << endl;
		cin >> password;
		User newUser(username, password);
		users.push_back(newUser);
		cout << "\t User registered successfully......" << endl;
	}
	bool LoginUser(string name, string pass) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].getUsername() == name && users[i].getpassword() == pass) {
				cout << "\t\t Login successfull....." << endl;
				return true;
			}
		}
		cout << "\t\t Invalid username or Password......" << endl;
		return false;
	}
	void showUser() {
		cout << "\t\t -----Users list----- " << endl;
		for (int i = 0; i < users.size(); i++) {
			cout << "\t\t  " << users[i].getUsername() << endl;
		}
	}
	void SearchUser(string username) {
		for (int i = 0; users.size(); i++) {
			if (users[i].getUsername() == username) {
				cout << "\t\t User Found......" << endl;
			}
		}
	}
	void Deleteuser(string username) {
		for (int i = 0; i < users.size(); i++) {
			if (users[i].getUsername() == username) {
				users.erase(users.begin() + i);
				cout << "\t\t user Removed successfully" << endl;
			}
		}
	}
};

int main() {
	usermanager Um;
	int op;
	char choice;
	do {
		system("cls");
		cout << " \n \n \t \t 1. Register User\t\t" << endl;
		cout << "\t\t 2. Login" << endl;
		cout << "\t\t 3. Show Userlist" << endl;
		cout << "\t\t 4. Search User" << endl;
		cout << "\t\t 5. Delete user" << endl;
		cout << "\t\t 6. exit" << endl;
		cout << "\t\t  Enter your choice" << endl;
		cin >> op;
		switch (op) {
		case 1: {
			Um.RegisterUser();
			break; }
		case 2: {
			string username, password;
			cout << "\t\tEnter username : ";
			cin >> username;
			cout << "\t\t Enter password : ";
			cin >> password;
			Um.LoginUser(username , password);
			break; }
		case 3: {
			Um.showUser();
			break;
		}
		case 4: {
			string username;
			cout << "\t\t Enter username" << endl;
			cin >> username;
			Um.SearchUser(username);
			break;
		}
		case 5: {
			string username;
			cout << "\t\t Enter Username: " << endl;
			cin >> username;
			Um.Deleteuser(username);
			break; }
		case 6: {
			exit(1);
		}
		}


		cout << "\t\t Do you want to continue? [Y/N]";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');


}

