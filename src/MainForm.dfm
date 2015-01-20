object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 
    'OBJ Solidizer And Voxelizer v0 - https://github.com/antonmartyno' +
    'v/OBJ-Solidizer-And-Voxelizer'
  ClientHeight = 664
  ClientWidth = 480
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBoxLoadOBJFile: TGroupBox
    Left = 8
    Top = 8
    Width = 465
    Height = 169
    Caption = 'Load an OBJ file'
    TabOrder = 0
    object LabelInputOBJFile: TLabel
      Left = 16
      Top = 24
      Width = 57
      Height = 17
      AutoSize = False
      Caption = 'Filename:'
    end
    object LabelOpenFileCurrentOperation: TLabel
      Left = 16
      Top = 56
      Width = 433
      Height = 17
      AutoSize = False
      Caption = 'Current operation:'
    end
    object LabelOpenFileOverallProgress: TLabel
      Left = 16
      Top = 112
      Width = 433
      Height = 17
      AutoSize = False
      Caption = 'Overall progress:'
    end
    object ButtonLoadFile: TButton
      Left = 352
      Top = 24
      Width = 97
      Height = 25
      Caption = 'Load this file'
      TabOrder = 0
      OnClick = ButtonLoadFileClick
    end
    object EditInputOBJFile: TEdit
      Left = 80
      Top = 24
      Width = 265
      Height = 21
      TabOrder = 1
      Text = 'P:\justcube.obj'
    end
    object ProgressBarOpenFileCurrentOperation: TProgressBar
      Left = 16
      Top = 80
      Width = 433
      Height = 17
      Step = 1
      TabOrder = 2
    end
    object ProgressBarOpenFileOverallProgress: TProgressBar
      Left = 16
      Top = 136
      Width = 433
      Height = 17
      TabOrder = 3
    end
  end
  object GroupBoxResaveOBJFile: TGroupBox
    Left = 8
    Top = 328
    Width = 465
    Height = 169
    Caption = 'Re-save the loaded OBJ file'
    TabOrder = 1
    object LabelResavedOBJFile: TLabel
      Left = 16
      Top = 24
      Width = 57
      Height = 17
      AutoSize = False
      Caption = 'Filename:'
    end
    object LabelResaveFileCurrentOperation: TLabel
      Left = 16
      Top = 56
      Width = 433
      Height = 17
      AutoSize = False
      Caption = 'Current operation:'
    end
    object LabelResaveFileOverallProgress: TLabel
      Left = 16
      Top = 112
      Width = 433
      Height = 17
      AutoSize = False
      Caption = 'Overall progress:'
    end
    object EditResavedOBJFile: TEdit
      Left = 80
      Top = 24
      Width = 265
      Height = 21
      TabOrder = 0
      Text = 'P:\resaved.obj'
    end
    object ButtonResaveFile: TButton
      Left = 352
      Top = 24
      Width = 97
      Height = 25
      Caption = 'Re-save here'
      TabOrder = 1
      OnClick = ButtonResaveFileClick
    end
    object ProgressBarResaveFileCurrentOperation: TProgressBar
      Left = 16
      Top = 80
      Width = 433
      Height = 17
      TabOrder = 2
    end
    object ProgressBarResaveFileOverallProgress: TProgressBar
      Left = 16
      Top = 136
      Width = 433
      Height = 17
      TabOrder = 3
    end
  end
  object GroupBoxOBJGeometryInformation: TGroupBox
    Left = 8
    Top = 184
    Width = 465
    Height = 137
    Caption = 'OBJ geometry information'
    TabOrder = 2
    object LabelOBJInformationAmountOfVertices: TLabel
      Left = 16
      Top = 24
      Width = 209
      Height = 17
      AutoSize = False
      Caption = 'Amount of vertices:'
    end
    object LabelOBJInformationAmountOfFaces: TLabel
      Left = 16
      Top = 40
      Width = 209
      Height = 17
      AutoSize = False
      Caption = 'Amount of triangles:'
    end
    object LabelOBJInformationXMin: TLabel
      Left = 240
      Top = 24
      Width = 209
      Height = 17
      AutoSize = False
      Caption = 'X min:'
    end
    object LabelOBJInformationXMax: TLabel
      Left = 240
      Top = 40
      Width = 209
      Height = 17
      AutoSize = False
      Caption = 'X max:'
    end
    object LabelOBJInformationYMin: TLabel
      Left = 240
      Top = 56
      Width = 209
      Height = 17
      AutoSize = False
      Caption = 'Y min:'
    end
    object LabelOBJInformationYMax: TLabel
      Left = 240
      Top = 72
      Width = 209
      Height = 17
      AutoSize = False
      Caption = 'Y max:'
    end
    object LabelOBJInformationZMin: TLabel
      Left = 240
      Top = 88
      Width = 209
      Height = 17
      AutoSize = False
      Caption = 'Z min:'
    end
    object LabelOBJInformationZMax: TLabel
      Left = 240
      Top = 104
      Width = 209
      Height = 17
      AutoSize = False
      Caption = 'Z max:'
    end
  end
  object GroupBoxVoxelizationSettings: TGroupBox
    Left = 8
    Top = 504
    Width = 465
    Height = 153
    Caption = 'Voxelization settings'
    TabOrder = 3
    object LabelGridDimensionsStart: TLabel
      Left = 232
      Top = 48
      Width = 57
      Height = 17
      AutoSize = False
      Caption = 'Start'
    end
    object LabelGridDimensionsCount: TLabel
      Left = 312
      Top = 48
      Width = 57
      Height = 17
      AutoSize = False
      Caption = 'Count'
    end
    object LabelGridDimensionsEnd: TLabel
      Left = 392
      Top = 48
      Width = 57
      Height = 17
      AutoSize = False
      Caption = 'End'
    end
    object LabelGridDimensionsX: TLabel
      Left = 176
      Top = 72
      Width = 31
      Height = 17
      AutoSize = False
      Caption = 'X'
    end
    object LabelGridDimensionsY: TLabel
      Left = 176
      Top = 96
      Width = 31
      Height = 17
      AutoSize = False
      Caption = 'Y'
    end
    object LabelGridDimensionsZ: TLabel
      Left = 176
      Top = 120
      Width = 31
      Height = 17
      AutoSize = False
      Caption = 'Z'
    end
    object LabelGridDimensionsStartX: TLabel
      Left = 232
      Top = 72
      Width = 57
      Height = 17
      AutoSize = False
      Caption = '0000'
    end
    object LabelGridDimensionsStartY: TLabel
      Left = 232
      Top = 96
      Width = 57
      Height = 17
      AutoSize = False
      Caption = '0000'
    end
    object LabelGridDimensionsStartZ: TLabel
      Left = 232
      Top = 120
      Width = 57
      Height = 17
      AutoSize = False
      Caption = '0000'
    end
    object LabelGridDimensionsCountX: TLabel
      Left = 312
      Top = 72
      Width = 57
      Height = 17
      AutoSize = False
      Caption = '0000'
    end
    object LabelGridDimensionsCountY: TLabel
      Left = 312
      Top = 96
      Width = 57
      Height = 17
      AutoSize = False
      Caption = '0000'
    end
    object LabelGridDimensionsCountZ: TLabel
      Left = 312
      Top = 120
      Width = 57
      Height = 17
      AutoSize = False
      Caption = '0000'
    end
    object LabelGridDimensionsEndX: TLabel
      Left = 392
      Top = 72
      Width = 57
      Height = 17
      AutoSize = False
      Caption = '0000'
    end
    object LabelGridDimensionsEndY: TLabel
      Left = 392
      Top = 96
      Width = 57
      Height = 17
      AutoSize = False
      Caption = '0000'
    end
    object LabelGridDimensionsEndZ: TLabel
      Left = 392
      Top = 120
      Width = 57
      Height = 17
      AutoSize = False
      Caption = '0000'
    end
    object LabelGridStep: TLabel
      Left = 16
      Top = 96
      Width = 145
      Height = 17
      AutoSize = False
      Caption = 'Grid step = '
    end
    object LabelGridDimensions: TLabel
      Left = 16
      Top = 120
      Width = 145
      Height = 17
      AutoSize = False
      Caption = 'Grid dimensions '#8211'>'
    end
    object ButtonInitVoxelizer: TButton
      Left = 16
      Top = 24
      Width = 97
      Height = 25
      Caption = 'Init voxelizer'
      TabOrder = 0
      OnClick = ButtonInitVoxelizerClick
    end
    object ButtonSetOptimalGrid: TButton
      Left = 16
      Top = 56
      Width = 97
      Height = 25
      Caption = 'Set optimal grid'
      TabOrder = 1
      OnClick = ButtonSetOptimalGridClick
    end
  end
  object TimerTrackResaveFileOperationStatus: TTimer
    Enabled = False
    Interval = 16
    OnTimer = TimerTrackResaveFileOperationStatusTimer
    Left = 296
    Top = 384
  end
  object TimerTrackLoadFileOperationStatus: TTimer
    Enabled = False
    Interval = 16
    OnTimer = TimerTrackLoadFileOperationStatusTimer
    Left = 312
    Top = 88
  end
end
