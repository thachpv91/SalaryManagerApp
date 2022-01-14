#include "myutil.h" // class's header file
#include "MyDefine.h"

void MyUtil::GetPass(const char * prompt, char * pass)
{

  char password[255] = "";
  unsigned char ch=0;
  int passLength = 0; 
  printf("%s", prompt);

  while((ch=getch())!= ENTER_KEY)
    {
         passLength = strlen(password);
         if(ch == BACK_SPACE_KEY)
        {	
         	if( passLength > 0)
         	{
              printf("\b \b"); // Xoa lui
              password[passLength - 1] = '\0';
            }
         }
         else if(ch==0 || ch==224) // handle escape sequences
         {
             getch(); // ignore non printable chars
             continue;
         }
       else
       {
         	 putchar(ch);  // Doc va hien ky tu pass
             password[passLength] = ch;
             Sleep(300);
             printf("\b \b"); // Xoa lui ky tu, sau do in ra dau *
             printf("*");
        }
    }
  password[passLength+1] = '\0';
  strcpy(pass, password);
}
bool MyUtil::MyCopyFile(const char * fileIn, const char * fileOut)
{
    FILE * pFileIn = fopen(fileIn, "rb");
    FILE * pFileOut = fopen(fileOut, "wb");
    if(pFileIn == NULL || pFileOut == NULL)
    {
	   return false;
	}
	char c;
	while(fread( &c, sizeof(char), 1, pFileIn))
	{
	    fwrite(&c,  sizeof(char), 1, pFileOut);
	}
	return true;
}
char *  MyUtil::MyStrStr(const char * dir, const char *key)
{
     char s1[255] = "";
     char s2[255] = "";
     strcpy(s1, dir);
     strcpy(s2, key);
     
     MyToLowerStr(s1);
     MyToLowerStr(s2);
     
     return strstr(s1, s2);
     
}
void MyUtil::MyToUpperStr(char *str)
{
    for(int i = 0 ; i < strlen(str); i++)
    {
	    str[i] = toupper(str[i]);
	}
}
void MyUtil::MyToLowerStr(char *str)
{
    for(int i = 0 ; i < strlen(str); i++)
    {
	    str[i] = tolower(str[i]);
	}
}

