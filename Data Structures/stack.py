# como a stack segue a regra LIFO basta usarmos os as funções padrão .append() e .pop(), pois elas seguem o princípio LIFO

def create_stack():
    stack = []
    return stack

def check_empty(stack):
    return len(stack) == 0

def push(stack, item):
    stack.append(item)

def pop(stack):
    if (check_empty(stack)):
        return
    return stack.pop()

stack = create_stack()
print(check_empty(stack))
push(stack, 1)
push(stack, 2)
push(stack, 3)
print(stack)
stack2 = create_stack()
push(stack2, pop(stack))
push(stack2, pop(stack))
push(stack2, pop(stack))
print(stack2)