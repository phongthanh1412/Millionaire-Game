#include"functions.h"

void drawAnswer2(char c) {
    if (c == 'A') {
        gotoxy(10, 25);
        cout << COLOR_BACKGROUND_k << setw(5) << " " << RESET << endl;
        gotoxy(10, 26);
        cout << COLOR_BACKGROUND_k << "  " << BLACK << "A" << COLOR_BACKGROUND_k << "  " << RESET << endl;
        gotoxy(10, 27);
        cout << COLOR_BACKGROUND_k << setw(5) << " " << RESET << endl;
    }
    else if (c == 'B') {
        gotoxy(14, 25);
        cout << COLOR_BACKGROUND_k << setw(5) << " " << RESET << endl;
        gotoxy(14, 26);
        cout << COLOR_BACKGROUND_k << "  " << BLACK << "B" << COLOR_BACKGROUND_k << "  " << RESET << endl;
        gotoxy(14, 27);
        cout << COLOR_BACKGROUND_k << setw(5) << " " << RESET << endl;
    }
    else if (c == 'C') {
        gotoxy(18, 25);
        cout << COLOR_BACKGROUND_k << setw(5) << " " << RESET << endl;
        gotoxy(18, 26);
        cout << COLOR_BACKGROUND_k << "  " << BLACK << "C" << COLOR_BACKGROUND_k << "  " << RESET << endl;
        gotoxy(18, 27);
        cout << COLOR_BACKGROUND_k << setw(5) << " " << RESET << endl;
    }
    else if (c == 'D') {
        gotoxy(22, 25);
        cout << COLOR_BACKGROUND_k << setw(5) << " " << RESET << endl;
        gotoxy(22, 26);
        cout << COLOR_BACKGROUND_k << "  " << BLACK << "D" << COLOR_BACKGROUND_k << "  " << RESET << endl;
        gotoxy(22, 27);
        cout << COLOR_BACKGROUND_k << setw(5) << " " << RESET << endl;
    }
}