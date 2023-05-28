#include<iostream>
#include<omp.h>
#include<vector>

using namespace std;

int main(){
    int n = 0;
    cout<<"Enter the number of elements :"<<endl;
    cin>>n;
    vector<int> numbers(n);
    cout<<"enter the elements :"<<endl;
    for(int i=0; i<n; i++){
        cin>>numbers[i];   
    }
    
    int min_val = numbers[0];
    int max_val = numbers[0];
    double sum = 0;
    
    double start= omp_get_wtime();
    
    #pragma omp parallel for reduction(min: min_val) reduction(max: max_val) reduction(+: sum)
    for(int i=0; i<n; i++){
        min_val = min(min_val, numbers[i]);
        max_val = max(max_val, numbers[i]);
        sum+=numbers[i];
    }

    double average = (sum) / n;

    double end= omp_get_wtime();
    
    double Time = (end-start)*1000.0;

    cout << "Minimum value: " << min_val << endl;
    cout << "Maximum value: " << max_val << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << average << endl;
    cout<<" time taken: "<<Time<<" miliseconds";

    return 0;
}