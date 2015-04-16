def _permute(c, ss):
    ps = _permute(ss[0], ss[1:]) if len(ss) > 1 else [ss]
    for s in ps:
        for idx in range(len(s) + 1):
            yield s[:idx] + c + s[idx:]

def permutations(s):
    return _permute(s[0], s[1:])

s = input()
#print(list(permutations(s)))
for p in permutations(s):
    print(p)
