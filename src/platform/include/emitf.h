#ifndef __EMITF_H__
#define __EMITF_H__

#define EMITL(s) out += sprintf(out, s)
#define EMITL2(s, a) out += sprintf(out, s, a)
#define EMITL3(s, a, b) out += sprintf(out, s, a, b)
#define EMITL4(s, a, b, c) out += sprintf(out, s, a, b, c)

#endif