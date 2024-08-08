/*3.	Write a program that performs encoding and decoding on user choice. Use following symbols irrespective of case.
A  =  ~		F  =  ^		K  =  >		P  =  /		U  =  #		Z  =  ]
B   = {		G  =  _		L  =  :		Q  =  1		V  = 7
C  =  $		H  =  &		M  =  ?		R  =  ,		W  =  "
D  =  %		I  =  !		N  =  +		S  =  2		X  = 9
E  =  `		J  =  *		O =  @		T  =  =		Y  =  |
*/

#include <stdio.h>
#include <string.h>

void encode(char *input) {
   int i;
    for ( i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case 'A': case 'a':
                printf("~");
                break;
            case 'B': case 'b':
                printf("{");
                break;
            case 'H': case 'h':
                printf("&");
                break;
            case 'N': case 'n':
                printf("+");
                break;
            case 'T': case 't':
                printf("=");
                break;
            case 'Z': case 'z':
                printf("]");
                break;
            case 'E': case 'e':
                printf("`");
                break;
            case 'C': case 'c':
                printf("$");
                break;
            case 'J': case 'j':
                printf("*");
                break;
            case 'P': case 'p':
                printf("/");
                break;
            case 'V': case 'v':
                printf("7");
                break;
            case 'I': case 'i':
                printf("!");
                break;
            case 'D': case 'd':
                printf("%");
                break;
            case 'K': case 'k':
                printf(">");
                break;
            case 'Q': case 'q':
                printf("1");
                break;
            case 'W': case 'w':
                printf("\"");
                break;
            case 'O': case 'o':
                printf("@");
                break;
            case 'F': case 'f':
                printf("^");
                break;
            case 'L': case 'l':
                printf(":");
                break;
            case 'R': case 'r':
                printf(",");
                break;
            case 'X': case 'x':
                printf("9");
                break;
            case 'U': case 'u':
                printf("#");
                break;
            case 'G': case 'g':
                printf("_");
                break;
            case 'M': case 'm':
                printf("?");
                break;
            case 'S': case 's':
                printf("2");
                break;
            case 'Y': case 'y':
                printf("|");
                break;
            default:
                printf("%c", input[i]);
        }
    }
}

void decode(char *input) {
   	int i;
    for ( i = 0; i < strlen(input); i++) {
        switch (input[i]) {
            case '~':
                printf("A");
                break;
            case '{':
                printf("B");
                break;
            case '&':
                printf("H");
                break;
            case '+':
                printf("N");
                break;
            case '=':
                printf("T");
                break;
            case ']':
                printf("Z");
                break;
            case '`':
                printf("E");
                break;
            case '$':
                printf("C");
                break;
            case '*':
                printf("J");
                break;
            case '/':
                printf("P");
                break;
            case '7':
                printf("V");
                break;
            case '!':
                printf("I");
                break;
            case '%':
                printf("D");
                break;
            case '>':
                printf("K");
                break;
            case '1':
                printf("Q");
                break;
            case '\"':
                printf("W");
                break;
            case '@':
                printf("O");
                break;
            case '^':
                printf("F");
                break;
            case ':':
                printf("L");
                break;
            case ',':
                printf("R");
                break;
            case '9':
                printf("X");
                break;
            case '#':
                printf("U");
                break;
            case '_':
                printf("G");
                break;
            case '?':
                printf("M");
                break;
            case '2':
                printf("S");
                break;
            case '|':
                printf("Y");
                break;
            default:
                printf("%c", input[i]);
        }
    }
}

int main() {
    char input[1000];
    int choice;


    	printf("Enter a string: ");
    	fgets(input, sizeof(input), stdin);
	do{
    	printf("Choose an operation:\n");
    	printf("1. Encode\n");
    	printf("2. Decode\n");
    	printf("0.Exit\n");
    	printf("Enter choice : ");
    	scanf("%d", &choice);
	
    	switch (choice) {
        	case 1:
            	printf("Encoded string: ");
            	encode(input);
            	break;
        	case 2:
            	printf("Decoded string: ");
            	decode(input);
            	break;
            case 0:
            	printf("Program Exit");
            	break;
        	default:
            	printf("Invalid choice\n");
            	break;
    	}
    }
	while(choice!=0);
    return 0;
}

