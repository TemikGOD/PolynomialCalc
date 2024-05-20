///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxUIPM.h"

///////////////////////////////////////////////////////////////////////////

frameMain::frameMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxFrame( parent, id, title, pos, size, style, name )
{
	this->SetSizeHints( wxSize( 521,262 ), wxSize( 521,262 ) );

	m_menubar1 = new wxMenuBar( 0 );
	m_menu_file = new wxMenu();
	wxMenuItem* m_menuItem_open;
	m_menuItem_open = new wxMenuItem( m_menu_file, wxID_ANY, wxString( wxT("Open...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_file->Append( m_menuItem_open );

	wxMenuItem* m_menuItem_save;
	m_menuItem_save = new wxMenuItem( m_menu_file, wxID_ANY, wxString( wxT("Save") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_file->Append( m_menuItem_save );

	wxMenuItem* m_menuItem_save_as;
	m_menuItem_save_as = new wxMenuItem( m_menu_file, wxID_ANY, wxString( wxT("Save as...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu_file->Append( m_menuItem_save_as );

	m_menubar1->Append( m_menu_file, wxT("File") );

	m_menu_table = new wxMenu();
	wxMenuItem* m_menuItem_lin_arr;
	m_menuItem_lin_arr = new wxMenuItem( m_menu_table, wxID_ANY, wxString( wxT("Linear on an array") ) , wxEmptyString, wxITEM_RADIO );
	m_menu_table->Append( m_menuItem_lin_arr );

	wxMenuItem* m_menuItem_lin_list;
	m_menuItem_lin_list = new wxMenuItem( m_menu_table, wxID_ANY, wxString( wxT("Linear on the list") ) , wxEmptyString, wxITEM_RADIO );
	m_menu_table->Append( m_menuItem_lin_list );

	wxMenuItem* m_menuItem_order_arr;
	m_menuItem_order_arr = new wxMenuItem( m_menu_table, wxID_ANY, wxString( wxT("Ordered on an array") ) , wxEmptyString, wxITEM_RADIO );
	m_menu_table->Append( m_menuItem_order_arr );

	wxMenuItem* m_menuItem_open_hash;
	m_menuItem_open_hash = new wxMenuItem( m_menu_table, wxID_ANY, wxString( wxT("Hash with open adressing") ) , wxEmptyString, wxITEM_RADIO );
	m_menu_table->Append( m_menuItem_open_hash );

	wxMenuItem* m_menuItem_hash_chain;
	m_menuItem_hash_chain = new wxMenuItem( m_menu_table, wxID_ANY, wxString( wxT("Hash with the chain metod") ) , wxEmptyString, wxITEM_RADIO );
	m_menu_table->Append( m_menuItem_hash_chain );

	wxMenuItem* m_menuItem_avl;
	m_menuItem_avl = new wxMenuItem( m_menu_table, wxID_ANY, wxString( wxT("AVL tree") ) , wxEmptyString, wxITEM_RADIO );
	m_menu_table->Append( m_menuItem_avl );

	m_menubar1->Append( m_menu_table, wxT("Table") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	m_panel3 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );


	bSizer11->Add( 0, 0, 3, wxEXPAND, 5 );

	m_staticText3 = new wxStaticText( m_panel3, wxID_ANY, wxT("Input calculation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	m_staticText3->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer11->Add( m_staticText3, 2, wxALL, 3 );


	bSizer10->Add( bSizer11, 1, wxALL, 0 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrl35 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 350,-1 ), 0 );
	m_textCtrl35->SetMinSize( wxSize( -1,25 ) );
	m_textCtrl35->SetMaxSize( wxSize( -1,25 ) );

	bSizer18->Add( m_textCtrl35, 5, wxALL|wxEXPAND, 5 );

	m_buttonCalculate = new wxButton( m_panel3, wxID_ANY, wxT("Calculate"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_buttonCalculate, 1, wxALL, 5 );


	bSizer10->Add( bSizer18, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );

	m_staticText23 = new wxStaticText( m_panel3, wxID_ANY, wxT("Result"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer53->Add( m_staticText23, 0, wxALL, 5 );


	bSizer10->Add( bSizer53, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrl17 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer54->Add( m_textCtrl17, 5, wxALL, 5 );

	m_buttonMainSave = new wxButton( m_panel3, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( m_buttonMainSave, 1, wxALL, 5 );


	bSizer10->Add( bSizer54, 1, wxEXPAND, 5 );


	bSizer9->Add( bSizer10, 1, wxALL|wxEXPAND, 0 );


	m_panel3->SetSizer( bSizer9 );
	m_panel3->Layout();
	bSizer9->Fit( m_panel3 );
	bSizer8->Add( m_panel3, 1, wxALL|wxEXPAND, 0 );


	bSizer7->Add( bSizer8, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer7 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_menu_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameMain::OpenMenuSelected ), this, m_menuItem_open->GetId());
	m_menu_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameMain::SaveMenuSelected ), this, m_menuItem_save->GetId());
	m_menu_file->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameMain::SaveAsMenuSelected ), this, m_menuItem_save_as->GetId());
	m_menu_table->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameMain::m_menuItem_lin_arr_selected ), this, m_menuItem_lin_arr->GetId());
	m_menu_table->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameMain::m_menuItem_lin_list_selected ), this, m_menuItem_lin_list->GetId());
	m_menu_table->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameMain::m_menuItem_order_arr_selected ), this, m_menuItem_order_arr->GetId());
	m_menu_table->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameMain::m_menuItem_open_hash_selected ), this, m_menuItem_open_hash->GetId());
	m_menu_table->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameMain::m_menuItem_hash_chain_selected ), this, m_menuItem_hash_chain->GetId());
	m_menu_table->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( frameMain::m_menuItem_avl_selected ), this, m_menuItem_avl->GetId());
	m_buttonCalculate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::CalculateClick ), NULL, this );
	m_buttonMainSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::MainSaveClick ), NULL, this );
}

frameMain::~frameMain()
{
	// Disconnect Events
	m_buttonCalculate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::CalculateClick ), NULL, this );
	m_buttonMainSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameMain::MainSaveClick ), NULL, this );

}

frameTable::frameTable( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_gridTable = new wxGrid( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_gridTable->CreateGrid( 0, 2 );
	m_gridTable->EnableEditing( false );
	m_gridTable->EnableGridLines( true );
	m_gridTable->EnableDragGridSize( false );
	m_gridTable->SetMargins( 0, 0 );

	// Columns
	m_gridTable->SetColSize( 0, 53 );
	m_gridTable->SetColSize( 1, 71 );
	m_gridTable->AutoSizeColumns();
	m_gridTable->EnableDragColMove( false );
	m_gridTable->EnableDragColSize( true );
	m_gridTable->SetColLabelValue( 0, wxT("Key") );
	m_gridTable->SetColLabelValue( 1, wxT("Value") );
	m_gridTable->SetColLabelValue( 2, wxEmptyString );
	m_gridTable->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_gridTable->EnableDragRowSize( true );
	m_gridTable->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_gridTable->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer11->Add( m_gridTable, 100, wxALL|wxEXPAND, 0 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonClearTable = new wxButton( m_panel2, wxID_ANY, wxT("Clear Table"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( m_buttonClearTable, 0, wxALL, 5 );


	bSizer12->Add( 0, 0, 5, wxEXPAND, 0 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonAddItem = new wxButton( m_panel2, wxID_ANY, wxT("Add Item"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_buttonAddItem, 0, wxALL, 5 );

	m_buttonRenameItem = new wxButton( m_panel2, wxID_ANY, wxT("Rename Item"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_buttonRenameItem, 0, wxALL, 5 );

	m_buttonDeleteItem = new wxButton( m_panel2, wxID_ANY, wxT("Delete Item"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_buttonDeleteItem, 0, wxALL, 5 );


	bSizer12->Add( bSizer13, 1, wxALL|wxEXPAND, 0 );


	bSizer11->Add( bSizer12, 1, wxEXPAND, 5 );


	bSizer10->Add( bSizer11, 1, wxALL|wxEXPAND, 0 );


	m_panel2->SetSizer( bSizer10 );
	m_panel2->Layout();
	bSizer10->Fit( m_panel2 );
	bSizer9->Add( m_panel2, 1, wxEXPAND | wxALL, 0 );


	bSizer8->Add( bSizer9, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer8 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( frameTable::tableClosed ) );
	m_buttonClearTable->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameTable::ClearTableClick ), NULL, this );
	m_buttonAddItem->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameTable::AddItemClick ), NULL, this );
	m_buttonRenameItem->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameTable::RenameItemClick ), NULL, this );
	m_buttonDeleteItem->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameTable::DeleteItemClick ), NULL, this );
}

frameTable::~frameTable()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( frameTable::tableClosed ) );
	m_buttonClearTable->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameTable::ClearTableClick ), NULL, this );
	m_buttonAddItem->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameTable::AddItemClick ), NULL, this );
	m_buttonRenameItem->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameTable::RenameItemClick ), NULL, this );
	m_buttonDeleteItem->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( frameTable::DeleteItemClick ), NULL, this );

}

MyDialogAdd::MyDialogAdd( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("Enter a unique key and value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer18->Add( m_staticText4, 0, wxALL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer15->Add( bSizer18, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextKey = new wxStaticText( this, wxID_ANY, wxT("Key:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextKey->Wrap( -1 );
	bSizer16->Add( m_staticTextKey, 0, wxALL, 5 );

	m_textCtrlAddKey = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_textCtrlAddKey, 1, wxALL, 5 );

	m_staticTextValue = new wxStaticText( this, wxID_ANY, wxT("Value:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextValue->Wrap( -1 );
	bSizer16->Add( m_staticTextValue, 0, wxALL, 5 );

	m_textCtrlAddValue = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_textCtrlAddValue, 3, wxALL, 5 );


	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonAddDialog = new wxButton( this, wxID_ANY, wxT("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_buttonAddDialog, 0, wxALL, 5 );

	m_buttonCancelDialog = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_buttonCancelDialog, 0, wxALL, 5 );


	bSizer15->Add( bSizer17, 1, wxEXPAND, 5 );


	bSizer14->Add( bSizer15, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer14 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_buttonAddDialog->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogAdd::AddDialogButtonClick ), NULL, this );
	m_buttonCancelDialog->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogAdd::CancelDialogButtonClick ), NULL, this );
}

MyDialogAdd::~MyDialogAdd()
{
	// Disconnect Events
	m_buttonAddDialog->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogAdd::AddDialogButtonClick ), NULL, this );
	m_buttonCancelDialog->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogAdd::CancelDialogButtonClick ), NULL, this );

}

MyDialogDelete::MyDialogDelete( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticTextDel = new wxStaticText( this, wxID_ANY, wxT("Enter key"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDel->Wrap( -1 );
	bSizer18->Add( m_staticTextDel, 0, wxALL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer15->Add( bSizer18, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextKey = new wxStaticText( this, wxID_ANY, wxT("Key:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextKey->Wrap( -1 );
	bSizer16->Add( m_staticTextKey, 0, wxALL, 5 );

	m_textCtrlDelKey = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_textCtrlDelKey, 1, wxALL, 5 );


	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonDeleteDialog = new wxButton( this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_buttonDeleteDialog, 0, wxALL, 5 );

	m_buttonCancelDialog = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_buttonCancelDialog, 0, wxALL, 5 );


	bSizer15->Add( bSizer17, 1, wxEXPAND, 5 );


	bSizer14->Add( bSizer15, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer14 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_buttonDeleteDialog->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogDelete::DeleteDialogButtonClick ), NULL, this );
	m_buttonCancelDialog->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogDelete::CancelDialogButtonClick ), NULL, this );
}

MyDialogDelete::~MyDialogDelete()
{
	// Disconnect Events
	m_buttonDeleteDialog->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogDelete::DeleteDialogButtonClick ), NULL, this );
	m_buttonCancelDialog->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogDelete::CancelDialogButtonClick ), NULL, this );

}

MyDialogRename::MyDialogRename( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );

	m_staticTextDel = new wxStaticText( this, wxID_ANY, wxT("Enter the current key then enter the values in the fields you want to change"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextDel->Wrap( -1 );
	bSizer18->Add( m_staticTextDel, 0, wxALL, 5 );


	bSizer18->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer15->Add( bSizer18, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextKey = new wxStaticText( this, wxID_ANY, wxT("Current key:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextKey->Wrap( -1 );
	bSizer16->Add( m_staticTextKey, 1, wxALL, 5 );

	m_textCtrlDelKey = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_textCtrlDelKey, 5, wxALL, 5 );


	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextKey1 = new wxStaticText( this, wxID_ANY, wxT("New key:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextKey1->Wrap( -1 );
	bSizer161->Add( m_staticTextKey1, 1, wxALL, 5 );

	m_textCtrlDelKey1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer161->Add( m_textCtrlDelKey1, 5, wxALL, 5 );


	bSizer15->Add( bSizer161, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer1611;
	bSizer1611 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextKey11 = new wxStaticText( this, wxID_ANY, wxT("New value:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextKey11->Wrap( -1 );
	bSizer1611->Add( m_staticTextKey11, 1, wxALL, 5 );

	m_textCtrlDelKey11 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer1611->Add( m_textCtrlDelKey11, 5, wxALL, 5 );


	bSizer15->Add( bSizer1611, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );


	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonRenameDialog = new wxButton( this, wxID_ANY, wxT("Rename"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_buttonRenameDialog, 0, wxALL, 5 );

	m_buttonCancelDialog = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_buttonCancelDialog, 0, wxALL, 5 );


	bSizer15->Add( bSizer17, 1, wxEXPAND, 5 );


	bSizer14->Add( bSizer15, 1, wxALL|wxEXPAND, 0 );


	this->SetSizer( bSizer14 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_buttonRenameDialog->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogRename::RenameDialogButtonClick ), NULL, this );
	m_buttonCancelDialog->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogRename::CancelDialogButtonClick ), NULL, this );
}

MyDialogRename::~MyDialogRename()
{
	// Disconnect Events
	m_buttonRenameDialog->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogRename::RenameDialogButtonClick ), NULL, this );
	m_buttonCancelDialog->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogRename::CancelDialogButtonClick ), NULL, this );

}

MyDialogSaveResult::MyDialogSaveResult( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 356,161 ), wxSize( 356,161 ) );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Insert key"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	m_staticText12->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer36->Add( m_staticText12, 1, wxALL, 5 );


	bSizer33->Add( bSizer36, 1, wxEXPAND, 0 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );

	m_textCtrl9 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( m_textCtrl9, 5, wxALL, 5 );

	m_buttonSaveResult = new wxButton( this, wxID_ANY, wxT("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( m_buttonSaveResult, 0, wxALL, 5 );


	bSizer33->Add( bSizer34, 2, wxEXPAND, 0 );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );


	bSizer35->Add( 0, 0, 1, wxEXPAND, 5 );

	m_buttonCancelSaveResult = new wxButton( this, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_buttonCancelSaveResult, 0, wxALL, 5 );


	bSizer33->Add( bSizer35, 2, wxEXPAND, 0 );


	bSizer32->Add( bSizer33, 1, wxEXPAND, 0 );


	this->SetSizer( bSizer32 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_buttonSaveResult->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogSaveResult::SaveResultClick ), NULL, this );
	m_buttonCancelSaveResult->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogSaveResult::CancelSaveResultClick ), NULL, this );
}

MyDialogSaveResult::~MyDialogSaveResult()
{
	// Disconnect Events
	m_buttonSaveResult->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogSaveResult::SaveResultClick ), NULL, this );
	m_buttonCancelSaveResult->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialogSaveResult::CancelSaveResultClick ), NULL, this );

}
