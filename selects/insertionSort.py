def insertionSort(arr):
    for i in range(1,len(arr)):
        tempValue = arr[i]
        tempIndex = i
        while arr[tempIndex-1] > tempValue and tempIndex > 0:
            arr[tempIndex] = arr[tempIndex-1]
            tempIndex -= 1
        arr[tempIndex] = tempValue
    return arr

print(insertionSort([4,3,6,2,7,1,2,123,12,5,3,6,126,2,5,1,3,56,1,6,13,7,23,5,2,1]))