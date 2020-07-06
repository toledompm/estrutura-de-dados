import random

def shellSort(arr):
    
    #A036562 a(n) = 4^(n+1) + 3*2^n + 1.
    gaps = [70368756760577, 17592192335873, 4398049656833, 1099513200641, 274878693377, 68719869953, 17180065793, 4295065601, 1073790977, 268460033, 67121153, 16783361, 4197377, 1050113, 262913, 65921, 16577, 4193, 1073, 281, 77, 23, 8, 1]

    #A033622 a(n) = 9*2^n - 9*2^(n/2) + 1 if n is even, a(n) = 8*2^n - 6*2^((n+1)/2) + 1 if n is odd.
    #gaps = [4294770689, 2415771649, 1073643521, 603906049, 268386305, 150958081, 67084289, 37730305, 16764929, 9427969, 4188161, 2354689, 1045505, 587521, 260609, 146305, 64769, 36289, 16001, 8929, 3905, 2161, 929, 505, 209, 109, 41, 19, 5, 1]

    n = len(arr)

    for gap in gaps:
        for i in range(gap,n):
            tempVal = arr[i]
            tempIndex = i
            while tempIndex>=gap and arr[tempIndex-gap] > tempVal:
                arr[tempIndex] = arr[tempIndex-gap]
                tempIndex -= gap
            arr[tempIndex] = tempVal

    return arr

arr = []
for i in range(1000000):
    arr.append(random.randint(0, 100000000))

print("starting sort")
print(shellSort(arr))