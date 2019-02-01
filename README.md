To Do:

Note: If you're not reading this on GitHub, I use backticks to highlight code as opposed to English.  In atom, code shows up green in this file.

1. There's a bug in `Block::copy_pieces` that we apparently missed from before.  It intermittently causes a crash.  I found it, fixed it, and then put it back in.  Find it.  Right now a test fails, and it will succeed when you fix it.  HINT: why do you sometimes get garbage on the screen, and why is it intermittent?

2. Commit and then push the fix.

3. Straighten out naming. Decide what the word "piece" and "block" mean, decide whether to rename `class Block` to `class Piece`, and, and make sure the file name matches the class name. Filename should be all lowercase, no spaces or underscores, and class name should be CapitalizedCamelCase.

4. Make sure the unit tests still pass, then commit and then push the changes.

5. Uncomment lines 27, 37, and 122-153 of test.cpp; this uncomments a unit test that will fail.

6. Write the constructor of `GameGrid` and the `checkCollision` function of `Block` (or `Piece`, if you went with `Piece`).  The constructor should just copy some data into a new member variable of `GameGrid` which you should probably call `data`, and the `checkCollision` function we've already discussed.

7. Make sure the unit tests pass.  Commit and then push the fix.

8. What is the purpose of the word `friend` in gamegrid.h?
