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
    fCandidate = randint(low,high) # low
    sCandidate = randint(low,high) # high
    tCandidate = randint(low,high) # high-low//2
    
    pivotValue = medianOfThree(arr[fCandidate],arr[sCandidate],arr[tCandidate])
    pivotId = fCandidate if arr[fCandidate] == pivotValue else sCandidate if arr[sCandidate] == pivotValue else tCandidate

    array[low], array[pivotId] = array[pivotId], array[low]
    i = low + 1

    for j in range(i,high+1):
        if array[j] <= pivotValue:
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

arr = [0,2123,123,15,44532,235,234,325,235,23,7627,4567,1241,234,1234,231,423,4123,4231,4,1234,124,3124,23,421,4,124,314,13,41,26,342,5634]
quickSort(arr,0,len(arr)-1) 
print (arr) 
