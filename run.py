import pathlib
import subprocess
import os

for foldername in os.listdir('input'):
	for filename in os.listdir(f'input/{foldername}'):
		subprocess.call([f'{pathlib.Path().absolute()}/prog', f'input/{foldername}/{filename}', f'{foldername}/{filename}'])
