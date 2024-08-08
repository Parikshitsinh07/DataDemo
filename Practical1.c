//1.Write a program that finds prime number that is also palindrome.

#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int n) {
   int i;
    if (n <= 1) {
        return false;
    }
    for ( i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to check if a number is a palindrome
bool isPalindrome(int n) {
    int original = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }

    return original == reversed;
}

// Function to find and print prime palindrome numbers up to a given limit
void findPrimePalindromes(int num) {
	if(isPalindrome(num)){
		printf("Num is Palindromes %d:\n", num);
	}
	else{
		printf("Num is Not Palindromes %d:\n", num);
	}
    if(isPrime(num)){
		printf("Num is Prime %d:\n", num);
	}
	else{
		printf("Num is Not Prime %d:\n", num);
	}
}

// Main function
int main() {
    int num;

    printf("Enter the limit to find prime palindromes: ");
    scanf("%d", &num);

    findPrimePalindromes(num);

    return 0;
}

