#include <iostream>

int main (void) {
  // Pad the whole damn thing with zeros at the edges.
  int f[4][4] = {{0,0,0,1},{1,1,1,0},{1,1,1,0},{1,1,1,0}};
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      std::cout << f[i][j] << " ";
    }
    std::cout << "\n";
  }

  
  
}
