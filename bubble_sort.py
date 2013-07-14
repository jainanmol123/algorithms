def bubble_sort(alist):
    return_list = alist
    length = len(return_list) - 1
    is_sorted = False
    # Will continue iterating until no swap is made, in that case
    # is_sorted = True and the sorted list is returned.
    while not is_sorted:
        is_sorted = True
        for e in range(length):
            if return_list[e] > return_list[e + 1]:
                # flag that there was a swap in the scan
                is_sorted = False
                # swap items
                return_list[e], return_list[e + 1] = return_list[e + 1], return_list[e]
    return return_list


def bubble_sort_counter(alist):
    return_list = alist
    length = len(return_list) - 1
    is_sorted = False
    counter = 0
    # Will continue iterating until no swap is made, in that case
    # is_sorted = True and the sorted list is returned.
    while not is_sorted:
        is_sorted = True
        for e in range(length):
            # Counts iteration
            counter += 1
            if return_list[e] > return_list[e + 1]:
                # Counts comparison
                counter += 1
                # flag that there was a swap in the scan
                is_sorted = False
                # swap items
                return_list[e], return_list[e + 1] = return_list[e + 1], return_list[e]
                # Counts swap (should I be adding 2 instead of 1?)
                counter += 1
    return return_list, counter

print bubble_sort_counter(([4,3,2,1]))
print bubble_sort_counter([5,4,3,2,1])
print bubble_sort_counter([6,5,4,3,2,1])
print bubble_sort_counter([7,6,5,4,3,2,1])