// /d/counties/zhuoshui/heishui_waterhouse.c
// 濁水縣 (Zhuoshui County) 房間 12/15：黑水埗・水上暗寮與毒囊交割處 (對應卷二 Ch.64 毒囊交割底單)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("黑水埗・水上毒囊交割暗寮");
    set_long("這間四周垂掛著黑油布簾的水上木寮，是黑水埗毒販與外埠買家秘密交割\n"
             "劇毒母液的暗樁。木桌暗格的油紙包裡，藏著一份沾有雄黃印泥的《黑水埗毒囊提純\n"
             "交割底單》——清楚記載金石商會總堂管事趙德貴親筆代簽、分兩批提走「地陰腐骨散\n"
             "母液」（用於下毒害死蘇遠山與黑石關犒軍鹹肉）的完整記錄！向西走過跳板即回\n"
             "【黑水埗・三號木樁浮橋】。\n");

    set_exits(([
        "west": "/d/counties/zhuoshui/heishui_pontoon.c",
    ]));

    add_item("poison_receipt", "記載趙德貴親筆代簽提走『地陰腐骨散母液』的黑水埗毒囊交割底單。");
    set_is_outdoor(0);
    set_coordinate(7, 5, 0);
}
