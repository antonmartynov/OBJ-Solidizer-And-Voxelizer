//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
#include "Engine.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Engine * engine;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	engine = new Engine();
	engine->initialize();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form1->Memo1->Clear();
	engine->geometryData->loadFile(Form1->Edit1->Text);
	Form1-Memo1->Lines->Add(engine->geometryData->loadFileStatus.currentOperationName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	engine->geometryData->saveFile(Form1->Edit2->Text);
}
//---------------------------------------------------------------------------

