#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  // base functions

  string image_path = "testopencvimage.bmp";
  Mat    img        = imread(image_path);
  Mat    imgGray, imgBlur, imgCanny, imgDilate, imgErode;

  // Essa função converte uma imagem de entrada de um espaço de cores para outro.
  cvtColor(img, imgGray, COLOR_BGR2GRAY);

  // Essa função convolve a imagem de origem com o kernel gaussiano (blur) especificado.
  //Size() Classe de modelo para especificar o tamanho de uma imagem ou retângulo.
  GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);

  // Essa função encontra bordas na imagem de entrada e as marca nas bordas do mapa de saída usando o
  // algoritmo Canny.
  Canny(imgBlur, imgCanny, 50, 150);

  Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
  // Dilata uma imagem usando um elemento estruturante específico.
  dilate(imgCanny, imgDilate, kernel);

  // Corrói uma imagem usando um elemento de estruturação específico.
  erode(imgDilate, imgErode, kernel);

  imshow("Image", img);
  imshow("Image Gray", imgGray);
  imshow("Image Blur", imgBlur);
  imshow("Image Canny", imgCanny);
  imshow("Image Dilation", imgDilate);
  imshow("Image Erosion", imgErode);

  waitKey(0); // Aguardando ate pressionamento de tecla

  return 0;
}
