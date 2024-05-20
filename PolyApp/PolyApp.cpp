// Polynomial.cpp : Defines the entry point for the application.
//
#define _HAS_STD_BYTE 0
#include "PolyApp.h"
#include <wx/app.h>
class MyApp : public wxApp
{
public:
	MyApp() {};
	virtual ~MyApp() {};
	virtual bool OnInit();
};

// ₀₁₂₃₄₅₆₇₈₉
// ¹²³⁴⁵⁶⁷⁸⁹⁰

DECLARE_APP(MyApp)

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() 
{
	PolyMathUIframeMain* mainFraime = new PolyMathUIframeMain(NULL);
	mainFraime->Show();
	return true; //Return true to continue processing, false to exit the application immediately.
}

//int main()
//{
//	ad::Vector<TableInterface<std::string, Polynomial>*> tables; 
//	auto table1 = new LinearListTable<std::string, Polynomial>();
//	auto table2 = new LinearTableOnAnArray<std::string, Polynomial>();
//	auto table3 = new OrderedTable<std::string, Polynomial>();
//	auto table4 = new AVLTreeTable<std::string, Polynomial>();
//	auto table5 = new OpenHashTable<std::string, Polynomial>(6);
//	auto table6 = new ListHashTable<std::string, Polynomial>();
//	tables.push_back(table1);
//	tables.push_back(table2);
//	tables.push_back(table3);
//	tables.push_back(table4);
//	tables.push_back(table5);
//	tables.push_back(table6);
//	Polynomial* asdd = new Polynomial();
//	for (int i = 0; i < tables.size(); i++)
//		(*tables[i]).add("saa", asdd);
//	for (int i = 0; i < tables.size(); i++)
//		(*tables[i]).add("saw", asdd);
//	for (int i = 0; i < tables.size(); i++)
//		(*tables[i]).add("sas", asdd);
//	for (int i = 0; i < tables.size(); i++)
//		(*tables[i]).erase("saa");
//	return 0;
//}
