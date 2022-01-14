#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
//#include <window.h>
#include "MyDefine.h"
#include "Application.h"
#include "MyDate.h"
#include "ApplicationManager.h"
#include "SalaryManager.h"
#include "AdvancePayment.h"
#include "AdvancePaymentDB.h"

int main()
{
///*
	  ApplicationManager::GetInstance()->StartApp(new SalaryManager());
	  ApplicationManager::FreeInstance();
//*/	  
/*
      AdvancePaymentDB a;
      a.Init("..\\Data\\AdvancePaymentDB.dat");
      a.Load();
      a.Export("D:\\AdvancePaymentListExport1.txt");
      getch();
      a.UnLoad();
//*/
      return 0;    
}
