#include <weapon.h>
inherit ITEM;
void create()
{
set_name("獨孤嵊",({"degu sa","sa"}));
set("unit","位");
set("long", @LONG

這位是『武天至聖』獨孤嵊，二十年前，自負去挑戰莫無愁，最後被
魔龍訣所敗並鎖在地牢中，且用魔刀所發展出的『魔血骨鍊』，鎖其筋骨。
LONG
);
set("no_get",1);
set("no_sac",1);         
setup();
}
