//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include <fstream.h>
#include <stdio.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CPort"
#pragma link "CPortCtl"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
        , ff1(0)
        , ff2(0)
        , ff3(0)
        , ff4(0)
        , ff5(0)
        , Sumf4(0)
        , dX (0)
        , pos(0)
{

}

//---------------------------------------------------------------------------
void __fastcall TForm1::StartBtnClick(TObject *Sender)
{
   ComPort->Open();
   StartBtn->Enabled = false;
   ClrBtn->Enabled = false;
   StopBtn->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopBtnClick(TObject *Sender)
{
   if (ComPort->Connected == true)
   {
        ComPort->Close();
   }
   else
   {ComPort->Free();}
   StartBtn->Enabled = true;
   ClrBtn->Enabled = true;
   StopBtn->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   if (ComPort->Connected == true) ComPort->Close();
}
//---------------------------------------------------------------------------

void TForm1::SaveToFile(String FileName)
{
      fstream file;
      file.open(FileName.c_str(), ios::out);
      if (!file)
         return;
      int count = Series1->Count();
      file << count << " ";
      for (int i = 0; i < count; i++)
      {
           int a1 = Series1->YValue[i];
           int a2 = Series2->YValue[i];
           int a3 = Series3->YValue[i];
           int a4 = Series4->YValue[i];
           int a5 = Series5->YValue[i];
           file << a1 << " " << a2 << " " << a3<< " "  << a4 << " " << a5 << " ";
      }
      file.close();
}

//----------------------------------------------------------------------------
void TForm1:: LoadFromFile(String FileName)
{
      fstream file;
      file.open(FileName.c_str());
      if (!file)
      {
         file.close();
         return;
      }
      int count=0;
      int a1 = 0;
      int a2 = 0;
      int a3 = 0;
      int a4 = 0;
      int a4s = 0;
      int a5 = 0;
      file >> count;
      for (int i = 0; i < count; i++)
      {
         file >> a1  >> a2 >>  a3 >> a4 >>  a5;
         Application->ProcessMessages();
         Series1->AddXY(i, a1);
         Series2->AddXY(i, a2);
         Series3->AddXY(i, a3);
         Series4->AddXY(i, a4);
         Series5->AddXY(i, a5);
         if (i > 50)
         {
            Chart1->BottomAxis->Scroll(1, false);
            Chart2->BottomAxis->Scroll(1, false);
            Chart3->BottomAxis->Scroll(1, false);
            Chart4->BottomAxis->Scroll(1, false);
            Chart5->BottomAxis->Scroll(1, false);
         }
         Edit1->Text = a1;
         Edit2->Text = a2;
         Edit3->Text = a3;
         Edit4->Text = a4;
         Edit7->Text = a5;
         Edit5->Text = a1*a2;
         a4s = a4s + a4;
      }
      Edit6->Text = a4s;
      file.close();
      return;
}

//----------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    if (OpenDialog1->Execute())
    {
         Series1->Clear();
         Series2->Clear();
         Series3->Clear();
         Series4->Clear();
         LoadFromFile(OpenDialog1->FileName);
     }
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   if (SaveDialog1->Execute())
     SaveToFile(SaveDialog1->FileName);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Chart4MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   TChart* Chart = static_cast<TChart*>(Sender);
   int tag = Chart->Tag;
   switch (tag)
   {
      case 1: pos = Chart1->BottomAxis->Minimum; break;
      case 2: pos = Chart2->BottomAxis->Minimum; break;
      case 3: pos = Chart3->BottomAxis->Minimum; break;
      case 4: pos = Chart4->BottomAxis->Minimum; break;
      case 5: pos = Chart5->BottomAxis->Minimum; break;
      default: break;
   }
 if(Button == mbLeft)
 {
   Edit1->Text = GetValue (Chart1, Series1, X);
   Edit2->Text = GetValue (Chart2, Series2, X);
   Edit3->Text = GetValue (Chart3, Series3, X);
   Edit4->Text = GetValue (Chart4, Series4, X);
   Edit7->Text = GetValue (Chart5, Series5, X);

   float ls = Edit1->Text.ToDouble()*Edit3->Text.ToDouble()*0.5/M_PI/60.;
   Edit5->Text = ls;
   ls = ls * 0.00135962162;
   Edit8->Text = ls;

   float rash = Edit4->Text.ToDouble() * 0.72 * ls * 60. / 1000;
   Edit9->Text = rash;

   Shape1->Left = X;
   }
}
//------------------------------------------------------------------

AnsiString __fastcall TForm1::GetValue (TChart *Chart, TLineSeries *Series, int X)
{
   double vx = Series->XScreenToValue(X);
   double vy;
   if (vx < Chart->BottomAxis->Minimum || vx > Chart->BottomAxis->Maximum)
	   return 0;
   int	idx0, idx1;
   for (idx1 = 0; idx1 < Series->XValues->Count(); idx1++)
	   if (Series->XValue[idx1] >= vx)
         break;
   if (idx1 == Series->XValues->Count())
      return 0;
   idx0 = idx1 - 1;
   double dx = (Series->XValue[idx1] - Series->XValue[idx0]) * (24.*60.*60.);
   double dy = Series->YValue[idx1] - Series->YValue[idx0];
   vy = Series->YValue[idx0];
   if (dx)	vy = vy + dy / ((dx == 0)? dy : dx);
   return vy;
}
     
//---------------------------------------------------------------------------
void __fastcall TForm1::ComDataPacket1Packet(TObject *Sender,
      const AnsiString Str)
{
   int a1, a2, a3, a4, a5;
   sscanf (Str.c_str(), "%d %d %d %d %d", &a1, &a2, &a3, &a4, &a5);

   float f1 = a1*0.26081 - 96.684;
   ff1 = ff1 + (f1 - ff1)*0.007;
   Series1->AddXY(Series1->Count()+1, (int)ff1);
   Edit1->Text = ff1;

   float f2 = a2*0.0695 - 7.07;
   ff2 = ff2 + (f2 - ff2)*0.01;
   Series2->AddXY(Series2->Count()+1, ff2);
   Edit2->Text = ff2;

   float f3 = a3*58.8/11;
   ff3 = ff3 + (f3 - ff3)*0.01;
   Series3->AddXY(Series3->Count()+1, ff3);
   Edit3->Text = ff3;
   Edit5->Text = ff1*ff3*0.5/M_PI/60.;

   float f4 = a4*5./15.;
   ff4 = ff4 + (f4 - ff4)*0.01;
   Series4->AddXY(Series4->Count()+1, ff4);
   Edit4->Text = ff4;
   Sumf4 += ff4;
   Edit6->Text = Sumf4;

   float f5 = a5*58.8/2.;
   ff5 = ff5 + (f5 - ff5)*0.01;
   Series5->AddXY(Series5->Count()+1, ff5);
   Edit7->Text = ff5;

   float ls = 0.00135962162*ff1*ff3*0.5/M_PI/60.;
   Edit8->Text = ls;

   float rash = 0.72 * ls * 60.;
   Edit9->Text = rash;

   if (Series1->Count() > 50)
   {
      Chart1->BottomAxis->Scroll(1, false);
      Chart2->BottomAxis->Scroll(1, false);
      Chart3->BottomAxis->Scroll(1, false);
      Chart4->BottomAxis->Scroll(1, false);
      Chart5->BottomAxis->Scroll(1, false);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClrBtnClick(TObject *Sender)
{
   Chart1->BottomAxis->Scroll(-(Series1->Count()),false);
   Chart2->BottomAxis->Scroll(-(Series2->Count()),false);
   Chart3->BottomAxis->Scroll(-(Series3->Count()),false);
   Chart4->BottomAxis->Scroll(-(Series4->Count()),false);
   Chart5->BottomAxis->Scroll(-(Series4->Count()),false);
   Series1->Clear();
   Series2->Clear();
   Series3->Clear();
   Series4->Clear();
   Series5->Clear();

   Edit1->Clear();
   Edit2->Clear();
   Edit3->Clear();
   Edit4->Clear();
   Edit5->Clear();
   Edit6->Clear();
   Edit7->Clear();
   ff1 = ff2 = ff3 = ff4 = ff5 = Sumf4 = 0;
}

//----------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
   int h = (ClientHeight-StartBtn->Height)/5;
   Chart1->Height = h;
   Chart2->Height = h;
   Chart3->Height = h;
   Chart4->Height = h;
   Chart5->Height = h;

   Chart1->Top = StartBtn->Top+StartBtn->Height;
   Chart2->Top = Chart1->Top+Chart1->Height;
   Chart3->Top = Chart2->Top+Chart2->Height;
   Chart5->Top = Chart3->Top+Chart3->Height;
   Chart4->Top = Chart5->Top+Chart5->Height;

   Chart1->Width = ClientWidth - (Edit1->Width + 20);
   Chart2->Width = ClientWidth - (Edit1->Width + 20);
   Chart3->Width = ClientWidth - (Edit1->Width + 20);
   Chart4->Width = ClientWidth - (Edit1->Width + 20);
   Chart5->Width = ClientWidth - (Edit1->Width + 20);

   Edit1->Left = Chart1->Left + Chart1->Width + 10;
   Edit2->Left = Chart1->Left + Chart1->Width + 10;
   Edit3->Left = Chart1->Left + Chart1->Width + 10;
   Edit4->Left = Chart1->Left + Chart1->Width + 10;
   Edit5->Left = Chart1->Left + Chart1->Width + 10;
   Edit7->Left = Chart1->Left + Chart1->Width + 10;
   Edit6->Left = Chart1->Left + Chart1->Width + 10;
   Edit8->Left = Chart1->Left + Chart1->Width + 10;
   Edit9->Left = Chart1->Left + Chart1->Width + 10;

   Edit1->Top = Chart1->Top + 2;
   Edit5->Top = Edit1->Top + Edit1->Height + 5;
   Edit2->Top = Chart2->Top + 2;
   Edit3->Top = Chart3->Top + 2;
   Edit4->Top = Chart4->Top + 2;
   Edit7->Top = Chart5->Top + 2;
   Edit6->Top = Edit4->Top + Edit4->Height + 5;
   Edit8->Top = Edit5->Top + Edit5->Height + 5;
   Edit9->Top = Edit6->Top + Edit6->Height + 5;

   Shape1->Width = 1;
   Shape1->Top = Chart1->Top;
   Shape1->Height = ClientHeight;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::FormMouseWheel(TObject *Sender, TShiftState Shift,
      int WheelDelta, TPoint &MousePos, bool &Handled)
{
      Chart1->BottomAxis->Scroll(WheelDelta*0.01,false);
      Chart2->BottomAxis->Scroll(WheelDelta*0.01,false);
      Chart3->BottomAxis->Scroll(WheelDelta*0.01,false);
      Chart4->BottomAxis->Scroll(WheelDelta*0.01,false);
      Chart5->BottomAxis->Scroll(WheelDelta*0.01,false);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Chart1Scroll(TObject *Sender)
{
   Chart2->BottomAxis->Scroll(Chart1->BottomAxis->Minimum - pos,false);
   Chart3->BottomAxis->Scroll(Chart1->BottomAxis->Minimum - pos,false);
   Chart4->BottomAxis->Scroll(Chart1->BottomAxis->Minimum - pos,false);
   Chart5->BottomAxis->Scroll(Chart1->BottomAxis->Minimum - pos,false);
   pos = Chart1->BottomAxis->Minimum;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Chart2Scroll(TObject *Sender)
{
   Chart1->BottomAxis->Scroll(Chart2->BottomAxis->Minimum - pos,false);
   Chart3->BottomAxis->Scroll(Chart2->BottomAxis->Minimum - pos,false);
   Chart4->BottomAxis->Scroll(Chart2->BottomAxis->Minimum - pos,false);
   Chart5->BottomAxis->Scroll(Chart2->BottomAxis->Minimum - pos,false);
   pos = Chart2->BottomAxis->Minimum;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart3Scroll(TObject *Sender)
{
   Chart1->BottomAxis->Scroll(Chart3->BottomAxis->Minimum - pos,false);
   Chart2->BottomAxis->Scroll(Chart3->BottomAxis->Minimum - pos,false);
   Chart4->BottomAxis->Scroll(Chart3->BottomAxis->Minimum - pos,false);
   Chart5->BottomAxis->Scroll(Chart3->BottomAxis->Minimum - pos,false);
   pos = Chart3->BottomAxis->Minimum;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart5Scroll(TObject *Sender)
{
   Chart1->BottomAxis->Scroll(Chart5->BottomAxis->Minimum - pos,false);
   Chart2->BottomAxis->Scroll(Chart5->BottomAxis->Minimum - pos,false);
   Chart3->BottomAxis->Scroll(Chart5->BottomAxis->Minimum - pos,false);
   Chart4->BottomAxis->Scroll(Chart5->BottomAxis->Minimum - pos,false);
   pos = Chart5->BottomAxis->Minimum;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Chart4Scroll(TObject *Sender)
{
   Chart1->BottomAxis->Scroll(Chart4->BottomAxis->Minimum - pos,false);
   Chart2->BottomAxis->Scroll(Chart4->BottomAxis->Minimum - pos,false);
   Chart3->BottomAxis->Scroll(Chart4->BottomAxis->Minimum - pos,false);
   Chart5->BottomAxis->Scroll(Chart4->BottomAxis->Minimum - pos,false);
   pos = Chart4->BottomAxis->Minimum;
}
//---------------------------------------------------------------------------

