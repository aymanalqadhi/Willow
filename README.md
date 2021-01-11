# Willow


Willow takes a more oriented approach in its language. There is a class system in willow, which the keyword class, has been renamed to manager.
global declarations and functions are called and used inside of the manager to accomplish the goals of the program. In the example code below one would say:
The manager manages all of the hello functions in this file.

hello manager
{
    hollow main:>
    {
        write:  "hello world\n">;
    }
}

Willow takes a c like approach to most of the code except for a few changes. In the above code you will notice that the main function uses a colon :
and a rarrow > instead of the lparen ( and rparen ). In willow it is considered good practice to have the colon next to the function name
for readabilty and put two spaces before the strand literal.


In willow the data types are hollow, num, deci, decii, deciv, mark, strand, and return.  

All derived types and statements are considered to be tools, these data tools are what we use on the actual data, to accomplish our goals. 
Willows data tools: check, else, loop, set, pare, compare, line, break, construct, log, bridge, list

In willow, variables are called placeholders. We use the word placeholder because it decribes the actual meaning of what we are doing more clearly.
We are using a placeholder, which has an address in memory, for one of our data types value.

When pertaining to scope: Anything outside of a file has a flag of external, if the flag is external, then the scope is in universal scope. 
Anything inside of a file has a flag of internal, which sets the external to null, and is in the global scope. Anything inside of a function 
is in the local scope. 


Image of possible scope: I wonder if this would actually work to avoid header confliction between files.
https://github.com/ravenleeblack/Willow/issues/1#issue-782949005
     
Any help would be much appreciated!!!     
     
                    Conversion Table
    =================================================================================
    This langauge:              Old Keywords:
    =================================================================================
     hollow                     void
     num                        int                
     deci                       float              
     decii                      double
     deciv                      double double     
     mark                       char
     strand                     string
     return                     return

     check                      if
     else                       else
     loop                       while
     act                        do
     set                        for
     pare                       bool
     compare                    switch
     line                       case
     list                       array
     break                      break
     construct                  struct
     log                        enum
     bridge                     union

     manager                    class
     private                    private
     public                     public
           
           
           
           
     

