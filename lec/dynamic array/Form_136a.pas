unit Unit136a;


interface
uses SysUtils,Dialogs;
 type
  DinMas = array of integer;
  Tipfile = file of integer;
  procedure ZapMassHand(var a: DinMas);
  procedure WriteMassText(var a: array of integer; var f: text);

implementation
  procedure ZapMassHand(var a: DinMas);
   var
     n,i : word;
     k: string[10];
   begin
     n:= StrToInt(InputBox('������� �����. ����. � �������',' ',' '));
     SetLength(a,n);   //��������� ������ ��� ������
     for i:=0 to n do
      begin
       k:= IntToStr(i);
       a[i]:= StrToInt(Inputbox('input' + k + 'element',' ',' '));
      end;
   end;
  procedure WriteMassText(var a: array of integer; var f: text);
    var
      n,i: integer; //n- ���������� ���������� ��������� � ������
    begin
      n:= StrToInt(InputBox('������� �����. ����. � ������',' ',' '));
      writeln(f, '�������� ������');
      write(f, a[0]:5,'  ');
      for i:=1 to High(a) do
        if (i mod n = 0) then writeln(f, a[i]:5)
         else write(f, a[i]:5,'  ');
      writeln(f,' ');
    end;

end.
