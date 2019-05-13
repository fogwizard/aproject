#include "Seg7.h"
#include "tinyxml2.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include<vector>
#include<algorithm>

using namespace std;

Seg7::Seg7()
{
    //ctor
}

Seg7::~Seg7()
{
    //dtor
}

#define Num0(t)    (t.Sega + t.Segb + t.Segc + t.Segd + t.Sege + t.Segf)
#define Num1(t)    (       t.Segb + t.Segc )
#define Num2(t)    (t.Sega + t.Segb + t.Segd + t.Sege + t.Segg)
#define Num3(t)    (t.Sega + t.Segb + t.Segc + t.Segd + t.Segg)
#define Num4(t)    (         t.Segb + t.Segc               + t.Segf + t.Segg)
#define Num5(t)    (t.Sega        + t.Segc + t.Segd + t.Segf + t.Segg)
#define Num6(t)    (t.Sega        + t.Segc + t.Segd + t.Sege + t.Segf + t.Segg)
#define Num7(t)    (t.Sega + t.Segb + t.Segc )
#define Num8(t)    (t.Sega + t.Segb + t.Segc + t.Segd + t.Sege + t.Segf + t.Segg)
#define Num9(t)    (t.Sega + t.Segb + t.Segc + t.Segd          + t.Segf + t.Segg)
#define Numblk     (0                                             )

int Seg7::get_number_seg(int num, seg_t info)
{
    switch(num) {
    case 0:
        return Num0(info);
    case 1:
        return Num1(info);
    case 2:
        return Num2(info);
    case 3:
        return Num3(info);
    case 4:
        return Num4(info);
    case 5:
        return Num5(info);
    case 6:
        return Num6(info);
    case 7:
        return Num7(info);
    case 8:
        return Num8(info);
    case 9:
        return Num9(info);
    default:
        break;
    }
    return -1;
}

int Seg7::do_seg7(void)
{
    char ch;
    int cnt = 0;
    vector<char> f;
    vector<uint8_t>  fout;

    cout <<  "please input com1->com8" << endl;
    for(int i = 0; i < 8; i++) {
        cin >> ch;
        f.push_back(ch);
    }

    /* revert element for read hardware */
    reverse(f.begin(), f.end());

    for(auto i:f) {
        cnt++;
        cout << "argv[" << cnt<<"]=" << i <<endl;
    }

    auto index0 = distance(f.begin(),find(f.begin(), f.end(), 'a'));
    auto index1 = distance(f.begin(),find(f.begin(), f.end(), 'b'));
    auto index2 = distance(f.begin(),find(f.begin(), f.end(), 'c'));
    auto index3 = distance(f.begin(),find(f.begin(), f.end(), 'd'));
    auto index4 = distance(f.begin(),find(f.begin(), f.end(), 'e'));
    auto index5 = distance(f.begin(),find(f.begin(), f.end(), 'f'));
    auto index6 = distance(f.begin(),find(f.begin(), f.end(), 'g'));
    auto index7 = distance(f.begin(),find(f.begin(), f.end(), 'h'));

    seg_t seg;

    seg.Sega = 1 << index0;
    seg.Segb = 1 << index1;
    seg.Segc = 1 << index2;
    seg.Segd = 1 << index3;
    seg.Sege = 1 << index4;
    seg.Segf = 1 << index5;
    seg.Segg = 1 << index6;
    seg.Segh = 1 << index7;

    cout << "a->" << (index0) << " seg=" << (int)(seg.Sega) <<  endl;
    cout << "b->" << (index1) << " seg=" << (int)(seg.Segb) <<  endl;
    cout << "c->" << (index2) << " seg=" << (int)(seg.Segc) <<  endl;
    cout << "d->" << (index3) << " seg=" << (int)(seg.Segd) <<  endl;
    cout << "e->" << (index4) << " seg=" << (int)(seg.Sege) <<  endl;
    cout << "f->" << (index5) << " seg=" << (int)(seg.Segf) <<  endl;
    cout << "g->" << (index6) << " seg=" << (int)(seg.Segg) <<  endl;
    cout << "h->" << (index7) << " seg=" << (int)(seg.Segh) <<  endl;

    for(auto i = 0; i < 10; i++) {
        fout.push_back(get_number_seg(i, seg));
    }

    /* output format 1 */
    cnt = 0x00;
    cout << "static const uint8_t seg_decode_1={" << endl;
    for(auto i:fout) {
        cnt++;
        printf("0x%x,", i);
    }
    cout << endl;
    cout << "}" << endl;

    /* output format 2 */
    cnt = 0x00;
    cout << "static const uint8_t seg_decode_2={" << endl;
    for(auto i:fout) {
        cnt++;
        printf("0x%x,", (~i)&0xff);
    }
    cout << endl;
    cout << "}" << endl;

    return 0;
    //ctor
}
