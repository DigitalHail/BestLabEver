#include <iostream>
#include "StringData.h"
int linear_search(std::vector<std::string>& container, std::string element) {
    for (int count = 0; count < container.size(); count++) {
        if (container[count] == element) {
                return count;
        }
    }
    return -1;
}
int binary_search(std::vector<std::string>& container,std::string element) {
    //max pointer
    int max_count = container.size()-1;
    //min pointer
    int minima=0;
    //loop to check all cases until minima = maxima
    while ( minima<=max_count) {
        //sets midpoint between the two bounds dudeeeeeeee
        int mid_index= int((minima+max_count)/2);
        // check for target equating to element selected
        if (container[mid_index] == element) {
            return mid_index;
        }
        // checks if greater than
        if (container[mid_index] < element) {
            // raises lower bound
            minima = mid_index+1;
        }
        // checks if less than
        else if (container[mid_index] > element) {
            // lower maximum bound
            max_count = mid_index-1;
        }
    }
    // what to return if the target is not in the container
    return -1;
}
int main() {
    //creates the container
    std::vector<std::string> string_data = getStringData();
    long long start;
    long long end;
    int index;
    //implements and prints time of all methods
    start = systemTimeNanoseconds();
    index = linear_search(string_data, "not_here");
    end = systemTimeNanoseconds();
    std::cout <<"linear search result for (not_here):"<< index<< " time: "<< end - start<<std::endl;
    start = systemTimeNanoseconds();
    index = binary_search(string_data, "not_here");
    end = systemTimeNanoseconds();
    std::cout <<"binary search result for (not_here):"<< index<< " time: "<< end - start<<std::endl;
    start = systemTimeNanoseconds();
    index = linear_search(string_data, "mzzzz");
     end = systemTimeNanoseconds();
    std::cout <<"linear search result for (mzzzz):"<< index<< " time: "<< end - start<<std::endl;
    start = systemTimeNanoseconds();
     index = binary_search(string_data,"mzzzz");
    end = systemTimeNanoseconds();
    std::cout <<"binary search result for (mzzzz):"<< index<< " time: "<< end - start<<std::endl;
    start = systemTimeNanoseconds();
     index = linear_search(string_data, "aaaaa");
    end = systemTimeNanoseconds();
    std::cout <<"linear search result for (aaaaa):"<< index<< " time: "<< end - start<<std::endl;
    start = systemTimeNanoseconds();
    index = binary_search(string_data, "aaaaa");
    end = systemTimeNanoseconds();
    std::cout<<"Binary search result for (aaaaa):"<< index<< " time: "<< end - start<< "  merge conflict destroyer" <<std::endl;
    return 0;
}

