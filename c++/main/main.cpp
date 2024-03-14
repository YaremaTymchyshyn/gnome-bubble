#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
using namespace std;

// function that implements the gnome sort algorithm
vector<int> gnome_sort(vector<int> arr)
{
    int n = arr.size();
    int index = 0;
    while (index < n) {
        if (index == 0){
            index++;
        }
        if (arr[index] >= arr[index - 1]){
            index++;
        }
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return arr;
}

// function that implements the bubble sort algorithm
void bubble_sort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped){
            break;
        }
    }
}

// function that implements the built-in sort method
vector<int> built_in_sort(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    return arr;
}



// utility function that generates an array of random numbers
vector<int> generate_random_array(int n, int min_value, int max_value)
{
    vector<int> random_array;
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        random_array.push_back(rand() % (max_value - min_value + 1) + min_value);
    }
    return random_array;
}

// utility function that generates an aleady sorted array of random numbers
vector<int> generate_random_sorted_array(int n, int min_value, int max_value)
{
    vector<int> random_array;
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        random_array.push_back(rand() % (max_value - min_value + 1) + min_value);
    }
    sort(random_array.begin(), random_array.end());
    return random_array;
}

// utility function that generates an aleady sorted reversed array of random numbers
vector<int> generate_random_reversed_array(int n, int min_value, int max_value)
{
    vector<int> random_array;
    srand(time(nullptr));
    for (int i = 0; i < n; i++)
    {
        random_array.push_back(rand() % (max_value - min_value + 1) + min_value);
    }
    sort(random_array.rbegin(), random_array.rend());
    return random_array;
}

// utility function that prints an array
vector<int> print_array(vector<int> arr)
{
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";
    return arr;
}

// utility function that generates an array of arrays of random numbers
vector<vector<int>> create_sorted_arrays(int n, int min_value, int max_value, int array_size)
{
    vector<vector<int>> result(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> new_array(array_size);
        for (int j = 0; j < array_size; j++)
        {
            new_array[j] = rand() % (max_value - min_value + 1) + min_value;
        }
        sort(new_array.begin(), new_array.end());
        result[i] = new_array;
    }
    return result;
}

// utility function that creates a concat array
vector<int> create_concat_arrays(vector<vector<int>> arr)
{
    vector<int> concat_array;
    for (vector<int>& array : arr)
    {
        for (int element : array)
        {
            concat_array.push_back(element);
        }
    }
    return concat_array;
}

// utility function that swaps two random elements of an array
vector<int> random_swap_sorted_array(vector<int> arr, int n)
{
    srand(time(nullptr)); // Seed the random number generator
    for (int i = 0; i < n; i++)
    {
        int idx1 = rand() % arr.size();
        int idx2 = rand() % arr.size();
        swap(arr[idx1], arr[idx2]);
    }
    return arr;
}



// function that calls one of the three sort methods for array
vector<int> sort_array(vector<int> arr)
{
    //return built_in_sort(arr);

    //return gnome_sort(arr);

    bubble_sort(arr);
    return arr;
}

// function that calls one of the three sort methods for array of arrays
vector<int> sort_sorted_arrays(vector<vector<int>> arr)
{
    vector<int> concat_array = create_concat_arrays(arr);

    //return built_in_sort(concat_array);

    //return gnome_sort(concat_array);

    bubble_sort(concat_array);
    return concat_array;
}



// array filled with random numbers
int random_arr()
{
    vector<int> arr1 = generate_random_array(100, 0, 9);
    print_array(arr1);
    clock_t start_time_n = clock();
    vector<int> sorted_arr1 = sort_array(arr1);
    cout << double(clock() - start_time_n) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr1);
    cout << endl;

    vector<int> arr2 = generate_random_array(10000, 0, 9);
    print_array(arr2);
    clock_t start_time_m = clock();
    vector<int> sorted_arr2 = sort_array(arr2);
    cout << double(clock() - start_time_m) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr2);
    return 0;
}

// array divided into several sorted sub-arrays
int divided_arr()
{
    vector<vector<int>> arr1 = create_sorted_arrays(10, 0, 9, 10);
    cout << "[";
    for (vector<int>& array : arr1) 
    {
        cout << "[";
        for (int element : array)
        {
            cout << element << " ";
        }
        cout << "]";
    }
    cout << "]\n";
    clock_t start_time_n = clock();
    vector<int> sorted_arr1 = sort_sorted_arrays(arr1);
    cout << double(clock() - start_time_n) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr1);
    cout << endl;

    vector<vector<int>> arr2 = create_sorted_arrays(100, 0, 9, 100);
    cout << "[";
    for (vector<int>& array : arr2)
    {
        cout << "[";
        for (int element : array)
        {
            cout << element << " ";
        }
        cout << "]";
    }
    cout << "]\n";
    clock_t start_time_m = clock();
    vector<int> sorted_arr2 = sort_sorted_arrays(arr2);
    cout << double(clock() - start_time_m) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr2);
    return 0;
}

// sorted array with swapped elements
int swapped_arr()
{
    vector<int> arr1 = random_swap_sorted_array(generate_random_sorted_array(100, 0, 9), 50);
    print_array(arr1);
    clock_t start_time_n = clock();
    vector<int> sorted_arr1 = sort_array(arr1);
    cout << double(clock() - start_time_n) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr1);
    cout << endl;

    vector<int> arr2 = random_swap_sorted_array(generate_random_array(10000, 0, 9), 5000);
    print_array(arr2);
    clock_t start_time_m = clock();
    vector<int> sorted_arr2 = sort_array(arr2);
    cout << double(clock() - start_time_m) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr2);
    return 0;
}

// array sorted in ascending order
int sorted_arr()
{
    vector<int> arr1 = generate_random_sorted_array(100, 0, 9);
    print_array(arr1);
    clock_t start_time_n = clock();
    vector<int> sorted_arr1 = sort_array(arr1);
    cout << double(clock() - start_time_n) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr1);
    cout << endl;

    vector<int> arr2 = generate_random_sorted_array(10000, 0, 9);
    print_array(arr2);
    clock_t start_time_m = clock();
    vector<int> sorted_arr2 = sort_array(arr2);
    cout << double(clock() - start_time_m) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr2);
    return 0;
}

// array sorted in descending order
int reversed_arr()
{
    vector<int> arr1 = generate_random_reversed_array(100, 0, 9);
    print_array(arr1);
    clock_t start_time_n = clock();
    vector<int> sorted_arr1 = sort_array(arr1);
    cout << double(clock() - start_time_n) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr1);
    cout << endl;

    vector<int> arr2 = generate_random_reversed_array(10000, 0, 9);
    print_array(arr2);
    clock_t start_time_m = clock();
    vector<int> sorted_arr2 = sort_array(arr2);
    cout << double(clock() - start_time_m) / CLOCKS_PER_SEC << '\n';
    print_array(sorted_arr2);
    return 0;
}



int main()
{
    //random_arr();
    //divided_arr();
    //swapped_arr();
    //sorted_arr();
    reversed_arr();
    return 0;
}