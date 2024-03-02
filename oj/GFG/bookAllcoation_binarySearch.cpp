#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/studio/problems/ayush-and-ninja-test_1097574?source=youtube&campaign=love_babbar_codestudio2&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio2
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/

bool  isValidSolution(const vector<int>& pages, int students, int currMid){
    int studentID = 1;
    int pageSum = 0;
    for(int iter=0; iter <pages.size(); iter++){
        // If last books sum including current page sum is less than currMid, add that book for the current student.
        if(pageSum + pages[iter] <= currMid) pageSum += pages[iter];
        else{
            // allocate the current book for a new student and check boundary conditions.
            studentID++;
            pageSum = pages[iter]; // Reset pageSum to hold the current books page count.

            // While allocating books for all students if number of students become more than given count, we have under-allocated the currMid.
            // If one book's page count is greater that the page count of all prior books, then currMid is under-allocated.
            if(studentID > students || pageSum >= currMid) return false;
        }
    }
    return true;
}


int solve(const vector<int>& pages, int students){
    int ans = -1;
    if(pages.size() < students) return ans;

    //determine the search space
    int totalPages =0, maxPage=INT_MIN;
    for(auto page:pages){
        totalPages += page;
        page > maxPage ? maxPage = page :1;
    }

    // solution can range between 0 (when #students > #books ) to totalPages (when #students = 1, ans = sum of all pages)
    // We will use binary search in this search space to find our solution.
    int lo, hi, mid;
    lo = maxPage;
    hi = totalPages;

    while(hi >= lo){
        mid = lo + (hi-lo)/2;

        if( isValidSolution(pages, students, mid)){
            ans = mid;
            hi = mid -1; // go to left as we want to find the minimum number of pages for the solution.
        }
        else lo = mid +1; // Not a valid solution so increase the mid  
    }
    return ans;
}


int main(){
    vector<int> pageList {10,20,30,40};
    int students = 1;
    cout << "Maximum number of pages assigned to a student is minimum: " << solve(pageList, students) << endl;



}