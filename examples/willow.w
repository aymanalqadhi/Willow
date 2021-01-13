hello manager
{
   hollow hello_world:>
   {
      write: "Hello World\n">;
   }
   hollow random:>
   {
     num count = 1;
     
     check count < 10:
     {
        write: "count is %03d.\n", count>;
     }
   }
} 
