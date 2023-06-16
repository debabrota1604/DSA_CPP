#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
void show(int a[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        cout << a[i] << " ";
}

int main(){
    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
   
    // size of the array
    int asize = sizeof(a) / sizeof(a[0]);
    cout << "The array before sorting is : \n";
   
    // print the array
    show(a, asize);
 
      // sort the array
    sort(a, a + asize);
 
    cout << "\n\nThe array after sorting is :\n";
   
    // print the array after sorting
    show(a, asize);

    cout << endl;



    // Initializing vector with array values
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect(arr, arr+n);
 
    cout << "Vector is :";
    for (int i=0; i<vect.size(); i++)
        cout << vect[i]<<" ";
 
    // Delete second element of vector
    vect.erase(vect.begin()+1);
 
    cout << "\nVector after erasing the element: ";
    for (int i=0; i<vect.size(); i++)
        cout << vect[i] << " ";
 
    // sorting to enable use of unique()
    sort(vect.begin(), vect.end());
 
    cout << "\nVector before removing duplicate: ";
    for (int i=0; i<vect.size(); i++)
        cout << vect[i] << " ";
 
    // Deletes the duplicate occurrences
    vect.erase(unique(vect.begin(),vect.end()),vect.end());
 
    cout << "\nVector after deleting duplicates: ";
    for (int i=0; i< vect.size(); i++)
        cout << vect[i] << " ";

    
    // Initializing vector with array values
    int arr2[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n2 = sizeof(arr)/sizeof(arr[0]);
    vector<int> vect2(arr2, arr2+n);
 
    cout << "\nGiven Vector is:\n";
    for (int i=0; i<n2; i++)
        cout << vect2[i] << " ";
 
    // modifies vector to its next permutation order
    next_permutation(vect2.begin(), vect2.end());
    cout << "\nVector after performing next permutation:\n";
    for (int i=0; i<n2; i++)
        cout << vect2[i] << " ";
 
    prev_permutation(vect2.begin(), vect2.end());
    cout << "\nVector after performing prev permutation:\n";
    for (int i=0; i<n2; i++)
        cout << vect2[i] << " ";

    int ar[6] =  {1, 2, 3, 4, 5, -6};
    // Checking if all elements are positive
    all_of(ar, ar+6, [](int x) { return x>0; })?
          cout << "All are positive elements" :
          cout << "All are not positive elements";
 
    return 0;
}