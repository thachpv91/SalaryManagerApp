#ifndef ADVANCEPAYMENTDB_H
#define ADVANCEPAYMENTDB_H

#include "databaseinterface.h" // inheriting class's header file

/*
 * No description
 */
class AdvancePayment;
class AdvancePaymentDB : public DataBaseInterface
{
	// private section
	public:
		// class constructor
		AdvancePaymentDB();
		// class destructor
		~AdvancePaymentDB();
		virtual void Import(const char *fileTxt);
		virtual void Export(const char *fileTxt);
		
		virtual void Load();
		virtual void Save();
		virtual void UnLoad();
		
		virtual void SaveOnlyChange();
		vector<AdvancePayment*> GetData();
		
		AdvancePayment * FindByStaffId(int id);
	protected:
		vector<AdvancePayment*> m_data;
};

#endif // ADVANCEPAYMENTDB_H

