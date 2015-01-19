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
	engine->loadFile(Form1->Edit1->Text);
    Form1->Timer1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	engine->saveFile(Form1->Edit2->Text);
	Form1->Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Form1->Memo1->Clear();
	Form1-Memo1->Lines->Add(engine->geometryData->loadFileStatus.currentOperationName + ": " +
							UnicodeString(engine->geometryData->loadFileStatus.currentOperationProgress * 100.0f) + "%");
	if(engine->geometryData->loadFileStatus.status == 1)
	{
		Form1->Timer1->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	Form1->Memo1->Clear();
	Form1-Memo1->Lines->Add(engine->geometryData->saveFileStatus.currentOperationName + ": " +
							UnicodeString(engine->geometryData->saveFileStatus.currentOperationProgress * 100.0f) + "%");
	if(engine->geometryData->saveFileStatus.status == 1)
	{
		Form1->Timer2->Enabled = false;
	}
}
//---------------------------------------------------------------------------

