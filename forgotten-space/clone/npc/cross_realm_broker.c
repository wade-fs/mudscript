// /clone/npc/cross_realm_broker.c
// 灰紋跨界掮客（走私「赤火」篆印晶箱之中盤代理人）(Ch.147)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("灰紋掮客");
    set_short(MAG "跨界走私代理人" NOR " 灰紋掮客");
    set_long("一名全身裹在防火灰紋斗篷裡的陰沉男子，懷裡藏著帶著凡間天工閣『赤火』篆印的走私晶箱，\n"
             "專司將下界方舟血精偷渡進洞天抵充配額、再換取延壽晶丹返銷雲津私盟。\n");
    set_id(({ "cross_realm_broker", "grey broker", "broker", "灰紋掮客", "掮客" }));

    setup_archetype("L", 85);
    set("class", "rogue");
    set("path", "wu");
    set("faction", "smuggler");
    set("roles", ({ "smuggler", "quest" }));
    set("no_auto_attack", 1);
    set("home_room", "/d/realm/wanwu/scrap_ring.c");

    add_response(({ "赤火", "赤煉", "雲津", "暗道" }),
        "灰紋掮客面色驟變死咬牙關：「別問我是誰派來的！萬仞山西側那條舊礦暗道十幾年來只認\n"
        "貨單編號不認臉——貨箱就在三號暗槽裡，要殺要剮隨便你們！」");
}
