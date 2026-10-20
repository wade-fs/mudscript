// clone/npc/outer_farmland_w_zhaodingtian.c
// 趙定田（人稱趙大叔）・老農 (outer_farmland_w_zhaodingtian) - 城西近郊青禾田

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("趙定田");
    set_short(GRN "青禾田老農" NOR " 趙定田 (趙大叔)");
    set_long("一位挽著褲管、手扶鐵鋤的老莊稼漢，皮膚被日頭曬得黝黑發亮，街坊與行人都親切喚他「趙大叔」。\n"
             "他在西郊青禾田耕種了四十餘年，全靠北面青河水閘引來的活水灌溉蔬果禾苗。\n");
    set_id(({ "outer_farmland_w_zhaodingtian", "farmer zhao", "zhao dingtian", "dingtian", "趙定田", "趙大叔", "老農" }));

    setup_archetype("J", 8);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "quest_giver", "info" }));
    set("schedule", "day");

    add_response(({ "幫農", "治水", "春耕", "秋穫", "水閘" }),
        "趙定田擦了把額頭的汗笑道：「只要北邊青河水閘的水路通暢，咱這青禾田一年四季都能給府城供上鮮菜新米！後生若是有空幫大叔疏通田壟，少不了你的熱飯吃！」");
}
