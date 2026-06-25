
# new array row
| v  | arrays | size |
|----|--------|------|
|v[0]| array[0][0]| 1 |
|v[1]| array[1][0]| 2 |
|v[3]| array[2][0]| 4 |
|v[7]| array[3][0]| 8 |
|v[15]| array[4][0]| 16 |
|v[$2^k - 1$] | array[k][0] | $2^k$|

| v  | arrays | size | new array size|
|----|--------|------| ----|
|v[0]| array[0][0]| 1| 1 |
|v[1]| array[1][0]| 2| 2 |
|v[2]| array[1][1]| 3| 2 |
|v[3]| array[2][0]| 4| 4 |
|v[4]| array[2][1]| 5| 4 |
|v[5]| array[2][2]| 6| 4 |
|v[6]| array[2][3]| 7| 4 |
|v[7]| array[3][0]| 8| 8 |
|v[8]| array[3][1]| 9| 8 |
|v[9]| array[3][2]| 10| 8 |
|v[10]| array[3][3]| 11| 8 |
|v[11]| array[3][4]| 12| 8 |
|v[12]| array[3][5]| 13| 8 |
|v[13]| array[3][6]| 14| 8 |
|v[14]| array[3][7]| 15| 8 |
|v[15]| array[4][0]| 16| 16|
|v[n] | array[$floor(log_2 n + 1)$][$n+ 1 - 2^{floor(log_2 n + 1)} + 1$] | $n + 1$| |


| v  | arrays | size | capacity|
|----|--------|------| ----|
|v[0]| array[0][0]| 1| 1 |
|v[1]| array[1][0]| 2| 2 |
|v[2]| array[1][1]| 3| 2 |
|v[3]| array[2][0]| 4| 4 |
|v[4]| array[2][1]| 5| 4 |
|v[5]| array[2][2]| 6| 4 |
|v[6]| array[2][3]| 7| 4 |
|v[7]| array[3][0]| 8| 8 |
|v[8]| array[3][1]| 9| 8 |
|v[9]| array[3][2]| 10| 8 |
|v[10]| array[3][3]| 11| 8 |
|v[11]| array[3][4]| 12| 8 |
|v[12]| array[3][5]| 13| 8 |
|v[13]| array[3][6]| 14| 8 |
|v[14]| array[3][7]| 15| 8 |
|v[15]| array[4][0]| 16| 16|
|v[n] | array[$log_2(ca)$][s - c] | $s$| $c$ |