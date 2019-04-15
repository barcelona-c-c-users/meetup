def all(seq, pred):
    for x in seq:
        if not pred(x):
            return False;
    return True;

def test(seq, fn):
    print all(seq, fn)

def is_even(n):
    return n % 2 == 0
def is_lower(c):
    return 'a' <= c and c <= 'z'
def is_conmutative(x,y,op):
    temp1 =  op(x,y)
    temp2 = op(y,x)
    return temp1 == temp2


def main():

    test([0,2], is_even)
    test("abC", is_lower)
    test([0,2 ],is_conmutative)

if __name__ == "__main__":
    main()

