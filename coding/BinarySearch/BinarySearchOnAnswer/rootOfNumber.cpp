#include <iostream>

using namespace std;

double root(double x, unsigned int n) 
{
  // your code goes here
  double start = 0;
  double end = x;

  while(end-start > 0.001){
    double mid = start + (end-start)/2;
    if(pow(mid, n) > x){
      end = mid;
    }else {
      start = mid;
    }
  }
  return start;
}

int main() {
  return 0;
}