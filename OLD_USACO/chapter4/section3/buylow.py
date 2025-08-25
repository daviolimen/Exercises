"""
ID: davideo2
LANG: PYTHON3
TASK: buylow
"""

def main():
    fin = open('buylow.in', 'r')
    fout = open('buylow.out', 'w')
    
    n = int(fin.readline())
    arr = []
    while (True):
        for num in map(int, fin.readline().split()):
            arr.append(num)
        if (len(arr) == n): break
    
    dp = [[1, 1] for _ in range(n)]

    for i in range(1, n):
        for j in range(i - 1, -1, -1):
            if (arr[j] <= arr[i]): continue
            if (dp[j][0] + 1 < dp[i][0]): continue
            if (dp[j][0] + 1 == dp[i][0]):
                dp[i][1] += dp[j][1]
            else:
                dp[i][0] = dp[j][0] + 1
                dp[i][1] = dp[j][1]

        for j in range(i - 1, -1, -1):
            if (arr[i] != arr[j]): continue
            if (dp[i][0] != dp[j][0]): continue
            dp[i][1] -= dp[j][1]
    
    bestLength = 0
    numOfSeq = 0
    for i in range(n):
        if (dp[i][0] > bestLength):
            bestLength = dp[i][0]
            numOfSeq = dp[i][1]
        elif (dp[i][0] == bestLength):
            numOfSeq += dp[i][1]
    
    fout.write(f"{bestLength} {numOfSeq}\n")

if __name__ == '__main__':
    main()
