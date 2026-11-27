// d/city/north/gong_forge.c
// 千錘地爐坊 (鍛造大師莫錘、物道辨材考核)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("百工坊街・千錘地爐坊");
    set_long("這座巨大的高溫鍛造工坊熱浪滾滾，火星四濺。\n"
             "地底連通微弱地火餘脈，四座丈許高的巨型熔爐晝夜不熄。\n"
             "原料完全依託烈礬縣赤銅與重石縣重玄粗生鐵錠，地上堆滿了暗紅粗礦。\n"
             "鍛造大師莫錘手持重錘立在巨型鐵砧前，專試學徒摸骨辨材眼力 (ask mochui about 辨材)。\n"
             "持有百工正式匠籍者可領爐接單鍛造官械 (commission / 開爐)。\n"
             "南面通往萬機正堂，往東是官造石作場，往西則是戒備森嚴的硝火作。\n");

    set_exits(([
        "south": "/d/city/north/gong_hall.c",
        "east":  "/d/city/north/gong_stone.c",
        "west":  "/d/city/north/gong_fireworks.c",
        "north": "/d/city/north/scrap_yard.c",
    ]));

    set("is_outdoor", 0);
    set("has_forge", 1);
    set_touch("default", HIR "巨型鐵砧被千錘敲得凹凸溫熱，地磚縫隙裡微弱地脈餘熱烤得鞋底發燙。" NOR);
    set_smell("default", YEL "滾燙鐵水、烈礬赤銅氣、高溫焦炭與工匠汗水交織成厚重的金屬火氣。" NOR);
    set_listen("default", HIY "四座巨爐風道轟鳴如悶雷，十六磅重錘砸落玄鐵胚的巨響震得耳膜嗡嗡作響。" NOR);

    mapping comm_rule = ([
        "require_qualification": "forge",
        "action_label": "承接官造百工工單",
        "sp_cost": 15,
        "sensory_msg": HIY "你出示百工匠籍腰牌領取官造生鐵錠，引地火餘脈入爐，精準比對火色將胚料反覆疊鍛，錘落處火星如金雨濺開，成器公差嚴絲合縫！" NOR,
        "train_stat": ([ "str": 15, "dex": 10 ]),
        "exp_gain": 15
    ]);
    add_action_rule("commission", comm_rule);
    add_action_rule("開爐", comm_rule);
    add_action_rule("inspect", ([
        "targets": ({ "clay" }),
        "quest_verb": "inspect",
        "quest_target": "clay",
        "usage_msg": "你想實測什麼礦料試塊？試試：inspect clay",
        "sensory_msg": HIY "你夾起烈礬白泥試塊探入地爐邊火測試耐火度與金蓮刀印紋理，果見矽礬結晶與血精坩堝完全吻合！" NOR,
        "exp_gain": 12
    ]));

    spawn_npc("/clone/npc/gong_mochui.c");
}
