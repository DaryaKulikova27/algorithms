Program Beds;
Const 
  Max=200;
Type
  Stack = array[1..Max*Max] of byte;
Var
  X,Y: ^Stack;
  i,j: integer;
  Top: word; 
  Fin,Fout: text;
  N,M: integer;
  C: array[0..Max+1,0..Max+1] of char;
  Count: integer;

Procedure Pop(Var i,j: integer);
  Begin
    i:=X^[Top];
    j:=Y^[Top];
    Top:=Top-1;
  End;

Procedure Push(i,j: integer);
  Begin
    if C[i,j]='#' then
      begin
        Top:=Top+1;
        X^[Top]:=i;
        Y^[Top]:=j;
        C[i,j]:='.'
      end;
  End;
  
Procedure Metka(i,j: integer);
Begin
  Top:=0;
  Push(i,j);
  While Top>0 do 
    begin
      Pop(i,j);
      Push(i+1,j);
      Push(i-1,j);
      Push(i,j+1);
      Push(i,j-1);
    end
End;

Begin
  For i:=0 to N+1 do
    For j:=0 to M+1 do
      C[i,j]:='.';
  Assign(Fin,'input.txt');
  Reset(Fin);
  ReadLn(Fin,N,M);
  For i:=1 to N do
    begin
      For j:=1 to M do Read(Fin, C[i,j]);
      ReadLn(Fin);
    end;
  Close(Fin);
  New(X);  New(Y);
  Count:=0;
  For i:=1 to N do
    For j:=1 to M do
      if C[i,j]='#' then 
        begin
          Count := Count+1; 
          Metka(i,j)
        end;
   Dispose(X);
   Dispose(Y);
  Assign(Fout,'output.txt');
  Rewrite(Fout);
  WriteLn(Fout,Count);
  Close(Fout);
End.

