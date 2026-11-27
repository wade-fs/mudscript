// /d/sects/bahuang/great_wall_gate.c
// 八荒武山・北線長城巡防牆暨關口 (Ch.93-94：三號豁口、測距紅旗與東側鐵包邊門)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八荒武山・北線長城巡防牆暨關口");
    set_long("萬仞青黑巨石壘成的北境長城頂端，北風如生鐵銼刀在雉堞與箭樓間嗚咽刮過。\n"
             "東側三號豁口外立著唐映親插的測距紅旗，左翼碎石高崖可俯瞰關下射界；關外一里\n"
             "終年白霧瀰漫之「白霧雪溝」地煞三倍於城頭，軍規嚴令絕不可追敵踏入。正北主關外\n"
             "可領軍令或勘探牌踏出【黑山長城北關雪道】進入北荒裂谷；西北方直通【長城西段缺口暨二道內門】；\n"
             "向南退下【黑山煞血營】，往西往【北荒巡哨營】，向東穿過鐵包邊門可沿無人邊線赴【鬼哭冰澗】。\n");

    set_exits(([
        "south":     "/d/sects/bahuang/black_mountain_camp.c",
        "west":      "/d/sects/bahuang/north_watch.c",
        "east":      "/d/sects/bahuang/ghost_cry_gorge.c",
        "north":     "/d/wastes/black_mountain_pass.c",
        "northwest": "/d/sects/bahuang/west_wall_breach.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", WHT "長城青黑條石垛口結著厚霜，鐵包邊門上的大銅環凍得粘手。" NOR);
    set_smell("default", YEL "軍營鐵鍋飯香與關外湧進來的純淨冰雪寒氣在門洞裡冷熱交匯。" NOR);
    set_listen("default", HIY "測距紅旗在罡風裡獵獵拍打，伴隨守關戰犛牛沉重踏地與換防兵卒的口令聲。" NOR);

    spawn_npc("/clone/npc/iron_yak.c");
}
