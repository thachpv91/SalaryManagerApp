#include "searchmenustate.h" // class's header file
#include "appstate.h" // inheriting class's header file
#include "MyDefine.h"
SearchMenuState::SearchMenuState()
{
}

SearchMenuState::~SearchMenuState()
{
}
void SearchMenuState::Init()
{

}
void SearchMenuState::Update()
{
    CLEAR_SCREEN();
    DisplayMenu();
    char c = getch();
    switch(c)
    {
	    case '1': printf("1.Search()"); return;
	}
}
void SearchMenuState::DisplayMenu()
{
     
     printf("\n\n   Search and Edit Staff Infor");
     printf("\n ---------------------------------\n");
     printf("\n 1. Search ");
     printf("\n 2. Edit");
     printf("\n 3. Remove ");
     printf("\n ----------------------------------");
     printf("\n Choise: ");
}


