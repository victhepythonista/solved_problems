def diamond(n):
    # Make some diamonds!

    # check if even or not and if invalid input
    if n % 2 == 0 or n <= 0:
        return None
    diamond = ""
    direction = 1  # indicator to find nxt or prev even numbers
    size = 1
    midpoint = ((n - 1) // 2) + 1  # find the middle point
    for i in range(1, n + 1):
        previous_size = size
        padding_size = (n - size) // 2  # per side . ie  "__***__"
        padding = " " * padding_size
        start_pos = n - padding_size - 1
        new_line = padding + ("*" * size) + "\n"
        diamond += new_line

        # add the padding
        if i == midpoint:
            # reverse direction
            direction = -1
        size = previous_size + (2 * direction)

    return diamond


"  *\n ***\n*****\n ***\n  *\n"
"*  \n *** \n*****\n *** \n  *"
print(diamond(21))
