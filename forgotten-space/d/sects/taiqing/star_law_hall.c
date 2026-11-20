// /d/sects/taiqing/star_law_hall.c
// 太清玄天宮・周天星律院 (Ch.86, Ch.91：星曆誤差對照與觀測主殿)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("太清玄天宮・周天星律院");
    set_long("大殿中央架著一座巨大的黃銅渾天儀，兩側紫檀長案上堆滿了羊皮星曆卷宗與\n"
             "近三十年雲津暴風雪誤差校對簿。空氣裡飄著淡淡松煙墨香，掌院宋知微正於案前\n"
             "靜靜核驗各觀測哨提交的原始讀數，案頭另押著準予限時查閱藏星秘閣與觀星台的批令。\n"
             "向南走出【太清外門雲舍】，向北進入天柱背陰山腹【藏星秘閣】，向東登上【天柱觀星台】，\n"
             "東北小徑蜿蜒通往後山【清修偏峰】。\n");

    set_exits(([
        "south":     "/d/sects/taiqing/outer_court.c",
        "north":     "/d/sects/taiqing/hidden_archive.c",
        "east":      "/d/sects/taiqing/outer_observatory.c",
        "northeast": "/d/sects/taiqing/quiet_peak.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/song_zhiwei.c");
}
