"""
function to compute gcd
using extended euclidean algorithm
"""
# x and y are coefficients of equation
# ax + by = gcd(a, b)

def extended_gcd(m , n, x, y):

	if m == 0:
		x = 0
		y = 1
		return n

	x1 = 1
	y1 = 1
	gcd = extended_gcd(n%m , m, x1, y1)		

	x = y1 - (n/m)*x1
	y = x1

	return gcd

# driver function
if __name__ == '__main__':
	
	# variables
	a = 3
	b = 15

	# print result
	print("GCD of",a,"and",b,"is",extended_gcd(a,b,1,1))	
