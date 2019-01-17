

char Piece::get(int row, int col) {
  return block[row][col];
}

void Piece::set(int row, int col, char b) {
  block[row][col] = b;
}
