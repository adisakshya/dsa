"""
function to compute gcd
using basic euclidean algorithm
"""
def gcd(m ,n):

	# if n divides m, then gcd = n	
	if m % n == 0:

		return n

	# recursive call to gcd function
	# with parameters (n, remainder(m/n))
	return gcd(max(n, m%n), min(n, m%n))	

# driver function
if __name__ == '__main__':
	
	# variables
	x = 3
	y = 10

	# print result
	print("GCD of",x,"and",y,"is",gcd(x,y))	
