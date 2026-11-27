// /d/counties/zhenfeng/garrison_lane.c
// 鎮風縣 (Zhenfeng County) 擴展生活翼：戍卒家眷窄巷與皮襖縫坊

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("鎮風縣・戍卒家眷窄巷");
    set_long("藏在避風石棧東側背風岩腳下的一條低矮石巷。屋簷全用厚草泥壓著碎石，\n"
             "家家戶戶門前架著晾曬羊皮與凍蘿蔔乾的木架。十幾戶戍卒家眷在此互相照應，\n"
             "巷口矮凳上堆著幾件待縫補的雙層軍用羊皮襖 (coat)。\n"
             "向西穿過避風石廊即回【鎮風縣驛・避風石棧】。\n");

    set_exits(([
        "west": "/d/counties/zhenfeng/post_inn.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);
    set_touch("default", HIW "巷口石階積著乾燥細沙，待補的羊皮襖內襯絨毛暖厚卻帶著粗針縫補痕跡。" NOR);
    set_smell("default", YEL "生羊皮硝味、煙燻蘿蔔乾與每家煤爐飄出的低沉炊煙交融在背風巷裡。" NOR);
    set_listen("default", WHT "牛筋針穿過厚皮料的「嚓、嚓」拉線聲與巷尾婦人哄孩子睡覺的輕哼此起彼落。" NOR);

    mapping stitch_rule = ([
        "targets": ({ "coat", "fur", "皮襖", "冬襖", "" }),
        "sp_cost": 10,
        "sensory_msg": YEL "你捏緊三稜皮針引著浸過蜂蠟的粗麻線，將兩件開線的羊皮冬襖肩縫針腳密密實實地補牢。" NOR,
        "train_stat": ([ "dex": 8, "per": 6 ]),
        "exp_gain": 12,
        "quest_verb": "stitch",
        "quest_target": "coat"
    ]);
    add_action_rule("stitch", stitch_rule);
    add_action_rule("縫衣", stitch_rule);

    spawn_npc("/clone/npc/folk/feng_seamstress.c");
}
