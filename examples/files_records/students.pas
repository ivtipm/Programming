unit students;

{$mode ObjFPC}{$H+}

interface
uses
  Classes, SysUtils;

type
    Student = record
      Name: string[128];    // ФИО
      Grade: real;          // ср. оценка
    end;

    ArrayStudents = array[1..1024] of Student;


    procedure random_students( var studs: ArrayStudents; n:integer);                               // Придумывает N случайных студентов
    procedure students_to_typed_file( var studs: ArrayStudents; n:integer; filename:string);       // запись массива студентов в типизированный файл
    procedure typed_file_to_text_file( typed_file:string; text_file:string);                       // переписывание данных из типизированного файла в текстовый


implementation

    // Придумывает N случайных студентов
    procedure random_students( var studs: ArrayStudents; n:integer);
    var
      i:integer;
      s: Student;
    begin
        randomize;
        for i:=1 to n do
          begin
            s.grade := 3 + random(20) / 10;
            s.name := 'Ivanov ' + IntToStr(random(100000)) + ' ' + IntToStr(random(100000));
            studs[i] := s;
          end;
    end;

    // запись массива студентов в типизированный файл
    procedure students_to_typed_file( var studs: ArrayStudents; n:integer; filename:string);       //
    var
      f: file of Student;
      i: integer;
    begin
      AssignFile(f, filename);
      rewrite(f);
      for i:=1 to n do
          begin
            write(f, studs[i]);
          end;
      CloseFile(f);
    end;

  // переписывание данных из типизированного файла в текстовый
  procedure typed_file_to_text_file( typed_file:string; text_file:string);       //
    var
      f: file of Student;
      txt: Text;
      s: Student;
      i: integer;
    begin
      AssignFile(f, typed_file);
      reset(f);

      // todo: дополнять файл, а не перезаписывать
      AssignFile(txt, text_file);
      rewrite(txt);

      while not eof(f) do
        begin
          read(f,s);
          writeln(txt, s.name, ' ', s.grade:3:1);
        end;

      CloseFile(txt);
      CloseFile(f);
    end;

end.

