// d/city/south/warehouse_grain.c
// 官商聯營大糧倉

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城南門側・聯營大糧倉");
    set_long("這座高大的青石深倉通風乾燥，地坪鋪著厚厚的木板防潮。\n"
             "無數麻包自地面整齊碼放至屋樑，斗秤官手持鐵尺正在逐袋抽樣稱重。\n"
             "此處專司漕船下貨後的暫存分流，保障全城市民口糧供應。\n"
             "向北推開兩扇生鐵重門，便回到了官辦糧食市集。\n");

    set_exits(([
        "north": "/d/city/south/grain_market.c",
    ]));

    set("is_outdoor", 0);
}
