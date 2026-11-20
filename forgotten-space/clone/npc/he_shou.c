// /clone/npc/he_shou.c
// 鶴壽・丹鼎宗大長老 (he_shou) - 百毒試藥谷暨百草谷 (Ch.89)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鶴壽");
    set_short(MAG "丹鼎宗大長老" NOR " 鶴壽真人");
    set_long("一名身材瘦長、鬚髮皆白卻雙眼異常精亮的老者，身披丹鼎宗紫金暗紋藥袍。\n"
             "他在門中向以救人濟世、深諳毒理著稱，唯有在極少數時刻，眼底會掠過一抹極深沉的無奈與算計。\n");
    set_id(({ "he_shou", "he shou", "heshou", "鶴壽", "鶴壽真人", "大長老" }));

    setup_archetype("F", 94);
    set("class", "gong");
    set("faction", "danding");
    set("roles", ({ "elder", "alchemist" }));
    set("home_room", "/d/sects/danding/herb_garden.c");

    add_response(({ "雪線苔", "水渠", "藥理" }),
        "鶴壽真人負手微笑，聲音溫和如鄰家老醫：「毒生於土、藥亦生於土。能看見雪線苔這點偏門道理算是有眼力。\n"
        "不過百草谷上游水渠自有執事與宗門打點，你初入山門，先把基本控火與辨藥功課學踏實了再說。」");

    add_response(({ "地肺丹火窟", "延命丹" }),
        "鶴壽真人眼神微沉，語氣轉淡：「丙字禁區丹火兇險，不是剛入門的外門藥童該打聽的地方。」");
}
