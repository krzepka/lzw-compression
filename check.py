import matplotlib.pyplot as plt
import numpy as np
import math

def getEntropy(one, two, three, four):
	#entropia rzędu t
	entropy = 0
	for word in three:
		context = word[:-1]
		p = longer[word]/shorter[context]
		entropy -= p*math.log2(p)
	return entropy
	
def getRepeats(s):
	two = {}
	three = {}
	four = {}
	for i in range(len(s)-3):
		context = chr(s[i]) + chr(s[i+1])
		wordcontext = context + chr(s[i+2])
		word = wordcontext + chr(s[i+3])
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
	sum02 = 0
	sum03 = 0
	for i in range(256):
		if hist[i]>0:
			sum12 = 0
			sum13 = 0
			for j in range(256):
				con2 = chr(i) + chr(j)
				if con2 in two:
					sum22 = 0
					sum23 = 0
					for k in range(256):
						con3 = con2 + chr(k)
						if con3 in three:
							p = three[con3] / amount
							sum22 += p * math.log2(1/p)
							sum3 = 0
							for l in range(256):
								con4 = con3 + chr(l)
								if con4 in four:
									sum3 += four[con4]*math.log2(amount/four[con4])/amount
							sum23 += sum3 * p
					p = two[con2] / amount
					sum12 += sum22 * p
					sum13 += sum23 * p
			p = hist[i] / len(ar)
			sum02 += sum12 * p
			sum03 += sum13 * p
							
	print(f'The second order entropy is {sum02:.3}')
	print(f'The third order entropy is {sum03:.3}')
	return ob, db

