unit U533;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, UnitZ533, Menus;

type
  TForm1 = class(TForm)
    MainMenu1: TMainMenu;
    OpenDialog1: TOpenDialog;
    File1: TMenuItem;
    OpentTxtFile1: TMenuItem;
    CloseTxtFile1: TMenuItem;
    Work1: TMenuItem;
    BuildSp1: TMenuItem;
    Sum1: TMenuItem;
    Delete1: TMenuItem;
    DeleteSp1: TMenuItem;
    WriteSpTextFile1: TMenuItem;
    procedure OpentTxtFile1Click(Sender: TObject);
    procedure CloseTxtFile1Click(Sender: TObject);
    procedure WriteSpTextFile1Click(Sender: TObject);
    procedure BuildSp1Click(Sender: TObject);
    procedure Sum1Click(Sender: TObject);
    procedure DeleteSp1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  Sp1: PUzel;
  ftxt: text;
implementation

{$R *.dfm}

procedure TForm1.OpentTxtFile1Click(Sender: TObject);
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

procedure TForm1.WriteSpTextFile1Click(Sender: TObject);
begin
  writeln(ftxt,'Содержимое двусвязанного списка ');
  WriteSpText(Sp1,ftxt);
  writeln(ftxt,' ')
end;


procedure TForm1.BuildSp1Click(Sender: TObject);
begin
 BuildSpisok(Sp1);
end;

procedure TForm1.Sum1Click(Sender: TObject);
begin
 writeln(ftxt, ' ');
 write(ftxt,'Искомая сумма равна = ');
 writeln( ftxt,SumElemSp(Sp1):7:2);
end;

procedure TForm1.DeleteSp1Click(Sender: TObject);
begin
  DelSpisok(Sp1);
end;

end.
