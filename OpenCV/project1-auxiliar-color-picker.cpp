#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  int          camera_id = 0;
  VideoCapture capture(camera_id);
  Mat          img, imgHsv, mask;

  int hmin = 0, smin = 0, vmin = 0;
  int hmax = 179, smax = 255, vmax = 255;

  // essa função chamada Window cria uma janela que pode ser usada como um espaço reservado para imagens e
  // trackbars. As janelas criadas são referidas por seus nomes.
  namedWindow("Trackbars", (320, 240));

  // Cria um trackbar e o anexa à janela especificada.
  createTrackbar("Hue Min", "Trackbars", &hmin, 179);
  createTrackbar("Hue Max", "Trackbars", &hmax, 179);
  createTrackbar("Sat Min", "Trackbars", &smin, 255);
  createTrackbar("Sat Max", "Trackbars", &smax, 255);
  createTrackbar("Val Min", "Trackbars", &vmin, 255);
  createTrackbar("Val Max", "Trackbars", &vmax, 255);

  while (true) {
    capture.read(img);

    cvtColor(img, imgHsv, COLOR_BGR2HSV);

    Scalar lowerLimit(hmin, smin, vmin);
    Scalar upperLimit(hmax, smax, vmax);
    // Verifica se os elementos da matriz estão entre os elementos de duas outras matrizes.
    // inRange(img, lowerLimit, upperLimit, mask);
    inRange(imgHsv, lowerLimit, upperLimit, mask);

    cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << endl;

    imshow("Image", img);
    // imshow("Image HSV", imgHsv);
    imshow("Image Mask", mask);

    waitKey(1); // 1ms
  }
  return 0;
}