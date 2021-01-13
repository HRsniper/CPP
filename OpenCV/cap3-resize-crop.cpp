#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  string image_path = "testopencvimage.bmp";
  Mat    img        = imread(image_path);

  Mat imgResize, imgResize_D, imgCrop;

  // Redimensiona uma imagem. com uma escala definida
  resize(img, imgResize, Size(500, 300));

  // Redimensiona uma imagem. com uma escala dinâmica
  resize(img, imgResize_D, Size(), 0.5, 0.5);

  // Crop images
  Rect roi(1, 1, 130, 100);
  imgCrop = img(roi);

  cout << "Original: " << img.size() << endl;
  cout << "Resize: " << imgResize.size() << endl;
  cout << "Resize Dynamic: " << imgResize_D.size() << endl;
  cout << "Crop: " << imgCrop.size() << endl;

  imshow("Image", img);
  imshow("Image Resize", imgResize);
  imshow("Image Resize Dynamic", imgResize_D);
  imshow("Image Crop", imgCrop);

  waitKey(0); // Aguardando ate pressionamento de tecla

  return 0;
}
