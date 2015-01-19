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
void __fastcall TForm1::ButtonLoadFileClick(TObject *Sender)
{
	engine->loadFile(Form1->EditInputOBJFile->Text);
	Form1->TimerTrackLoadFileOperationStatus->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerTrackLoadFileOperationStatusTimer(TObject *Sender)
{
	Form1->LabelOpenFileCurrentOperation->Caption = "Current operation: " + engine->geometryData->loadFileStatus.currentOperationName;
	Form1->ProgressBarOpenFileCurrentOperation->Position = (int)(engine->geometryData->loadFileStatus.currentOperationProgress * 100.0f);
	Form1->ProgressBarOpenFileOverallProgress->Position = (int)(engine->geometryData->loadFileStatus.overallProgress * 100.0f);
	if(engine->geometryData->loadFileStatus.status == 1)
	{
		Form1->TimerTrackLoadFileOperationStatus->Enabled = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonResaveFileClick(TObject *Sender)
{
	engine->saveFile(Form1->EditResavedOBJFile->Text);
	Form1->TimerTrackResaveFileOperationStatus->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerTrackResaveFileOperationStatusTimer(TObject *Sender)
{
	Form1->LabelResaveFileCurrentOperation->Caption = "Current operation: " + engine->geometryData->saveFileStatus.currentOperationName;
	Form1->ProgressBarResaveFileCurrentOperation->Position = (int)(engine->geometryData->saveFileStatus.currentOperationProgress * 100.0f);
	Form1->ProgressBarResaveFileOverallProgress->Position = (int)(engine->geometryData->saveFileStatus.overallProgress * 100.0f);
	if(engine->geometryData->saveFileStatus.status == 1)
	{
		Form1->TimerTrackResaveFileOperationStatus->Enabled = false;
	}
}
//---------------------------------------------------------------------------

