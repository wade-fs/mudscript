// /d/counties/zhenfeng/pawnshop.c
// 鎮風縣 (Zhenfeng County) 房間 5/14：通寶當鋪・鎮風分號

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("通寶當鋪・鎮風分號");
    set_long("這間以厚重花崗岩砌成的當鋪分號，火牆燒得滾燙。高高的鐵柵櫃台後，\n"
             "朝奉正收兌邊軍將士拿來典當的戰利獸骨、雪狼皮與欠餉白條，同時暗中為金石商會\n"
             "收購散人私藏的高純風蝕石英。向東北推開防風重門即回【皮甲硬弓邊集】。\n");

    set_exits(([
        "northeast": "/d/counties/zhenfeng/market.c",
    ]));

    set_has_bank(1);
    set_is_outdoor(0);
    set_coordinate(-1, 16, 0);
}
