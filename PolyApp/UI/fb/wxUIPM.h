///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.1.0-0-g733bf3d)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class frameMain
///////////////////////////////////////////////////////////////////////////////
class frameMain : public wxFrame
{
	private:

	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_menu_file;
		wxMenu* m_menu_table;
		wxPanel* m_panel3;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_textCtrl35;
		wxButton* m_buttonCalculate;
		wxStaticText* m_staticText23;
		wxTextCtrl* m_textCtrl17;
		wxButton* m_buttonMainSave;

		// Virtual event handlers, override them in your derived class
		virtual void OpenMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void SaveMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void SaveAsMenuSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem_lin_arr_selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem_lin_list_selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem_order_arr_selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem_open_hash_selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem_hash_chain_selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_menuItem_avl_selected( wxCommandEvent& event ) { event.Skip(); }
		virtual void CalculateClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void MainSaveClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		frameMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("PolyMath"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 521,262 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL, const wxString& name = wxT("MainWindow") );

		~frameMain();

};

///////////////////////////////////////////////////////////////////////////////
/// Class frameTable
///////////////////////////////////////////////////////////////////////////////
class frameTable : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel2;
		wxGrid* m_gridTable;
		wxButton* m_buttonClearTable;
		wxButton* m_buttonAddItem;
		wxButton* m_buttonRenameItem;
		wxButton* m_buttonDeleteItem;

		// Virtual event handlers, override them in your derived class
		virtual void tableClosed( wxCloseEvent& event ) { event.Skip(); }
		virtual void ClearTableClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void AddItemClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void RenameItemClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void DeleteItemClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		frameTable( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Table"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 923,411 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~frameTable();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialogAdd
///////////////////////////////////////////////////////////////////////////////
class MyDialogAdd : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText4;
		wxStaticText* m_staticTextKey;
		wxTextCtrl* m_textCtrlAddKey;
		wxStaticText* m_staticTextValue;
		wxTextCtrl* m_textCtrlAddValue;
		wxButton* m_buttonAddDialog;
		wxButton* m_buttonCancelDialog;

		// Virtual event handlers, override them in your derived class
		virtual void AddDialogButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void CancelDialogButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyDialogAdd( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add item in table"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 490,200 ), long style = wxDEFAULT_DIALOG_STYLE );

		~MyDialogAdd();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialogDelete
///////////////////////////////////////////////////////////////////////////////
class MyDialogDelete : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticTextDel;
		wxStaticText* m_staticTextKey;
		wxTextCtrl* m_textCtrlDelKey;
		wxButton* m_buttonDeleteDialog;
		wxButton* m_buttonCancelDialog;

		// Virtual event handlers, override them in your derived class
		virtual void DeleteDialogButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void CancelDialogButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyDialogDelete( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Delete item from table"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 490,200 ), long style = wxDEFAULT_DIALOG_STYLE );

		~MyDialogDelete();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialogRename
///////////////////////////////////////////////////////////////////////////////
class MyDialogRename : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticTextDel;
		wxStaticText* m_staticTextKey;
		wxTextCtrl* m_textCtrlDelKey;
		wxStaticText* m_staticTextKey1;
		wxTextCtrl* m_textCtrlDelKey1;
		wxStaticText* m_staticTextKey11;
		wxTextCtrl* m_textCtrlDelKey11;
		wxButton* m_buttonRenameDialog;
		wxButton* m_buttonCancelDialog;

		// Virtual event handlers, override them in your derived class
		virtual void RenameDialogButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void CancelDialogButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyDialogRename( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Rename item in table"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 490,200 ), long style = wxDEFAULT_DIALOG_STYLE );

		~MyDialogRename();

};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialogSaveResult
///////////////////////////////////////////////////////////////////////////////
class MyDialogSaveResult : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText12;
		wxTextCtrl* m_textCtrl9;
		wxButton* m_buttonSaveResult;
		wxButton* m_buttonCancelSaveResult;

		// Virtual event handlers, override them in your derived class
		virtual void SaveResultClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void CancelSaveResultClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyDialogSaveResult( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Save Result"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 356,161 ), long style = wxDEFAULT_DIALOG_STYLE );

		~MyDialogSaveResult();

};

