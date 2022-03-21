unit U136;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Menus,Unit136a;

type
  TForm1 = class(TForm)
    MainMenu1: TMainMenu;
    Zupolnmass1: TMenuItem;
    Hands1: TMenuItem;
    Sluch1: TMenuItem;
    Write1: TMenuItem;
    Writetotext1: TMenuItem;
    Writetotipfile1: TMenuItem;
    Rezult1: TMenuItem;
    Srarifm1: TMenuItem;
    Sumsquare1: TMenuItem;
    Open1: TMenuItem;
    OpenTxt1: TMenuItem;
    OpenTipFile1: TMenuItem;
    Close1: TMenuItem;
    CloseTxtFile1: TMenuItem;
    CloseTipFile1: TMenuItem;
    Delete1: TMenuItem;
    DelDinMas1: TMenuItem;
    OpenDialog1: TOpenDialog;
    procedure OpenTxt1Click(Sender: TObject);
    procedure CloseTxtFile1Click(Sender: TObject);
    procedure DelDinMas1Click(Sender: TObject);
    procedure Hands1Click(Sender: TObject);
    procedure Writetotext1Click(Sender: TObject);

  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  dm: DinMas;     //имя динамического массива
  fDM: Tipfile;   //файловая переменная для работы с типизированным файлом
  ftxt: text;     //файловая переменная для работы с текстовым файлом
implementation

{$R *.dfm}

procedure TForm1.OpenTxt1Click(Sender: TObject);
 var s:string;
begin
   if not OpenDialog1.Execute then exit;
  //s:= Inputbox('input name file', ' ', ' ');
  s:= OpenDialog1.FileName;
  AssignFile(ftxt,s);
  Append(ftxt);
end;

procedure TForm1.CloseTxtFile1Click(Sender: TObject);
begin
 CloseFile(ftxt);
end;

procedure TForm1.DelDinMas1Click(Sender: TObject);
begin
 SetLength(dm,0);
end;

procedure TForm1.Hands1Click(Sender: TObject);
begin
 ZapMassHand(dm);
end;

procedure TForm1.Writetotext1Click(Sender: TObject);
begin
  WriteMassText(dm,ftxt);
end;

end.
