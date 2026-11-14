// /d/counties/zhenfeng/suibing_fort.c
// 鎮風縣 (Zhenfeng County) 房間 13/14：碎冰堡・獵獸屯兵寨 (轄下新手村 2，對應卷二 Ch.62)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("zhenfeng");
    set_short("碎冰堡・獵獸屯兵寨");
    set_long("這座位於鎮風縣東翼冰河谷口的半軍事化屯堡，是鎮風縣轄下另一處基礎\n"
             "聚落。堡牆上插滿了削尖的巨型獸肋骨，村民半數為退伍邊軍與專獵北荒雪狼的硬弓\n"
             "獵手，家家戶戶晾曬著生筋與厚毛皮。向西可返【鎮風縣・南塞巨石甕城門】，往北\n"
             "走入石砌地窖則是【碎冰堡・軍屯地下糧窖】。\n");

    set_exits(([
        "west":  "/d/counties/zhenfeng/south_gate.c",
        "north": "/d/counties/zhenfeng/suibing_granary.c",
    ]));

    set_coordinate(1, 16, 0);
}
