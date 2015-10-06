object Form1: TForm1
  Left = 239
  Top = 208
  AutoScroll = False
  Caption = #1052#1086#1084#1077#1085#1090#1085#1099#1081' '#1089#1090#1077#1085#1076
  ClientHeight = 543
  ClientWidth = 575
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  ShowHint = True
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnMouseWheel = FormMouseWheel
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Lbl_Info: TLabel
    Left = 840
    Top = 48
    Width = 3
    Height = 13
  end
  object Chart1: TChart
    Tag = 1
    Left = 5
    Top = 32
    Width = 391
    Height = 97
    AllowPanning = pmHorizontal
    AllowZoom = False
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Gradient.EndColor = clSilver
    Gradient.Visible = True
    Title.Text.Strings = (
      #1052#1086#1084#1077#1085#1090', '#1053'*'#1084)
    OnScroll = Chart1Scroll
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.Maximum = 100
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 50
    Legend.Visible = False
    View3D = False
    TabOrder = 0
    OnMouseDown = Chart4MouseDown
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object StartBtn: TButton
    Left = 115
    Top = 0
    Width = 70
    Height = 25
    Hint = '|'#1053#1072#1095#1072#1083#1086' '#1079#1072#1075#1088#1091#1079#1082#1080
    Caption = #1057#1090#1072#1088#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 1
    OnClick = StartBtnClick
  end
  object Chart2: TChart
    Tag = 2
    Left = 5
    Top = 136
    Width = 391
    Height = 97
    AllowPanning = pmHorizontal
    AllowZoom = False
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Gradient.EndColor = clSilver
    Gradient.Visible = True
    Title.Text.Strings = (
      #1058#1103#1075#1072', '#1082#1075)
    OnScroll = Chart2Scroll
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.Maximum = 100
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 70
    View3D = False
    TabOrder = 3
    OnMouseDown = Chart4MouseDown
    object Series2: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      ShowInLegend = False
      Pointer.Dark3D = False
      Pointer.Draw3D = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Chart3: TChart
    Tag = 3
    Left = 5
    Top = 240
    Width = 391
    Height = 81
    AllowPanning = pmHorizontal
    AllowZoom = False
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Gradient.EndColor = clSilver
    Gradient.Visible = True
    Title.Text.Strings = (
      #1063#1072#1089#1090#1086#1090#1072' '#1086#1073#1086#1088#1086#1090#1086#1074' '#1076#1074#1080#1075#1072#1090#1077#1083#1103', '#1086#1073'/'#1084#1080#1085)
    OnScroll = Chart3Scroll
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.ExactDateTime = False
    BottomAxis.Increment = 1
    BottomAxis.Maximum = 100
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 8000
    Legend.Visible = False
    View3D = False
    TabOrder = 4
    OnMouseDown = Chart4MouseDown
    object Series3: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Chart4: TChart
    Tag = 4
    Left = 5
    Top = 424
    Width = 391
    Height = 105
    AllowPanning = pmHorizontal
    AllowZoom = False
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Gradient.EndColor = clSilver
    Gradient.Visible = True
    Title.Text.Strings = (
      #1056#1072#1089#1093#1086#1076', '#1084#1083'/'#1084#1080#1085)
    OnScroll = Chart4Scroll
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.Maximum = 100
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 50
    Legend.Visible = False
    View3D = False
    TabOrder = 5
    OnMouseDown = Chart4MouseDown
    object Series4: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Dark3D = False
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Edit3: TEdit
    Left = 440
    Top = 240
    Width = 50
    Height = 21
    Hint = #1063#1072#1089#1090#1086#1090#1072' '#1086#1073#1086#1088#1086#1090#1086#1074' '#1076#1074#1080#1075#1072#1090#1077#1083#1103', '#1086#1073'/'#1084#1080#1085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 7
  end
  object Edit4: TEdit
    Left = 408
    Top = 424
    Width = 80
    Height = 21
    Hint = #1056#1072#1089#1093#1086#1076' '#1090#1086#1087#1083#1080#1074#1072', '#1084#1083'/'#1084#1080#1085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 8
  end
  object StopBtn: TButton
    Left = 190
    Top = 0
    Width = 70
    Height = 25
    Hint = '|'#1054#1082#1086#1085#1095#1072#1085#1080#1077' '#1079#1072#1075#1088#1091#1079#1082#1080
    Caption = #1057#1090#1086#1087
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 9
    OnClick = StopBtnClick
  end
  object Button3: TButton
    Left = 420
    Top = 0
    Width = 70
    Height = 25
    Hint = '|'#1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1080#1079' '#1092#1072#1081#1083#1072
    Caption = #1054#1090#1082#1088#1099#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 10
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 345
    Top = 0
    Width = 70
    Height = 25
    Hint = '|'#1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 11
    OnClick = Button4Click
  end
  object ComComboBox1: TComComboBox
    Left = 8
    Top = 2
    Width = 90
    Height = 21
    Hint = '|'#1042#1099#1073#1086#1088' COM-'#1087#1086#1088#1090#1072
    ComPort = ComPort
    ComProperty = cpPort
    AutoApply = True
    Text = 'COM4'
    Style = csDropDownList
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ItemHeight = 13
    ItemIndex = 0
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 12
  end
  object Edit5: TEdit
    Left = 408
    Top = 64
    Width = 80
    Height = 21
    Hint = #1052#1086#1097#1085#1086#1089#1090#1100', '#1082#1042#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 13
  end
  object ClrBtn: TButton
    Left = 270
    Top = 0
    Width = 70
    Height = 25
    Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 14
    OnClick = ClrBtnClick
  end
  object KRasEdit: TEdit
    Left = 0
    Top = 760
    Width = 57
    Height = 21
    TabOrder = 15
    Text = '5'
  end
  object Chart5: TChart
    Left = 5
    Top = 328
    Width = 391
    Height = 89
    AllowPanning = pmHorizontal
    AllowZoom = False
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Gradient.EndColor = clSilver
    Gradient.Visible = True
    Title.Text.Strings = (
      #1063#1072#1089#1090#1086#1090#1072' '#1086#1073#1086#1088#1086#1090#1086#1074' '#1074#1072#1083#1072' '#1074#1080#1085#1090#1072', '#1086#1073'/'#1084#1080#1085)
    OnScroll = Chart5Scroll
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.Maximum = 100
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.Maximum = 5000
    Legend.Visible = False
    View3D = False
    TabOrder = 16
    object Series5: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Edit7: TEdit
    Left = 440
    Top = 328
    Width = 50
    Height = 21
    Hint = #1063#1072#1089#1090#1086#1090#1072' '#1086#1073#1086#1088#1086#1090#1086#1074' '#1074#1072#1083#1072' '#1074#1080#1085#1090#1072', '#1086#1073'/'#1084#1080#1085
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 17
  end
  object Edit2: TEdit
    Left = 408
    Top = 136
    Width = 80
    Height = 21
    Hint = #1058#1103#1075#1072', '#1082#1075
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
  end
  object Edit1: TEdit
    Left = 408
    Top = 32
    Width = 80
    Height = 21
    Hint = #1052#1086#1084#1077#1085#1090', '#1053'*'#1084
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 2
  end
  object Shape1: TPanel
    Left = 240
    Top = 56
    Width = 33
    Height = 289
    Color = clRed
    TabOrder = 18
  end
  object Edit8: TEdit
    Left = 408
    Top = 96
    Width = 81
    Height = 21
    Hint = #1052#1086#1097#1085#1086#1089#1090#1100', '#1083'.'#1089'.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 19
  end
  object Edit9: TEdit
    Left = 408
    Top = 496
    Width = 81
    Height = 21
    Hint = ' '#1056#1072#1089#1093#1086#1076' '#1090#1086#1087#1083#1080#1074#1072', '#1075'.'#1083'.'#1089'./'#1095
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 20
  end
  object About: TButton
    Left = 500
    Top = 0
    Width = 49
    Height = 25
    Hint = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'.'
    Caption = '?'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 21
    OnClick = AboutClick
  end
  object TrackBar1: TTrackBar
    Left = 400
    Top = 240
    Width = 30
    Height = 177
    Hint = #1059#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1076#1088#1086#1089#1089#1077#1083#1077#1084
    LineSize = 2
    Max = 100
    Orientation = trVertical
    Frequency = 1
    Position = 100
    SelEnd = 100
    SelStart = 0
    TabOrder = 22
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = TrackBar1Change
  end
  object Edit10: TEdit
    Left = 440
    Top = 392
    Width = 50
    Height = 21
    Hint = #1055#1086#1083#1086#1078#1077#1085#1080#1077' '#1076#1088#1086#1089#1077#1083#1103', %'
    Color = clSilver
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 23
  end
  object ComPort: TComPort
    BaudRate = br9600
    Port = 'COM1'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    Left = 736
  end
  object OpenDialog1: TOpenDialog
    Left = 664
  end
  object SaveDialog1: TSaveDialog
    Left = 696
  end
  object ComDataPacket1: TComDataPacket
    ComPort = ComPort
    StartString = '$'
    StopString = '!'
    OnPacket = ComDataPacket1Packet
    Left = 776
  end
end
