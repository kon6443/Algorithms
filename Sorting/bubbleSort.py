def bubble_sort(list):
    for i in range(len(list)):
        for j in range(len(list)-1-i):
            if list[j] > list[j+1]:
                # Swap
                our_list[j], list[j+1] = list[j+1], list[j]

