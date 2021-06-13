import matplotlib.pyplot as plt
import numpy as np
import math

def getEntropy(shorter, longer):
	#entropia rzędu t
	entropy = 0
	for word in longer:
		context = word[:-1]
		p = longer[word]/shorter[context]
		entropy -= p*math.log2(p)
	return entropy
	
def getRepeats(s):
	two = {}
	three = {}
	four = {}
	for i in range(len(s)-3):
		context = s[i] + s[i+1]
		wordcontext = context + s[i+2]
		word = wordcontext + s[i+3]
		if context in two:
			two[context] += 1
		else:
			two[context] = 1
		if wordcontext in three:
			three[wordcontext] += 1
		else:
			three[wordcontext] = 1
		if word in four:
			four[word] += 1
		else:
			four[word] = 1
	return two, three, four

def check(s):
	original = open(f'input/{s}', 'rb')
	decoded = open(f'output/{s}', 'rb')
	ob = original.read(1)
	db = decoded.read(1)
	hist = np.zeros((256,))
	sum = 0
	ar=[]
	while ob and db:
		if ob != db:
	        	break;
		ar.append(ob)
		hist[int.from_bytes(ob, 'big')] += 1
		sum += 1
		ob = original.read(1)
		db = decoded.read(1)
	if ob == db: print(f'{s} is correct')
	else: print(f'{s} is incorrect')
	plt.plot(range(256), hist)
	plt.show()
	entropy = 0
	for i in range(256):
		prob = hist[i]/sum
		if prob != 0:
			entropy += prob*math.log2(1/prob)
	print(f'The entropy of this file is {entropy:.3}')
	two, three, four = getRepeats(ar)
	print(f'The second order entropy is {getEntropy(two, three):.3}')
	print(f'The third order entropy is {getEntropy(three, four):.3}')
	return ob, db

