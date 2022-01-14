#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
// Util
#define SAFE_DEL(p) {if(p != 0){ delete p; p = 0;}}
#define SAFE_DEL_ARRAY(p)  if(p != 0){ delete [] p; p = 0;}
#define CLEAR_SCREEN()   {fflush(stdout); system("cls");}
// Config
#define CONFIG_FILE "..\\Config.txt"
// Const
#define MAX_DATA_BASE 10
#define NUMBER_DATA_BASE 9


#define TEXT_PLEASE_RECHOISE     "\n Please choise again!"
#define TEXT_LOGIN_SUCEED        "\n Login succeed!"
#define TEXT_LOGIN_FAULT         "\n Login fault!"
#define TEXT_LOGIN_INCORRECT     "\n Username or Password is incorrect!"
#define TEXT_FORMAT_PAGE_NUMBER  "\n                            Page: %d"
// POPUP
#define TEXT_NOT_PERMISSION  "\n You don't have permission."
#define TEXT_NOT_IMPLEMENT   "\n Not yet been implemented!"
// FORMAT STRING
//" %3s %-25s %-10s %-5s %s"
#define TEXT_FORMAT_STAFF_INFOR "%2d %-25s %-12s %-5s %s"

// define keypad
#define SPECIAL_KEY -32
#define ESC_KEY 27
#define ENTER_KEY 13
#define DELETE_SKEY 83
#define BACK_SPACE_KEY 8

#define RIGHT_SKEY 77
#define LEFT_SKEY 75

#define BASIC_SALARY 2150000
