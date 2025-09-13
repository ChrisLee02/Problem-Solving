
# N = int(input())
# for i in range(N):
#     count = 0
#     L = list(map(int, input().split(' ')))
#     Average = sum(L[1:]) / L[0]
#     for j in L[1:]:
#         if j>Average:
#             count += 1
#
#     print(  "{:.3f}%".format((count*100/L[0])) )

# L = list(map(int, input().split()))
# L.sort()
# print(L[0]*L[-1])
import copy
import sys

N = int(input())
L=[]
A = {}

for i in range(N):
    a = int(sys.stdin.readline())
    L.append(a)
L.sort()
print( int(round(sum(L)/len(L))) )
print( L[ int(len(L)/2)] )
for i in L:
    A[i] = 0
for i in L:
    A[i] = A[i] + 1
Max = max(A.values())
B=copy.deepcopy(A)
for i in A:
    if(A[i] < Max):
        del B[i]
C = list(B.keys())
C.sort()
if(len(C) > 1):
    print(C[1])
else:
    print(C[0])
print(max(L) - min(L))


# for i in range(N):
#     A, B = input().split(' ')
#     A = int(A)
#     B = int(B)
#     C, D = A, B
#     if (A < B):
#         A, B = B, A
#
#     while (B > 0):
#         짬통 = A
#         A = B
#         B = 짬통 % B
#
#     print(int(C * D / A))








