#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name(HIB + "千獸魂" + NOR,({"ghost lance","lance"}));
           set_weight(8000);
           if( clonep() )
                   set_default_object(__FILE__);
           else {
                   set("unit", "把 ");
           set("long","這是十幾年前某個村莊,因為要消滅千年血妖,而集結千頭野獸
          的魂魄,所鑄成的魔槍 .\n");
                   set("value",30000);
                   set("material", "gem");
           set("wield_msg", "$N拿起了$n,身邊頓時充滿了妖氣。 .\n");
           set("unwield_msg", "$N將$n收了起來,$n頓時妖氣消失無形。.\n");
           }
           init_lance(80);
           setup();
           }






