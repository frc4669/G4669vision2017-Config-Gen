/**
* Galileo Robotics Computer Vision Config Generator
* @author  Kenny Ngo
* @date    3/16/2017
* @version 2.0
*/

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
using namespace cv;
using namespace std;

//Prototypes
void writeGlobalVar();
void loadGlobalVar();

//Global Variables
VideoCapture cap;

//int exposure = 0;

int minH = 0;
int minS = 0;
int minV = 0;

int maxH = 179;
int maxS = 255;
int maxV = 255;

int cannyThresh = 450;
int thresholdThresh = 450; //Not sure if this should be the same var as cannyThresh
int cornerThresh = 235;

int blockSize = 2;
int apertureSize = 3;
double k = 0.04;

int contour_length_threshold = 40;

Mat src, blurred, blurredHSV, filtered, filteredGray, canny, threshold_output, scaled, contGray;
Mat tempProcessed, contDrawing, cornerDrawing, normal, normScaled;

vector<vector<Point> > contours;
vector<Vec4i> hierarchy;


int main()
{
    cout << "VISION CORE: INITIALIZED\n";

    if(!cap.open(0))
    {
        cout << "VISION ERROR: CANNOT ACCESS CAMERA\n" << "VISION CORE: STOPPED\n";

        return 0;
    }

    //cap.set(CV_CAP_PROP_BUFFERSIZE, 1);

    loadGlobalVar();

    namedWindow("Source", 1);
    namedWindow("Color Filtered", 1);
    namedWindow("Contour", 1);
    namedWindow("Drawing", 1);

    createTrackbar("Min H", "Color Filtered", &minH, 179);
    createTrackbar("Max H", "Color Filtered", &maxH, 179);
    
    createTrackbar("Min S", "Color Filtered", &minS, 255);
    createTrackbar("Max S", "Color Filtered", &maxS, 255);

    createTrackbar("Min V", "Color Filtered", &minV, 255);
    createTrackbar("Max V", "Color Filtered", &maxV, 255);

    createTrackbar("Contour Thresh", "Contour", &cannyThresh, 500);
    createTrackbar("Threshold Thresh", "Contour", &cannyThresh, 500);
    createTrackbar("Contour length", "Contour", &contour_length_threshold , 1000);

    createTrackbar("Corner Thresh", "Drawing", &cornerThresh, 500);

    //createTrackbar("Exposure", "Source", &exposure, 100);

    while (1)
    {
        //cap.set(CV_CAP_PROP_EXPOSURE, exposure - 100);

        if( waitKey(1) == 27 )
            break;

        //src = cap.grab();
        //cap >> src; //**********************CHANGE LATER
        src = imread("4.png", 1);

        //Checks if frame is empty
        if (src.empty())
        {
            cout << "VISION ERROR: CANNOT ACCESS FRAME\n" << "VISION CORE: STOPPED\n";
            return 0;
        }

        //Blur
        GaussianBlur(src, blurred, Size(15,15), 0, 0);

        //Filter Color
        assert(blurred.type() == CV_8UC3);
        cvtColor(blurred, blurredHSV, CV_BGR2HSV);
        inRange(blurredHSV, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), tempProcessed);


        bitwise_and(blurred, blurred, filtered, tempProcessed = tempProcessed);

        imshow("Color Filtered", filtered);

        cvtColor(filtered, filtered, CV_HSV2BGR);
        cvtColor(filtered, filtered, CV_BGR2GRAY);

        //Contour
        contDrawing = Mat::zeros(src.rows, src.cols, CV_8UC3);

        Canny(filtered, canny, cannyThresh, cannyThresh*2, 3);
        findContours( canny, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );
        threshold(filtered, threshold_output, thresholdThresh, 255, THRESH_BINARY);

        //Bounding Rectangle
        vector<vector<Point> > contours_poly(contours.size());
        vector<Rect> boundRect(contours.size());

        //Filter out small countour
        for(vector<vector<Point> >::iterator it = contours.begin(); it!=contours.end();)
        {
            if (it->size()<contour_length_threshold)
                it = contours.erase(it);
            else
                ++it;
        }


        //Draw contour
        for(size_t i = 0; i < contours.size(); i++)
        {
            approxPolyDP( Mat(contours[i]), contours_poly[i], 3, true );
            boundRect[i] = boundingRect( Mat(contours_poly[i]) );
        }

        for(size_t i = 0; i< contours.size(); i++)
        {
            Scalar color = Scalar( 0, 255, 0 );
            rectangle( contDrawing, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );
        }

//Add to other program later
        //for(size_t i = 0; i < contours.size(); i++)
        //{
            

        //Corner Detection
        cvtColor(contDrawing, contGray, CV_RGB2GRAY);

        cornerDrawing = Mat::zeros( contDrawing.size(), CV_32FC1 );

        cornerHarris( contGray, cornerDrawing, blockSize, apertureSize, k, BORDER_DEFAULT );
        normalize(cornerDrawing, normal, 0, 255, NORM_MINMAX, CV_32FC1, Mat() );
        //convertScaleAbs(normal, normScaled);
        int maxX = -1;
        int minX = 10000;
        int centerX = 0;
        int width = 0;
        
        for (int y = 0; y < normal.rows; y++)
        {
            for (int x = 0; x < normal.cols; x++)
            {
                if ((int) normal.at<float>(y,x) > cornerThresh)
                {
                    circle(normal, Point(x,y), 5, Scalar(0), 2, 8, 0);
                    cout << x << " " << y << endl;
                    if (x > maxX)
                        maxX = x;
                    if (x < minX)
                        minX = x;
                }
            }
        }

        centerX = (maxX + minX) / 2;
        width = maxX - minX;
        cout << centerX << " " << width << endl;
        cout << "MAX: " << maxX << " MIN: " << minX << endl;
        cout << "Contours: " << contours.size() << endl;

        imshow("Source", src);
        imshow("Contour", contDrawing);
        imshow("Drawing", normal); //Keep uncommented in development to avoid videoio error
    }
       
    string input = "x";
    while (input != "y", input != "n")
    {
        cout << "Save configuration? y n\n>> ";
        cin >> input;
        if (input == "y")
        {
            writeGlobalVar();
            break; 
        }
        else if (input == "n")
            break;
    }


    cout << "VISION CORE: STOPPED\n";

    return 0;
}

void writeGlobalVar()
{
    string conf_file;
    ofstream config;

    cout << "VISION CORE: WHAT TO WRITE TO?\n>> ";
    cin >> conf_file;

    config.open(conf_file.c_str());

        cout << "VISION CORE: VARIABLE PRESET LOADING STARTED\n";

        config << minH << endl;
        config << maxH << endl;
        config << minS << endl;
        config << maxS << endl;
        config << minV << endl;
        config << maxV << endl;
        config << cannyThresh << endl;
        config << thresholdThresh << endl;
        config << cornerThresh << endl;
        config << contour_length_threshold;


        cout << "VISION CORE: VARIABLE PRESET LOADING SUCCESSFUL\n";

        config.close();

}

void loadGlobalVar()
{
    ifstream config;
    string load;

    cout << "VISION CORE: Load Previous File? *Type ""n"" to skip\n>> "; 
    cin >> load;

    if ( load == "n")
        exit;

    config.open(load.c_str());

    if (config)
    {
        cout << "VISION CORE: VARIABLE PRESET LOADING STARTED\n";

        config >> minH;
        config >> maxH;
        config >> minS;
        config >> maxS;
        config >> minV;
        config >> maxV;
        config >> cannyThresh;
        config >> thresholdThresh;
        config >> cornerThresh;
        config >> contour_length_threshold;

        cout << "VISION CORE: VARIABLE PRESET LOADING SUCCESSFUL\n";

        config.close();
    }
    else
        cout << "VISION ERROR: CANNOT ACCESS PRE-SET VARIABLE, VARIABLES SET TO DEFAULT VALUES\n"; 

}
