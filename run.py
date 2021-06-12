import pathlib
import subprocess
import os
import numpy as np
from check import check

files = 0; correct = 0; ratio = []
for foldername in os.listdir('input'):
	for filename in os.listdir(f'input/{foldername}'):
		subprocess.call([f'{pathlib.Path().absolute()}/prog', f'input/{foldername}/{filename}', f'{foldername}/{filename}'])
		ob, db, _, _ =check(f'{foldername}/{filename}')
		enc_size = os.path.getsize(f'output/{foldername}/{filename}.enc')
		dec_size = os.path.getsize(f'output/{foldername}/{filename}')
		thisratio = dec_size/enc_size
		ratio.append(thisratio)
		print(f'The compression ratio is: {thisratio:.3}. The compression percentage is: {(1 - 1/thisratio)*100:.3}%')
		files += 1
		if ob == db: correct += 1
print(f'Correctly encoded+decoded files: {correct}/{files}')
print(f'Average compression ratio: {np.average(ratio):.3}')
