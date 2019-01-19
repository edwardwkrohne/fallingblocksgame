// Some sort of brief comment here

class Block {
public:
  //constructor
  Block(int y, int x, int pieceId );


  char get(int row, int col);
  // other functions that you want go here.

  

  void rotateCW();
  void rotateCCW();
  void print(ostream& out);

private:
  void copy_pieces(char (&dest)[5][5], const char (&src)[5][5]);


  char data[5][5];

}
