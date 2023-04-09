#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

const int ROWS = 10;
const int COLUMNS = 10;

//functions prototypes
void displaymenu();
void displayseats();
void registerUser();
void loadUsersFromFile();

//user login - struct
struct User {
	string name;
	string username;
	string password;
	string phone_number;
};

vector<User> users;

void displayseats() {
	cout << "seating plan" << endl;
}

void displaymenu() {
	//cin.ignore();
	//system("CLS");
	//cout << " \n\n\n\n\n\n\n\n\n" << endl;
	cout << "                               ,^      /l			" << endl;
	cout << "                              ;  l   ;' l			" << endl;
	cout << "                      \^\.   j' ,| ,'   l			" << endl;
	cout << "                      |0 '';;],, [; _, ,j			" << endl;
	cout << "                    {_, ''.    ''L     ;;		    " << endl;
	cout << "                    ,:' '               ':			" << endl;
	cout << "                 _,:I   -,                ;,		" << endl;
	cout << "                _,u    QJ,                 ;,                    __                                 __" << endl;
	cout << "               --}    ---.,,__             ';,  _      __ ___   / /_____ ____   ____ ___   ___     / /_ ____" << endl;
	cout << "                ||    T_=--..,_             ,; | | /| / // _ \\./ // ___// __ \\ / __ `__ \\ / _ \\   / __// __ \\" << endl;
	cout << "            ,:''-';,    ',                    ;| |/ |/ //  __// // /__ / /_/ // / / / / //  __/  / /_ / /_/ /	" << endl;
	cout << "          ,;'     ^';,                         |__/|__/ \\___//_/ \\___/ \\____//_/ /_/ /_/ \\___/   \\__/ \\____/ " << endl;
	cout << "        ,C   u-      ';,          ___   / /__  __   _____ (_)____   ___   ____ ___   ____ _ _____ 	" << endl;
	cout << "       ,:   ||;j       ;         / _ \\ / // / / /  / ___// // __ \\ / _ \\ / __ `__ \\ / __ `// ___/" << endl;
	cout << "       .j     u-　      ;.       /  __// // /_/ /  / /__ / // / / //  __// / / / / // /_/ /(__  ) " << endl;
	cout << "       '~    --        ;:       \\___//_/ \\__, /   \\___//_//_/ /_/ \\___//_/ /_/ /_/ \\__,_//____/ " << endl;
	cout << "       .;               j               /____/  ,;  	" << endl;
	cout << "       i                {                       ;	" << endl;

	cout << "\n1\tdont have an account? REGISTER NOW" << endl;
	cout << "2\texisting user?        Login" << endl;
	cout << "3\tlog out" << endl;
	cout << "4\tadmin login" << endl;
	cout << "5\texit" << endl;


}


void registerUser() {

	User newUser;
	string name;


	//register user banner
	//cout << " \n\n\n\n\n\n\n\n\n" << endl;
	cout << "\t              ( \\	" << endl;
	cout << "\t   __         _)_\\_	" << endl;
	cout << "\t  ' \\;---.-._S_____2_			                   _        __	" << endl;
	cout << "\t    /   / /_/       (______	       _____ ___   ____ _ (_)_____ / /_ ___   _____" << endl;
	cout << "\t __(  _;-'    =    =|____._'.__	      / ___// _ \\ / __ `// // ___// __// _ \\ / ___/" << endl;
	cout << "\t/   _/     _  @\\ _(@(      '--'.     / /   /  __// /_/ // /(__  )/ /_ /  __// /" << endl;
	cout << "\t(_ /      /\\  _   =( ) ___     \\    /_/    \\___/ \\__, //_//____/ \\__/ \\___//_/" << endl;
	cout << "\t  /      /\\ \\_ '.___'-.___~.    '\\	   	/____/   ____   ____  _      __" << endl;
	cout << "\t /      /\\ \\__'--') '-.__c` \\    |	   	        / __ \\ / __ \\| | /| / /" << endl;
	cout << "\t|     .'  )___'--'/  /`)     \\   /	               / / / // /_/ /| |/ |/ /" << endl;
	cout << "\t|    |'-|    _|--'\\_(_/       '.'	              /_/ /_/ \\____/ |__/|__/" << endl;
	cout << "\t|    |   \\_  -\\	" << endl;
	cout << "\t\\   |     \\ /`)	" << endl;
	cout << "\t  '._/       (_/     " << endl;
	cout << "\n";



	cout << "\t\t\t\t\tPlease enter your name\t\t: ";
	getline(cin, newUser.name);
	cin.ignore();

	cout << "\t\t\t\t\tPlease enter a username\t\t: ";
	getline(cin, newUser.username);
	cin.ignore();

	cout << "\t\t\t\t\tPlease enter a password\t\t: ";
	getline(cin, newUser.password);
	cin.ignore();


	cout << "\t\t\t\t\tPlease enter your phone number\t: ";
	getline(cin, newUser.phone_number);
	cin.ignore();

	users.push_back(newUser);


	//saving the data of new user
	ofstream file;
	file.open("users.txt", ios::app);
	file << newUser.name << "," << newUser.username << "," << newUser.password << "," << newUser.phone_number << "\n";
	file.close();

	cout << "\n\nRegistration successful!\n" << endl;
	cin.ignore();
	system("Pause");

}

bool loginUser() {

	
		cout << "  _,                           _	 " << endl;
		cout << ".'  `.                 ,___.>'',' - .. - .   " << endl;
		cout << "`-.   ;           .--'-        . - ._@;      "<< endl;
		cout << "   ;  !_.--..._ .'      /     .[_@'`'.       " << endl;
		cout << "  ;            /       : .'  ; :_.._  `.     " << endl;
		cout << "   :           ;        ;[   _T-;  `.'-. `-. " << endl;
		cout << "   \\        .-:      ; `.`-=_,88p.   _.}.-' " << endl;
		cout << "    `-.__.-'   \\    /L._ Y', P$T888;  ""    " << endl;
		cout << "             .-'_.-'  / ;$$$$$$]8P;          " << endl;
		cout << "             \\ /     / / 'Y$$P' ^,'         " << endl;
		cout << "              ;\\_    `.\\_._                " << endl;
		cout << "              ]__\\     \\___;				  " << endl;

		cout << "\n\n" << endl;
	/*
	


	*/
	//
	string username, password;
	cout << "Please enter your username: ";
	getline(cin, username);
	cin.ignore();


	cout << "Please enter your password: ";
	getline(cin, password);
	cin.ignore();

	for (int i = 0; i < users.size(); i++) {
		if (users[i].username == username && users[i].password == password) {
			cout << "\nWelcome " << users[i].name << "!" << endl;
			system("Pause");
			return true;
		}
	}
	cout << "\nInvalid username or password." << endl;
	system("Pause");
	cin.ignore();
	return false;

}


void loadUsersFromFile() {
	ifstream file("users.txt");
	string line;
	while (getline(file, line)) {
		User user;
		size_t pos = 0;
		string token;
		int i = 0;
		while ((pos = line.find(",")) != string::npos) {
			token = line.substr(0, pos);
			line.erase(0, pos + 1);
			switch (i) {
			case 0:
				user.name = token;
				break;
			case 1:
				user.username = token;
				break;
			case 2:
				user.password = token;
				break;
			case 3:
				user.phone_number = token;
				break;
			}
			i++;
		}
		users.push_back(user);
	}

}

int main() {


	char choice;
	loadUsersFromFile();
	bool isLoggedIn = false;
	bool validInput = false;
	do {
		system("CLS");
		displaymenu();
		cout << "\nenter your choice: ";
		cin >> choice;



		switch (choice) {
		case '1':
			system("CLS");
			registerUser();
			break;
		case '2':
			if (!isLoggedIn) {
				system("CLS");
				isLoggedIn = loginUser();
			}
			else {
				cout << "\nYou are already logged in." << endl;
				system("Pause");

				//the rest of everything
				cout << "\nwhats your plan tonight?" << endl;

				cout << "\n1\tcheck out all movies" << endl;
				cout << "2\tpurchase ticket" << endl;
				cout << "3\tlog out" << endl;
				cout << "4\texit" << endl;
			}
			break;
		case '3':
			char logout;
			cout << "log out?\t" << endl;
			cout << "\npress 'Y' to logout" << endl;
			cout << "\npress any other key to go back to the main screen" << endl;
			cin >> logout;
			if (logout == 'Y' || logout == 'y') {
				isLoggedIn = false;
				cout << "\nyou have successfully logged out of the system" << endl;
				system("Pause");
				displaymenu();

			}
			else {
				cout << "\nyou're still logged in\nenter any key to go back to the main menu" << endl;
			}
			break;
		case '5':
			cout << "\nGoodbye!" << endl;
			return 0;
		default:

			cout << "\nInvalid choice.\n" << endl;
			system("Pause");
			//cout << "\nenter your choice: ";
			//cin >> choice;
			//displaymenu();
			break;

		}

	} while (choice != 5);
}




/*
*


cout <<" 　 　         _	"<< endl;
cout <<"              ( \		"<< endl;
cout <<"   __         _)_\_		"<< endl;
cout <<"  ' \;---.-._S_____2_		"<< endl;
cout <<"    /   / /_/       (______		"<< endl;
cout <<" __(  _;-'    =    =|____._'.__		"<< endl;
cout <<"/   _/     _  @\ _(@(      '--.\		"<< endl;
cout <<"(_ /      /\  _   =( ) ___     \\		"<< endl;
cout <<"  /      /\ \_ '.___'-.___~.    '\		"<< endl;
cout <<" /      /\ \__'--') '-.__c` \    |		"<< endl;
cout <<"|     .'  )___'--'/  /`)     \   /		"<< endl;
cout <<"|    |'-|    _|--'\_(_/       '.'		"<< endl;
cout <<"|    |   \_  -\							"<< endl;
cout <<"\   |     \ /`)							"<< endl;
cout <<"  '._/      (_/ 　						"<< endl;



   _,                          _
.'  `.                  ___.>"''-..-.
`-.   ;           .--"""        .-._@;
   ;  !_.--..._ .'      /     .[_@'`'.
  ;            /       : .'  ; :_.._  `.
  :           ;        ;[   _T-"  `.'-. `-.
   \        .-:      ; `.`-=_,88p.   _.}.-"
	`-.__.-'   \    /L._ Y",P$T888;  ""
			 .-'_.-'  / ;$$$$$$]8P;
			 \ /     / / "Y$$P" ^"
			  ;\_    `.\_._
			  ]__\     \___;
*/
