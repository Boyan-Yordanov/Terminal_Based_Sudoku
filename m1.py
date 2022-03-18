from random import randint, shuffle


# Initializing a 9 by 9 empty grid
field = [[0 for i in range(9)] for j in range(9)]

# A function to check if the field is full
def checkfield(field):
    for row in range(0, 9):
        for col in range(0, 9):
            if field[row][col] == 0:
                return False
    # We have a complete field!
    return True

# Identify on which square we are working
def indentify_square(row, col):
    square = []
    if row < 3:
        if col < 3:
            square = [field[i][0:3] for i in range(0, 3)]
        elif col < 6:
            square = [field[i][3:6] for i in range(0, 3)]
        else:
            square = [field[i][6:9] for i in range(0, 3)]
    elif row < 6:
        if col < 3:
            square = [field[i][0:3] for i in range(3, 6)]
        elif col < 6:
            square = [field[i][3:6] for i in range(3, 6)]
        else:
            square = [field[i][6:9] for i in range(3, 6)]
    else:
        if col < 3:
            square = [field[i][0:3] for i in range(6, 9)]
        elif col < 6:
            square = [field[i][3:6] for i in range(6, 9)]
        else:
            square = [field[i][6:9] for i in range(6, 9)]
    return square
    
# A backtracking/recursive function to check all possible combinations of numbers until a solution is found
def solvefield(field):
    global counter
    # Find next empty cell
    for i in range(0, 81):
        row = i // 9
        col = i % 9
        if field[row][col] == 0:
            for value in range(1, 10):
                # Check that this value has not already be used on this column and row 
                if not (value in field[row]) and not value in ([field[i][col] for i in range (0,9)]):
                    # Identify which of the 9 squares we are working on
                    square = indentify_square(row, col)
                    # Check that this value has not already be used on this 3x3 square
                    if not value in (square[0] + square[1] + square[2]):
                        field[row][col] = value
                        if checkfield(field):
                            counter += 1
                            break
                        else:
                            if solvefield(field):
                                return True
            break
    field[row][col] = 0


# A backtracking/recursive function to check all possible combinations of numbers until a solution is found
def fillfield(field):
    numberList = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    global counter
    # Find next empty cell
    for i in range(0, 81):
        row = i // 9
        col = i % 9
        if field[row][col] == 0:
            shuffle(numberList)
            for value in numberList:
                # Check that this value has not already be used on this column and row 
                if not (value in field[row]) and not value in ([field[i][col] for i in range (0,9)]):
                        # Identify which of the 9 squares we are working on
                        square = indentify_square(row, col)
                        # Check that this value has not already be used on this 3x3 square
                        if not value in (square[0] + square[1] + square[2]):
                            field[row][col] = value
                            if checkfield(field):
                                return True
                            else:
                                if fillfield(field):
                                    return True
            break
    field[row][col] = 0


fillfield(field)
print(field)


attempts = 1
counter = 1
while attempts > 0:
    # Select a random cell that is not already empty
    row = randint(0, 8)
    col = randint(0, 8)
    while field[row][col] == 0:
        row = randint(0, 8)
        col = randint(0, 8)
    # Remember its cell value in case we need to put it back
    backup = field[row][col]
    field[row][col] = 0

    # Take a full copy of the field
    copyfield = []
    for r in range(0, 9):
        copyfield.append([])
        for c in range(0, 9):
            copyfield[r].append(field[r][c])

    # Count the number of solutions that this field has (using a backtracking approach implemented in the solvefield() function)
    counter = 0
    solvefield(copyfield)
    # If the number of solution is different from 1 then we need to cancel the change by putting the value we took away back in the field
    if counter != 1:
        field[row][col] = backup
        # We could stop here, but we can also have another attempt with a different cell just to try to remove more numbers
        attempts -= 1

print(field)
