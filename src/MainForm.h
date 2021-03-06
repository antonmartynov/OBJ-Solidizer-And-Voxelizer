//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TTimer *TimerTrackResaveFileOperationStatus;
	TGroupBox *GroupBoxLoadOBJFile;
	TButton *ButtonLoadFile;
	TEdit *EditInputOBJFile;
	TLabel *LabelInputOBJFile;
	TLabel *LabelOpenFileCurrentOperation;
	TProgressBar *ProgressBarOpenFileCurrentOperation;
	TLabel *LabelOpenFileOverallProgress;
	TProgressBar *ProgressBarOpenFileOverallProgress;
	TTimer *TimerTrackLoadFileOperationStatus;
	TGroupBox *GroupBoxResaveOBJFile;
	TLabel *LabelResavedOBJFile;
	TEdit *EditResavedOBJFile;
	TButton *ButtonResaveFile;
	TLabel *LabelResaveFileCurrentOperation;
	TProgressBar *ProgressBarResaveFileCurrentOperation;
	TLabel *LabelResaveFileOverallProgress;
	TProgressBar *ProgressBarResaveFileOverallProgress;
	TGroupBox *GroupBoxOBJGeometryInformation;
	TLabel *LabelOBJInformationAmountOfVertices;
	TLabel *LabelOBJInformationAmountOfFaces;
	TLabel *LabelOBJInformationXMin;
	TLabel *LabelOBJInformationXMax;
	TLabel *LabelOBJInformationYMin;
	TLabel *LabelOBJInformationYMax;
	TLabel *LabelOBJInformationZMin;
	TLabel *LabelOBJInformationZMax;
	TGroupBox *GroupBoxVoxelizationSettings;
	TButton *ButtonInitVoxelizer;
	TLabel *LabelGridDimensionsStart;
	TLabel *LabelGridDimensionsCount;
	TLabel *LabelGridDimensionsEnd;
	TLabel *LabelGridDimensionsX;
	TLabel *LabelGridDimensionsY;
	TLabel *LabelGridDimensionsZ;
	TLabel *LabelGridDimensionsStartX;
	TLabel *LabelGridDimensionsStartY;
	TLabel *LabelGridDimensionsStartZ;
	TLabel *LabelGridDimensionsCountX;
	TLabel *LabelGridDimensionsCountY;
	TLabel *LabelGridDimensionsCountZ;
	TLabel *LabelGridDimensionsEndX;
	TLabel *LabelGridDimensionsEndY;
	TLabel *LabelGridDimensionsEndZ;
	TLabel *LabelGridStep;
	TLabel *LabelGridDimensions;
	TButton *ButtonSetOptimalGrid;
	TGroupBox *GroupBoxProcess;
	TButton *ButtonRandomize;
	TLabel *LabelProcessCurrentOperation;
	TProgressBar *ProgressBarProcessCurrentOperation;
	TLabel *LabelProcessOverallProgress;
	TProgressBar *ProgressBarProcessOverallProgress;
	TTimer *TimerTrackProgressOperationStatus;
	TGroupBox *GroupBoxOutput;
	TLabel *LabelOutputCubesOBJFileFileName;
	TEdit *EditOutputCubesOBJFile;
	TButton *ButtonOutputCubesOBJFile;
	TLabel *LabelOutputCubesOBJFileCurrentOperation;
	TProgressBar *ProgressBarOutputCubesOBJFileCurrentOperation;
	TLabel *LabelOutputCubesOBJFileOverallProgress;
	TProgressBar *ProgressBarOutputCubesOBJFileOverallProgress;
	TTimer *TimerTrackOutputOperationStatus;
	TEdit *EditGithubURL;
	void __fastcall ButtonLoadFileClick(TObject *Sender);
	void __fastcall TimerTrackLoadFileOperationStatusTimer(TObject *Sender);
	void __fastcall TimerTrackResaveFileOperationStatusTimer(TObject *Sender);
	void __fastcall ButtonResaveFileClick(TObject *Sender);
	void __fastcall ButtonInitVoxelizerClick(TObject *Sender);
	void __fastcall ButtonSetOptimalGridClick(TObject *Sender);
	void __fastcall ButtonRandomizeClick(TObject *Sender);
	void __fastcall TimerTrackProgressOperationStatusTimer(TObject *Sender);
	void __fastcall ButtonOutputCubesOBJFileClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
