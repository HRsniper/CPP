#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  string image_path = "testopencvcards.jpg";

  Mat img = imread(image_path);
  Mat imgHsv, mask;

  int hmin = 0, smin = 14, vmin = 151;
  int hmax = 209, smax = 121, vmax = 255;

  if (img.empty()) {
    cout << "Não foi possível ler a imagem: " << image_path << endl;
    return 1;
  }

  cvtColor(img, imgHsv, COLOR_BGR2HSV);

  // essa função chamada Window cria uma janela que pode ser usada como um espaço reservado para imagens e
  // trackbars. As janelas criadas são referidas por seus nomes.
  namedWindow("Trackbars", (320, 240));

  // Cria um trackbar e o anexa à janela especificada.
  createTrackbar("Hue Min", "Trackbars", &hmin, 360);
  createTrackbar("Hue Max", "Trackbars", &hmax, 360);
  createTrackbar("Sat Min", "Trackbars", &smin, 255);
  createTrackbar("Sat Max", "Trackbars", &smax, 255);
  createTrackbar("Val Min", "Trackbars", &vmin, 255);
  createTrackbar("Val Max", "Trackbars", &vmax, 255);

  while (true) {
    Scalar lowerLimit(hmin, smin, vmin);
    Scalar upperLimit(hmax, smax, vmax);
    // Verifica se os elementos da matriz estão entre os elementos de duas outras matrizes.
    inRange(img, lowerLimit, upperLimit, mask);

    imshow("Image", img);
    imshow("Image HSV", imgHsv);
    imshow("Image Mask", mask);

    waitKey(1); // 1ms
  }
  return 0;
}