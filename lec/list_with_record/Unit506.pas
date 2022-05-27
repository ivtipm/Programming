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

    {Операции для работы с двусвязанным списком }
   procedure AddFirst(var f: PUzel; a: PUzel);{Вставить узел a первым в список}
   procedure AddAfter(var old:PUzel; a: PUzel);{Вставить узел a после old}
   {Построить список; f - указатель на голову списка}
   procedure BuildSpisok(var f: PUzel);
   {Вывод списка в текстовый файл}
   procedure WriteSpText(var f: PUzel;var ftxt:Text);
    {Выделить из списка первый узел и вернуть его пользователю}
   procedure DelFirstElement(var f,a: PUzel);
   {Выделить из списка узел,следующий за узлом old и вернуть его пользователю}
   procedure DelElement(var old,a: PUzel);
   procedure DelSpisok(var f: PUzel);  //Удалить список
   {Сохранение списка в типизированном файле}
   procedure SaveSpisokftip(var f: PUzel;var ft:FZap);
    {Восстановление списка из типизированного файла}
   procedure BuildSpFromFile(var f: PUzel;var ft:FZap);
   {Функция, которая определяет средний вес вещей в списке }
   function SRV(var f: PUzel): real;
    {процедура, которая выводит в окно  ShowMessage  и в текстовый файл
    результат поиска багажей, средний вес которых меньше либо равен среднему
    весу вещи в списке.}
   procedure FindSRVBag(var f: PUzel; var ftxt: text);
   {Процедура добавления в хвост списка новых узлов}
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
        Fam := InputBox('Введите фамилию',' ',' ');
        Nam := InputBox('Введите имя',' ',' ');
        Otch := InputBox('Введите отчество',' ',' ');
        Npasp:= InputBox('Введите серию и номер паспорта',' ',' ');
        ColV:= StrToInt(InputBox('Введите количество вещей',' ',' '));
        VesV:= StrToFloat(InputBox('Введите вес вещей',' ',' '));
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
      ch:= InputBox('Для завершения ввода нажмите Y',' ',' ')[1];
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


   {Сохранение списка в типизированном файле}
   procedure SaveSpisokftip(var f: PUzel;var ft:FZap);
    var
     p: PUzel;
    begin
     p:=f;
     seek(ft,0);    //устанавливаем указатель в типизированном файле на 0 
      while (p <> nil) do
       begin
        write(ft,p^.x);
        p:= p^.next;
       end;
    end;


   {Восстановление списка из типизированного файла}
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


   {Функция, которая определяет средний вес вещей в списке }
   function SRV(var f: PUzel): real;
    var
     p: PUzel;                          //текущий указатель на узел списка
     n: integer;                        //количество вещей во всех багажах
     S: real;                               //суммарный вес вещей в списке
    begin
     p:=f;
     n:=0; S:=0;
     {Цикл вычисления общего количества и суммарного веса вещей в списке}
     while (p <> nil) do
      begin
       n:= n + p^.x.ColV;
       S:= S + p^.x.VesV;
       p:=p^.next;             //перевод указателя на следующий уел списка
      end;
     SRV:= S/N;                               //средний вес вещей в списке
    end;


    {процедура, которая выводит в окно  ShowMessage  и в текстовый файл
    результат поиска багажей, средний вес которых от среднего
    веса  вещи в списке не более чем на 0.5 кг.}
   procedure FindSRVBag(var f: PUzel; var ftxt: text);
    var
     p: PUzel;                           //текущий указатель на узел списка
     SRi, SR: real;         //SRi-средний вес вещи в багаже и  SR- в списке
     S: string;                                  //строка вывода результата
    begin
     SR:= SRV(f);                               //средний вес вещи в списке
     p:=f; //
     while (p <> nil) do             //цикл поиска багажа в списке по ключу
      begin
       SRi:= p^.x.VesV/ p^.x.ColV;              //средний вес вещи в багаже
       if(abs(SRi - SR) <= 0.5) then
         begin              //если багаж найден, то создать строку вывода S
          with p^.x do
           S:= Fam + ' ' + Nam + ' '+ Otch + ' ' + Npasp + ' '+
              IntToStr(ColV)+ ' '+ FloatToStr(VesV);
          ShowMessage(S);
          writeln(ftxt,S);             //вывод результата в текстовый файл
         end;
       p:= p^.next;                  //перевод указателя на следующий узел
      end;
    end;


   {Процедура добавления в хвост списка новых узлов}
  procedure AppUzels(var f: PUzel);
   var
    a,p,d: PUzel;    //указатели:а-на созданный узел,p-текущий,d- на хвост
    i,n: byte;
   begin
    p:= f;
    while (p <> nil) do   //цикл для определения указателя на хвост списка
     begin
      d:=p;
      p:= p^.next;
     end;
    n:= StrToInt(InputBox('Введите число вставляемых узлов',' ',' '));
    for i:=1 to n do                   //цикл вставки узлов в хвост списка
     begin
      new(a);
      with a^.x do
       begin
        Fam := InputBox('Введите фамилию',' ',' ');
        Nam := InputBox('Введите имя',' ',' ');
        Otch := InputBox('Введите отчество',' ',' ');
        Npasp:= InputBox('Введите серию и номер паспорта',' ',' ');
        ColV:= StrToInt(InputBox('Введите количество вещей',' ',' '));
        VesV:= StrToFloat(InputBox('Введите вес вещей',' ',' '));
       end;
      a^.next := nil;
      a^.pred := nil;
      AddAfter(d,a);
      d := a;
     end;
    end;

end.
