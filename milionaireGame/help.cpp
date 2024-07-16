#include"functions.h"

void fify_fifty(myListQuestion& questionlist, question* newQuestion) {
	
    PlaySound(TEXT("./sound/50-50.wav"), NULL, SND_FILENAME | SND_ASYNC);
	questionlist.showQuestion2(newQuestion);
}

void callFriend(question* newQuestion) {
    
    gotoxy(30, 23);
    cout << "Who do you want to call? ";
    string name;
    cin >> name;
    gotoxy(30, 25);
    cout << BLUE << "We are connecting with " << name << "..." << RESET << endl;
    PlaySound(TEXT("./sound/callfriend.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Sleep(44000);
    gotoxy(30, 27);
    cout << GREEN << name << " chooses answer " << newQuestion->ans << RESET;
   
}

void askAudience(question* newQuestion) {

    gotoxy(30, 25);
    cout << BLUE << "We are consulting the audience..." << RESET;
    PlaySound(TEXT("./sound/askAudience.wav"), NULL, SND_FILENAME | SND_ASYNC);
    Sleep(32000);
    gotoxy(30, 27);
    cout << GREEN << "80% of the audience chooses answer " << newQuestion->ans << RESET;
}