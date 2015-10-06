//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <math.h>
#include <CPort.hpp>
#include <Dialogs.hpp>
#include "CPortCtl.hpp"
#include <ComCtrls.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart1;
        TButton *StartBtn;
        TEdit *Edit1;
        TChart *Chart2;
        TChart *Chart3;
        TLineSeries *Series2;
        TLineSeries *Series3;
        TChart *Chart4;
        TLineSeries *Series4;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TButton *StopBtn;
        TComPort *ComPort;
        TLabel *Lbl_Info;
   TOpenDialog *OpenDialog1;
   TSaveDialog *SaveDialog1;
   TButton *Button3;
   TButton *Button4;
   TComDataPacket *ComDataPacket1;
   TComComboBox *ComComboBox1;
   TEdit *Edit5;
   TButton *ClrBtn;
   TEdit *KRasEdit;
   TChart *Chart5;
   TLineSeries *Series5;
   TEdit *Edit7;
   TPanel *Shape1;
   TLineSeries *Series1;
   TEdit *Edit8;
   TEdit *Edit9;
   TButton *About;
   TTrackBar *TrackBar1;
   TEdit *Edit10;

   void __fastcall StartBtnClick(TObject *Sender);
   void __fastcall StopBtnClick(TObject *Sender);
   void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
   void __fastcall Button3Click(TObject *Sender);
   void __fastcall Button4Click(TObject *Sender);
   void __fastcall Chart4MouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
   void __fastcall ComDataPacket1Packet(TObject *Sender, const AnsiString Str);
   AnsiString __fastcall GetValue (TChart *Chart, TLineSeries *Series, int X);
   void __fastcall ClrBtnClick(TObject *Sender);
   void __fastcall FormResize(TObject *Sender);
   void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
   void __fastcall Chart1Scroll(TObject *Sender);
   void __fastcall Chart2Scroll(TObject *Sender);
   void __fastcall Chart3Scroll(TObject *Sender);
   void __fastcall Chart5Scroll(TObject *Sender);
   void __fastcall Chart4Scroll(TObject *Sender);
   void __fastcall AboutClick(TObject *Sender);
   void __fastcall TrackBar1Change(TObject *Sender);

private:	// User declarations
   void SaveToFile(String FileName);
   void LoadFromFile(String FileName);
   float ff1, ff2, ff3, ff4, ff5, Sumf4;
   int dX;
   double pos;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
