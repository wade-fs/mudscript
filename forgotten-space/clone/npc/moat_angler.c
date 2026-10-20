// clone/npc/moat_angler.c
// 獨釣叟・釣魚蓑翁 (moat_angler) - 護城河畔

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("獨釣叟");
    set_short(CYN "護城河釣魚蓑翁" NOR " 獨釣叟");
    set_long("一位披著青竹蓑衣、頭戴斗笠的老翁，靜靜坐在護城河蘆葦叢邊垂釣，彷彿對城頭喧囂充耳不聞。\n");
    set_id(({ "moat_angler", "du diao sou", "angler", "fisherman", "獨釣叟", "釣魚蓑翁", "蓑翁" }));

    setup_archetype("J", 5);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "info" }));
    set("schedule", "24h");

    add_response(({ "釣魚", "護城河", "水閘", "暗渠", "潛渡" }),
        "獨釣叟壓低斗笠，幽幽說道：「水深魚肥，夜黑風高……蘆葦蕩底下那道生鏽的廢棄排水鐵閘，每逢子夜總有水鬼換氣的聲音呢。」");
}
