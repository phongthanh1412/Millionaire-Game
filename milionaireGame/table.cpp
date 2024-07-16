#include"functions.h"

void drawTable() {
    gotoxy(112, 21);
    cout << COLOR_BACKGROUND_l << "                                            " << RESET << endl;
    gotoxy(112, 22);
    cout << COLOR_BACKGROUND_l << "  " << COLOR_BACKGROUND_c << BLUE << "  Question number  "
         << COLOR_BACKGROUND_l << "  " << COLOR_BACKGROUND_c << "   Question value  "
         << COLOR_BACKGROUND_l << "  " << RESET << endl;
    gotoxy(112, 23);
    cout << COLOR_BACKGROUND_l << "                                            " << RESET << endl;

    int questionNumbers[15] = { 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
    string questionValues[15] = { "1000000 $", "500000 $", "250000 $", "125000 $", "64000 $",
                                      "32000 $", "16000 $", "8000 $", "4000 $", "2000 $",
                                      "1000 $", "500 $", "300 $", "200 $", "100 $" };

    for (int i = 0; i < 15; i++) {
        gotoxy(112, 24 + i);
        cout << COLOR_BACKGROUND_l << "  "
            << COLOR_BACKGROUND_c << BLACK << setw(10) << internal << questionNumbers[i] << RESET << COLOR_BACKGROUND_c << "  "
            << COLOR_BACKGROUND_c << BLACK << setw(26) << internal << questionValues[i] << RESET << COLOR_BACKGROUND_c << "  "
            << COLOR_BACKGROUND_l << "  " << RESET << endl;
    }

    gotoxy(112, 23 + 16);
    cout << COLOR_BACKGROUND_l << setw(44) << " " << RESET << endl;
}