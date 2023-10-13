// a tiny BrainFuck interpreter
// This example will only work on BOS right now if it does work
uint8_t t[65536] = {0};
uint16_t p = 0;

void gui_PrintString(char *s) = 0x2246C;

void printc(char c) {
	char s[2] = {0, 0};
	s[0] = c;
	gui_PrintString(&s);
}

char inputstr[256] = {0};
uint24_t inputstrindex = 0;

char inputc(void) {
	if (inputstr[inputstrindex] == 0) {
		return 0;
	}
	return inputstr[inputstrindex++];
}

char *bf(char *ptr, char *max) {
	while (ptr < max) {
		char c = *ptr++;
		if (c=='<') p--;
		if (c=='>') p++;
		if (c=='+') t[p]++;
		if (c=='-') t[p]--;
		if (c=='.') printc(t[p]);
		if (c==',') t[p] = inputc();
		if (c==']') return ptr;
		if (c=='[') {
			if(t[p]) {
				char *i = ptr-1;
				ptr = bf(ptr, max);
				if (t[p]) ptr = i;
			} else {
				int l = 1;
				do {
					c = *ptr++;
					if (c=='[') l++;
					if (c==']') l--;
				} while (l && ptr < max);
			}
		}
	}
	return ptr;
}

int main(int argc, char **argv) {
	void *fd;
	char *ptr;
	if (!(fd = fs_OpenFile(argv[1]))) return -1;
	ptr = fs_GetFDPtr(fd);
	bf(ptr, ptr+fs_GetFDLen(fd));
	return 0;
}