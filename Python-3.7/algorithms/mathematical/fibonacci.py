# import sqrt from math module
from math import sqrt

# golden square root formula
# opbtained from solving recurrence relation of fibonacci series
# f(n) = f(n-1) + f(n-2)
phi = (1 + sqrt(5))/2 

# function to find n-th fibonacci number
def fib(n):

	# if n <= 5 return number from series
	series = [1, 1, 2, 3, 5]
	if n <= 5:
		return series(n)

	# get fibonacci n > 5 using formula
	temp = 5
	fib_n = 5
	while temp < n:
		fib_n = round(fib_n*phi)
		temp = temp + 1

	# return n-th fibonacci number	
	return fib_n

# driver function
if __name__ == '__main__':
	
	print(fib(9))
