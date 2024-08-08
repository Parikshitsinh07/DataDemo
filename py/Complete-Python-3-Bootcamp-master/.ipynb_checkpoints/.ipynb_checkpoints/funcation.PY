from Arithmetic import sum, sub, Multiplication, div
from static import mode, median, mean

print(sum(4, 5))
print(sub(4, 5))
print(Multiplication(4, 5))
print(div(4, 5))

li = [1, 2, 3, 4, 5, 6, 7, 8, 3, 5, 2, 1, 7, 4, 5, 3]
print("mean is :", mean(li))
print("median is :", median(li))
print("Mode is :", mode(li))
