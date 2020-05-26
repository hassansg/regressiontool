/*This is a general linear regression model used to find regression and correlation coefficients between data sets and/or variables.
The variables used here in the code may be changed however you like for your own use. I will be using a statistical
method known as the Pearson method. The value obtained from that is known as the correlation coefficient. The Pearson method
will be used in this case since it is based on rank relationships and does not need as much rigorous analysis. It is also the most
common method of measuring correlation.*/
//------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <math.h>
#include <array>
//------------------------------------------------------------------------------------------------------------------------
#define     TRUE    1
#define     FALSE   0
//------------------------------------------------------------------------------------------------------------------------
float gradient_regression(const std::vector<float>& x, const std::vector<float>& y);
float gradient_correlation(std::vector<float>& x, std::vector<float>& y, int z);
//------------------------------------------------------------------------------------------------------------------------
int main(void){

    //variable declaration code block
    std::vector<float> A;
    std::vector<float> B;
    int input1;
    int input2;
    int input_number;
    int counter2 = 0;
    int counter1 = 0;
    int vector_size = A.size();
    //this will ask the user for the number of inputs they have to limit the loop
    std::cout << "Enter the number of inputs you will set.(i.e. 1,2,3 is 3 inputs, so enter 3)\n";
    std::cin >> input_number;

    //this takes the input from the user and pushes it to our first vector, A
    std::cout << "\nInput the first set of data:\n";
    std::cout << "(Make sure the size of the first vector and the second vector are equal)\n";
    while (std::cin >> input1){
        A.push_back(input1); 
        counter2++;
        if (counter2 == input_number){
            break;}}

    //this takes the input from the user and pushes it to our second vector, B
    std::cout << "\nInput the second set of data:\n";
    while (std::cin >> input2){
        B.push_back(input2); 
        counter1++;
        if (counter1 == input_number){
            break;}}

    //This here will print out the regression coefficient and gives the user their overall result
    std::cout << "\nREGRESSION = ";
        std::cout << gradient_regression(A,B) << "\n";
        if (gradient_regression(A,B) == 1)
            std::cout << "\nAbsolute Positive Regression.\n";
        else if (gradient_regression(A,B) > 0 && gradient_regression(A,B) < 1)
            std::cout << "\nPositive Regression.\n";
        else if (gradient_regression(A,B) < 0)
            std::cout << "\nNegative Regression.\n";
        else if (gradient_regression(A,B) == 0){
            std::cout << "\nNo Regression.\n"; } //ANALYSIS OF OUTPUT REVIEW

    //This will print the correlation coefficient and gives the user their overall result
            std::cout << "\nCORRELATION = ";
        std::cout << gradient_correlation(A,B,vector_size) << "\n";
        if (gradient_correlation(A,B,vector_size) == TRUE)
            std::cout << "\nAbsolute Positive Correlation.\n";
        else if (gradient_correlation(A,B,vector_size) > FALSE && gradient_correlation(A,B,vector_size) < TRUE)
            std::cout << "\nPositive Correlation.\n";
        else if (gradient_correlation(A,B,vector_size) < FALSE && gradient_correlation(A,B,vector_size) > -0.5)
            std::cout << "\nNegative Correlation.\n";
        else {
            std::cout << "\nNo Correlation.\n"; }

    return 0;
}
//------------------------------------------------------------------------------------------------------------------------
float gradient_regression(const std::vector<float>& x, const std::vector<float>& y){
    //two variables for the argument are (x,y). Same shceme for a 2D cartesian plane
    if(x.size() != y.size())
        std::cout << "\nMake sure the vectors have the same number of values for the regression function!\n";
        return 1;
    //we need to make sure that there is the same number coordinant pairs
     float  c    = x.size();
     float  M_x  = std::accumulate(x.begin(), x.end(), 0.0);
     float  M_y  = std::accumulate(y.begin(), y.end(), 0.0);
     float  M_xy = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
     float  M_xx = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
     float X    = (c * M_xy - M_x * M_y) / (c * M_xx - M_x * M_x);
    return X; }
//This function shows the regression coefficient between two sets of values in vector spaces (R^2)
//------------------------------------------------------------------------------------------------------------------------
double gradient_correlation(std::vector<float>& x, std::vector<float>& y, int vector_size)
{
    if(x.size() != y.size())
        std::cout << "\nMake sure the vectors have the same number of values for the correlation function!\n";
        return 1;
 
    int sum_x = 0;
    int sum_y = 0;
    int sum_xy = 0;
    int sum_x_squared = 0;
    int sum_y_squared = 0;
 
    for (int i = 0; i < vector_size; i++)
    {   sum_x= sum_x + x[i];
        sum_y = sum_y + y[i];
        sum_xy = sum_xy + x[i] * y[i];
        sum_x_squared = sum_x_squared + x[i] * x[i];
        sum_y_squared= sum_y_squared + y[i] * y[i]; 
    }
 
    // use formula for calculating pearson correlation coefficient
   double coefficient = (z * sum_xy - sum_x * sum_y) / sqrt(z * sum_x_squared - sum_x * sum_x)* sqrt(z * sum_y_squared- sum_y * sum_y);
 
    return coefficient; 
}
//This function finds the Pearson coefficient of correlation between two sets of values in vector space