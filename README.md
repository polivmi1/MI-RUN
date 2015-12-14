# MI-RUN

Welcome to our implementation of a new language and its runtime.
In the main folder you will find the parser, compiler and all its components. 

The grammar is specified in a file Calc.bnfc
Files example.txt, exampleExceptions.txt and exampleLinkedList.txt contain example programs on how to program in our language.

To translate the compiler there is Makefile, for which you will need g++, flex and bison tools.
bnfc-2.8-win.exe is only for translating Calc.bnfc on windows into files, that are compatible with flex/bison.

After the compilation you will obtain file TestCalc.exe, that when running accepts one parameter: the name of the file, in which is written your program.

In folder VM, there is the actual virtual machine.
Running TestCalc.exe will make two files saved_data and saved_dataC, which contain bytecode/classes/functions/constants,...
For a simple architecture of our VM you can see file UML.png, which is unfortunately incomplete and changed a bit since then.

To run your program in our VM there is a Makefile and then you run TestRun.exe.

The language is dynamically-typed and object-oriented, allows basic syntax structures, inheritance and exceptions. 
There are 4 basic native functions: print(exp), x = readInt(), x = readDouble(), x = readString()
The VM is stack-based and contains generative garbage collector.

