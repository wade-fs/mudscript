// d/city/center/yamen_archive.c
// 府衙案卷庫 (沈泥身世線重要交涉場景)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("府衙後堂・案卷庫");
    set_long("這是一間終年陰涼乾燥的高大條石密室。\n"
             "四周數十座樟木書架直頂屋樑，整齊排列著數萬冊以黃皮紙抄錄的戶籍底單、\n"
             "歷年稅契與前朝舊案底宗。空氣中瀰漫著濃重的防蟲芸草與陳年墨香。\n"
             "案牘主簿文承敬正伏於長案前核對舊案底冊。\n"
             "南面推門可回到府衙正堂。\n");

    set_exits(([
        "south": "/d/city/center/yamen.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/center_wenchengjing.c");
}
