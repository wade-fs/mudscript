// /d/counties/zhuoshui/ginger_soup_stall.c
// 濁水縣 (Zhuoshui County) 擴展生活翼：黑水老薑驅瘴攤

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhuoshui");
    set_short("濁水縣・黑水老薑驅瘴攤");
    set_long("架在濁水高腳吊腳樓東側木棧台上的露天草棚湯攤。棚中央砌著一口大灶，\n"
             "一口漆黑大銅鍋終日滾煮著拍碎的老薑、花椒與切片甘草 (soup)，濃烈辛辣的\n"
             "熱氣直衝鼻腔。路過的浮橋修工與窮苦淘金客總會掏兩文銅錢蹲在木欄邊喝上一碗驅寒。\n"
             "向西走過木棧即回【濁水縣驛・高腳吊腳樓】。\n");

    set_exits(([
        "west": "/d/counties/zhuoshui/post_inn.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);
    set_touch("default", MAG "潮濕木棧板踩上去微微發滑，大銅鍋邊沿卻蒸騰著滾燙灼人的濕熱水氣。" NOR);
    set_smell("default", YEL "衝鼻辛辣的老薑、花椒與艾草濃香，硬生生壓住了橋下黑水潭泛上來的淤泥瘴氣。" NOR);
    set_listen("default", CYN "大銅鍋湯水「咕嘟、咕嘟」翻滾，不時響起喝完熱湯的橋工重重放下粗陶碗的碰擊聲。" NOR);

    mapping boil_rule = ([
        "targets": ({ "soup", "pot", "薑湯", "大鍋", "" }),
        "sp_cost": 8,
        "sensory_msg": YEL "你往大銅鍋裡添入拍碎的鮮老薑與青花椒，用大木勺連攪數十圈，滾燙辛辣的驅瘴熱氣瞬間瀰漫全棚！" NOR,
        "train_stat": ([ "con": 8, "per": 6 ]),
        "exp_gain": 12,
        "quest_verb": "boil",
        "quest_target": "soup"
    ]);
    add_action_rule("boil", boil_rule);
    add_action_rule("熬湯", boil_rule);

    spawn_npc("/clone/npc/folk/zhuoshui_bridgekeeper.c");
}
