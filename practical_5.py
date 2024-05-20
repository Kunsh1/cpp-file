# Write a Program to evaluate a polynomial function.
# (For example store f(x) = 4n2 + 2n + 9 in an array and for a given value of n, say n = 5, compute the value of f(n)).

def evaluate_polynomial(coefficients, n):
    result = 0
    for i, coeff in enumerate(coefficients):
        result += coeff * (n ** i)
    return result


degree = int(input("Enter the degree of the polynomial: "))

coefficients = []
for i in range(degree + 1):
    if i == 0:
        coeff = int(input(f"Enter coefficient for the constant term: "))
        coefficients.append(coeff)
    else:
        coeff = int(input(f"Enter coefficient for term with degree {i}: "))
        coefficients.append(coeff)

n = int(input('Enter the value of n:'))
result = evaluate_polynomial(coefficients, n)
print(f"The value of the polynomial for n = {n} is {result}.")
