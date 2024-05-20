#include "../Headers/PolyMathUIMyDialogAdd.h"
#include "../../../Polynomial/Polynomial.h"

PolyMathUIMyDialogAdd::PolyMathUIMyDialogAdd( wxWindow* parent )
:
MyDialogAdd( parent )
{

}

void PolyMathUIMyDialogAdd::AddDialogButtonClick( wxCommandEvent& event )
{
	std::string key = m_textCtrlAddKey->GetValue().ToStdString();
	Polynomial value = Polynomial::parsePolynomial(m_textCtrlAddValue->GetValue().ToStdString());
}

void PolyMathUIMyDialogAdd::CancelDialogButtonClick( wxCommandEvent& event )
{
// TODO: Implement CancelDialogButtonClick
}
