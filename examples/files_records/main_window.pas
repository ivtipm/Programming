unit main_window;

// https://pastebin.com/4fqBNxj0
// https://pastebin.com/zMjGdKFT

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls,
  students;

type

  { TForm_main }

  TForm_main = class(TForm)
    Button_gen: TButton;
    Memo: TMemo;
    procedure Button_genClick(Sender: TObject);
  private

  public

  end;

const
  N = 3;
  data_file = 'data.students';
  text_file = 'data.students.txt';

var
  Form_main: TForm_main;

  studs: ArrayStudents;


implementation

{$R *.lfm}

{ TForm_main }

//
procedure TForm_main.Button_genClick(Sender: TObject);
var
    s: Student;
    i:integer;
begin
    random_students(studs, n);
    students_to_typed_file(studs, n, data_file);
    typed_file_to_text_file(data_file, text_file);

    for i:=1 to n do
      begin
        s:= studs[i];
        Memo.Lines.Add( s.name + '      ' + FloatToStr(s.grade) );
      end;
end;

end.

