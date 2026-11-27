// /d/sects/bahuang/north_watch.c
// 八荒武山・北荒巡哨營 (Ch.94：測冰鐵簽與巡哨斥候駐點)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八荒武山・北荒巡哨營");
    set_long("緊貼長城西段雉堞搭建的哨所石屋，木架上整齊插著十餘根綁了紅布條的測冰長鐵簽、\n"
             "牛筋安全繩與單筒遠鏡。斥候祁無傷在此標繪北荒雪線與獸道異常，記下大裂谷深處\n"
             "每逢深夜便隱隱傳來的規律地底震聲。\n"
             "向東沿城牆走廊返回【北線長城巡防牆暨關口】。\n");

    set_exits(([
        "east": "/d/sects/bahuang/great_wall_gate.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", HIW "哨營木欄結滿白霜，遠望箭垛上的鐵製測向標冷得刺骨。" NOR);
    set_smell("default", CYN "只有荒原冰雪寒風與哨卒火盆裡半熄木炭的微弱煙氣。" NOR);
    set_listen("default", WHT "曠野朔風呼嘯而過，哨塔上偶爾傳來斥候敲響警鐘測試銅音的沉悶一聲。" NOR);

    add_action_rule("stake", ([
        "targets": ({ "ice_rift" }),
        "quest_verb": "stake",
        "quest_target": "ice_rift",
        "usage_msg": "你想沿哪處目標打設測冰鐵簽？試試：stake ice_rift",
        "sensory_msg": HIC "你拎起綁紅布條的長鐵簽逐段釘入城下裂谷冰縫，細看布條規律微顫頻率，畫出地底暗脈走向！" NOR,
        "exp_gain": 14
    ]));

    spawn_npc("/clone/npc/qi_wushang.c");
}
