

char * strWithout3a3b(int A, int B){
    int len;
    int n1, n2;
    int x, y;
    char c1, c2;
    char *str;
    
    if (A == 0 || B == 0)
        return NULL;
    
    str = (char *)malloc(sizeof(char) * (A + B) + 1);
    if (!str)
        return NULL;
    
    if (A == B) {
        n1 = n2 = A;
        x = 0;
        y = n1;
        c1 = 'a';
        c2 = 'b';
    } else {
        if (A > B) {
            n1 = A;
            n2 = B;
            c1 = 'a';
            c2 = 'b';
        } else {
            n1 = B;
            n2 = A;
            c1 = 'b';
            c2 = 'a';
        }
        
        /*
         * A > B
         * 2X + y = A
         * x + y - 1 = B        
         */
        x = n1 - (n2 + 1);
        y = 2 * n2 - n1 + 2;
    }
    
    len = 0;
    while (x--) {
        str[len++] = c1;
        str[len++] = c1;
        if (n2) {
            str[len++] = c2;
            n2--;
        }
    }
    
    while (y--) {
        str[len++] = c1;
        if (n2) {
            str[len++] = c2;
            n2--;
        }
    }

    str[len] = 0;
    
    return str;
}