#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
//loading bar animation
#include <chrono>
#include <thread>
using namespace std;

const int ROWS = 10;
const int COLUMNS = 10;

//admin username and password
const string username = "admin";
const string password = "password";


const int duration = 5; // Total duration of the loading bar in seconds
const int delay = 100; // Delay between progress updates in milliseconds


//functions prototypes
void displaymenu();
//void registerUser();
void loadUsersFromFile();
void showLoadingBar(int duration, int delay);
void displayloginmenu();
bool loginUser();
bool adminLogin();
void displayadminmenu();

//loading bar
void showLoadingBar(int duration, int delay) {
	int progress = 0;
	int barWidth = 40;

	cout << "\n\t\t\t\t\t\tLoading: [";
	for (int i = 0; i < barWidth; ++i) {
		cout << " ";
	}
	cout << "] 0%";

	for (int i = 0; i < barWidth; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(delay)); // Delay for smooth progress animation

		cout << "\b\b\b"; // Move cursor back
		cout << "||"; // Update progress
		++progress;

		cout.flush();
	}

	cout << "\b\b\b"; // Move cursor back
	cout << "] 100% Done!" << std::endl;
}

//admin login
bool adminLogin() {
	//admin authorization page banner
	cout << "\n\t ______     _____     __    __     __     __   __        __         ______     ______     __     __   __" << endl;
	cout << "\t/\\  __ \\   /\\  __-.  /\\ \"-./  \\   /\\ \\   /\\ \"-.\\ \\      /\\ \\       /\\  __ \\   /\\  ___\\   /\\ \\   /\\ \"-.\\ \\ " << endl;
	cout << "\t\\ \\  __ \\  \\ \\ \\/\\ \\ \\ \\ \\-./\\ \\  \\ \\ \\  \\ \\ \\-.  \\     \\ \\ \\____  \\ \\ \\/\\ \\  \\ \\ \\__ \\  \\ \\ \\  \\ \\ \\-.  \\" << endl;
	cout << "\t \\ \\_\\ \\_\\  \\ \\____-  \\ \\_\\ \\ \\_\\  \\ \\_\\  \\ \\_\\\\\"\\_\\     \\ \\_____\\  \\ \\_____\\  \\ \\_____\\  \\ \\_\\  \\ \\_\\\\\"\\_\\ " << endl;
	cout << "\t  \\/_/\\/_/   \\/____/   \\/_/  \\/_/   \\/_/   \\/_/ \\/_/      \\/_____/   \\/_____/   \\/_____/   \\/_/   \\/_/ \\/_/" << endl;

	cout << "\n\n\t------------------------------------------------------------------------------------------------------------------ " << endl;
	cout << "\t--------------------------------------------[authorization page]-------------------------------------------------- " << endl;
	cout << "\t------------------------------------------------------------------------------------------------------------------ " << endl;


	string inputUsername;
	string inputPassword;

	cout << "\n\n\t\t\t\t\t\tPlease enter your username: ";
	cin >> inputUsername;
	//cout << endl;
	cout << "\n\t\t\t\t\t\tPlease enter your password: ";
	cin >> inputPassword;
	cout << endl;

	if (inputUsername == username && inputPassword == password) {
		cout << "\n\t\t\t\t\t\tWelcome, admin!\n\t\t\t\t\t\tredirecting to admin menu" << endl;
		showLoadingBar(duration, delay);

		cin.ignore();
		system("CLS");

		return true;
	}
	else {
		return false;
	}
}

void displayadminmenu() {
	cout << "\n\t                               ,^      /l			" << endl;
	cout << "\t                             ;  l   ;' l			" << endl;
	cout << "\t                      \\^\\.   j' ,| ,'   l			" << endl;
	cout << "\t                      |0 '';;],, [; _, ,j			" << endl;
	cout << "\t                    {_, ''.    ''L     ;;		    " << endl;
	cout << "\t                    ,:' '               ':			" << endl;
	cout << "\t                 _,:I   -,                ;,		" << endl;
	cout << "\t                _,u    QJ,                 ;,                    __                                 __" << endl;
	cout << "\t               --}    ---.,,__             ';,  _      __ ___   / /_____ ____   ____ ___   ___     / /_ ____" << endl;
	cout << "\t                ||    T_=--..,_             ,; | | /| / // _ \\./ // ___// __ \\ / __ `__ \\ / _ \\   / __// __ \\" << endl;
	cout << "\t            ,:''-';,    ',                    ;| |/ |/ //  __// // /__ / /_/ // / / / / //  __/  / /_ / /_/ /	" << endl;
	cout << "\t          ,;'     ^';,                         |__/|__/ \\___//_/ \\___/ \\____//_/ /_/ /_/ \\___/   \\__/ \\____/ " << endl;
	cout << "\t        ,C   u-      ';,          ___   / /__  __   _____ (_)____   ___   ____ ___   ____ _ _____ 	" << endl;
	cout << "\t       ,:   ||;j       ;         / _ \\ / // / / /  / ___// // __ \\ / _ \\ / __ `__ \\ / __ `// ___/" << endl;
	cout << "\t       .j     u-　      ;.       /  __// // /_/ /  / /__ / // / / //  __// / / / / // /_/ /(__  ) " << endl;
	cout << "\t       '~    --        ;:       \\___//_/ \\__, /   \\___//_//_/ /_/ \\___//_/ /_/ /_/ \\__,_//____/ " << endl;
	cout << "\t       .;               j               /____/  ,;  	" << endl;
	cout << "\t       i                {                       ;	" << endl;

	cout << "\n\n\t------------------------------------------------------------------------------------------------------------------ " << endl;
	cout << "\t----------------------------------------------------[admin menu]-------------------------------------------------- " << endl;
	cout << "\t------------------------------------------------------------------------------------------------------------------ " << endl;

	cout << "\n\t\t\t\t\t\t\t1\tview all movies" << endl;
	cout << "\t\t\t\t\t\t\t2\tadd movie" << endl;
	cout << "\t\t\t\t\t\t\t3\tremove movie" << endl;
	cout << "\t\t\t\t\t\t\t4\tview " << endl;
	cout << "\t\t\t\t\t\t\t5\texit" << endl;

}

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

	cout << "\n\t                               ,^      /l			" << endl;
	cout << "\t                             ;  l   ;' l			" << endl;
	cout << "\t                      \\^\\.   j' ,| ,'   l			" << endl;
	cout << "\t                      |0 '';;],, [; _, ,j			" << endl;
	cout << "\t                    {_, ''.    ''L     ;;		    " << endl;
	cout << "\t                    ,:' '               ':			" << endl;
	cout << "\t                 _,:I   -,                ;,		" << endl;
	cout << "\t                _,u    QJ,                 ;,                    __                                 __" << endl;
	cout << "\t               --}    ---.,,__             ';,  _      __ ___   / /_____ ____   ____ ___   ___     / /_ ____" << endl;
	cout << "\t                ||    T_=--..,_             ,; | | /| / // _ \\./ // ___// __ \\ / __ `__ \\ / _ \\   / __// __ \\" << endl;
	cout << "\t            ,:''-';,    ',                    ;| |/ |/ //  __// // /__ / /_/ // / / / / //  __/  / /_ / /_/ /	" << endl;
	cout << "\t          ,;'     ^';,                         |__/|__/ \\___//_/ \\___/ \\____//_/ /_/ /_/ \\___/   \\__/ \\____/ " << endl;
	cout << "\t        ,C   u-      ';,          ___   / /__  __   _____ (_)____   ___   ____ ___   ____ _ _____ 	" << endl;
	cout << "\t       ,:   ||;j       ;         / _ \\ / // / / /  / ___// // __ \\ / _ \\ / __ `__ \\ / __ `// ___/" << endl;
	cout << "\t       .j     u-　      ;.       /  __// // /_/ /  / /__ / // / / //  __// / / / / // /_/ /(__  ) " << endl;
	cout << "\t       '~    --        ;:       \\___//_/ \\__, /   \\___//_//_/ /_/ \\___//_/ /_/ /_/ \\__,_//____/ " << endl;
	cout << "\t       .;               j               /____/  ,;  	" << endl;
	cout << "\t       i                {                       ;	" << endl;

	cout << "\n\n\t------------------------------------------------------------------------------------------------------------------ " << endl;
	cout << "\t----------------------------------------------------[main menu]--------------------------------------------------- " << endl;
	cout << "\t------------------------------------------------------------------------------------------------------------------ " << endl;

	cout << "\n\t\t\t\t\t1\tdont have an account? REGISTER NOW" << endl;
	cout << "\t\t\t\t\t2\texisting user?        Login" << endl;
	cout << "\t\t\t\t\t3\tlog out" << endl;
	cout << "\t\t\t\t\t4\tadmin login" << endl;
	cout << "\t\t\t\t\t5\texit" << endl;


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
	cout << "\n\t------------------------------------------------------------------------------------------------------------------ " << endl;
	cout << "\t--------------------------------------------------[hello!]-------------------------------------------------------- " << endl;
	cout << "\t------------------------------------------------------------------------------------------------------------------ " << endl;
	cin.ignore();


	cout << "\n\n\t\t\t\t\tPlease enter your name\t\t: ";
	getline(cin, newUser.name);

	cout << "\t\t\t\t\tPlease enter a username\t\t: ";
	getline(cin, newUser.username);

	cout << "\t\t\t\t\tPlease enter a password\t\t: ";
	getline(cin, newUser.password);


	cout << "\t\t\t\t\tPlease enter your phone number\t: ";
	getline(cin, newUser.phone_number);

	users.push_back(newUser);
	//back_insert the data at the end of the vector

	//saving the data of new user
	ofstream file;
	file.open("users.txt", ios::app);
	file << newUser.name << "," << newUser.username << "," << newUser.password << "," << newUser.phone_number << "\n";
	file.close();

	cout << "\n\n\t\t\t\t\t\t  Registration successful!" << endl;
		cout << "\n\t\t\t\t\t  press any key to go back to main menu" << endl;
	cin.ignore();
	//system("Pause");

}

bool loginUser() {

	cout << "\t  _,                           _	 " << endl;
	cout << "\t.'  `.                 ,___.>'',' - .. - .   " << endl;
	cout << "\t`-.   ;           .--'-        . - ._@;      " << endl;
	cout << "\t   ;  !_.--..._ .'      /     .[_@'`'.       " << endl;
	cout << "\t  ;            /       : .'  ; :_.._  `.         __           __ __" << endl;
	cout << "\t   :           ;        ;[   _T-;  `.'-. `-.    / /_   ___   / // /____     __  __ _____ ___   _____" << endl;
	cout << "\t   \\        .-:      ; `.`-=_,88p.   _.}.-'    / __ \\ / _ \\ / // // __ \\   / / / // ___// _ \\ / ___/" << endl;
	cout << "\t    `-.__.-'   \\    /L._ Y', P$T888;  ""        / / / //  __// // // /_/ /  / /_/ /(__  )/  __// /    " << endl;
	cout << "\t             .-'_.-'  / ;$$$$$$]8P;          /_/ /_/ \\___//_//_/ \\____/   \\__,_//____/ \\___//_/     " << endl;
	cout << "\t             \\ /     / / 'Y$$P' ^,'         " << endl;
	cout << "\t              ;\\_    `.\\_._                " << endl;
	cout << "\t              ]__\\     \\___;				  " << endl;
	cout << "\n\n\t------------------------------------------------------------------------------------------------------------------ " << endl;
	cout << "\t-------------------------------------------------[login now]------------------------------------------------------ " << endl;
	cout << "\t------------------------------------------------------------------------------------------------------------------ " << endl;

	string username, password;
	cin.ignore();
	cout << "\n\n\t\t\t\t\t\tplease enter your username: ";
	getline(cin, username);
	cout << "\n\t\t\t\t\t\tplease enter your password: ";
	getline(cin, password);

	for (int i = 0; i < users.size(); i++) {
		if (users[i].username == username && users[i].password == password) {
			cout << "\n\t\t\t\t\t\t\t Welcome " << users[i].username << "!" << endl;
			cout << "\n\t\t\t\t\t\tPress enter to continue...";
			cin.ignore();
			return true;
		}
	}


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

void displayloginmenu() {
	//banner
	cout << "\n\t                               ,^      /l			" << endl;
	cout << "\t                             ;  l   ;' l			" << endl;
	cout << "\t                      \\^\\.   j' ,| ,'   l			" << endl;
	cout << "\t                      |0 '';;],, [; _, ,j			" << endl;
	cout << "\t                    {_, ''.    ''L     ;;		    " << endl;
	cout << "\t                    ,:' '               ':			" << endl;
	cout << "\t                 _,:I   -,                ;,		" << endl;
	cout << "\t                _,u    QJ,                 ;,                    __                                 __" << endl;
	cout << "\t               --}    ---.,,__             ';,  _      __ ___   / /_____ ____   ____ ___   ___     / /_ ____" << endl;
	cout << "\t                ||    T_=--..,_             ,; | | /| / // _ \\./ // ___// __ \\ / __ `__ \\ / _ \\   / __// __ \\" << endl;
	cout << "\t            ,:''-';,    ',                    ;| |/ |/ //  __// // /__ / /_/ // / / / / //  __/  / /_ / /_/ /	" << endl;
	cout << "\t          ,;'     ^';,                         |__/|__/ \\___//_/ \\___/ \\____//_/ /_/ /_/ \\___/   \\__/ \\____/ " << endl;
	cout << "\t        ,C   u-      ';,          ___   / /__  __   _____ (_)____   ___   ____ ___   ____ _ _____ 	" << endl;
	cout << "\t       ,:   ||;j       ;         / _ \\ / // / / /  / ___// // __ \\ / _ \\ / __ `__ \\ / __ `// ___/" << endl;
	cout << "\t       .j     u-　      ;.       /  __// // /_/ /  / /__ / // / / //  __// / / / / // /_/ /(__  ) " << endl;
	cout << "\t       '~    --        ;:       \\___//_/ \\__, /   \\___//_//_/ /_/ \\___//_/ /_/ /_/ \\__,_//____/ " << endl;
	cout << "\t       .;               j               /____/  ,;  	" << endl;
	cout << "\t       i                {                       ;	" << endl;

	cout << "\n\n\t------------------------------------------------------------------------------------------------------------------ " << endl;
	cout << "\t-----------------------------------------------[user menu]-------------------------------------------------------- " << endl;
	cout << "\t------------------------------------------------------------------------------------------------------------------ " << endl;
	//the rest of everything
	cout << "\n\t\t\t\t\t\t1\tview all moview" << endl;
	cout << "\t\t\t\t\t\t2\tpurchase tickets" << endl;
	//bla bla im not sure what to add
	cout << "\t\t\t\t\t\t3\t ..." << endl;
	cout << "\t\t\t\t\t\t4\tto log out: go back to main menu" << endl;
	cout << "\t\t\t\t\t\t5\texit" << endl;


	int userchoice;

	cout << "\n\t\t\t\t\t\tEnter your choice: ";
	cin >> userchoice;

	switch (userchoice) {
	case 1:
		// option 1: View all movies
		cout << "Viewing all movies..." << flush;
		system("CLS");
		//displayseats();
		break;
	case 2:
		// Handle option 2: Purchase tickets
		cout << "Purchasing tickets..." << endl;
		// Add your code here
		break;
	case 3:



		break;
	case 4:
		// Handle option 4: Back to main menu
		cout << "Going back to main menu..." << flush;
		system("CLS");
		displaymenu();
		break;
	case 5:
		// Handle option 5: Exit
		cout << "Exiting..." << endl;
		// Add your code here
		return; // Exit the loop and the function
	default:
		// Handle invalid input
		cout << "Invalid choice. Please try again." << endl;
		break;
	}
	system("Pause");



}

int main() {


	char choice;
	char admin_choice;
	loadUsersFromFile();
	bool isLoggedIn = false;
	bool validInput = false;
	do {
		system("CLS");
		displaymenu();
		cout << "\n\t\t\t\t\t\tenter your choice: ";
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
				cout << "\n\tYou are already logged in" << endl;
				cout << "\tRedirecting you to the user menu...\n" << endl;

				showLoadingBar(duration, delay);

				cin.ignore();
				system("CLS");
				displayloginmenu();

			}
			break;

		case '3':
		{
			char logout;
			
			if (!isLoggedIn) { 
				cout << "\n\tYou're not logged in\n\tPress enter to go back to the main menu" << endl; 
				cin.ignore();
				cin.ignore();
				displaymenu();
				break;
			}
			cout << "\tLog out?" << endl;
			cout << "\n\tPress 'Y' to logout" << endl;
			cout << "\n\tPress any other key to go back to the main screen" << endl;
			cout << "\t:";
			cin >> logout;
			if (logout == 'Y' || logout == 'y') {
				isLoggedIn = false;
				cout << "\n\tYou have successfully logged out of the system\n\tPress enter to go back to the main menu" << endl; 
				cin.ignore();
				cin.ignore();
				displaymenu();

			}
			else {
				cout << "\n\tYou're still logged in\n\tPress enter to go back to the main menu" << endl; 
				cin.ignore();
				cin.ignore();
			}
			break;
		}

		case '4':
		{
			////admin login
			int max_attempts = 3;
			int attempts = 0;
			bool login_successful = false;
			
			while (attempts < max_attempts && !login_successful) {
				system("CLS");
				if (adminLogin()) {
					login_successful = true; 
					displayadminmenu();

					cout << "\n\t\t\t\t\t\tEnter your choice: ";
					cin >> admin_choice;
				}
				else {
					attempts++;
					cout << "\n\t\t\t\t\t\tIncorrect login credentials. Attempts remaining: " << max_attempts - attempts << endl;
					if (attempts<3){
					cout << "\n\t\t\t\t\t\tPress any key to try again..." << endl;
					}
					else {
						cout << "\n\t\t\t\t\t\tYou have exceeded the maximum number of login attempts.\n\t\t\t\t\t\tredirecting to the main page...." << endl;
						showLoadingBar(duration, delay);

					}
					cin.ignore();
					cin.ignore();
				}
			}

			break;
		}

		case '5':
			cout << "\nGoodbye!" << endl;
			return 0;
		default:

			cout << "\nInvalid choice.\n" << endl;
			system("Pause");
			break;
		}

	} while (choice != 5);
}
