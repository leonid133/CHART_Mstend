//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "about.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Graphics::TBitmap* picture=new Graphics::TBitmap;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
   : TForm(Owner)
{
 
}
//---------------------------------------------------------------------------

void __fastcall TForm2::AboutOffClick(TObject *Sender)
{
   Form2->Visible = false;   
}
//---------------------------------------------------------------------------



