#ifndef DIVISION_H
#define DIVISION_H

/*
 * No description
 */
class Division
{
	// private section
	public:
		// class constructor
		Division();
		Division(int id, const char *name);
		Division(Division &division);
		// class destructor
		~Division();
		
		void SetId(int id);
		void SetName(const char *name);
		
		int GetId();
		void GetName(char *name);
	//protected:
		
		int m_Id; // Ma bo phan
		char m_Name[255]; // Ten bo phan
};

#endif // DIVISION_H

