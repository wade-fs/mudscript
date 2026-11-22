// /clone/npc/lava_bone_beast.c
// 三階熔岩骨鬣獸 (Ch.140 重力衰減半拍實戰試煉)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("熔岩骨鬣獸");
    set_short(HIR "三階荒獸" NOR " 熔岩骨鬣獸");
    set_long("一頭體如小丘、頸背豎滿燒紅玄鐵骨刺的裂谷三階狂獸，踏地時連焦岩都微微震顫。\n"
             "硬撼其正面甲殼幾近找死，唯有卡準重力衰減半拍的息差方能貫穿頸椎軟縫。\n");
    set_id(({ "lava_bone_beast", "bone beast", "beast", "熔岩骨鬣獸", "骨鬣獸" }));

    setup_archetype("K", 88);
    set("class", "beast");
    set("path", "li");
    set("faction", "realm_wild");
    set("no_auto_attack", 1);
    set("home_room", "/d/realm/zhanzu/hunting_camp.c");
}
