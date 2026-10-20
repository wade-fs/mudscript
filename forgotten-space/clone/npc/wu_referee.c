// clone/npc/wu_referee.c
// 擂台裁判 斷魂刀

#include "/include/ansi.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("斷魂刀");
    set_short(WHT "生死擂裁判" NOR " 斷魂刀");
    set_long("一位抱著厚重鬼頭刀的黑衣老兵，雙目陰鷙，專司生死擂台規矩與私鬥仲裁。\n");
    set_id(({ "wu_referee", "referee", "duanhun", "斷魂刀", "裁判" }));

    set_level(30);
    recalc_stats();

    add_response(({ "生死狀", "擂台", "規矩" }),
        "斷魂刀冷冷道：「上了擂台，生死自負。三招見真章，私鬥不上擂者依軍律嚴懲。」");
}
