unit UnitZ531;
// Односвязные списки

interface
  uses SysUtils, Dialogs;
  
  type
   PUzel = ^Zp;

   Zp = record
         x: real;
         next: PUzel;
        end;

   FZap = file of real;

   {Операции для работы с односвязанным списком }
   procedure AddFirst(var f: PUzel; a: PUzel);          {Вставить узел a первым в список}
   procedure AddAfter(var old:PUzel; a: PUzel);         {Вставить узел a после old}
   procedure BuildSpisok(var f: PUzel);                 {Построить список; f -указатель на голову списка}
   procedure WriteSpText(var f: PUzel;var ftxt:Text);   {Вывод списка в текстовый файл}
   procedure NewSpisok(var f: PUzel; var fn: PUzel);    {Создать из существующего списка новый}
   procedure DelFirstElement(var f,a: PUzel);           {Выделить из списка первый узел и вернуть его пользователю}
   procedure DelElement(var old,a: PUzel);              {Выделить из списка узел,следующий за узлом old и вернуть его пользователю}
   procedure DelSpisok(var f: PUzel);                   // Удалить список
   function EndElemSp(var f: PUzel):real;               // Значение последнего  элем. в списке


implementation

   procedure AddFirst(var f: PUzel; a: PUzel);
    begin
     a^.next := f;
     f:=a;
    end;

   procedure AddAfter(var old:PUzel; a: PUzel);
    begin
     a^.next := old^.next;
     old^.next := a;
    end;

   procedure BuildSpisok(var f: PUzel);
    var
     a,d :PUzel;
     ch: char;
    begin
     f:= nil;
     repeat
      new(a);
      a^.x := StrToFloat(InputBox('Введите реальное число',' ',' '));
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
      ch:= InputBox('Для завершения ввода нажмите Y',' ',' ')[1];
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

   function EndElemSp(var f: PUzel):real;
     var
      p: PUzel;
     begin
      p:= f;
      while not(p = nil) do
       begin
        if (p^.next = nil) then Result:= p^.x;
        p:=p^.next;
       end;
     end;

   procedure NewSpisok(var f: PUzel; var fn: PUzel);
    var
     xn: real;
     p,a,d: PUzel;
    begin
      xn := EndElemSp(f);
      p:= f;
      fn:=nil;
      new(a);
      a^.x := p^.x - xn;
      AddFirst(fn,a);
      d:= fn;
     while not(p^.next = nil) do
      begin
       new(a);
       a^.x := p^.x - xn;
       AddAfter(d,a);
       d := a;
       p:=p^.next;
      end;
    end;

   procedure DelFirstElement(var f,a: PUzel);
    begin
      a := f;
      f := f^.next;
      a^.next := nil;
    end;

   procedure DelElement(var old,a: PUzel);
    begin
     a := old^.next;
     old^.next := a^.next;
     a^.next := nil;
    end;

   procedure DelSpisok(var f: PUzel);  //Удалить список
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
