// clone/npc/under_drain_gate_diver.c
// 翻江鼠・潛水賊 (under_drain_gate_diver) - 廢棄排水水閘

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("翻江鼠");
    set_short(HIB "暗渠潛水賊" NOR " 翻江鼠");
    set_long("一位全身塗滿防寒魚油、腰間掛著閉氣水囊的水鬼探子，專門替走私客從廢棄排水鐵閘潛渡至外城護城河盲區。\n");
    set_id(({ "under_drain_gate_diver", "under_drain_gate_scout", "fanjiangshu", "diver", "water thief", "翻江鼠", "潛水賊", "水鬼探子" }));

    setup_archetype("L", 22);
    set("class", "mortal");
    set("faction", "jianghu");
    set("roles", ({ "service", "info" }));
    set("schedule", "24h");

    add_response(({ "潛渡", "水閘", "護城河", "偷渡", "走私" }),
        "翻江鼠抹了一把臉上的水珠嘿嘿笑道：「這道太古排水鐵閘底下的欄柵早被老子鋸斷了兩根！要是你在地面上犯了事或帶了違禁品，從這兒往上游 (up) 就能直接摸到西城外護城河蘆葦叢！」");
}
