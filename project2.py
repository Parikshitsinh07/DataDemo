import random

randnumber = random.randint(1, 100)
gusses = []

while True:
    print("Welcome To Guessing Game")
    print("if you are exit this game to pase 1 number")
    guess = int(input("please enter your number between 2 to 100:"))

    if guess < 1 or guess > 100:
        print("please entry your valid number ")
        continue
    if guess == randnumber:
        gusses.append(guess)
        print(f"omg congretulations your guess is {len(gusses)}")
    if abs(randnumber-guess) < 5 or abs(guess-randnumber) < 5:
        print('nice play')
    else:
        print('bed Play')

    if guess == 1:
        break
