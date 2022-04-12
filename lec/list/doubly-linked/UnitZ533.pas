unit UnitZ533;

interface
  uses SysUtils, Dialogs;
  type
   PUzel = ^Zp2;
   Zp2 = record
         x: real;
         next: PUzel;
         pred: PUzel;
        end;
   FZap = file of real;
   {�������� ��� ������ � ������������ ������� }
   procedure AddFirst(var f: PUzel; a: PUzel);{�������� ���� a ������ � ������}
   procedure AddAfter(var old:PUzel; a: PUzel);{�������� ���� a ����� old}
   {��������� ������; f -��������� �� ������ ������}
   procedure BuildSpisok(var f: PUzel);
   {����� ������ � ��������� ����}
   procedure WriteSpText(var f: PUzel;var ftxt:Text);
    {�������� �� ������ ������ ���� � ������� ��� ������������}
   procedure DelFirstElement(var f,a: PUzel);
   {�������� �� ������ ����,��������� �� ����� old � ������� ��� ������������}
   procedure DelElement(var old,a: PUzel);
   procedure DelSpisok(var f: PUzel);  //������� ������
   function SumElemSp(var f: PUzel):real; //���������� ����� �� ������� ������
implementation
    procedure AddFirst(var f: PUzel; a: PUzel);
    begin
     a^.next := f;
     if f<> nil then f^.pred := a;
     f:=a;
    end;
   procedure AddAfter(var old:PUzel; a: PUzel);
    begin
     a^.next := old^.next;
     old^.next := a;
     if a^.next <> nil then a^.next^.pred := a;
     a^.pred := old;
    end;
   procedure BuildSpisok(var f: PUzel);
    var
     a,d :PUzel;
     ch: char;
    begin
     f:= nil;
     repeat
      new(a);
      a^.x := StrToFloat(InputBox('������� �������� �����',' ',' '));
      a^.next := nil;
      if (f = nil) then
         begin
          AddFirst(f,a);
          d:= f;
         end
        else
         begin
          AddAfter(d,a);
          d := a;
         end;
      ch:= InputBox('��� ���������� ����� ������� Y',' ',' ')[1];
     until (ch = 'Y') or (ch ='y');    
    end;
   procedure WriteSpText(var f: PUzel; var ftxt:Text);
    var
     p: PUzel;
     s: string;
     y: real;
    begin
     p:= f;
     while not(p = nil) do
      begin
       y:= p^.x;
       s:=Format('%-7.3g',[y]);
       write(ftxt, s);
       p:= p^.next;
      end;
    end;
   function SumElemSp(var f: PUzel):real;
     var
      p,d: PUzel;
      s: real;
     begin
      p:= f;
      {����������� ��������� �� ��������� ������� ������}
      while not(p = nil) do
       begin
        if (p^.next = nil) then d:= p;
        p:=p^.next;
       end;
      {���������� ����� ��������� ������ �� ��������� �������}
      p:= f;
      s:= 0;
      while not(p^.next = nil) do
       begin
        s:= s + (p^.x + p^.next^.x +2*d^.x);
        p:= p^.next;
        d:= d^.pred;
       end;
       return s;
     end;
   procedure DelFirstElement(var f,a: PUzel);
    begin
      a := f;
      f := f^.next;
      a^.next := nil;
      if f<>nil then f^.pred := nil;
    end;
   procedure DelElement(var old,a: PUzel);
    begin
     if (old^.next = nil) then a:= nil  //old ��������� ���� � ������
      else
       if (old^.next^.next = nil) then  //old ������������� ���� � ������
          begin
           a := old^.next;
           a^.pred:= nil;
           old^.next:= nil;
          end
         else
          begin             //�� old �� ����� ���� ����� � ������
           a := old^.next;
           old^.next := a^.next;
           old^.next^.pred:= old;
           a^.next := nil;
           a^.pred:= nil;
          end;
    end;
   procedure DelSpisok(var f: PUzel);  //������� ������
    var
     a: PUzel;
    begin
     while (f <> nil) do
      begin
       DelFirstElement(f,a);
       Dispose(a);
      end;
    end;
end.
 