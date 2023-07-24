class Foo:
    def __init__(self):
        pass

    def inherited(self):
        print("Hello Foo")

class Bar(Foo):
    def __init__(self):
        pass

    def inherited(self):
        print("Hello Bar")

class Baz(Foo):
    def __init__(self):
        pass

    def inherited(self):
        print("Hello Baz")


def some_fn(arg):
    arg.inherited()

if __name__ == '__main__':
    foo = Foo()
    bar = Bar()
    baz = Baz()

    some_fn(foo)
    some_fn(bar)
    some_fn(baz)
