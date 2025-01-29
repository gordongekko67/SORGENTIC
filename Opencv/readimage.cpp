#include <opencv2/opencv.hpp>
#include <iostream>

//namespace per utilizzare tutte le funzioni di OpenCV
using namespace cv;
using namespace std;


int main(int argc, char **argv)
{
  //Apriamo l'immagire utilizzando imread()
  //Mat corrisponde alla matrice di pixel che forma l'immagine
  Mat immagineOriginale = imread(argv[1]);

  //Attraverso l'attributo data andiamo a verificare se l'immagine
  //è stata aperta correttamente
  if(immagineOriginale.data == NULL)
  {
    cerr << "Error open image" << endl;
    return(-1);
  }

  //namedWindow() costruisce la finestra dove poi imshow()
  //mostrerà l'immagine
  namedWindow("Immagine Originale", CV_WINDOW_AUTOSIZE);
  imshow("Immagine Originale", immagineOriginale);

  //Supponiamo che si voglia fare un resize dell'Immagine
  //Andiamo ad utilizzare la funzione resize()

  //Cloniamo prima l'immagine originale in un'altra matrice
  Mat immagineResize = immagineOriginale.clone();
  resize(immagineResize, immagineOriginale, Size(640, 480));

  namedWindow("Immagine Resize", CV_WINDOW_AUTOSIZE);
  imshow("Immagine Resize", immagineOriginale);

  //Supponiamo di voler ottenere le dimensioni dell'immagine
  //Gli attributi rows e cols ci permettono di conoscere
  //il numero di righe e il numero di colonne dell'immagine
  cout << "Numero di righe dell'immagine: " << immagineOriginale.rows << endl;
  cout << "Numero di colonne dell'immagine: " << immagineOriginale.cols << endl;

  //Supponiamo di voler convertire l'immagine da RGB a Scala di Grigi
  //Usiamo la funzione cvtColor()

  Mat immagineGray = immagineOriginale.clone();
  cvtColor(immagineGray, immagineGray, CV_BGR2GRAY);

  namedWindow("Immagine Gray", CV_WINDOW_AUTOSIZE);
  imshow("Immagine Gray", immagineGray);

  waitKey(0);
  return(0);
}







