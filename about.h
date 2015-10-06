//---------------------------------------------------------------------------

#ifndef aboutH
#define aboutH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
   TButton *AboutOff;
   TBevel *Bevel1;
   TStaticText *StaticText3;
   TMemo *Memo1;
   TStaticText *StaticText2;
   TStaticText *StaticText1;
   TImage *Image1;
   void __fastcall AboutOffClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
   __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
