// d/city/east/wu_hall.c
// 八方武館正堂 (力道受牌考核、霸山總教頭)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("八方武館・演武正堂");
    set_long("整座大堂以厚重的青石巨磚與粗獷鐵力木大柱撐起，豪邁肅殺。\n"
             "正堂正中掛著一張巨大完整的吊額白睛猛虎整皮，上方懸掛「氣血如爐」四字鐵匾。\n"
             "兩側兵器架上插滿了開山巨斧、破甲重槊與透骨重弓。\n"
             "八方武館總教頭霸山端坐於虎皮交椅之上，豪邁雄壯，聲若奔雷。\n"
             "通過擂台考驗者，可在此向霸山敬茶立誓 (ask bashan about 受牌) 獲發黑鐵腰牌。\n"
             "向南可步出正堂回到大校場，往東通往披甲兵器庫，往西則是城防軍宿營。\n");

    set_exits(([
        "south": "/d/city/east/wu_plaza.c",
        "east":  "/d/city/east/wu_armory.c",
        "west":  "/d/city/east/wu_barracks.c",
    ]));

    set("is_outdoor", 0);
    spawn_npc("/clone/npc/wu_bashan.c");
    spawn_npc("/clone/npc/wu_hall_enforcer.c");
}
