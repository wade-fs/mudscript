// /d/yunjin/mountain_caravan_yard.c
// 雲津仙集・山道車馬行 (Ch.98, Ch.101：雙馬雪橇隊、北荒輜重招標榜與鬼市暗門通道)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・山道車馬行");
    set_long("停滿北地矮腳駑馬與雙馬木橇的大車院，馬槽旁堆著防寒草料與新上油的鐵爪橇板。\n"
             "木棚牆面上貼著剛由公所統籌頒布的《三宗聯合勘探隊隨軍輜重雪橇招標榜》，引來數家商號爭搶。\n"
             "車行最僻靜西角緊挨著一條臭氣熏天的死巷暗門，門後石階竟直墜峽谷岩石裂縫地下。\n"
             "向北返【三宗物資交易街】，向下掀開暗門走入【雲海鬼市】。\n");

    set_exits(([
        "north": "/d/yunjin/three_sect_market.c",
        "down":  "/d/yunjin/ghost_market.c",
    ]));

    set("is_outdoor", 1);
}
