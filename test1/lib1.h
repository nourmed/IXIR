#ifdef _LIB_H_
#define _LIB_H_
#include <Wire.h>

#define I2C_ADDR 0x38 //0x38 and 0x39

//Integration Time
#define IT_1_2 0x0 //1/2T
#define IT_1   0x1 //1T
#define IT_2   0x2 //2T
#define IT_4   0x3 //4T

extern void uv(void);


#endif
