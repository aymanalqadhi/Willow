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

Willow takes a c like approach but with many changes in the structure. In the above code you will notice that the main function uses a colon :
and a rarrow > instead of the lparen ( and rparen ). In willow it is considered good practice to have the colon next to the function name
for readabilty and put two spaces before the strand literal.


In willow the data types are hollow, num, deci, decii, deciv, mark, strand, and return.  

All derived types and statements are considered to be tools, these data tools are what we use on the actual data, to accomplish our goals. 
Willows data tools: check, else, loop, set, pare, compare, line, break, construct, log, bridge, list


     hollow main:>
     {
        num i = 0;
        
        check i < 10:
        {

        }
        else check something else:
        {
        
        }
        
        check i < 10: { //do something fancy }
        check i < 10: { //do something fancy }
        check i < 10: { //do something fancy }
     }

As mentioned above. Another one of the changes is how the check statement is done. I changed the if to check because it reminds us to check 
the expresssion. In the above example you'll notice that The parens are also missing. This makes the check expression more readable. Even more
so if you are in the habit of using check statements in a linear fashion. It is also one character to write.

In willow, variables are called placeholders. We use the word placeholder because it makes more sense.
In the above code, we have a placeholder named i, the placeholder i has an address in memory, that holds the num value 0 at that address.


    hollow main:>
    {
        set num i = 0; i < 10; i++:
        {

        }
    }

In the above code we have a set loop. Set loops are just loops that are set a certain amount of times based off the conditions.Just like the check 
statement we ditch the parens especially the left paren and replace the right with a colon.


    hollow main:>
    {
      num choice = 0;
      
      compare choice:
      {
       line 1:     
       line 2:
       otherwise:
       break;
      }
    }
    
In the above code we have switched alot for readability and clarity. We switched a switch lol. Compare makes more sense in relation to the expression.
We ditched the parens again and end it with a colon. We can now say that we are comparing the expression to each line.

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
           
           
           
           
     

