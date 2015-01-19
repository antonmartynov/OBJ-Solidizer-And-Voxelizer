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
	TGroupBox *GroupBox1;
	TLabel *LabelOBJInformationAmountOfVertices;
	TLabel *LabelOBJInformationAmountOfFaces;
	TLabel *LabelOBJInformationXMin;
	TLabel *LabelOBJInformationXMax;
	TLabel *LabelOBJInformationYMin;
	TLabel *LabelOBJInformationYMax;
	TLabel *LabelOBJInformationZMin;
	TLabel *LabelOBJInformationZMax;
	void __fastcall ButtonLoadFileClick(TObject *Sender);
	void __fastcall TimerTrackLoadFileOperationStatusTimer(TObject *Sender);
	void __fastcall TimerTrackResaveFileOperationStatusTimer(TObject *Sender);
	void __fastcall ButtonResaveFileClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
