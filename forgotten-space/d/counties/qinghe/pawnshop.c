// /d/counties/qinghe/pawnshop.c
// 青河縣 (Qinghe County) 房間 5/14：通寶當鋪・青河分號

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("通寶當鋪・青河分號");
    set_long("通寶當鋪青河分號的樟木高櫃後，朝奉正用小巧的象牙戥子稱量著陳年野山參\n"
             "與高純定神香露，並為急需周轉的百草坪藥農辦理秋收青苗質押與飛錢匯兌。一旦道觀\n"
             "靈圃因潰壩欠債，這裡便是商會收購折價抵債契的幕後樞紐。向東北推門即回【百草糧油水集】。\n");

    set_exits(([
        "northeast": "/d/counties/qinghe/market.c",
    ]));

    set_has_bank(1);
    set_is_outdoor(0);
    set_coordinate(-9, 9, 0);
}
