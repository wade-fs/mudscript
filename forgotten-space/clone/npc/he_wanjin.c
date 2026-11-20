// /clone/npc/he_wanjin.c
// 何萬金・萬寶閣雲津分號掌櫃 (he_wanjin) - 萬寶閣雲津分號 (Ch.84, Ch.90)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("何萬金");
    set_short(HIY "萬寶閣雲津掌櫃" NOR " 何萬金");
    set_long("四十九歲的富態掌櫃，身穿簇新的寶藍暗花緞袍，手指戴著三枚翡翠玉扳指。\n"
             "他語氣客氣得令人挑不出毛病，卻最擅長利用甲字倉押金、排他條款與信用評級擠壓新商號。\n");
    set_id(({ "he_wanjin", "he wanjin", "wanjin", "何萬金", "掌櫃" }));

    setup_archetype("I", 45);
    set("class", "mortal");
    set("faction", "wanbao_pavilion");
    set("roles", ({ "merchant", "rival" }));
    set("home_room", "/d/yunjin/wanbao_pavilion.c");

    add_response(({ "試單", "供貨", "甲字倉", "排他" }),
        "何萬金笑眯眯地轉動著翡翠扳指，語調圓滑：「小姑娘剛從金石府上來，還是把這萬山商埠看得簡單了。\n"
        "西街甲字倉我們萬寶閣先替公所包著，免得生手接了外門大單交不出貨砸了招牌。\n"
        "不過看在你們帶了烈礬窯坊與青河藥材的可追溯底單份上，若願意自負全額貨損，倒不妨先從一筆小額炭藥試單幹起。」");

    add_response(({ "馬匹", "車馬行", "冷風坡", "雪崩" }),
        "何萬金笑容不減，眼皮卻微微垂下：「大雪封山之時，驛站備用雪橇馬匹向來價高者得。\n"
        "商場上各憑本事包車備貨，談不上誰卡誰的脖子——交不上貨就照契書賠錢，天經地義。」");
}
