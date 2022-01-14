#ifndef MYUTIL_H
#define MYUTIL_H

/*
 * No description
 */
namespace MyUtil
{

	void GetPass(const char * prompt, char * input);
	bool MyCopyFile(const char * fileIn, const char * fileOut);
	char *  MyStrStr(const char * dir, const char *key);
	void MyToUpperStr(char *str);
	void MyToLowerStr(char *str);
};
#endif // MYUTIL_H

