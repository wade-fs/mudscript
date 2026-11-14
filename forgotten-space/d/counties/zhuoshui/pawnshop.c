// /d/counties/zhuoshui/pawnshop.c
// 濁水縣 (Zhuoshui County) 房間 4/15：通寶當鋪・濁水分號 (對應卷二 Ch.64-65 & 30天 Stage 3 信用凍結現場)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("通寶當鋪・濁水分號");
    set_long("這座四面包裹著生鐵皮的吊腳樓當鋪，是整個東南沼澤最核心的黑貨估價\n"
             "與洗白樞紐。不管是泥螺灘淘出的無印赤金、還是黑水埗來歷不明的古銅器，只要經\n"
             "此處朝奉開出通寶飛錢，便能合法匯入都城。向東北推開鐵柵門即回【浮橋金砂水集】。\n");

    set_stage_desc(3, "因一名帳房攜涉案底單失蹤，通寶當鋪已暫時凍結濁水分號一切信用票據兌付，人心惶惶！");
    set_stage_desc(4, "淘金幫向當鋪賠償百兩赤金贖回信用，櫃台雖重開兌付，但失蹤的半頁殘帳已流入府城。");

    set_exits(([
        "northeast": "/d/counties/zhuoshui/market.c",
    ]));

    set_has_bank(1);
    set_is_outdoor(0);
    set_coordinate(5, 5, 0);
}
