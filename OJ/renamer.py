import os
from glob import glob

fns = glob('./*')

for fn in fns:
	print('fuck')
	path, name = os.path.split(fn)
	if name == 'renamer.py':
		continue;
	name = name.replace(' ', '_')
	os.rename(fn, path + '/' + name)