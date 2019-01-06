Type

   make test

To run the test.  You want to fill in rotateCW in block.cpp to make the test pass.  You need to change
the variable called "block" within the function,
which will require a temp variable. Do your rotation
as you copy to the temp variable, and then copy
the temp variable back to the original.

When I did this, I created that tmep variable with:

   char temp_block[5][5];
