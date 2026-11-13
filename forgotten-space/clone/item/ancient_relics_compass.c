// clone/item/ancient_relics_compass.c
// 太古五器合鳴星光指針 - 卷二終章大結局信物

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("太古五器合鳴星光指針", ({ "ancient relics compass", "relics_compass", "ancient_compass", "星光指針", "太古指針" }));
    set_short(HIC "【太古五器合鳴星光指針】" NOR);
    set_long("由逆星斷碑拓片、太古不融黑鐵、天門引與青銅契版、戰神骨片及地煞晶核五器齊聚時，\n"
             "在同一木案上受共鳴牽引所凝結成的玄妙星光靈印。\n"
             "針尖在絕靈法網之下穿透虛空，無比堅定地指向正北方二階名山雲海深處，\n"
             "標誌著第二卷「金石雙壁」完結，指引少年同袍們邁向更廣闊的二階天地（Tier 2）。\n");
    set_weight(50);
    set_value(10000);
    set("is_relic_compass", 1);
    set("compass_direction", "north_mountains");
}
