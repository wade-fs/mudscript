// /d/yunjin/three_sect_market.c
// 雲津仙集・三宗物資交易街 (Ch.90, Ch.98, Ch.101)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・三宗物資交易街");
    set_long("雲津仙集最熱鬧的長街，街道兩旁擺滿朱砂符紙鋪、青河苦參乾草行、烈礬耐火炭垛\n"
             "與精鐵鑄軸貨攤。城南幾家專做北境邊貨的商棧挑簾透出昏黃燈火，偶有身著各脈外門\n"
             "服色的弟子低聲核對初七、廿二批次的靈石票。\n"
             "向西穿過石牌坊是人聲鼎沸的【山神廟會茶市】，向北回到【西街貨棧區】，向南步入【山道車馬行】。\n");

    set_exits(([
        "north": "/d/yunjin/western_warehouse_street.c",
        "south": "/d/yunjin/mountain_caravan_yard.c",
        "west":  "/d/yunjin/temple_tea_fair.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", YEL "長街兩旁攤位木板摩挲得油亮，竹匾裡的青河苦參與朱砂符紙觸感各異。" NOR);
    set_smell("default", HIG "朱砂墨香、苦參乾草清苦味、耐火炭末與商棧燈油氣味雜陳。" NOR);
    set_listen("default", HIY "各脈外門弟子低聲討價還價、算盤珠子清脆撥動與長街行人摩肩擦踵的喧鬧。" NOR);

    mapping market_rule = ([
        "targets": ({ "stalls", "goods", "貨攤", "市價", "" }),
        "sp_cost": 3,
        "sensory_msg": HIY "你沿街逐攤比對朱砂、苦參與耐火炭的靈石票折算價碼，把三宗物資行情摸了個七七八八。" NOR,
        "train_stat": ([ "int": 6 ]),
        "exp_gain": 8
    ]);
    add_action_rule("browse", market_rule);
    add_action_rule("比價", market_rule);

    spawn_npc("/clone/npc/folk/county_broker.c");
}
