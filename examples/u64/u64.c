
void print(char *s) = 0x0207C0;

uint8_t *u64_add(uint8_t *a, uint8_t *b) {
    uint8_t c = 0;
    unsigned int acc = 0;
    do {
        a[c] = acc = acc + a[c] + b[c];
        acc = acc >> 8;
    } while (c++ < 8);
    return a;
}

uint8_t *u64_from_int(uint8_t *a, long b) {
    uint8_t c, d;
    long *aa;
    *(aa = a) = b;
    c = 4;
    if (b >= 0x80000000) {
        d = 0xff;
    } else {
        d = 0x00;
    }
    do {
        a[c] = d;
    } while (c++ < 8);
    return a;
}

long u64_to_int(uint8_t *a) {
	long *b;
	b = a;
	return *b;
}

char *u64_to_hexstr(uint8_t *a, char *str) {
	char *hexchars = "0123456789ABCDEF";
	uint8_t i = 16;
	do {
		uint8_t c;
		c = *a++;
		i = i - 2;
		*str = hexchars[c >> 4];
		str++;
		*str = hexchars[c & 15];
		str++;
	} while (i > 0);
	str[1] = 0;
	return str-16;
}

int main(void) {
    uint8_t a[8];
    uint8_t b[8];
	char buffer[17];

    u64_from_int(&a, 1234);
    u64_from_int(&b, 5678);
    u64_add(&a, &b);
	u64_to_hexstr(&a, &buffer);
	print(&buffer);

    return u64_to_int(&a);
}
