# python script that computes LCM
# of two numbers as
# LCM(a,b) = (a*b)/GCD(a,b)


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

# function to compute LCM of two numbers
# a*b = LCM(a,b)*GCD(a,b)
def lcm(a, b):

	# return result
	return (a*b)//gcd(a,b)

# driver function
if __name__ == '__main__':
	
	# variables
	x = 25
	y = 15

	# print result
	print("LCM of",x,"and",y,"is",lcm(x,y))	
