#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Crea una matrice di 400x400 di colore nero
    cv::Mat image = cv::Mat::zeros(400, 400, CV_8UC3);
    
    // Disegna un cerchio bianco al centro
    cv::circle(image, cv::Point(200, 200), 100, cv::Scalar(255, 255, 255), -1);

    // Mostra l'immagine
    cv::imshow("Test OpenCV", image);

    // Aspetta che un tasto venga premuto
    cv::waitKey(0);
    
    return 0;
}
