import matplotlib.pyplot as plt
import numpy as np

def check(s):
	original = open(f'input/{s}', 'rb')
	decoded = open(f'output/{s}', 'rb')
	ob = original.read(1)
	db = decoded.read(1)
	hist = np.zeros((256,))
	while ob and db:
		if ob != db:
	        	break;
		hist[int.from_bytes(ob, 'big')] += 1
		ob = original.read(1)
		db = decoded.read(1)
	if ob == db: print(f'{s} is correct')
	else: print(f'{s} is incorrect')
	plt.plot(range(256), hist)
	plt.show()
	return ob, db, original, decoded

