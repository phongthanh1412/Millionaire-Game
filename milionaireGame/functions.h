#pragma once

#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <string>
#include <mmsystem.h>
#include <chrono>

const char GREEN[] = "\033[32m";
const char RED[] = "\033[31m";
const char YELLOW[] = "\033[33m";
const char BLUE[] = "\033[34m";
const char WHITE[] = "\033[1;37m";
const char BLACK[] = "\033[30m";
const char COLOR_BACKGROUND_c[] = "\033[48;5;230m";
const char COLOR_BACKGROUND_f[] = "\033[48;5;203m";
const char COLOR_BACKGROUND_g[] = "\033[48;5;196m";
const char COLOR_BACKGROUND_i[] = "\033[48;5;21m";
const char COLOR_BACKGROUND_k[] = "\033[48;5;12m";
const char COLOR_BACKGROUND_l[] = "\033[48;5;94m";
const char COLOR_BACKGROUND_q[] = "\033[48;5;196m";
const char COLOR_BACKGROUND_r[] = "\033[48;5;22m";


const char ERASE[] = "\033[2K";
const char RESET[] = "\033[0m";

using namespace std;
using namespace std::chrono;

// Khai báo và khởi tạo cấu trúc 1 gameplayer
struct gamePlayer
{
    string name, address, occupation;
    
    gamePlayer* next;

    gamePlayer(string name, string address, string occupation)
    {
        this->name = name;
        this->address = address;
        this->occupation = occupation;
        this->next = NULL;
    }
};

// Các hàm thao tác với danh sách customer
struct myListPlayer
{
    gamePlayer* head;

    myListPlayer() {
        head = NULL;
    }

};
// Khai báo và khởi tạo cấu trúc 1 question
struct question
{
    string query, ansA, ansB, ansC, ansD;
    char ans;
    
    question* next;

    question(string query, string ansA, string ansB, string ansC, string ansD, char ans)
    {
        this->query = query;
        this->ansA = ansA;
        this->ansB = ansB;
        this->ansC = ansC;
        this->ansD = ansD;
        this->ans = ans;
        this->next = NULL;
    }
};

// Các hàm thao tác với danh sách customer
struct myListQuestion
{
    question* head;

    myListQuestion() {
        head = NULL;
    }

    void addQuestion(question* newQuestion);

    void deleteQuestion(char& ans);

    void showQuestion();

    void showQuestion2(question* newQuestion);

    void deleteQuestionMemoryList();

};

void gotoxy(int x, int y);

void backToMenu(char back, int idx);

void mainMenuScreen(int idx);

void helpScreen(int idx);

void tutorial();

void drawTable();

void drawAnswer();

void drawAnswer2(char c);

void helpScreen(int idx);

void prepareForGame(myListPlayer& playerlist, myListQuestion& questionlist);

void login(string& name, string& address, string& occupation);

void readQuestionFromFile(myListQuestion& questionlist);

void fify_fifty(myListQuestion& questionlist, question* newQuestion);

void callFriend(question* newQuestion);

void askAudience(question* newQuestion);

