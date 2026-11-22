// /d/counties/liefan/miners_tea_shed.c
// 烈礬縣 (Liefan County) 擴展生活翼：下工礦工歇腳粗茶棚

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("烈礬縣・礦工歇腳粗茶棚");
    set_long("搭在赤岩客舍東側牆外的簡陋紅柳枝涼棚，地上擺著幾條被赤銅礦灰染成\n"
             "紅褐色的舊長凳。傍晚收工後，買不起客舍好酒好菜的井下礦工總會擠在這裡，\n"
             "花兩文錢舀一碗涼甘草明礬解毒粗茶 (tea) 潤潤乾咳的喉嚨，順便交換井下風聲。\n"
             "向西繞過紅砂岩牆即回【烈礬縣驛・赤岩客舍】。\n");

    set_exits(([
        "west": "/d/counties/liefan/post_inn.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);
    set_touch("default", HIR "舊木長凳積著一層洗不掉的赤紅礦灰，摸起來粗糙乾澀，茶缸外沿涼潤微濕。" NOR);
    set_smell("default", YEL "涼甘草的微甜草氣混著礦工身上濃烈的硫磺塵土與汗味。" NOR);
    set_listen("default", WHT "棚裡不時響起老礦工壓抑的乾咳聲、銅錢落在竹筒裡的脆響，以及礦車輪子遠去聲。" NOR);

    mapping tea_rule = ([
        "targets": ({ "tea", "water", "粗茶", "" }),
        "sp_cost": 4,
        "sensory_msg": HIG "你從粗陶大缸裡舀起一碗微涼甘甜的甘草粗茶飲下，喉間那股硫磺礦塵刺痛感頓時舒緩了許多。" NOR,
        "train_stat": ([ "con": 5 ]),
        "exp_gain": 8
    ]);
    add_action_rule("drink_tea", tea_rule);
    add_action_rule("喝粗茶", tea_rule);

    spawn_npc("/clone/npc/folk/liefan_old_miner.c");
}
