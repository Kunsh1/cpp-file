# For any number n, write a program to list all the solutions of the equation x1 + x2 + x3 + ...+ xn = C, 
# where C is a constant (C<=10) and x1, x2, x3,...,xn are nonnegative integers, using brute force strategy.


# def find_sols(n, Constant):
#     solutions = []
#     for x1 in range(Constant + 1):
#         for x2 in range(Constant - x1 + 1):
#             for x3 in range(Constant - x1 - x2 + 1):
#                 xn = Constant - x1 - x2 - x3
#                 if xn >= 0:
#                     solutions.append([x1, x2, x3] + [xn] * (n - 4))
#     return solutions


# n = int(input("Enter the number of variables (n): "))
# Constant = int(input("Enter the Constant (C <= 10): "))
    
# if n < 1 or Constant < 0 or Constant > 10:
#     print("Invalid input!")
# else:    
#     solutions = find_sols(n, Constant)
#     print("Solutions:")
#     for solution in solutions:
#         print(solution)


# For any number n, write a program to list all the solutions of the equation x1 + x2 + x3 + ...+ xn = C, 
# where C is a constant (C<=10) and x1, x2, x3,...,xn are nonnegative integers, using brute force strategy.

def find_solutions(n, C):
    solutions = []
    def generate_solution(current_solution, remaining_sum):
        if len(current_solution) == n - 1:
            current_solution.append(remaining_sum)
            solutions.append(current_solution[:])
            current_solution.pop()
            return
        for i in range(remaining_sum + 1):
            current_solution.append(i)
            generate_solution(current_solution, remaining_sum - i)
            current_solution.pop()
    generate_solution([], C)
    return solutions


n = int(input("Enter the value of n(variable): "))
Constant = int(input("Enter the value of Constant (C <= 10): "))

if n < 1 or Constant < 0 or Constant > 10:
     print("Invalid input!")
else:
    solutions = find_solutions(n, Constant)
    print("Solutions:")
    for solution in solutions:
        print(solution)

