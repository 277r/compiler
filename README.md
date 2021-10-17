# compiler
## me trying to make a c(++) compiler

## the compiler is made out of 4 components 

### preprocessor
removes unneeded data like comments and (possibly) unused functions
resolves #include, #define, and other preprocessor derivatives starting with a '#'

### compiler
compiles the code to assembly

### assembler
turns the assembly files into raw machine code, stores it in object files

### linker
combines all object files and turns it into an executable


## ysk
you should know that this compiler will not be an actual compiler to be used, it will be a compiler that can compile valid c(++) code, but if you enter broken code it will probably crash or give a broken output file. this compiler also will not support every thing c/c++ have to offer. this compiler is made to see if i know how to make a compiler, not to build an actual compiler and use it  