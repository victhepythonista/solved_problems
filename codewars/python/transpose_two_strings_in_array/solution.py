def transpose_two_strings(arr):
    # make lengths match
    s1, s2 = arr
    result = ""
    l = max([len(s1), len(s2)])
    shortest = s1 if len(s1) <= len(s2) else s2
    # add white spaces to the shorter string and level it ..
    # also get length diff
    arr[arr.index(shortest)] += " " * (l - len(shortest))
    s1, s2 = arr

    # interate the  length printing 1 by 1
    for i in range(l):
        newline = f"{s1[i]} {s2[i]}\n"
        result += newline
    result = result[:-1]  # remove last \n
    return result


print(transpose_two_strings(["?b?b", "!a!a!"]))
