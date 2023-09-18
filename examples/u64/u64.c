
uint8_t *u64_add(uint8_t *a, uint8_t *b) {
    uint8_t c = 0;
    uint16_t acc = 0;
    do {
        a[c] = acc = acc + a[c] + b[c];
        acc = acc >> 8;
    } while (c++ < 8);
    return a;
}

uint8_t *u64_from_int(uint8_t *a, int b) {
    uint8_t c, d;
    int *aa;
    *(aa = a) = b;
    c = 4;
    if (b >= 0x800000) {
        d = 0xff;
    } else {
        d = 0x00;
    }
    do {
        a[c] = d;
    } while (c++ < 8);
    return a;
}

int main(void) {
    uint8_t a[8];

    u64_from_int(&a, 1200);
    u64_add(&a, &a);

    return 0;
}
