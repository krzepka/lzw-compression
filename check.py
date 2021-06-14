import matplotlib.pyplot as plt
import numpy as np
import math
from entropy import getRepeats, getOrderEntropy

def check(s):
	original = open(f'input/{s}', 'rb')
	decoded = open(f'output/{s}', 'rb')
	ob = original.read(1)
	db = decoded.read(1)
	hist = np.zeros((256,))
	ar=[]
	while ob and db:
		if ob != db:
	        	break;
		ar.append(int.from_bytes(ob, 'big'))
		hist[int.from_bytes(ob, 'big')] += 1
		ob = original.read(1)
		db = decoded.read(1)
	if ob == db: print(f'{s} is correct')
	else: print(f'{s} is incorrect')
	plt.plot(range(256), hist)
	plt.show()
	entropy = 0
	for i in range(256):
		prob = hist[i]/len(ar)
		if prob != 0:
			entropy += prob*math.log2(1/prob)
	print(f'The entropy of this file is {entropy:.3}')
	two, three, four = getRepeats(ar)
	amount = len(ar)-3
							
	print(f'The second order entropy is {getOrderEntropy(two, three, amount):.3}')
	print(f'The third order entropy is {getOrderEntropy(three, four, amount):.3}')
	return ob, db

