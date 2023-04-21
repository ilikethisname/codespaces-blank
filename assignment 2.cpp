/*
    !!!Please don't share or copy to avoid plagiarism!!!
 */


/*
things that havent been done
-----------------------------
error checking for the registration
seat reservation (seating plan display is done)
contents of the user and admin menu
the loading bar... isnt perfect
by ree
*/

/*
 1) sometimes the order of functions prototype matters
 2) add in module one by one: please check and make sure the whole program runs as it should be at your stage before passing to another, debug for possible errors before passing to another, this is to make sure we can know where the program gone wrong at which module
 3) i add system('cls') at my part after the whole program is complete
 
 changes done:
 1) at end of ree's displayadminmenu() to match my admin update part
 2) case 4: admin login there added my modules
 3) changed admin choice from char type to int type
 
 by joseph
 */
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

// ree's part
const int ROWS = 10;
const int COLUMNS = 17;

//admin username and password
const string username = "admin";
const string password = "password";

const int duration = 5; // Total duration of the loading bar in seconds
const int delay = 100; // Delay between progress updates in milliseconds



// joseph's part: for admin update, display movie details, searching
const int Size = 50;

struct Movie{
    string name,time,location;
};




//ree's part: functions prototypes
void displaymenu();
void registerUser();
void loadUsersFromFile();
void showLoadingBar(int duration, int delay);
void displayloginmenu();
bool loginUser();
bool adminLogin();
void displayadminmenu();
void displayseats();

//joseph's part: functions prototypes
bool check_exist (string name, string moviesOS[]);
int null_index(string moviesOS[]);
void set_movieOS(Movie movies[], string moviesOS[]);
bool compare(const Movie &a, const Movie &b);
int check_index(Movie movies[]);
int starting_index(Movie movies[]);
void movie_details(string moviesOS[],Movie movies[]);
void update(Movie movies[],string movieOS[]);



//user login - struct
struct User {
    string name;
    string username;
    string password;
    string phone_number;
};

vector<User> users;


int main() {
    
    //joseph: read in movies.txt and arrange before anything else
    Movie movies[Size] = {};
    string moviesOS[Size] = {};
    ifstream inMovies("movies.txt");
    char dummy;

    //read in movies.txt
    if (inMovies.is_open()){
        int i = 0;
        
        while (!inMovies.eof()){
            getline(inMovies,movies[i].name);
            inMovies >> movies[i].time;
            inMovies.ignore();
            getline(inMovies,movies[i].location);
            inMovies.ignore();
            i++;
        }
        inMovies.close();
    }
    else
        cout << "Unable to open movies.txt!";

    //sort the movies array ascendingly according to time
    //display original movie table
    sort(movies, movies + Size, compare);
    movie_details(moviesOS, movies);
    
    

    //ree: login
    char choice;
    int admin_choice;
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
                    cout << endl << endl;
                    
                    while (admin_choice >= 1 && admin_choice <= 3){
                        if (admin_choice == 1){
                            //view movies
                            movie_details(moviesOS, movies);
                            cin.ignore();
                        }
                            
                        else if (admin_choice == 2){
                            
                            //start of admin update menu
                            update(movies,moviesOS);
                            
                            
                            //update movies.txt
                            ofstream outFile ("movies.txt", ios::out);
                            
                            for (int i = starting_index(movies); i < Size; i ++){
                                outFile << movies[i].name << endl;
                                outFile << movies[i].time << " " << movies[i].location << endl << endl;
                            }
                            
                            outFile.close();
        
                            
                            //Display updated movie table
                            cout << "The new movie table:\n\n";
                            movie_details(moviesOS, movies);
                            cout << "Changes are successfully updated." << endl;
                            
                        }
                        else if (admin_choice == 3)
                            cout << "William, are you doing this part too?";
                        
                        
                        cout << "\n\t\t\t\t\t  press any key to go back to admin update interface...";
                        cin.ignore();
                        displayadminmenu();
                        cout << "\n\t\t\t\t\t\tEnter your choice: ";
                        cin >> admin_choice;
                        
                    }
                    

                    
                }
                else {
                    attempts++;
                    cout << "\n\t\t\t\t\t\tIncorrect login credentials. Attempts remaining: " << max_attempts - attempts << endl;
                    if (attempts < 3) {
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

    system("Pause");
    return 0;
}



//ree's functions definitions

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

void displayseats() {


    //seating plan benner
    cout << "\t\t\t\t                       __                 __             __   _             " << endl;
    cout << "\t\t\t\t   _____ ___   ____ _ / /_   _____ ___   / /___   _____ / /_ (_)____   ____ " << endl;
    cout << "\t\t\t\t  / ___// _ \\ / __ `// __/  / ___// _ \\ / // _ \\ / ___// __// // __ \\ / __ \\" << endl;
    cout << "\t\t\t\t (__  )/  __// /_/ // /_   (__  )/  __// //  __// /__ / /_ / // /_/ // / / /" << endl;
    cout << "\t\t\t\t/____/ \\___/ \\__,_/ \\__/  /____/ \\___//_/ \\___/ \\___/ \\__//_/ \\____//_/ /_/ " << endl;

    cout << "\n\n\t------------------------------------------------------------------------------------------------------------------ " << endl;
    cout << "\t--------------------------------------------------[choose your seat]---------------------------------------------- " << endl;
    cout << "\t------------------------------------------------------------------------------------------------------------------ " << endl;

    char seats[ROWS][COLUMNS];

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            seats[i][j] = ' ';
        }
    }

    char rowLabel = 'A';
    for (int i = 0; i < ROWS; i++) {
        cout << "\n\t\t\t\t\t";
        for (int j = 1; j <= COLUMNS; j++) {
            // Check if the seat is taken
            if (seats[i][j - 1] == 'X') {
                cout << "X ";
            }
            else {
                cout << rowLabel << j << " ";
            }
        }
        rowLabel++;
        cout << endl;
    }

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
    cout << "\n\t                               ,^      /l            " << endl;
    cout << "\t                             ;  l   ;' l            " << endl;
    cout << "\t                      \\^\\.   j' ,| ,'   l            " << endl;
    cout << "\t                      |0 '';;],, [; _, ,j            " << endl;
    cout << "\t                    {_, ''.    ''L     ;;            " << endl;
    cout << "\t                    ,:' '               ':            " << endl;
    cout << "\t                 _,:I   -,                ;,        " << endl;
    cout << "\t                _,u    QJ,                 ;,                    __                                 __" << endl;
    cout << "\t               --}    ---.,,__             ';,  _      __ ___   / /_____ ____   ____ ___   ___     / /_ ____" << endl;
    cout << "\t                ||    T_=--..,_             ,; | | /| / // _ \\./ // ___// __ \\ / __ `__ \\ / _ \\   / __// __ \\" << endl;
    cout << "\t            ,:''-';,    ',                    ;| |/ |/ //  __// // /__ / /_/ // / / / / //  __/  / /_ / /_/ /    " << endl;
    cout << "\t          ,;'     ^';,                         |__/|__/ \\___//_/ \\___/ \\____//_/ /_/ /_/ \\___/   \\__/ \\____/ " << endl;
    cout << "\t        ,C   u-      ';,          ___   / /__  __   _____ (_)____   ___   ____ ___   ____ _ _____     " << endl;
    cout << "\t       ,:   ||;j       ;         / _ \\ / // / / /  / ___// // __ \\ / _ \\ / __ `__ \\ / __ `// ___/" << endl;
    cout << "\t       .j     u-　      ;.       /  __// // /_/ /  / /__ / // / / //  __// / / / / // /_/ /(__  ) " << endl;
    cout << "\t       '~    --        ;:       \\___//_/ \\__, /   \\___//_//_/ /_/ \\___//_/ /_/ /_/ \\__,_//____/ " << endl;
    cout << "\t       .;               j               /____/  ,;      " << endl;
    cout << "\t       i                {                       ;    " << endl;

    cout << "\n\n\t------------------------------------------------------------------------------------------------------------------ " << endl;
    cout << "\t----------------------------------------------------[admin menu]-------------------------------------------------- " << endl;
    cout << "\t------------------------------------------------------------------------------------------------------------------ " << endl;

    cout << "\n\t\t\t\t\t\t\t1\tView Movies" << endl;
    cout << "\t\t\t\t\t\t\t2\tPerform Update" << endl;
    cout << "\t\t\t\t\t\t\t3\tCheck transactions and profit" << endl;
    cout << "\t\t\t\t\t\t\tPress any other number to exit " << endl;
    

}

void displaymenu() {

    cout << "\n\t                               ,^      /l            " << endl;
    cout << "\t                             ;  l   ;' l            " << endl;
    cout << "\t                      \\^\\.   j' ,| ,'   l            " << endl;
    cout << "\t                      |0 '';;],, [; _, ,j            " << endl;
    cout << "\t                    {_, ''.    ''L     ;;            " << endl;
    cout << "\t                    ,:' '               ':            " << endl;
    cout << "\t                 _,:I   -,                ;,        " << endl;
    cout << "\t                _,u    QJ,                 ;,                    __                                 __" << endl;
    cout << "\t               --}    ---.,,__             ';,  _      __ ___   / /_____ ____   ____ ___   ___     / /_ ____" << endl;
    cout << "\t                ||    T_=--..,_             ,; | | /| / // _ \\./ // ___// __ \\ / __ `__ \\ / _ \\   / __// __ \\" << endl;
    cout << "\t            ,:''-';,    ',                    ;| |/ |/ //  __// // /__ / /_/ // / / / / //  __/  / /_ / /_/ /    " << endl;
    cout << "\t          ,;'     ^';,                         |__/|__/ \\___//_/ \\___/ \\____//_/ /_/ /_/ \\___/   \\__/ \\____/ " << endl;
    cout << "\t        ,C   u-      ';,          ___   / /__  __   _____ (_)____   ___   ____ ___   ____ _ _____     " << endl;
    cout << "\t       ,:   ||;j       ;         / _ \\ / // / / /  / ___// // __ \\ / _ \\ / __ `__ \\ / __ `// ___/" << endl;
    cout << "\t       .j     u-　      ;.       /  __// // /_/ /  / /__ / // / / //  __// / / / / // /_/ /(__  ) " << endl;
    cout << "\t       '~    --        ;:       \\___//_/ \\__, /   \\___//_//_/ /_/ \\___//_/ /_/ /_/ \\__,_//____/ " << endl;
    cout << "\t       .;               j               /____/  ,;      " << endl;
    cout << "\t       i                {                       ;    " << endl;

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
    cout << "\t              ( \\    " << endl;
    cout << "\t   __         _)_\\_    " << endl;
    cout << "\t  ' \\;---.-._S_____2_                               _        __    " << endl;
    cout << "\t    /   / /_/       (______           _____ ___   ____ _ (_)_____ / /_ ___   _____" << endl;
    cout << "\t __(  _;-'    =    =|____._'.__          / ___// _ \\ / __ `// // ___// __// _ \\ / ___/" << endl;
    cout << "\t/   _/     _  @\\ _(@(      '--'.     / /   /  __// /_/ // /(__  )/ /_ /  __// /" << endl;
    cout << "\t(_ /      /\\  _   =( ) ___     \\    /_/    \\___/ \\__, //_//____/ \\__/ \\___//_/" << endl;
    cout << "\t  /      /\\ \\_ '.___'-.___~.    '\\           /____/   ____   ____  _      __" << endl;
    cout << "\t /      /\\ \\__'--') '-.__c` \\    |                   / __ \\ / __ \\| | /| / /" << endl;
    cout << "\t|     .'  )___'--'/  /`)     \\   /                   / / / // /_/ /| |/ |/ /" << endl;
    cout << "\t|    |'-|    _|--'\\_(_/       '.'                  /_/ /_/ \\____/ |__/|__/" << endl;
    cout << "\t|    |   \\_  -\\    " << endl;
    cout << "\t\\   |     \\ /`)    " << endl;
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

    cout << "\t  _,                           _     " << endl;
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
    cout << "\t              ]__\\     \\___;                  " << endl;
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
    cout << "\n\t                               ,^      /l            " << endl;
    cout << "\t                             ;  l   ;' l            " << endl;
    cout << "\t                      \\^\\.   j' ,| ,'   l            " << endl;
    cout << "\t                      |0 '';;],, [; _, ,j            " << endl;
    cout << "\t                    {_, ''.    ''L     ;;            " << endl;
    cout << "\t                    ,:' '               ':            " << endl;
    cout << "\t                 _,:I   -,                ;,        " << endl;
    cout << "\t                _,u    QJ,                 ;,                    __                                 __" << endl;
    cout << "\t               --}    ---.,,__             ';,  _      __ ___   / /_____ ____   ____ ___   ___     / /_ ____" << endl;
    cout << "\t                ||    T_=--..,_             ,; | | /| / // _ \\./ // ___// __ \\ / __ `__ \\ / _ \\   / __// __ \\" << endl;
    cout << "\t            ,:''-';,    ',                    ;| |/ |/ //  __// // /__ / /_/ // / / / / //  __/  / /_ / /_/ /    " << endl;
    cout << "\t          ,;'     ^';,                         |__/|__/ \\___//_/ \\___/ \\____//_/ /_/ /_/ \\___/   \\__/ \\____/ " << endl;
    cout << "\t        ,C   u-      ';,          ___   / /__  __   _____ (_)____   ___   ____ ___   ____ _ _____     " << endl;
    cout << "\t       ,:   ||;j       ;         / _ \\ / // / / /  / ___// // __ \\ / _ \\ / __ `__ \\ / __ `// ___/" << endl;
    cout << "\t       .j     u-　      ;.       /  __// // /_/ /  / /__ / // / / //  __// / / / / // /_/ /(__  ) " << endl;
    cout << "\t       '~    --        ;:       \\___//_/ \\__, /   \\___//_//_/ /_/ \\___//_/ /_/ /_/ \\__,_//____/ " << endl;
    cout << "\t       .;               j               /____/  ,;      " << endl;
    cout << "\t       i                {                       ;    " << endl;

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
        displayseats();
        //cin << seat
        //more will be here
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




//joseph's function definitions

//check for existence of same movie in moviesOS array
bool check_exist (string name, string moviesOS[]){
    for (int i = 0; i < Size; i++){
        if (name == moviesOS[i])
            return true;
    }
    
    return false;
}


//check for first position without null string
int null_index(string moviesOS[]){
    int pos = 0;
    for (int i = 0; i < Size; i++){
        if (moviesOS[i] != "")
            pos ++;
        else
            break;
    }
    
    return pos;
}


//find out movies on show without repeating movies
void set_movieOS(Movie movies[], string moviesOS[]){
    for (int i = 0; i < Size; i++ ){
        string name = movies[i].name;
        
        if (! check_exist(name, moviesOS)){
            int index = null_index(moviesOS);
            moviesOS[index] = name;
        }
    }
}


//compare condition for sorting in ascending order based on time
bool compare(const Movie &a, const Movie &b){
    return a.time < b.time;
}


//find the starting index for the null structs in array
int check_index(Movie movies[]){
    for (int i = 0; i < Size; i++){
        if (movies[i].name == "" && movies[i].time == "" && movies[i].location == "")
            return i;
    }
    
    return 50;
}

//find starting index that contains movie slot in movies array
int starting_index(Movie movies[]){
    for (int i = 0; i < Size; i++){
        if (movies[i].name == "" && movies[i].time == "" && movies[i].location == "");
        else
            return i;
    }
    return 50;
}


//show movie details(name, time, hall)
void movie_details(string moviesOS[],Movie movies[]){
    set_movieOS(movies,moviesOS);
    cout << left << setw(30) << "Movies" << setw(17) << "| Showtime" << setw(15) << "| Halls" << endl;
    
    for (int i = 0; i < null_index(moviesOS); i++){
        cout << "---------------------------------------------------------" << endl;
        for (int j = 0; j < Size; j++){
            if (movies[j].name == moviesOS[i])
                cout << setw(30) << movies[j].name << "| " << setw(15) << movies[j].time << "| " << setw(15) << movies[j].location << endl;
        }
    }
    cout << "---------------------------------------------------------" << endl;
}


//admin update
void update(Movie movies[],string movieOS[]){
    int choice;
    char choice2;
    
    do{
        int search_index[50], index, no = 0;
        string name, changed_time,changed_location, add_name, add_time, add_hall;
        bool valid_name = false;
        
        do{
            cout << "\nAdmin Interface: Update Menu" << endl;
            cout << "1) Change movie slot(Showtime/Hall)" << endl;
            cout << "2) Add movie slot" << endl;
            cout << "3) Delete movie slot" << endl;
            cout << "4) Exit\n" << endl;
            cout << "Please enter 1,2,3 or 4: " ;
            cin >> choice;
            cin.ignore();
            cout << endl;
            
            if (choice > 4 || choice < 1)
                cout << "Invalid input. Please enter again..." << endl;
            
        }while (choice > 4 || choice < 1);
        
        
        //check for valid movie name, display specific movie details if valid
        while (!valid_name && choice != 2 && choice != 4){
            cout << "Enter the name of movie to perform update/changes: ";
            getline(cin,name);
            cout << endl << endl;
            cout << left << setw(30) << name << "|   Showtime" << setw(15) << "|    Halls" << endl;
            cout << "---------------------------------------------------------" << endl;
            
            //Display specific movie details for admin as reference
            for (int i = 0; i < Size; i ++){
                if (movies[i].name == name){
                    valid_name = true;
                    no++;
                    search_index[no] = i; //collect index of specific movie
                    cout << "(" << no  << ")" << right << setw(29) << "| " << setw(10) << movies[i].time << "|   " << movies[i].location << endl;
                }
            }
            
            if (!valid_name)
                cout << "Movie not found in database.\nPlease be careful with the spellings and capital letters.\n---------------------------------------------------------" << endl;
        }
        
        //change showtime or hall
        if (choice == 1){
            
            cout << "\nPress 'A' for changing showtime.\nPress 'B' for changing hall.\nEnter: ";
            cin >> choice2;
            cout << endl;
            
            if (choice2 == 'A'){
                cout << "Which slot's showtime do you want to change (Enter number): ";
                cin >> no;
                index = search_index[no];
                cout << "Changing showtime from " << movies[index].time << " to: " ;
                cin.ignore();
                getline(cin, changed_time);
                movies[index].time = changed_time;
                sort(movies, movies + Size, compare);
            }
            
            else if (choice2 == 'B'){
                cout << "Which slot's hall do you want to change (Enter number): ";
                cin >> no;
                index = search_index[no];
                cout << "Changing hall from " << movies[index].location << " to: " ;
                cin.ignore();
                getline(cin,changed_location);
                movies[index].location = changed_location;
            }
            
            else
                cout << "Invalid choice! Exiting back to Admin Interface..." << endl;
            
        }
        
        //add new movie slot
        else if (choice == 2){
            cout << "Movie Name: ";
            getline(cin, add_name);
            cout << "Showtime: ";
            cin >> add_time;
            cin.ignore();
            cout << "Hall: ";
            getline(cin, add_hall);
            
            index = check_index(movies);
            if (index == Size)
                cout << " Error: The movie storage is full. Movie not added.\nExiting back to Admin Interface..." << endl;
            else{
                movies[index].name = add_name;
                movies[index].time = add_time;
                movies[index].location = add_hall;
                sort(movies, movies + Size, compare);
            }
        }
        
        //delete movie slot
        else if (choice == 3){
            cout << "Which slot to delete (Enter number): ";
            cin >> no;
            index = search_index[no];
            for (int i = index; i < Size - 1; i ++)
                movies[i] = movies[i + 1];
            movies[Size - 1] = movies[0];
        }
            
    }while (choice != 4);
    
}
