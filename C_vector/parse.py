import sys
import os

pointer = sys.argv[1]
fname = sys.argv[2]

syscall1 = f"gcc ./member_functions/{fname}.c -c -DADDRESS={pointer}"
syscall2 = f"objdump -d ./{fname}.o | awk '/<_{fname}>/,/^$/' > ./dump.txt"

os.system(syscall1)
os.system(syscall2)

syms = "0123456789abcdef"

with open("dump.txt", "r") as f:
    text = f.read()

def is_hex(s: str):
    if len(s) != 2:
        return False

    return s[0] in syms and s[1] in syms

spl = text.split()

pls = filter(is_hex, spl)

# print(*pls)


lst = [int(x, 16) for x in pls]


with open("code.txt", "w") as f:
  for i in lst:
      f.write(str(i) + " ")
