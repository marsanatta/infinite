#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int size;

typedef struct pixel{
  int r;
  int g;
  int b;
  int a;

  /*inline void operator=(const struct pixel &p){
    a = p.a;
    r = p.r;
    g = p.g;
    b = p.b;
    
  }*/

}Pixel;

//O(n^2)
void spinImage1(Pixel** image){

  //transform image to 1D arrary
  Pixel* image1D = new Pixel[size*size];
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      image1D[i*size + j] = image[i][j];
    }
  }

  int used = 0;
  for (int j = 0; j < size; j++) {
    for (int i = size-1; i >= 0; i--) {
      image[i][j] = image1D[size*size-1-used];
      used++;
    }
  }

}

//O(n^2)
void spinImage2(Pixel** image){
  
  for (int layer = 0; layer < size/2; layer++) {
    for (int i = 0; i < size-1-(layer*2); i++){
      //keep top
      Pixel top = image[layer][layer+ i];
      //left to top
      image[layer][layer+ i] = image[size-1-i-layer][layer];
      //bottom to left
      image[size-1-i-layer][layer] = image[size-1-layer][size-1-i-layer];
      //right to bottom
      image[size-1-layer][size-1-i-layer] = image[i+layer][size-1-layer];
      //top to right
      image[i+layer][size-1-layer] = top;
    }
  }

}

int main() {

  cin >> size;
  Pixel** image = new Pixel*[size];
  for (int i = 0; i < size; i++) {
    image[i] = new Pixel[size];
  }
  

  srand(time(NULL));
  int elem = 1;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      image[i][j].a = rand() % 256; 
      image[i][j].r = elem++;
      image[i][j].g = rand() % 256;
      image[i][j].b = rand() % 256;
    }
  }

  cout << "original image: " << endl;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << image[i][j].r << " ";
    }
    cout << endl;
  }
  
  spinImage1(image);
  cout << endl << "after spin 90 degree using way1: " << endl;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << image[i][j].r << " ";
    }
    cout << endl;
  }



  spinImage2(image);
  cout << endl << "after spin 90 degree using way2: " << endl;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cout << image[i][j].r << " ";
    }
    cout << endl;
  }
 

  return 0;
}
