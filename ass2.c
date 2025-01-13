
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct keyword {
    char k[100];
} kw[300];  // Declared for keywords

struct operator {
    char op[100];
} o[10];  // Declared for operators

struct output {
    int sr;
    char name[100];
    char type[100];
} out[500];  // Declared for output

int main() {
    FILE *ptr;
    int i, j, a = 1, idflag = 0, opflag = 0, punctflag = 0;
    char str[100];
    ptr = fopen("input.c", "r");

    // Initializing the keyword list
    strcpy(kw[0].k, "auto");
    strcpy(kw[1].k, "case");
    strcpy(kw[2].k, "break");
    strcpy(kw[3].k, "char");
    strcpy(kw[4].k, "const");
    strcpy(kw[5].k, "continue");
    strcpy(kw[6].k, "default");
    strcpy(kw[7].k, "do");
    strcpy(kw[8].k, "double");
    strcpy(kw[9].k, "else");
    strcpy(kw[10].k, "enum");
    strcpy(kw[11].k, "extern");
    strcpy(kw[12].k, "float");
    strcpy(kw[13].k, "for");
    strcpy(kw[14].k, "goto");
    strcpy(kw[15].k, "if");
    strcpy(kw[16].k, "int");
    strcpy(kw[17].k, "long");
    strcpy(kw[18].k, "register");
    strcpy(kw[19].k, "return");
    strcpy(kw[20].k, "main");
    strcpy(kw[21].k, "short");
    strcpy(kw[22].k, "signed");
    strcpy(kw[23].k, "sizeof");
    strcpy(kw[24].k, "static");
    strcpy(kw[25].k, "struct");
    strcpy(kw[26].k, "switch");
    strcpy(kw[27].k, "typedef");
    strcpy(kw[28].k, "union");
    strcpy(kw[29].k, "unsigned");
    strcpy(kw[30].k, "void");
    strcpy(kw[31].k, "volatile");
    strcpy(kw[32].k, "while");

    // Initializing the operator list
    strcpy(o[0].op, "+");
    strcpy(o[1].op, "-");
    strcpy(o[2].op, "*");
    strcpy(o[3].op, "/");
    strcpy(o[4].op, "=");
    strcpy(o[5].op, "==");
    strcpy(o[6].op, "++");
    strcpy(o[7].op, "--");
    strcpy(o[8].op, ">");
    strcpy(o[9].op, "<");

    if (ptr == NULL) {
        printf("File is Empty\n");
        return 1;  // Exit if file is empty
    } else {
        while (fscanf(ptr, "%s", str) != EOF) {
            idflag = 0;
            opflag = 0;
            punctflag = 0;

            // Check if the token is a keyword
            for (i = 0; i < 33; i++) {  // Increased to 33 to accommodate all keywords
                if (strcmp(str, kw[i].k) == 0) {
                    out[a].sr = a;
                    strcpy(out[a].name, str);
                    strcpy(out[a].type, "Keyword");
                    a++;
                    idflag = 1;
                    break;
                }
            }

            // Check if the token is an operator
            for (i = 0; i < 10; i++) {
                if (strcmp(str, o[i].op) == 0) {
                    out[a].sr = a;
                    strcpy(out[a].name, str);
                    strcpy(out[a].type, "Operator");
                    a++;
                    opflag = 1;
                    break;
                }
            }

            // Check if the token is a punctuator
            if (str[0] == ',' || str[0] == ';' || str[0] == '(' || str[0] == ')' || str[0] == '{' || str[0] == '}') {
                out[a].sr = a;
                strcpy(out[a].name, str);
                strcpy(out[a].type, "Punctuator");
                a++;
                punctflag = 1;
            }

            // If it's not a keyword, operator, or punctuator, consider it an identifier
            if (idflag == 0 && opflag == 0 && punctflag == 0) {
                out[a].sr = a;
                strcpy(out[a].name, str);
                strcpy(out[a].type, "Identifier");
                a++;
            }
        }
    }

    // Display output
    printf("Sr.No.\tName\t\tType\n");
    for (j = 1; j < a; j++) {
        printf("%d\t%s\t\t%s\n", out[j].sr, out[j].name, out[j].type);
    }

    fclose(ptr);
    return 0;
}