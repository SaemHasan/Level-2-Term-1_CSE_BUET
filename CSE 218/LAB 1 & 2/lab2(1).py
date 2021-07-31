def func(x,y) :
    """this is doc string """
    return x+y

def sub(x,y):
    """this is a fn that substracts """
    return x-y


if __name__ == '__main__' :
    print('this is a test')
    a=func(2.3,3)
    print(a)
    print(type(a))
    #this is a single line comment
    """multi 
    line 
    comment """
    print(5/3)
    print(5//3.3)
    help(sub)