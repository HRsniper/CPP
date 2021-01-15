#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

void getContours(Mat imgDilate, Mat img) {
  vector<vector<Point>> contours;
  vector<Vec4i>         hierarchy;

  // A função recupera contornos da imagem binária usando o algoritmo [227]
  findContours(imgDilate, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

  // Desenha contornos contornos ou contornos preenchidos.
  /* -1 para desenhar todos contornos */
  // drawContours(img, contours, -1, Scalar(0, 255, 0), 2);

  /* remove noise */
  vector<vector<Point>> contoursPoly(contours.size());
  vector<Rect>          boundRect(contours.size());
  string                objectType;

  for (size_t i = 0; i < contours.size(); i++) {
    // Calcula uma área de contorno.
    double area = contourArea(contours[i]);

    cout << "area" << i << ": " << area << endl;

    if (area > 1000) {
      // drawContours(img, contours, i, Scalar(0, 255, 0), 2);

      /* detection contours of polycons */
      // Calcula um perímetro de contorno ou comprimento de curva.
      double perimeter = arcLength(contours[i], true);

      double roundNumbers = 0.02 * perimeter;
      // essa função aproxima uma curva ou um polígono com outra curva / polígono com menos vértices para que
      // a distância entre eles seja menor ou igual à precisão especificada
      approxPolyDP(contours[i], contoursPoly[i], roundNumbers, true);
      drawContours(img, contoursPoly, i, Scalar(0, 255, 0), 2);
      cout << "area" << i << " edges: " << contoursPoly[i].size() << endl;

      /* retângulo delimitador */
      // essa função calcula e retorna o retângulo delimitador mínimo à direita para o conjunto de pontos
      // especificado ou pixels diferentes de zero da imagem em escala de cinza.
      boundRect[i] = boundingRect(contoursPoly[i]);

      // rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 2);
      /* retângulo delimitador */

      /* detectar qual objeto é qual */
      int objectCorners = int(contoursPoly[i].size());
      if (objectCorners == 3) {
        objectType = "Triangulo";
      } else if (objectCorners == 4) {

        double aspectRatio = double(boundRect[i].width) / double(boundRect[i].height);
        cout << "area" << i << " aspect ratio: " << aspectRatio << endl;

        if (aspectRatio < 1) {
          objectType = "Retangulo";
        } else {
          objectType = "Quadrilatero";
        }

      } else if (objectCorners == 5) {
        objectType = "Pentagono";
      } else if (objectCorners == 6) {
        objectType = "Hexagono";
      } else if (objectCorners == 8) {
        objectType = "Octagono / Circulo";
      } else if (objectCorners == 10) {
        objectType = "Decagono / Estrela";
      }

      putText(img, objectType, { boundRect[i].x, boundRect[i].y }, FONT_HERSHEY_DUPLEX, 0.5,
              Scalar(0, 0, 255));
      cout << "area" << i << ": " << objectType << endl;

      /* detectar qual objeto é qual */

      /* detection contours of polycons */
    }
  }
  /* remove noise */
}

int main(int argc, char const *argv[]) {
  string image_path = "testopencvshapes.png";

  Mat img = imread(image_path);
  Mat imgGray, imgBlur, imgCanny, imgDilate;

  if (img.empty()) {
    cout << "Não foi possível ler a imagem: " << image_path << endl;
    return 1;
  }

  // preprocessando imagem para achar as arestas/bordas
  cvtColor(img, imgGray, COLOR_BGR2GRAY);
  GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
  Canny(imgBlur, imgCanny, 50, 100);
  Mat kernel = getStructuringElement(MORPH_RECT, Size(4, 4));
  dilate(imgCanny, imgDilate, kernel);
  ///////////////

  getContours(imgDilate, img);

  imshow("Image", img);
  // imshow("Image Gray", imgGray);
  // imshow("Image Blur", imgBlur);
  // imshow("Image Canny", imgCanny);
  // imshow("Image Dilation", imgDilate);

  waitKey(0);

  return 0;
}