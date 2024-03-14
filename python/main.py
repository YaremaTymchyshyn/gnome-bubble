import random
import time
import array


# function that implements the gnome sort algorithm
def gnome_sort(arr):
    n = len(arr)
    index = 0
    while index < n:
        if index == 0:
            index = index + 1
        if arr[index] >= arr[index - 1]:
            index = index + 1
        else:
            arr[index], arr[index - 1] = arr[index - 1], arr[index]
            index = index - 1
    return arr


# function that implements the bubble sort algorithm
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break


# function that implements the built-in sort method
def built_in_sort(arr):
    arr.sort()
    return arr


# array filled with random numbers
def random_arr():
    def generate_random_array(n, min_value, max_value):
        random_array = []
        for i in range(n):
            random_array.append(random.randint(min_value, max_value))
        return array.array('i', random_array)

    def sort_array(arr):
        #built_in_sort(arr)
        #gnome_sort(arr)
        bubble_sort(arr)
        return arr

    arr1 = generate_random_array(100, 0, 9)
    print(arr1)
    start_time_n = time.time()
    sorted_arr1 = sort_array(arr1)
    print(time.time() - start_time_n)
    print(sorted_arr1)

    arr2 = generate_random_array(10000, 0, 9)
    print(arr2)
    start_time_m = time.time()
    sorted_arr2 = sort_array(arr2)
    print(time.time() - start_time_m)
    print(sorted_arr2)


# array divided into several sorted sub-arrays
def divided_arr():
    def create_sorted_arrays(n, min_value, max_value, array_size):
        result = []
        for i in range(n):
            new_array = sorted([random.randint(min_value, max_value) for j in range(array_size)])
            result.append(new_array)
        return result

    def create_concat_arrays(arr):
        concat_array = []
        for array in arr:
            for element in array:
                concat_array.append(element)
        return concat_array

    def sort_sorted_arrays(arr):
        concat_array = create_concat_arrays(arr)
        #built_in_sort(concat_array)
        #gnome_sort(concat_array)
        bubble_sort(concat_array)
        return concat_array

    arr1 = create_sorted_arrays(10, 0, 9, 10)
    print(arr1)
    start_time_n = time.time()
    sorted_arr1 = sort_sorted_arrays(arr1)
    print(time.time() - start_time_n)
    print(sorted_arr1)

    arr2 = create_sorted_arrays(100, 0, 9, 100)
    print(arr2)
    start_time_m = time.time()
    sorted_arr2 = sort_sorted_arrays(arr2)
    print(time.time() - start_time_m)
    print(sorted_arr2)


# sorted array with swapped elements
def swapped_arr():
    def generate_random_sorted_array(n, min_value, max_value):
        random_array = []
        for i in range(n):
            random_array.append(random.randint(min_value, max_value))
        return sorted(random_array)

    def random_swap_sorted_array(arr, n):
        for i in range(n):
            idx1 = random.randint(0, len(arr) - 1)
            idx2 = random.randint(0, len(arr) - 1)
            arr[idx1], arr[idx2] = arr[idx2], arr[idx1]
        return arr

    def sort_array(arr):
        #built_in_sort(arr)
        #gnome_sort(arr)
        bubble_sort(arr)
        return arr

    arr1 = random_swap_sorted_array(generate_random_sorted_array(100, 0, 9), 50)
    print(arr1)
    start_time_n = time.time()
    sorted_arr1 = sort_array(arr1)
    print(time.time() - start_time_n)
    print(sorted_arr1)

    arr2 = random_swap_sorted_array(generate_random_sorted_array(10000, 0, 9), 5000)
    print(arr2)
    start_time_m = time.time()
    sorted_arr2 = sort_array(arr2)
    print(time.time() - start_time_m)
    print(sorted_arr2)


# array sorted in ascending order
def sorted_arr():
    def generate_random_sorted_array(n, min_value, max_value):
        random_array = []
        for i in range(n):
            random_array.append(random.randint(min_value, max_value))
        return sorted(random_array)

    def sort_array(arr):
        #built_in_sort(arr)
        #gnome_sort(arr)
        bubble_sort(arr)
        return arr

    arr1 = generate_random_sorted_array(100, 0, 9)
    print(arr1)
    start_time_n = time.time()
    sorted_arr1 = sort_array(arr1)
    print(time.time() - start_time_n)
    print(sorted_arr1)

    arr2 = generate_random_sorted_array(10000, 0, 9)
    print(arr2)
    start_time_m = time.time()
    sorted_arr2 = sort_array(arr2)
    print(time.time() - start_time_m)
    print(sorted_arr2)


# array sorted in descending order
def reversed_arr():
    def generate_random_sorted_array(n, min_value, max_value):
        random_array = []
        for i in range(n):
            random_array.append(random.randint(min_value, max_value))
        return sorted(random_array, reverse=True)

    def sort_array(arr):
        #built_in_sort(arr)
        #gnome_sort(arr)
        bubble_sort(arr)
        return arr

    arr1 = generate_random_sorted_array(100, 0, 9)
    print(arr1)
    start_time_n = time.time()
    sorted_arr1 = sort_array(arr1)
    print(time.time() - start_time_n)
    print(sorted_arr1)

    arr2 = generate_random_sorted_array(10000, 0, 9)
    print(arr2)
    start_time_m = time.time()
    sorted_arr2 = sort_array(arr2)
    print(time.time() - start_time_m)
    print(sorted_arr2)


# main program
def main():
    random_arr()
    #divided_arr()
    #swapped_arr()
    #sorted_arr()
    #reversed_arr()


main()
