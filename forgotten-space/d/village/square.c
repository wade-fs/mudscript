// d/village/square.c
// 黑石鋪・中央青石街市 (Tier 0 核心樞紐)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石鋪・青石街市");
    set_long("這是一座依山勢而建的邊陲粗獷聚落。腳下的青石板路被往來商隊的鐵蹄\n"
             "磨得凹凸斑駁，泛著深沉的黑青色。街市中央搭著幾間避風的破舊茶棚，\n"
             "旁邊的鐵匠鋪內炭火熊熊，傳出節奏分明的叮噹打鐵聲。幾塊告示牌斜插\n"
             "在老客棧門口，貼滿了鄉民求助與商隊招募的泛黃布告。\n"
             "向北是一座寸草不生的陡峭黑石斷崖，南邊飄來陣陣水霧與溪流的轟鳴，\n"
             "東面是遮蔽天日的荊棘荒林，西面則聳立著通往廢棄道壇的孤岩天梯。\n");

    set_exits(([
        "north": "/d/village/mine.c",
        "south": "/d/village/stream.c",
        "east":  "/d/village/forest.c",
        "west":  "/d/village/altar.c",
    ]));

    set("no_combat", 1);
    set("is_outdoor", 1);
    set("has_shop", 1);
    set("has_forge", 1);
}
