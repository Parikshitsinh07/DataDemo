import random

num = random.randint(1, 100)

guesses = [0]

while True:
    guess = int(
        input("I'm thinking of a number between 1 and 100.\n  What is your guess? "))
    if guess < 1 or guess > 100:
        print("OUT OF BOUNDS! Please try again: ")
        continue

    if guess == num:
        print(
            f'CONGRATULATIONS, YOU GUESSED IT IN ONLY {len(guesses)} GUESSES!!')

    guesses.append(guess)

    # when testing the first guess, guesses[-2]==0, which evaluates to False
    # and brings us down to the second section

    if guesses[-2]:
        if abs(num-guess) < abs(num-guesses[-2]):
            print('WARMER!')
        else:
            print('COLDER!')

    else:
        if abs(num-guess) <= 5:
            print('WARM!')
        else:
            print('COLD!')

    ready = input("Are you continue this game (y/n) :")

    if ready == 'y':
        continue

    break
