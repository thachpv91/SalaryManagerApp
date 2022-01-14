#ifndef POSITION_H
#define POSITION_H

/*
 * No description
 */
class Position
{
	// private section
	public:
		Position();
		Position(Position &pos);
		Position(int id, const char * name, int factor);
		~Position();
		
		void SetId(int positionId);
		void SetName(const char *position);
		void SetCoefficientPay(int factor);
		
		int GetId();
		void GetName(char *position);
		int GetCoefficientPay();
		
		
		
//	protected:
		int m_Id; // Ma vi tri cong viec / chuc vu
		char m_Name[255]; // Ten Vi tri con viec / chuc vu
		int  m_CoefficientPay ; // he so luong
};

#endif // POSITION_H

