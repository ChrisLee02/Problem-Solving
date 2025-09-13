#2884번 - 알람 시계
h, m = input().split(' ')
h = int(h)
m = int(m)
T = m + h*60
if(T<45):
    T = T+24*60-45
else:
    T = T - 45

print(T//60,T%60)



