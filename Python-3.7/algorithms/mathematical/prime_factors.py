# import math module
import math 
  
# A function to find all prime factors of  
# a given number n 
def get_factors(n): 
    
    factors = []  
    # number of two's that divide n 
    while n % 2 == 0: 
        factors.append(2) 
        n = n / 2
          
    # n must be odd at this point 
    # so a skip of 2 ( i = i + 2) can be used 
    for i in range(3,int(math.sqrt(n))+1,2): 
          
        # while i divides n , add i to list and divide n by i
        while n % i== 0: 
            factors.append(i)
            n = n / i 
              
    # Condition if n is a prime 
    # number greater than 2 
    if n > 2: 
        factors.append(int(n))
    
    # return list of prime factors
    return factors

if __name__ == '__main__':

    print(get_factors(125))
