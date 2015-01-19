object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 
    'OBJ Solidizer And Voxelizer v0 - https://github.com/antonmartyno' +
    'v/OBJ-Solidizer-And-Voxelizer'
  ClientHeight = 360
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
    Top = 184
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
  object TimerTrackResaveFileOperationStatus: TTimer
    Enabled = False
    Interval = 16
    OnTimer = TimerTrackResaveFileOperationStatusTimer
    Left = 312
    Top = 264
  end
  object TimerTrackLoadFileOperationStatus: TTimer
    Enabled = False
    Interval = 16
    OnTimer = TimerTrackLoadFileOperationStatusTimer
    Left = 312
    Top = 88
  end
end
