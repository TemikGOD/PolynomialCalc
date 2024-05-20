#include "../Headers/PolyMathUIframeTable.h"
#include "../Headers/PolyMathUIMyDialogAdd.h"
#include "../Headers/PolyMathUIMyDialogDelete.h"
#include "../Headers/PolyMathUIMyDialogRename.h"

PolyMathUIframeTable::PolyMathUIframeTable( wxWindow* parent )
:
frameTable( parent )
{

}

void PolyMathUIframeTable::tableClosed(wxCloseEvent& event)
{
  if (event.CanVeto())
  {
    event.Veto();
    Show(false);
  }
  else
  {
    Destroy();
  }
}

void PolyMathUIframeTable::ClearTableClick( wxCommandEvent& event )
{
// TODO: Implement ClearTableClick
}

void PolyMathUIframeTable::AddItemClick( wxCommandEvent& event )
{
  PolyMathUIMyDialogAdd* addDialog = new PolyMathUIMyDialogAdd(this);
  addDialog->Show();
}

void PolyMathUIframeTable::RenameItemClick( wxCommandEvent& event )
{
// TODO: Implement RenameItemClick
}

void PolyMathUIframeTable::DeleteItemClick( wxCommandEvent& event )
{
// TODO: Implement DeleteItemClick
}
