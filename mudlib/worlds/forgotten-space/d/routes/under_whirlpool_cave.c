// /d/routes/under_whirlpool_cave.c
// 地下溶洞暗河 (seg_city_zhuoshui_under, 310里) 節點 2：鐘乳暗渦洞・私梟停泊處 (對應卷二 Ch.64-65)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit ROUTE_ROOM_OB;

void create() {
    ::create();
    set_route_segment("seg_city_zhuoshui_under");
    set_node_index(2);
    set_short("地下溶洞暗河・鐘乳暗渦洞");
    set_long("巨大的倒懸鐘乳石群下方，暗河水勢陡然湍急，形成數道深不可測的黑色\n"
             "漩渦。岸邊天然石台上釘著幾根生鏽鐵樁，常有走私無印生銅與黑水埗毒囊的私梟\n"
             "扁舟在此秘密停泊交接。品物夏歲暴雨時，暗河倒灌將徹底淹沒此洞。向西北逆流回\n"
             "【磷苔水道】，往東南即可穿出溶洞抵達【濁水縣・溶洞地下暗埠】。\n");

    set_exits(([
        "northwest": "/d/routes/under_karst_river.c",
        "southeast": "/d/counties/zhuoshui/smuggler_dock.c",
    ]));

    set_is_outdoor(0);
    set("is_underground", 1);
    set_coordinate(5, 7, -1);
}
