// d/city/center/black_alley.c
// 鬼市暗巷入口 (通往城下暗渠與舊城廢墟)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("鬼市暗巷・暗門入口");
    set_long("這是一條夾在當鋪高牆與商會庫房之間的陰暗死巷。\n"
             "常年不見日光，地面石階長滿黏滑青苔，散落著折斷的木箱板與黑布角。\n"
             "一名疤臉漢子披著厚重油布雨披，按刀倚在角落石階旁。\n"
             "身後一道生鐵鑄就的下旋鐵梯深不見底，隱約傳出地下溶洞的滴水聲。\n"
             "往西可折返通寶當鋪，順鐵梯向下 (down) 則直墜城下太古暗渠與地下鬼市。\n");

    set_exits(([
        "west": "/d/city/center/pawnshop.c",
        "down": "/d/city/under/black_market.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", WHT "暗巷石階長滿黏滑陰冷的青苔，身後生鐵下旋梯把手帶著地下滲出的潮濕水珠。" NOR);
    set_smell("default", MAG "高牆死角積年的陰溝霉臭、桐油雨披味與地下溶洞湧上的冰涼泥腥。" NOR);
    set_listen("default", WHT "死巷徹底隔絕了中心廣場的繁華人聲，只餘鐵梯深處傳來的空洞滴水聲。" NOR);

    spawn_npc("/clone/npc/black_alley_gatekeeper.c");
}
