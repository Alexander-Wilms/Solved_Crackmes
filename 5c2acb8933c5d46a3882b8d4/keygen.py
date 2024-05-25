import os
import random
import string
import time
from pathlib import Path

while True:
	print()
	chars = string.ascii_letters
	key = ""
	for i in range(8):
		c1 = random.choice(chars)
		c2 = chr(ord(c1) + 1)
		key += c1 + c2
	print(key)
	keygen_path = str(Path(__file__).parent / "SimpleKeyGen")
	cmd = f"{keygen_path} {key}"
	os.system(cmd)
	time.sleep(2)
