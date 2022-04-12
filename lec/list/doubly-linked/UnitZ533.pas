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
   {Операции для работы с двусвязанным списком }
   procedure AddFirst(var f: PUzel; a: PUzel);{Вставить узел a первым в список}
   procedure AddAfter(var old:PUzel; a: PUzel);{Вставить узел a после old}
   {Построить список; f -указатель на голову списка}
   procedure BuildSpisok(var f: PUzel);
   {Вывод списка в текстовый файл}
   procedure WriteSpText(var f: PUzel;var ftxt:Text);
    {Выделить из списка первый узел и вернуть его пользователю}
   procedure DelFirstElement(var f,a: PUzel);
   {Выделить из списка узел,следующий за узлом old и вернуть его пользователю}
   procedure DelElement(var old,a: PUzel);
   procedure DelSpisok(var f: PUzel);  //Удалить список
   function SumElemSp(var f: PUzel):real; //Вычисление суммы по условию задачи
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
   function SumElemSp(var f: PUzel):real;
     var
      p,d: PUzel;
      s: real;
     begin
      p:= f;
      {Определение указателя на последний элемент списка}
      while not(p = nil) do
       begin
        if (p^.next = nil) then d:= p;
        p:=p^.next;
       end;
      {Вычисление суммы элементов списка по заданному правилу}
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
     if (old^.next = nil) then a:= nil  //old последний узел в списке
      else
       if (old^.next^.next = nil) then  //old предпоследний узел в списке
          begin
           a := old^.next;
           a^.pred:= nil;
           old^.next:= nil;
          end
         else
          begin             //за old не менее двух узлов в списке
           a := old^.next;
           old^.next := a^.next;
           old^.next^.pred:= old;
           a^.next := nil;
           a^.pred:= nil;
          end;
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
 