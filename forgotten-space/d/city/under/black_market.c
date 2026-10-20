// d/city/under/black_market.c
// 城下暗渠・地下鬼市 (違禁毒藥、無印生銅銷贓暗街)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("城下暗渠・地下鬼市");
    set_long("此處位於金石都城地下十餘丈深處的太古舊城石拱穹頂之下。\n"
             "四周岩壁上生滿了散發幽綠微光的磷苔，空氣陰冷潮濕，瀰漫著地下水汽與硫磺腐味。\n"
             "街道兩旁斜插著幾盞油燈，蒙面黑市牙商與刺客在此低聲密語，交易無印生銅、違禁毒藥與來歷不明的古物。\n"
             "此處處於官方絕靈法網盲區，亦無巡城捕快，全憑江湖黑道規矩說話。\n"
             "順生鐵旋梯向上 (up) 可爬出至地面鬼市暗巷，向南則沿古渠步道進入暗渠水網樞紐。\n");

    set_exits(([
        "up":    "/d/city/center/black_alley.c",
        "south": "/d/city/under/canal_hub.c",
    ]));

    set("is_underground", 1);
    set("has_shop", 1);
    spawn_npc("/clone/npc/under_black_market_broker.c");
}
