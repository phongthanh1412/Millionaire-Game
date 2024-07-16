#include"functions.h"

void helpScreen(int idx) {
    drawTable();
    const char* text2[] = {
        "  _    _ ______ _      _____  ",
        " | |  | |  ____| |    |  __ \\ ",
        " | |__| | |__  | |    | |__) |",
        " |  __  |  __| | |    |  ___/ ",
        " | |  | | |____| |____| |     ",
        " |_|  |_|______|______|_|     ",
        "                              "
    };

    int startX2 = 120;
    int startY2 = 2;

    for (int i = 0; i < 7; i++) {
        gotoxy(startX2, startY2 + i);
        cout << text2[i];
    }
    const char* title[] = {
        "             50:50 - Fifty-Fifty            ",
        "             Phone a friend                 ",
        "             Ask the audience               "
    };
    int size = sizeof(title) / sizeof(title[0]);
    int pos = 13;
    gotoxy(110, 10);
    cout << COLOR_BACKGROUND_i << "  " << COLOR_BACKGROUND_i << WHITE << "                   Options                    " << COLOR_BACKGROUND_i << "  " << RESET << endl;
    gotoxy(110, 11);
    cout << COLOR_BACKGROUND_i << "  " << COLOR_BACKGROUND_i << "                                              " << COLOR_BACKGROUND_i << "  " << RESET << endl;
    gotoxy(110, 12);
    cout << COLOR_BACKGROUND_i << "  " << COLOR_BACKGROUND_k << "                                              " << COLOR_BACKGROUND_i << "  " << RESET << endl;

    for (int i = 0; i < size; i++) {
        gotoxy(110, pos + i * 2); // Tăng khoảng cách giữa các dòng
        if (i == idx) {
            cout << COLOR_BACKGROUND_i << "  " << RESET << COLOR_BACKGROUND_l << WHITE << title[i] << "  " << COLOR_BACKGROUND_i << "  " << RESET << endl;
        }
        else {
            cout << COLOR_BACKGROUND_i << "  " << RESET << COLOR_BACKGROUND_k << BLACK << title[i] << "  " << RESET << COLOR_BACKGROUND_i << "  " << RESET << endl;
        }
        gotoxy(110, pos + i * 2 + 1); // Thêm dòng trống giữa các mục
        cout << COLOR_BACKGROUND_i << "  " << COLOR_BACKGROUND_k << "                                              " << COLOR_BACKGROUND_i << "  " << RESET << endl;
    }

    gotoxy(110, pos + size * 2);
    cout << COLOR_BACKGROUND_i << setw(50) << " " << RESET << endl;
}
