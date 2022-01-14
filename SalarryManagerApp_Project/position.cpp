#include "position.h" // class's header file
#include "MyDefine.h"
Position::Position(){}
Position::Position(Position &pos)
{
    m_Id = pos.GetId();
    pos.GetName(m_Name);
    m_CoefficientPay = pos.GetCoefficientPay();
}
Position::Position(int id, const char * name, int factor)
{
    m_Id = id;
    strcpy(m_Name, name);
    m_CoefficientPay = factor;
	 
}
Position::~Position(){}
void Position::SetId(int positionId)
{
	m_Id = positionId;
}
void Position::SetName(const char *position)
{
	strcpy(m_Name, position);
}
void Position::SetCoefficientPay(int factor)
{
	m_CoefficientPay = factor;
}
int Position::GetId()
{
	return m_Id;
}
void Position::GetName(char *position)
{
	strcpy(position, m_Name);
}
int Position::GetCoefficientPay()
{
	return (m_CoefficientPay > 0) ? m_CoefficientPay : 1;
}
