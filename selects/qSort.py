from random import randint

def medianOfThree(num1,num2,num3):
    if num1 > num2:
        if num2 > num3:
            return num2
        if num1 > num3:
            return num3
        return num1
    if num1 > num3:
        return num1
    if num2 > num3:
        return num3
    return num2

def partition(array, low, high):

    #pivotId = medianOfThree(randint(low, high),randint(low, high),randint(low, high))
    pivotId = medianOfThree(low,high,high-low//2)

    array[low], array[pivotId] = array[pivotId], array[low]
    pivot = array[low]
    i = low + 1

    for j in range(i,high+1):
        if array[j] <= pivot:
            array[j], array[i] = array[i], array[j]
            i += 1
        j += 1

    array[low], array[i - 1] = array[i - 1], array[low]
    return i - 1

def quickSort(arr,low,high): 
    if low > high: return

    partitionIndex = partition(arr,low,high)

    quickSort(arr, low, partitionIndex-1)
    quickSort(arr, partitionIndex+1, high)

arr = [0,2,45,1,32,52,235,20452,32,234,1,414,15,12,51,213]
quickSort(arr,0,len(arr)-1) 
print (arr) 