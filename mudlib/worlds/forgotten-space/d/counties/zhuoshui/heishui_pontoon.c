// /d/counties/zhuoshui/heishui_pontoon.c
// 濁水縣 (Zhuoshui County) 房間 11/15：黑水埗・三號木樁浮橋 (轄下新手村 2，對應卷二 Ch.64 & 30天 Stage 2)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("黑水埗・三號木樁浮橋");
    set_long("這裡是濁水縣南端最魚龍混雜的水上聚落「黑水埗」。三座由生鐵巨鏈鎖連\n"
             "的木樁浮橋橫跨在深不見底的黑水潭上，當地勢力最大的「淘金幫」刀客在此設卡\n"
             "把守。往北可回【浮橋金砂水集】，向東跨過跳板是隱秘的【水上暗寮與毒囊交割處】，\n"
             "順著橋墩鐵梯向下潛入 (down) 則可進入半淹沒的【廢棄排石暗渠】。\n");

    set_stage_desc(2, "外來亡命客與淘金幫在浮橋火併，水澤毒瘴加劇，縣署已下令封鎖三座木樁浮橋！");

    set_exits(([
        "north": "/d/counties/zhuoshui/market.c",
        "east":  "/d/counties/zhuoshui/heishui_waterhouse.c",
        "down":  "/d/counties/zhuoshui/old_canal_entry.c",
    ]));

    set_coordinate(6, 5, 0);
}
