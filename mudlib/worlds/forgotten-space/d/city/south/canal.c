// d/city/south/canal.c
// 西水門漕運碼頭 (青河水路終點、曹鐵錨把頭)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城南內河・漕運碼頭");
    set_long("西水門內側這條寬闊內河碼頭以條石砌就，青苔斑駁，水波拍岸。\n"
             "十餘艘平底漕船正緊貼石階停泊，翻砂苦力光著膀子，吆喝著將整簍整袋的草藥與糧油扛上碼頭。\n"
             "碼頭水行把頭曹鐵錨手持煙袋鍋，按刀立在跳板邊查驗船牌公契。\n"
             "往西穿過水門鐵閘即出西水門關口，向東則直通官辦糧食市集。\n");

    set_exits(([
        "west":  "/d/city/gate/gate_west.c",
        "east":  "/d/city/south/grain_market.c",
        "north": "/d/city/outer/river_wharf.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", CYN "西水門青石碼頭階梯被河水打濕而滑溜微涼，麻繩纜樁磨出深溝。" NOR);
    set_smell("default", CYN "青河泥沙水腥、平底糧船新塗的桐油味與卸貨苦力的汗氣。" NOR);
    set_listen("default", HIY "漕船撞擊護樁的悶響、腳夫扛包踩過木跳板的踏步聲與曹鐵錨扯嗓調度。" NOR);

    spawn_npc("/clone/npc/south_canal_caotiemao.c");
}
