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
	if(engine->geometryData->loadFileStatus.status != 0)
	{
		Form1->TimerTrackLoadFileOperationStatus->Enabled = false;
		Form1->LabelOBJInformationAmountOfVertices->Caption = "Amount of vertices: " + UnicodeString(engine->geometryData->spatialInformation.verticesCount);
		Form1->LabelOBJInformationAmountOfFaces->Caption = "Amount of triangles: " + UnicodeString(engine->geometryData->spatialInformation.facesCount);
		Form1->LabelOBJInformationXMin->Caption = "X min: " + UnicodeString(engine->geometryData->spatialInformation.xMin);
		Form1->LabelOBJInformationXMax->Caption = "X max: " + UnicodeString(engine->geometryData->spatialInformation.xMax);
		Form1->LabelOBJInformationYMin->Caption = "Y min: " + UnicodeString(engine->geometryData->spatialInformation.yMin);
		Form1->LabelOBJInformationYMax->Caption = "Y max: " + UnicodeString(engine->geometryData->spatialInformation.yMax);
		Form1->LabelOBJInformationZMin->Caption = "Z min: " + UnicodeString(engine->geometryData->spatialInformation.zMin);
		Form1->LabelOBJInformationZMax->Caption = "Z max: " + UnicodeString(engine->geometryData->spatialInformation.zMax);
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
	if(engine->geometryData->saveFileStatus.status != 0)
	{
		Form1->TimerTrackResaveFileOperationStatus->Enabled = false;
	}
}
//---------------------------------------------------------------------------

