class Stack:
    def __init__(self, elements=None):
        self.stack = elements if elements else []

    def push(self, value):
        self.stack.append(value)

    def pop(self):
        return self.stack.pop(0) if self.stack else None

    def rotate(self):
        if self.stack:
            self.stack.append(self.stack.pop(0))

    def reverse_rotate(self):
        if self.stack:
            self.stack.insert(0, self.stack.pop())

    def size(self):
        return len(self.stack)

    def __repr__(self):
        return repr(self.stack)


def emulate_push_swap(stack_a):
    stack_b = Stack()
    print(f"Initial Stack A: {stack_a}")
    print(f"Initial Stack B: {stack_b}")

    qs_try(stack_a, stack_b, stack_a.size())
    print(f"Final Sorted Stack A: {stack_a}")


def qs_try(stack_a, stack_b, size):
    if size <= 1:
        return

    pivot = find_median(stack_a.stack[:size])
    print(f"qs_try -> Pivot: {pivot}, Size: {size}")

    ptb = 0

    # Partition Stack A into Stack B
    for _ in range(size):
        if stack_a.stack[0] < pivot:
            stack_b.push(stack_a.pop())
            ptb += 1
        else:
            stack_a.rotate()

    print(f"After Partitioning (qs_try): Stack A: {stack_a}, Stack B: {stack_b}, ptb: {ptb}")

    # Recursively sort >= pivot in Stack A
    qs_try(stack_a, stack_b, size - ptb)

    # Recursively sort < pivot in Stack B (mini-partition)
    qs_tryb(stack_a, stack_b, ptb)

    # Restore elements from Stack B to Stack A
    while ptb > 0:
        stack_a.push(stack_b.pop())
        ptb -= 1

    print(f"Restored Stack A: {stack_a}")


def qs_tryb(stack_a, stack_b, size):
    if size <= 1:
        return

    pivot = find_median(stack_b.stack[:size])
    print(f"qs_tryb -> Pivot: {pivot}, Size: {size}")

    pta = 0

    # Partition Stack B into smaller mini-partitions
    for _ in range(size):
        if stack_b.stack[0] >= pivot:
            stack_a.push(stack_b.pop())
            pta += 1
        else:
            stack_b.rotate()

    print(f"After Partitioning (qs_tryb): Stack A: {stack_a}, Stack B: {stack_b}, pta: {pta}")

    # Recursively sort >= pivot in Stack A
    qs_try(stack_a, stack_b, pta)

    # Recursively sort < pivot in Stack B (mini-partition)
    qs_tryb(stack_a, stack_b, size - pta)

    # Restore elements from Stack A back to Stack B
    while pta > 0:
        stack_b.push(stack_a.pop())
        pta -= 1

    print(f"Restored Stack B: {stack_b}")


def find_median(stack):
    sorted_stack = sorted(stack)
    return sorted_stack[len(sorted_stack) // 2]


# Test Case
if __name__ == "__main__":
    import random

    initial_stack_a = Stack(random.sample(range(1, 101), 100))  # Random stack from 1 to 100
    emulate_push_swap(initial_stack_a)

