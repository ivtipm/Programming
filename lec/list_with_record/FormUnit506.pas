unit U506;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs,Unit506, Menus;

type
  TForm1 = class(TForm)
    MainMenu1: TMainMenu;
    OpenDialog1: TOpenDialog;
    File1: TMenuItem;
    OpenTxtFile1: TMenuItem;
    CloseTxtFile1: TMenuItem;
    List1: TMenuItem;
    BuildList1: TMenuItem;
    Delete1: TMenuItem;
    DelList1: TMenuItem;
    SaveListTxt1: TMenuItem;
    OpenTipFile1: TMenuItem;
    CloseTipFile1: TMenuItem;
    BuildFromFile1: TMenuItem;
    SaveListftip1: TMenuItem;
    FindBag1: TMenuItem;
    AddUzels1: TMenuItem;
    procedure OpenTxtFile1Click(Sender: TObject);
    procedure CloseTxtFile1Click(Sender: TObject);
    procedure BuildList1Click(Sender: TObject);
    procedure DelList1Click(Sender: TObject);
    procedure SaveListTxt1Click(Sender: TObject);
    procedure OpenTipFile1Click(Sender: TObject);
    procedure CloseTipFile1Click(Sender: TObject);
    procedure BuildFromFile1Click(Sender: TObject);
    procedure SaveListftip1Click(Sender: TObject);
    procedure FindBag1Click(Sender: TObject);
    procedure AddUzels1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  PList: PUzel;
  ftxt : text;
  ftip : FZap;
implementation

{$R *.dfm}

procedure TForm1.OpenTxtFile1Click(Sender: TObject);
 var
  s: string;
begin
 if not OpenDialog1.Execute then exit;
 s := OpenDialog1.FileName;
 AssignFile(ftxt,s);
 Append(ftxt);
end;

procedure TForm1.CloseTxtFile1Click(Sender: TObject);
begin
  CloseFile(ftxt);
end;

procedure TForm1.BuildList1Click(Sender: TObject);
begin
   BuildSpisok(PList);
end;

procedure TForm1.DelList1Click(Sender: TObject);
begin
   DelSpisok(PList);
end;

procedure TForm1.SaveListTxt1Click(Sender: TObject);
begin
  writeln(ftxt,'Содержимое двусвязанного списка ');
  WriteSpText(PList,ftxt);
  writeln(ftxt,' ')
end;

procedure TForm1.OpenTipFile1Click(Sender: TObject);
 var
  s: string;
begin
 if not OpenDialog1.Execute then exit;
 s := OpenDialog1.FileName;
 AssignFile(ftip,s);
 Reset(ftip);
end;

procedure TForm1.CloseTipFile1Click(Sender: TObject);
begin
 CloseFile(ftip);
end;

procedure TForm1.BuildFromFile1Click(Sender: TObject);
begin
  BuildSpFromFile(PList,ftip);
end;

procedure TForm1.SaveListftip1Click(Sender: TObject);
begin
  SaveSpisokftip(PList,ftip);
end;

procedure TForm1.FindBag1Click(Sender: TObject);
begin
  FindSRVBag(PList, ftxt);
end;

procedure TForm1.AddUzels1Click(Sender: TObject);
begin
  AppUzels(PList);
end;
 initialization
  {if not OpenDialog1.Execute then exit; }
 { AssignFile(ftxt,'textZ506.txt');
  Append(ftxt); }
  {if not OpenDialog1.Execute then exit;}
 { AssignFile(ftip,'tipZ506.txt');
  Reset(ftip);}
 finalization
  Closefile(ftxt);
  Closefile(ftip);
  DelSpisok(PList);
end.
