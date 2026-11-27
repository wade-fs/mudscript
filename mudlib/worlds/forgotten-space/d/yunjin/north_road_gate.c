// /d/yunjin/north_road_gate.c
// 雲津仙集・北境商旅入口 (Ch.84)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・北境商旅入口");
    set_long("高大宏偉的青石牌樓下懸著「萬山交匯」四個蒼勁篆字。此處不設大乾府衙捕快，\n"
             "改由身穿鐵甲牌的商埠巡檢丁維持秩序，核驗南來行商的跨州路引與車馬折舊帳。\n"
             "南上通往【青石埡口】，往北步入熱鬧非凡的【雲津萬山廣場】。\n");

    set_exits(([
        "south": "/d/wastes/north_road/qing_pass.c",
        "north": "/d/yunjin/wanshan_square.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", WHT "『萬山交匯』青石牌樓冰涼厚重，門檻處的條石被無數雪橇鐵刃劃出縱橫白痕。" NOR);
    set_smell("default", YEL "牲口棚草料味、北風雪氣與門邊爐火煮著的濃鹹奶茶香氣。" NOR);
    set_listen("default", WHT "商埠巡檢丁鐵甲牌撞擊的叮噹聲、路引核驗問話聲與車輪滾過石門洞的悶響。" NOR);

    mapping pass_rule = ([
        "targets": ({ "pass", "gate", "路引", "折舊帳", "" }),
        "sp_cost": 3,
        "sensory_msg": CYN "你站在一旁看商埠巡檢丁仔細核對南來商號的跨州路引與車馬折舊帳，絲毫不見鬆懈。" NOR,
        "train_stat": ([ "per": 6 ]),
        "exp_gain": 6
    ]);
    add_action_rule("check_pass", pass_rule);
    add_action_rule("驗路引", pass_rule);

    spawn_npc("/clone/npc/folk/route_guard.c");
}
