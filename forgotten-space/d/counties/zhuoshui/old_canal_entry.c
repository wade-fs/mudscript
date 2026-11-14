// /d/counties/zhuoshui/old_canal_entry.c
// 濁水縣 (Zhuoshui County) 房間 13/15：廢棄排石暗渠・鐵柵水門 (對應卷二 Ch.65 沈泥潛入廢棄排石暗渠)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("廢棄排石暗渠・鐵柵水門");
    set_long("順著黑水埗三號浮橋底下的巨型橋墩潛入水下，眼前是一條前朝開鑿用以\n"
             "排洩水磨尾砂的青石暗渠。鏽蝕的鐵柵水門半掩，潮濕的石壁上刻著只有舊商盟與\n"
             "通寶當鋪老朝奉才認得的「九連環尺規」引路暗記。順鐵梯向上 (up) 返回【黑水埗・三號木樁浮橋】，\n"
             "向東推開暗門可入【暗渠石室・柯九算藏身處】，往南則通往【溶洞地下暗埠】。\n");

    set_exits(([
        "up":    "/d/counties/zhuoshui/heishui_pontoon.c",
        "east":  "/d/counties/zhuoshui/kejiusuan_vault.c",
        "south": "/d/counties/zhuoshui/smuggler_dock.c",
    ]));

    set_is_outdoor(0);
    set("is_underground", 1);
    set_coordinate(6, 5, -1);
}
