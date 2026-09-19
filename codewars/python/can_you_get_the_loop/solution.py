
class Node:
    next = None

def loop_size(node) -> int:
    if not node:
        return 0

    slow = node
    fast = node

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        
        if slow == fast:  #lloop detected
            break
    else:
        return 0#no loop 

    loop_length = 1
    current = slow.next  # Start counting from the next node

    while current != slow:  # Count until we loop back to the starting point
        loop_length += 1
        current = current.next

    return loop_length



#quick test 
expected=  3

n1 = Node() 
n2 = Node() 
n3 = Node()
n4 = Node()

n1.next = n2
n2.next = n3 
n3.next = n4 
n4.next = n2

result = loop_size(n1)

if expected == result:
    print("TEST OK :) ")
else:
    print(f"Error , got {result} instead of {expected}")


