object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'OBJ Solidizer And Voxelizer v0'
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
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 97
    Height = 25
    Caption = 'Load this file'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 112
    Top = 8
    Width = 145
    Height = 21
    TabOrder = 1
    Text = 'P:\justcube.obj'
  end
  object Memo1: TMemo
    Left = 16
    Top = 40
    Width = 201
    Height = 177
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object Button2: TButton
    Left = 264
    Top = 8
    Width = 81
    Height = 25
    Caption = 'Re-save here'
    TabOrder = 3
    OnClick = Button2Click
  end
  object Edit2: TEdit
    Left = 352
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 4
    Text = 'P:\resaved.obj'
  end
end
