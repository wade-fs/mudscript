// clone/npc/wu_referee.c
// 擂台裁判 厲無咎（名號「斷魂刀」，wu_arena_duanhundao）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("厲無咎");
    set_short(WHT "生死擂裁判" NOR "「斷魂刀」厲無咎");
    set_long("一位抱著厚重鬼頭刀的黑衣老兵，左手斷了一根尾指，雙目陰鷙冷酷。\n"
             "他早年於北塞軍中以一手斷魂快刀聞名，退伍後受聘於八方武館，專司生死擂台規矩與私鬥仲裁。\n");
    set_id(({ "wu_arena_duanhundao", "wu_referee", "li wujiu", "liwujiu", "referee", "duanhundao", "duanhun", "厲無咎", "斷魂刀", "裁判" }));

    setup_archetype("C", 40);
    set("class", "wu_initiate");
    set("faction", "wu");
    set("roles", ({ "service", "guard" }));
    set("schedule", "24h");

    add_response(({ "生死狀", "擂台", "規矩", "私鬥" }),
        "厲無咎冷冷道：「上了生死擂台，刀劍無眼，生死自負。三招見真章，私鬥不上擂者依軍律嚴懲。」");
}
