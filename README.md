# Willow

In willow the data types are hollow, num, deci, mark, return.                  

The tools to be used on the data types are all the statements: check, else, loop, set, pare, compare, line, break, construct, log, bridge, list

Manager replaces class in the oriented setup and takes a more c# approach where all objects or functions are called inside the manager.

When pertaining to scope and the flag external is used, then the scope is universal, whichs means anything outside of the files are universal, anything inside the file gets a flag of internal, and is global scope, unless it breaks down into the local scope.

                    Conversion Table
    =================================================================================
    This langauge:              Old Keywords:
    =================================================================================
     hollow                     void
     num                        int
     deci                       float
     mark                       char
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

     place_holder     aka       variable
           
           
           
     
                 scope layout(maybe, we'll see if I cant make it happen)
               
                universal(external)
                  /       \
                 /         \
                /           \
               /             \
              /                \
             /                   \
            /                      \
          global(internal)         global(internal)
           |                        |
           |                        |
           |-local                  |-local
           |                        |
           |-local                  |-local
