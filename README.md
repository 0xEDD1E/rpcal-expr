# rpcal-expr
Reverse Polish calculator (in command line arguments mode)

This is a reverse polish calculator
It is very simple and operated with command line arguments
program is written in C with notepad++.
It was written as an answer to a exrecise in K&R's "The C Programming Language" book.

program name is "expr"
Using expr:
 > expr <NUM1> <NUM2> ... <+-x/> <+-x/> ... 

as an example
 > expr 2 3 4 + x
 
evaluate the expression
 > 2 x (3 + 4) \
 > OUTPUT: 14.000000
 
Special Notes:
  >this program can't use (*) as multiply sign in windows or linux
  >and also (/) as the division sign in linux (in bash shell)

