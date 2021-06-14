import math

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

def getConditionalEntropy(context, shorter, longer):
	#entropia warunkowa
	if context not in shorter:
		return 0
	entropy = 0
	for i in range(256):
		word = context + chr(i)
		if word in longer:
			p = longer[word]/shorter[context]
			entropy -= p*math.log2(p)
	return entropy
	
def getOrderEntropy(shorter, longer, amount):
	entropy = 0
	for context in shorter:
		e = getConditionalEntropy(context, shorter, longer)
		e *= shorter[context] / amount
		entropy += e
	return entropy
