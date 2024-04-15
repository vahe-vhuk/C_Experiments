with open("dump.txt", "r") as f:
    text = f.read()

def is_hex(s: str):
    if len(s) != 2:
        return False

    return s.isalnum()

spl = text.split()

pls = filter(is_hex, spl)

# print(*pls)


lst = [int(x, 16) for x in pls]


with open("code.txt", "w") as f:
  for i in lst:
      f.write(str(i) + " ")
