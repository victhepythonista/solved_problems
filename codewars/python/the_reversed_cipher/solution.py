def encode(s):
    # get a list of the words
    # words = s.split(" ")
    # cipher = ""
    # get_rev = lambda x:x[::-1]
    # # reverse the words in place
    # for w in words:
    #     rev = w[::-1] # reverse the word
    #     cipher += rev[1:] + rev[0] + " " # movve the first letter of rev and add space ath end
    # return cipher[:-1]
    return "".join([w[::-1][1:] + w[-1] + " " for w in s.split()])[:-1]


# print(encode("Hello World!"))
