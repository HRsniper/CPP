#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

float width = 250, height = 350;
Mat   imgWarp_K, imgWarp_Q, imgWarp_J, imgWarp_9;
Mat   matrix_K, matrix_Q, matrix_J, matrix_9;

int main(int argc, char const *argv[]) {
  string image_path = "testopencvcards.jpg";

  Mat img = imread(image_path);

  if (img.empty()) {
    cout << "Não foi possível ler a imagem: " << image_path << endl;
    return 1;
  }

  //                         top-left      top-right     botton-left   botton-right
  Point2f src_K[4]       = { { 529, 142 }, { 771, 190 }, { 405, 395 }, { 674, 457 } };
  Point2f destination[4] = { { 0.0f, 0.0f }, { width, 0.0f }, { 0.0f, height }, { width, height } };

  // Calcula uma transformação de perspectiva de quatro pares de pontos correspondentes.
  matrix_K = getPerspectiveTransform(src_K, destination);

  // Aplica uma transformação de perspectiva a uma imagem.
  warpPerspective(img, imgWarp_K, matrix_K, Size(width, height));
  // mesmo saida
  // warpPerspective(img, imgWarp, matrix, Point(width, height));

  // capturando o restantes das cartas
  Point2f src_Q[4] = { { 67, 334 }, { 339, 279 }, { 92, 637 }, { 401, 573 } };
  matrix_Q         = getPerspectiveTransform(src_Q, destination);
  warpPerspective(img, imgWarp_Q, matrix_Q, Size(width, height));

  Point2f src_J[4] = { { 779, 112 }, { 1017, 85 }, { 847, 360 }, { 1114, 328 } };
  matrix_J         = getPerspectiveTransform(src_J, destination);
  warpPerspective(img, imgWarp_J, matrix_J, Size(width, height));

  Point2f src_9[4] = { { 744, 390 }, { 1026, 442 }, { 650, 712 }, { 965, 783 } };
  matrix_9         = getPerspectiveTransform(src_9, destination);
  warpPerspective(img, imgWarp_9, matrix_9, Size(width, height));
  ///////////////

  // desenhado círculos nas pontas da carta
  for (size_t i = 0; i < 4; i++) {
    circle(img, src_K[i], 10, Scalar(0, 0, 255), FILLED);

    circle(img, src_Q[i], 10, Scalar(0, 0, 255), FILLED);
    circle(img, src_J[i], 10, Scalar(0, 0, 255), FILLED);
    circle(img, src_9[i], 10, Scalar(0, 0, 255), FILLED);
  }

  imshow("Image", img);
  imshow("Image Warp K", imgWarp_K);

  imshow("Image Warp Q", imgWarp_Q);
  imshow("Image Warp J", imgWarp_J);
  imshow("Image Warp 9", imgWarp_9);

  waitKey(0); // Aguardando ate pressionamento de tecla

  return 0;
}