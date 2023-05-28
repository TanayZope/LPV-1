#include<bits/stdc++.h>
#include<omp.h>
using namespace std;

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    
    for(int i=0; i<n-1; i++){
        #pragma omp parallel for
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>=arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


int main(){
    vector<int> arr = { 9, 1, 8, 2, 7, 3, 6, 4, 5, 0 };
    
    cout<<"original :"<<endl;
    for(int num:arr){
        cout<<num<<" ";
    }cout<<endl;
    
    double start = omp_get_wtime();
    
    bubbleSort(arr);
    
    double end = omp_get_wtime();
    double Time = (end-start)*1000.0;
    
    cout<<"sorted :"<<endl;
    for(int num:arr){
        cout<<num<<" ";
    }cout<<endl;
    
    cout<<"time taken :"<<Time<<" miliseconds";
    
    return 0;
}