#ifndef SEG7_H
#define SEG7_H
#include "stdint.h"

typedef struct {
	uint8_t Sega;
	uint8_t Segb;
	uint8_t Segc;
	uint8_t Segd;
	uint8_t Sege;
	uint8_t Segf;
	uint8_t Segg;
	uint8_t Segh;
}seg_t;

class Seg7
{
    public:
        Seg7();
        int do_seg7(void);
        int get_number_seg(int num, seg_t info);
        virtual ~Seg7();
    protected:
    private:
};

#endif // SEG7_H
