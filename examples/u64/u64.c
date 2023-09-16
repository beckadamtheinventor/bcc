
uint8_t *u64_add(uint8_t *a, uint8_t *b) {
    uint8_t c;
    uint16_t acc;
    c = acc = 0;
    do {
        acc = acc + a[c] + b[c];
        a[c] = acc;
        acc = acc >> 8;
    } while (c++ < 8);
    return a;
}

uint8_t *u64_from_int(uint8_t *a, int32_t b) {
    uint8_t c;
    uint32_t *aa;
    aa = a;
    aa[0] = b;
    c = 4;
    do {
        a[c] = 0;
    } while (c++ < 8);
    return a;
}

int main(void) {
    uint8_t a[8];

    u64_from_int(&a, 1200);
    u64_add(&a, &a);

    return 0;
}
