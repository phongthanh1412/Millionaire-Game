#include"functions.h"

void prepareForGame(myListPlayer& playerlist, myListQuestion& questionlist) {
    string name, address, occupation;
    int idx = 0;
    char button, arrow;

    gotoxy(75, 20);
    cout << YELLOW << "START TO PLAY!" << RESET;
    char enter;
    do {
        enter = _getch();
    } while (enter != 13);

    mainMenuScreen(idx);

    while (1) {
        button = _getch();
        // Nhấn Enter để chọn chỉ mục cần thực hiện
        if (button == 13) {
            if (idx == 0) {
                int idx1 = 0;
                char set;
                system("cls");
                tutorial();
                char back = ' ';
                backToMenu(back, idx);
            }           
            else if (idx == 1) {
                system("cls");
                login(name, address, occupation);
                system("cls");
                readQuestionFromFile(questionlist);
                gotoxy(65, 20);
                cout << "Press any key to back to main menu...";
                char back = ' ';
                backToMenu(back, idx);
            }
        }
        else if (button == 'E') {
            questionlist.deleteQuestionMemoryList();
            break;
        }
        // Nhấn mũi tên để di chuyển giữa các chỉ mục
        else {
            arrow = _getch();
            if (arrow == 72) {
                idx = (idx - 1 + 2) % 2;
            }
            else if (arrow == 80) {
                idx = (idx + 1) % 2;
            }
            mainMenuScreen(idx);
        }
    }
}