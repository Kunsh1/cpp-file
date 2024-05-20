# Write a Program that generates all the permutations of a given set of digits, with or without repetition.

from itertools import permutations

digits = input("Enter digits separated by spaces: ").split()
with_repetition = input("Allow repetition? (y/n): ").lower().strip() == 'y'

if with_repetition:
    # Generate permutations with repetition using itertools.permutations
    perms = list(permutations(digits, len(digits)))
else:
    # Remove duplicates from digits to avoid duplicate permutations
    unique_digits = list(set(digits))
    # Generate permutations without repetition using itertools.permutations
    perms = list(permutations(unique_digits))

# Output the permutations
print("Permutations:")
for perm in perms:
    print(''.join(perm))
