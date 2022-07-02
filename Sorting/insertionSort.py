def insertionSort(array):
    for index in range(1, len(array)):
        cursor = array[index]
        j = index-1
        # reverse traverse here.
        while j>=0 and array[j]>cursor:
            array[j+1] = array[j]
            j = j-1
        array[j+1] = cursor

