unit Unit506;

interface
 uses SysUtils, Dialogs;
  type
   Bag = record
          Fam, Nam, Otch : string[20];
          ColV: byte;
          VesV: real;
          Npasp: string[20];
         end;
   PUzel = ^Zp2;
   Zp2 = record
         x: Bag;
         next: PUzel;
         pred: PUzel;
        end;
   FZap = file of Bag;

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
   {���������� ������ � �������������� �����}
   procedure SaveSpisokftip(var f: PUzel;var ft:FZap);
    {�������������� ������ �� ��������������� �����}
   procedure BuildSpFromFile(var f: PUzel;var ft:FZap);
   {�������, ������� ���������� ������� ��� ����� � ������ }
   function SRV(var f: PUzel): real;
    {���������, ������� ������� � ����  ShowMessage  � � ��������� ����
    ��������� ������ �������, ������� ��� ������� ������ ���� ����� ��������
    ���� ���� � ������.}
   procedure FindSRVBag(var f: PUzel; var ftxt: text);
   {��������� ���������� � ����� ������ ����� �����}
    procedure AppUzels(var f: PUzel);



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
      with a^.x do
       begin
        Fam := InputBox('������� �������',' ',' ');
        Nam := InputBox('������� ���',' ',' ');
        Otch := InputBox('������� ��������',' ',' ');
        Npasp:= InputBox('������� ����� � ����� ��������',' ',' ');
        ColV:= StrToInt(InputBox('������� ���������� �����',' ',' '));
        VesV:= StrToFloat(InputBox('������� ��� �����',' ',' '));
       end;
      a^.next := nil;
      a^.pred := nil;
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
     y: Bag;
    begin
     p:= f;
     while not(p = nil) do
      begin
       y:= p^.x;
       s:=y.Fam +'  ' + y.Nam +'  '+ y.Otch + '  '+ y.Npasp +'  '+
        IntToStr(y.ColV) + '  '+ FloatToStr(y.VesV);
       writeln(ftxt, s);
       p:= p^.next;
      end;
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


   {���������� ������ � �������������� �����}
   procedure SaveSpisokftip(var f: PUzel;var ft:FZap);
    var
     p: PUzel;
    begin
     p:=f;
     seek(ft,0);    //������������� ��������� � �������������� ����� �� 0 
      while (p <> nil) do
       begin
        write(ft,p^.x);
        p:= p^.next;
       end;
    end;


   {�������������� ������ �� ��������������� �����}
   procedure BuildSpFromFile(var f: PUzel;var ft:FZap);
    var
     a,d : PUzel;
    begin
     f:= nil;
     Seek(ft,0);
     repeat
      new(a);
      read(ft,a^.x);
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
     until Eof(ft);
    end;


   {�������, ������� ���������� ������� ��� ����� � ������ }
   function SRV(var f: PUzel): real;
    var
     p: PUzel;                          //������� ��������� �� ���� ������
     n: integer;                        //���������� ����� �� ���� �������
     S: real;                               //��������� ��� ����� � ������
    begin
     p:=f;
     n:=0; S:=0;
     {���� ���������� ������ ���������� � ���������� ���� ����� � ������}
     while (p <> nil) do
      begin
       n:= n + p^.x.ColV;
       S:= S + p^.x.VesV;
       p:=p^.next;             //������� ��������� �� ��������� ��� ������
      end;
     SRV:= S/N;                               //������� ��� ����� � ������
    end;


    {���������, ������� ������� � ����  ShowMessage  � � ��������� ����
    ��������� ������ �������, ������� ��� ������� �� ��������
    ����  ���� � ������ �� ����� ��� �� 0.5 ��.}
   procedure FindSRVBag(var f: PUzel; var ftxt: text);
    var
     p: PUzel;                           //������� ��������� �� ���� ������
     SRi, SR: real;         //SRi-������� ��� ���� � ������ �  SR- � ������
     S: string;                                  //������ ������ ����������
    begin
     SR:= SRV(f);                               //������� ��� ���� � ������
     p:=f; //
     while (p <> nil) do             //���� ������ ������ � ������ �� �����
      begin
       SRi:= p^.x.VesV/ p^.x.ColV;              //������� ��� ���� � ������
       if(abs(SRi - SR) <= 0.5) then
         begin              //���� ����� ������, �� ������� ������ ������ S
          with p^.x do
           S:= Fam + ' ' + Nam + ' '+ Otch + ' ' + Npasp + ' '+
              IntToStr(ColV)+ ' '+ FloatToStr(VesV);
          ShowMessage(S);
          writeln(ftxt,S);             //����� ���������� � ��������� ����
         end;
       p:= p^.next;                  //������� ��������� �� ��������� ����
      end;
    end;


   {��������� ���������� � ����� ������ ����� �����}
  procedure AppUzels(var f: PUzel);
   var
    a,p,d: PUzel;    //���������:�-�� ��������� ����,p-�������,d- �� �����
    i,n: byte;
   begin
    p:= f;
    while (p <> nil) do   //���� ��� ����������� ��������� �� ����� ������
     begin
      d:=p;
      p:= p^.next;
     end;
    n:= StrToInt(InputBox('������� ����� ����������� �����',' ',' '));
    for i:=1 to n do                   //���� ������� ����� � ����� ������
     begin
      new(a);
      with a^.x do
       begin
        Fam := InputBox('������� �������',' ',' ');
        Nam := InputBox('������� ���',' ',' ');
        Otch := InputBox('������� ��������',' ',' ');
        Npasp:= InputBox('������� ����� � ����� ��������',' ',' ');
        ColV:= StrToInt(InputBox('������� ���������� �����',' ',' '));
        VesV:= StrToFloat(InputBox('������� ��� �����',' ',' '));
       end;
      a^.next := nil;
      a^.pred := nil;
      AddAfter(d,a);
      d := a;
     end;
    end;

end.
