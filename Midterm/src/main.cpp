#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "main.h"

//defined global variables

//defined structures

//functions
void post_vs_prefixed() {
    //prefix
    int x = 10;
    int y = ++x; //the value of x is incremented first before being assigned to Y in the expression (y=11, x=11)

    std::cout << "Prefix" << std::endl;
    std::cout << "value of x: " << x << " value of y after assigning it to ++x: " << y << std::endl;

    //postfix
    int a = 5;
    int b = a++; //assigns the value of a to b before incrementing b (b=5, a=6)

    std::cout << "Postfix" << std::endl;
    std::cout << "value of a: " << a << " value of b after assigning it to a++: " << b << std::endl;
}

int calc_rect_area_pbv(int len, int width) {
    if (len < 0 || width < 0) {
        return -1;
    }
    return len * width;
}

void calc_rect_area_pbr(int &len, int &width) {
    int newLen, newWidth;

    std::cout << "Enter new length: ";
    std::cin >> newLen;

    if (newLen < 0) {
        std::cout << "Warning: Negative length entered. Dimensions not updated.\n";
        return;
    }

    std::cout << "Enter new width: ";
    std::cin >> newWidth;

    if (newWidth < 0) {
        std::cout << "Warning: Negative width entered. Dimensions not updated.\n";
        return;
    }

    len = newLen;
    width = newWidth;

    
}

void update_rect_dimensions() {
    int length{0}, width{0};

    std::cout << "initial length of rectangle: ";
    std::cin >> length;

    std::cout << "initial width of rectangle: ";
    std::cin >> width;

    int area = calc_rect_area_pbv(length, width);
    std::cout << "area of rectangle: " << area << std::endl;

    calc_rect_area_pbr(length, width);

    area = calc_rect_area_pbv(length, width);
    std::cout << "updated area of rectangle: " << area << std::endl;
}

void pointer_arithmetic_example() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int *ptr = arr; //points to the address of the first element in arr arr[0] and *(ptr) are the same

    ptr = ptr + 2; //ptr now points to the 3rd element in arr. arr[2]

    ptr = ptr + 3; //ptr now points to the last element in arr.

    //prints out the array backwards
    for(int i = 0; i < (sizeof(arr)/sizeof(int)); i++){
        std::cout << *(ptr--) << " ";
    }
    std::cout << std::endl;


}

std::vector<int> merge_array(std::vector<int> &arr1, std::vector<int> &arr2) {
    std::vector<int> mergedArr;

    mergedArr.insert(mergedArr.end(), arr1.begin(), arr1.end());
    mergedArr.insert(mergedArr.end(), arr2.begin(), arr2.end());

   return mergedArr;
}

void fill_arr(int amount, std::vector<int> &arr)
{
    int count = 0;
    while(count < amount) {
        int item{0};
        std::cout << "enter an integer: ";
        std::cin >> item;
        arr.push_back(item);

        count++;
    }

}

void print_arr(const std::vector<int> & arr){

    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void merge_array_proc(){
    int arr1Size{0}, arr2Size{0};
    std::vector<int> arr1, arr2;

    std::cout << "Enter Size for Array 1: ";
    std::cin >> arr1Size;
    fill_arr(arr1Size, arr1);

    std::cout << "Enter Size for Array 2: ";
    std::cin >> arr2Size;
    fill_arr(arr2Size, arr2);

    std::vector<int> mergedArray = merge_array(arr1, arr2);
    std::cout << "Contents of Merged Array: ";
    print_arr(mergedArray);

}

//program entrypoint
int main() {
    //example code - Question 1
    post_vs_prefixed();

    //Question 2
    update_rect_dimensions();

    //examle code - Question 3
    pointer_arithmetic_example();

    //question 4
    merge_array_proc();

    return 0;
}