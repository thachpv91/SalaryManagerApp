#include "division.h" // class's header file
#include "MyDefine.h"
#include "MyDate.h"
// class constructor
Division::Division()
{
	// insert your code here
}

// class destructor
Division::~Division()
{
	// insert your code here
}
Division::Division(int id, const char *name)
{
	m_Id = id;
	strcpy(m_Name, name);
	// insert your code here
}
Division::Division(Division &division)
{
	// insert your code here
	m_Id = division.GetId();
	division.GetName(m_Name);
}
void Division::SetId(int id)
{
	// insert your code here
	m_Id = id;
}
void Division::SetName(const char *name)
{
	// insert your code here
	strcpy(m_Name, name);
}
int Division::GetId()
{
	// insert your code here
	return m_Id;
}
void Division::GetName(char *name)
{
	// insert your code here
	strcpy(name, m_Name);
}
