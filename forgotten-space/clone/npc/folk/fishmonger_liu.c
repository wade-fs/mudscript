// clone/npc/folk/fishmonger_liu.c
// 魚販劉三娘・外城河埠魚市（漁民卸船市井與青河下游水情） (Ch.43-82)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("魚販劉三娘");
    set_short(CYN "河埠魚市" NOR " 劉三娘");
    set_long("一位紮著藍花布頭巾、圍裙滿是銀亮魚鱗、嗓門比誰都脆的四十歲爽利婦人。\n"
             "每天天還沒亮，她就在外城河埠守著頭批回港的漁船挑揀青魚與河蝦，是城南貧民區最熟水情的萬事通。\n");
    set_id(({ "fishmonger_liu", "liu sanniang", "fishmonger", "魚販劉三娘", "劉三娘", "魚販" }));

    setup_archetype("H", 7);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "shop", "info" }));
    set("no_combat", 1);

    add_response(({ "魚市", "青魚", "河水", "手藝" }),
        "劉三娘手起刀落刮淨一條大草魚的魚鱗笑道：「早市開秤講究手腳麻利！城裡大酒樓挑最肥的鱖魚，剩下便宜的小雜魚我們就半賣半送給南關外矮巷流民煮湯。有空可以在水盆邊學著剖魚理蝦（gut fish）。」");
    add_response(({ "漕運", "水門", "暗渠" }),
        "劉三娘皺起眉頭往南門水道望去：「這幾天夜裡總見府城暗渠口飄出黑呼呼的油花跟死魚……咱們打魚的不敢往深水暗閘那塊撒網了。」");
}
