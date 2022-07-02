def bubble_sort(list):
    for i in range(len(list)):
        for j in range(len(list)-1-i):
            if our_list[j] > our_list[j+1]:
                # Swap
                our_list[j], our_list[j+1] = our_list[j+1], our_list[j]

