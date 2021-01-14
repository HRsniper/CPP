#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  // blank image
  // Scalar() = sempre se ref a cor
  Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

  // Desenha um círculo.
  // Point() Classe de modelo para pontos 2D especificados por suas coordenadas x e y.
  circle(img, Point(256, 256), 155, Scalar(0, 0, 255), FILLED);

  // Desenha um retângulo simples, espesso ou preenchido à direita.
  //                  x, y,width,height
  // rectangle(img, Rect(130, 226, 254, 62), Scalar(0, 0, 255), FILLED);

  // a - b
  // |   |
  // c - d
  //                   a    c           b    d
  rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);

  // Desenha um segmento de linha conectando dois pontos.
  line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 2);

  // Desenha uma string de texto.
  putText(img, "STOP", Point(178, 278), FONT_HERSHEY_DUPLEX, 2, Scalar(0, 0, 255), 2);

  imshow("Image", img);

  waitKey(0); // Aguardando ate pressionamento de tecla

  return 0;
}