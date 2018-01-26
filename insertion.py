def insertion_sort(arr):
     for i in range(1, len(arr)):
 
        k = arr[i]
        j = i-1
        while j >=0 and k < arr[j] :
                swap=swap+1
                arr[j+1] = arr[j]
                j -= 1
        arr[j+1] = k
        comparisons+=1
    print("%d"%swap)
    print("%d"%comparisons)


arr = [1,3,9,12,7,2,5]
insertion_sort(arr)
for i in range(len(arr)):
    print ("%d" %arr[i])