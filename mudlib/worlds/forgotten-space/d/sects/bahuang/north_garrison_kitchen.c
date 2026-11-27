// /d/sects/bahuang/north_garrison_kitchen.c
// 八荒武山・北線軍寨炊事後勤區 (Ch.94：阿滿與《天興十九年失蹤者與未寄家書簿》)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑山營・北線軍寨炊事後勤區");
    set_long("靠近兵營後坡的石砌炊事大棚，三口厚鐵大鍋正咕嘟冒著熱氣，牆邊堆著冰凍肉乾\n"
             "與一袋袋粗糧。炊事婦人阿滿守在碗櫃旁核點各哨排缺糧實數，櫃底暗格子裡壓著一本\n"
             "記載天興十九年五年前走山隊與兩名接應斥候失蹤改判的舊簿與一沓寄不出去的家書。\n"
             "向西跨出伙房返回【黑山煞血營】。\n");

    set_exits(([
        "west": "/d/sects/bahuang/black_mountain_camp.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", YEL "軍寨伙房油膩厚實的木案板暖烘烘的，大鐵鍋鍋沿燙手卻令人捨不得離遠。" NOR);
    set_smell("default", HIY "燉羊肉、花椒大蔥、烙粗麥餅與松柴灶煙濃郁得讓人瞬間忘了牆外暴雪。" NOR);
    set_listen("default", CYN "大鐵勺敲打鍋邊、菜刀篤篤切肉與伙房雜役熱火朝天端湯送飯的吆喝。" NOR);

    spawn_npc("/clone/npc/a_man.c");

    mapping letter_rule = ([
        "targets": ({ "letters", "book", "家書", "書信", "" }),
        "sp_cost": 6,
        "sensory_msg": WHT "你坐在灶台邊借著燈光將數十封沾了雪漬與油煙的戍卒家書按哨所月份逐一捆紮編號，紙頁間還掉出半枚舊銅釦。" NOR,
        "train_stat": ([ "per": 8, "int": 6 ]),
        "exp_gain": 12,
        "quest_verb": "sort",
        "quest_target": "letters"
    ]);
    add_action_rule("sort", letter_rule);
    add_action_rule("理信", letter_rule);
}
