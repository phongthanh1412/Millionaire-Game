#include"functions.h"

// Hàm xác định toạ độ các dòng chữ, bảng
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Hàm quay về màn hình chính
void backToMenu(char back, int idx) {
    do {
        back = _getch();
    } while (back != 13);
    system("cls");
    mainMenuScreen(idx);
}

void tutorial() {
    cout << "Tutorial";
}

void login(string& name, string& address, string& occupation) {
    gotoxy(65, 10);
    cout << " _                 _       ";
    gotoxy(65, 11);
    cout << "| |               (_)      ";
    gotoxy(65, 12);
    cout << "| |     ___   __ _ _ _ __  ";
    gotoxy(65, 13);
    cout << "| |    / _ \\ / _` | | '_ \\ ";
    gotoxy(65, 14);
    cout << "| |___| (_) | (_| | | | | |";
    gotoxy(65, 15);
    cout << "|______\\___/ \\__, |_|_| |_|";
    gotoxy(65, 16);
    cout << "              __/ |        ";
    gotoxy(65, 17);
    cout << "             |___/         ";
    cout << "\033[21;75H" << COLOR_BACKGROUND_l << WHITE << "::[ Login ]::" << RESET;
    cout << "\033[23;65H" << COLOR_BACKGROUND_l << WHITE << "   Enter your name:  " << RESET;
    getline(cin, name);
    cout << "\033[25;65H" << COLOR_BACKGROUND_l << WHITE << "   Enter your address:  " << RESET;
    getline(cin, address);
    cout << "\033[27;65H" << COLOR_BACKGROUND_l << WHITE << "   Enter your occupation:  " << RESET;
    getline(cin, occupation);
}

void myListQuestion::addQuestion(question* newQuestion) {
    if (head == NULL)
    {
        head = newQuestion;
    }
    else
    {
        question* cur = head;
        if (head == NULL)
        {
            head = newQuestion;
        }
        else
        {
            question* temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newQuestion->next = temp->next;
            temp->next = newQuestion;

        }
    }
}

void myListQuestion::deleteQuestion(char& ans) {
    if (head == NULL)
        return;
    int cnt = 0;
    question* cur = head;
    question* prev = NULL;
    while (cur != NULL && cnt < 2)
    {
        if (cur->ans != ans)
        {
            if (prev != NULL)
            {
                prev->next = cur->next;
            }
            else
            {
                head = cur->next;
            }
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
        cnt++;
    }
}

void readQuestionFromFile(myListQuestion& questionlist) {
    fstream ifile("questions.txt", ios::in);
    if (ifile.eof())
    {
        cout << "Unable to open file questions.txt" << endl;
        return;
    }
    int idx = 0;
    string query, ansA, ansB, ansC, ansD;
    char ans;
    bool isFiftyUsed = 0, isCallUsed = 0, isConsultUsed = 0;
    while (getline(ifile, query, ';')) {
        const char* text1[] = {
        "  __  __ _____ _      _      _____ ____  _   _          _____ _____  ______ ",
        " |  \\/  |_   _| |    | |    |_   _/ __ \\| \\ | |   /\\   |_   _|  __ \\|  ____|",
        " | \\  / | | | | |    | |      | || |  | |  \\| |  /  \\    | | | |__) | |__   ",
        " | |\\/| | | | | |    | |      | || |  | | . ` | / /\\ \\   | | |  _  /|  __|  ",
        " | |  | |_| |_| |____| |____ _| || |__| | |\\  |/ ____ \\ _| |_| | \\ \\| |____ ",
        " |_|  |_|_____|______|______|_____\\____/|_| \\_/_/    \\_\\_____|_|  \\_\\______|",
        "                                                                           ",
        "                                                                           "
        };

        int startX1 = 10;
        int startY1 = 2;

        for (int i = 0; i < 8; i++) {
            gotoxy(startX1, startY1 + i);
            cout << text1[i];
        }
        drawAnswer();

        PlaySound(TEXT("./sound/mainTheme.wav"), NULL, SND_FILENAME | SND_ASYNC);
        auto start = high_resolution_clock::now();

        getline(ifile, ansA, ';');
        getline(ifile, ansB, ';');
        getline(ifile, ansC, ';');
        getline(ifile, ansD, ';');
        ifile >> ans;
        string dummy;
        getline(ifile, dummy); // Đọc bỏ dòng thừa nếu có

        question* newQuestion = new question(query, ansA, ansB, ansC, ansD, ans);
        questionlist.addQuestion(newQuestion);
        questionlist.showQuestion();

        helpScreen(idx);
        float timeLapse;
        bool timeIsUp = false;
        char c = '\0';
        gotoxy(10, 23);
        cout << "Your answer:  ";

        while (!timeIsUp) {
            auto now = high_resolution_clock::now();
            auto duration = duration_cast<seconds>(now - start);
            timeLapse = duration.count();
            if (duration.count() >= 30) {
                PlaySound(TEXT("./sound/timesUp.wav"), NULL, SND_FILENAME | SND_ASYNC);
                gotoxy(10, 29);
                cout << COLOR_BACKGROUND_g << setw(19) << " " << RESET << endl;
                gotoxy(10, 30);
                cout << COLOR_BACKGROUND_g << "  " << WHITE << setw(10) << left << "   TIME'S UP   " << COLOR_BACKGROUND_g << "  " << RESET << endl;
                gotoxy(10, 31);
                cout << COLOR_BACKGROUND_g << setw(19) << " " << RESET << endl;
                timeIsUp = true;
            }

            if (_kbhit()) {
                c = _getch();

                if (c == 'H') {
                    char button, arrow;
                    bool helpUsed = false;
                    while (!helpUsed) {
                        button = _getch();
                        if (button == 13) {
                            if (idx == 0 && !isFiftyUsed) {
                                fify_fifty(questionlist, newQuestion);
                                helpUsed = true;
                                isFiftyUsed = true;
                            }
                            else if (idx == 1 && !isCallUsed) {
                                callFriend(newQuestion);
                                helpUsed = true;
                                isCallUsed = true;
                            }
                            else if (idx == 2 && !isConsultUsed) {
                                askAudience(newQuestion);
                                helpUsed = true;
                                isConsultUsed = true;
                            }
                        }
                        else if (button == 'e') {
                            helpUsed = true;
                        }
                        else {
                            arrow = _getch();
                            if (arrow == 72) {
                                idx = (idx - 1 + 3) % 3;
                            }
                            else if (arrow == 80) {
                                idx = (idx + 1) % 3;
                            }
                            helpScreen(idx);
                        }
                    }                  
                    gotoxy(10, 23);
                    cout << "Your answer:  ";
                    c = _getch();
                }
                break;
            }
        }
        if (timeIsUp) {
            char c1 = _getch();
            system("cls");
            break;
        }
        if (c == newQuestion->ans) {
            drawAnswer2(c);

            gotoxy(10, 29);
            cout << COLOR_BACKGROUND_r << setw(51) << " " << RESET << endl;
            gotoxy(10, 30);
            cout << COLOR_BACKGROUND_r << "  " << WHITE << setw(10) << left << "  Congratulations! That's the correct answer!  " << COLOR_BACKGROUND_r << "  " << RESET << endl;
            gotoxy(10, 31);
            cout << COLOR_BACKGROUND_r << setw(51) << " " << RESET << endl;
            PlaySound(TEXT("./sound/correct.wav"), NULL, SND_FILENAME | SND_ASYNC);
        }
        else if (c != newQuestion->ans && timeLapse < 5) {
            drawAnswer2(c);

            gotoxy(10, 29);
            cout << COLOR_BACKGROUND_g << setw(51) << " " << RESET << endl;
            gotoxy(10, 30);
            cout << COLOR_BACKGROUND_g << "  " << WHITE << setw(10) << left << "Sorry. That's incorrect! Better luck next time!" << COLOR_BACKGROUND_g << "  " << RESET << endl;
            gotoxy(10, 31);
            cout << COLOR_BACKGROUND_g << setw(51) << " " << RESET << endl;
            PlaySound(TEXT("./sound/wrong.wav"), NULL, SND_FILENAME | SND_ASYNC);
            char c1 = _getch();
            system("cls");
            break;
        }

        // Kiểm tra eof để quyết định quay lại menu
        if (ifile.eof()) {
            char c1 = _getch();
            break;
        }
        else {
            char c1 = _getch();
            system("cls");
        }
    }
    ifile.close();
}
void myListQuestion::showQuestion() {
    question* temp = head;
    while (temp != NULL)
    {
        gotoxy(0, 10);
        cout << ERASE;
        gotoxy(0, 11);
        cout << ERASE;
        gotoxy(0, 12);
        cout << ERASE;
        gotoxy(0, 13);
        cout << ERASE;
        gotoxy(0, 10);
        cout << temp->query;
        gotoxy(20, 14);
        cout << ERASE;
        gotoxy(20, 14);
        cout << temp->ansA;
        gotoxy(20, 16);
        cout << ERASE;
        gotoxy(20, 16);
        cout << temp->ansB;
        gotoxy(20, 18);
        cout << ERASE;
        gotoxy(20, 18);
        cout << temp->ansC;
        gotoxy(20, 20);
        cout << ERASE;
        gotoxy(20, 20);
        cout << temp->ansD;

        temp = temp->next;
    }
}

void myListQuestion::showQuestion2(question* newQuestion) {
    while (newQuestion != NULL) {
        gotoxy(0, 10);
        cout << newQuestion->query;

        string res[4] = { newQuestion->ansA, newQuestion->ansB, newQuestion->ansC, newQuestion->ansD };
        bool correct[4] = { false, false, false, false };

        if (newQuestion->ans == 'A')
            correct[0] = true;
        if (newQuestion->ans == 'B')
            correct[1] = true;
        if (newQuestion->ans == 'C')
            correct[2] = true;
        if (newQuestion->ans == 'D')
            correct[3] = true;

        // Xác định các đáp án sai và lưu trữ chỉ số của chúng
        int incorrectIdx[2];
        int idx = 0;
        for (int i = 0; i < 4; i++) {
            if (!correct[i]) {
                incorrectIdx[idx++] = i;
                if (idx == 2)
                    break;
            }
        }
        // Chọn ngẫu nhiên hai chỉ số để loại bỏ từ các đáp án sai
        srand(time(0));
        int removeIdx1 = incorrectIdx[rand() % 2];
        int removeIdx2 = incorrectIdx[rand() % 2];
        while (removeIdx2 == removeIdx1) {
            removeIdx2 = incorrectIdx[rand() % 2];
        }
        // Đánh dấu các đáp án được loại bỏ là rỗng
        res[removeIdx1] = "";
        res[removeIdx2] = "";
        // In ra các đáp án còn lại      

        gotoxy(20, 14);
        cout << ERASE;
        gotoxy(20, 14);
        if (res[0] != "")
            cout << res[0];
        else cout << "A.";

        gotoxy(20, 16);
        cout << ERASE;

        gotoxy(20, 16);
        if (res[1] != "")
            cout << res[1];
        else cout << "B.";

        gotoxy(20, 18);
        cout << ERASE;

        gotoxy(20, 18);
        if (res[2] != "")
            cout << res[2];
        else cout << "C.";

        gotoxy(20, 20);
        cout << ERASE;

        gotoxy(20, 20);
        if (res[3] != "")
            cout << res[3];
        else cout << "D.";

        newQuestion = newQuestion->next;
        helpScreen(idx);
        drawTable();
    }
}
void myListQuestion::deleteQuestionMemoryList() {
    while (head != NULL)
    {
        question* temp = head;
        head = head->next;
        delete temp;
    }
    head = NULL;
}