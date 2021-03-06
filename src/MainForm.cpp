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
	Form1->LabelOpenFileCurrentOperation->Caption = "Current operation: " + engine->geometryData->loadFileStatus.currentOperationName;
	Form1->ProgressBarOpenFileCurrentOperation->Position = (int)(engine->geometryData->loadFileStatus.currentOperationProgress * 100.0f);
	Form1->ProgressBarOpenFileOverallProgress->Position = (int)(engine->geometryData->loadFileStatus.overallProgress * 100.0f);
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
	if(engine->geometryData->saveFileStatus.status != 0)
	{
		Form1->TimerTrackResaveFileOperationStatus->Enabled = false;
	}
	Form1->LabelResaveFileCurrentOperation->Caption = "Current operation: " + engine->geometryData->saveFileStatus.currentOperationName;
	Form1->ProgressBarResaveFileCurrentOperation->Position = (int)(engine->geometryData->saveFileStatus.currentOperationProgress * 100.0f);
	Form1->ProgressBarResaveFileOverallProgress->Position = (int)(engine->geometryData->saveFileStatus.overallProgress * 100.0f);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonInitVoxelizerClick(TObject *Sender)
{
	engine->initVoxelizer();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSetOptimalGridClick(TObject *Sender)
{
	engine->createOptimalGrid(0.2f);

	Dimensions optimalDimensions = engine->voxelizer->getVoxelGridDimensions();
	Form1->LabelGridDimensionsStartX->Caption = UnicodeString(optimalDimensions.x.start);
	Form1->LabelGridDimensionsCountX->Caption = UnicodeString(optimalDimensions.x.count);
	Form1->LabelGridDimensionsEndX->Caption = UnicodeString(optimalDimensions.x.start + optimalDimensions.x.step * (float)(optimalDimensions.x.count - 1));
	Form1->LabelGridDimensionsStartY->Caption = UnicodeString(optimalDimensions.y.start);
	Form1->LabelGridDimensionsCountY->Caption = UnicodeString(optimalDimensions.y.count);
	Form1->LabelGridDimensionsEndY->Caption = UnicodeString(optimalDimensions.y.start + optimalDimensions.y.step * (float)(optimalDimensions.y.count - 1));
	Form1->LabelGridDimensionsStartZ->Caption = UnicodeString(optimalDimensions.z.start);
	Form1->LabelGridDimensionsCountZ->Caption = UnicodeString(optimalDimensions.z.count);
	Form1->LabelGridDimensionsEndZ->Caption = UnicodeString(optimalDimensions.z.start + optimalDimensions.z.step * (float)(optimalDimensions.z.count - 1));

	Form1->LabelGridStep->Caption = "Grid step = " + UnicodeString(optimalDimensions.x.step);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonRandomizeClick(TObject *Sender)
{
	engine->voxelize();
	Form1->TimerTrackProgressOperationStatus->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TimerTrackProgressOperationStatusTimer(TObject *Sender)
{
	if(engine->voxelizer->processStatus.status != 0)
	{
        Form1->TimerTrackProgressOperationStatus->Enabled = false;
	}
	Form1->LabelProcessCurrentOperation->Caption = "Current operation: " + engine->voxelizer->processStatus.currentOperationName;
	Form1->ProgressBarProcessCurrentOperation->Position = (int)(engine->voxelizer->processStatus.currentOperationProgress * 100.0f);
	Form1->ProgressBarProcessOverallProgress->Position = (int)(engine->voxelizer->processStatus.overallProgress * 100.0f);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonOutputCubesOBJFileClick(TObject *Sender)
{
	engine->saveVoxelsAsCubeGeometry(Form1->EditOutputCubesOBJFile->Text);
}
//---------------------------------------------------------------------------

