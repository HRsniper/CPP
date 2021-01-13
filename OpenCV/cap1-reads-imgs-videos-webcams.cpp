#include <iostream>
#include <string>

#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  // image
  string image_path = "testopencvimage.bmp";
  Mat    img        = imread(image_path);
  imshow("Aperte qualquer tecla para fechar", img);
  waitKey(0); // Aguardando ate pressionamento de tecla

  // video
  string       video_path = "testopencvvideo.mp4";
  VideoCapture video(video_path);
  Mat          imgs;

  while (true) {
    video.read(imgs);
    imshow("Aperte qualquer tecla para fechar", imgs);
    waitKey(1); // Aguardando 1ms entre as images
  }

  // webcam
  int camera_id = 0;
  VideoCapture webcam(camera_id);
  Mat          imgs_cam;

  while (true) {
    webcam.read(imgs_cam);
    imshow("Aperte qualquer tecla para fechar", imgs_cam);
    waitKey(1); // Aguardando 1ms entre as images
  }

  return 0;
}
