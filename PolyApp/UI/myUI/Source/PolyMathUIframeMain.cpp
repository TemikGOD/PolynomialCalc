#include "../Headers/PolyMathUIframeMain.h"

PolyMathUIframeMain::PolyMathUIframeMain( wxWindow* parent )
:
frameMain( parent )
{
	selectedTable = Table_LinearTableOnAnArray;
	auto table1 = new LinearListTable<std::string, Polynomial>();
	auto table2 = new LinearTableOnAnArray<std::string, Polynomial>();
	auto table3 = new OrderedTable<std::string, Polynomial>();
	auto table4 = new AVLTreeTable<std::string, Polynomial>();
	auto table5 = new OpenHashTable<std::string, Polynomial>();
	auto table6 = new ListHashTable<std::string, Polynomial>();
	tables.push_back(table1);
	tables.push_back(table2);
	tables.push_back(table3);
	tables.push_back(table4);
	tables.push_back(table5);
	tables.push_back(table6);
	for (auto i = 0; i < tables.size(); i++)
		tablesUI[i] = new PolyMathUIframeTable(this);
}

void PolyMathUIframeMain::OpenMenuSelected( wxCommandEvent& event )
{
// TODO: Implement OpenMenuSelected
}

void PolyMathUIframeMain::SaveMenuSelected( wxCommandEvent& event )
{
// TODO: Implement SaveMenuSelected
}

void PolyMathUIframeMain::SaveAsMenuSelected( wxCommandEvent& event )
{
// TODO: Implement SaveAsMenuSelected
}

void PolyMathUIframeMain::m_menuItem_lin_arr_selected( wxCommandEvent& event )
{
	selectedTable = Table_LinearTableOnAnArray;
	tablesUI[selectedTable]->Show();
}

void PolyMathUIframeMain::m_menuItem_lin_list_selected( wxCommandEvent& event )
{
	selectedTable = Table_LinearListTable;
	tablesUI[selectedTable]->Show();
}

void PolyMathUIframeMain::m_menuItem_order_arr_selected( wxCommandEvent& event )
{
	selectedTable = Table_OrderedTable;
	tablesUI[selectedTable]->Show();
}

void PolyMathUIframeMain::m_menuItem_open_hash_selected( wxCommandEvent& event )
{
	selectedTable = Table_OpenHashTable;
	tablesUI[selectedTable]->Show();
}

void PolyMathUIframeMain::m_menuItem_hash_chain_selected( wxCommandEvent& event )
{
	selectedTable = Table_ListHashTable;
	tablesUI[selectedTable]->Show();
}

void PolyMathUIframeMain::m_menuItem_avl_selected( wxCommandEvent& event )
{
	selectedTable = Table_AVLTreeTable;
	tablesUI[selectedTable]->Show();
}

void PolyMathUIframeMain::TextUpdated( wxCommandEvent& event )
{
// TODO: Implement TextUpdated
}

void PolyMathUIframeMain::CalculateClick( wxCommandEvent& event )
{
// TODO: Implement CalculateClick
}

void PolyMathUIframeMain::MainSaveClick( wxCommandEvent& event )
{
// TODO: Implement MainSaveClick
}
