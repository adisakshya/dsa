# function to find prime numbers <= number
def sieve(n):
  
  # list of prime numbers
	primes_list = []
  
	primes = [True for i in range(n+1)]
	p = 2
	
  # eliminate multiples of primes
  while p*p <= n:
		if primes[p] == True:
			for i in range(p*p, n+1, p):
				primes[i] = False
		p = p + 1
  
  # get prime numbers
	for p in range(2, n):
		if primes[p]:
			primes_list.append(p)
	return primes_list					

# driver function
if __name__ == '__main__':
	
	print(sieve(10))
