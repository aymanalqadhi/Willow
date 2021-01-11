# Willow


Willow takes a more oriented approach in its language. The keyword class has been renamed to manager. Global declarations and functions are called and used inside 
of the manager in a more c# fashion to accomplish our goals in the program. In the example code below we could say: The manager manages all of the hello functions
in this file. When we say it in this fashion then the class becomes easier to understand. 

    hello manager
    {
      hollow main:>
      {
        write:  "hello world\n">;
      }
    }

Willow takes somewhat of a c like approach, but there are many changes, and not just the keywords but also in the grammer. In the above code you will notice that the main function uses a colon : and a rarrow > instead of c's lparen ( and rparen ). In willow it is considered good practice to have the colon next to the function name
for readabilty and put two spaces before the strand literal.


In willow the data types are hollow, num, deci, decii, deciv, mark, strand, and return.  

All derived types and statements are considered to be data tools. These data tools are the tools we will use on the actual data, to accomplish our goals. 
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

As mentioned above. One of the many changes is how the check statement is done. I changed the if to check because it reminds us to check 
the expresssion then excute a statement. In the above example you'll notice that The parens are also missing. This makes the check expression more readable. Even more
so if you are in the habit of using check statements in a linear fashion. Without both parens we now have one less character to type when coding since the rparen is replaced with a colon.


In willow, variables are called placeholders. We use the word placeholder because it makes more sense.
In the code below, we have a placeholder named i, the placeholder i has an address in memory, that holds the num value 0 at that address.


    hollow main:>
    {
        num i = 0;
        
        set i; i < 10; i++:
        {

        }
    }

In the above code we have a set loop. Set loops are just loops that are set a certain amount of times based off the conditions. like the check 
statement we ditch the parens.


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
If the set up in the above link is doable, then it would be considered bad practice to write universals in the .mf file, they
should only be initialized and declared in a user header file.



     
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
           
           
           
           
     

