# https://www.geeksforgeeks.org/permutation-and-combination-in-python/

# https://stackoverflow.com/a/57985648/2278742
from more_itertools import distinct_permutations


def get_sum_of_products(key):
    sum_of_products = 0
    key_len = len(key)
    for char in key:
        sum_of_products += ord(char) * key_len**2

    return sum_of_products


assert get_sum_of_products("0") == 48
comb = distinct_permutations("~~n000000")
number_of_keys = 1

for i in comb:
    permutation = ""
    for char in list(i):
        permutation += char
    if get_sum_of_products(permutation) == 52650:
        print(f"{number_of_keys:>2}: {permutation}")
        number_of_keys += 1
    if number_of_keys > 50:
        break
