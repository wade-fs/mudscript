#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name(HIW "千丈雪" NOR,({"meter-snow","snow"}));
           set_weight(6000);
           if( clonep() )
     set_default_object(__FILE__);
           else {
                   set("unit", "把");
           set("long","這一把槍相傳是由一位住在天山的鐵匠,用天山寒冰所打造出
           來的 .\n");
                   set("value",20000);
                   set("material", "gem");
           set("wield_msg", "$N拿起了$n,霎時全身一陣寒冰隴照你全身。 .\n");
           set("unwield_msg", "$N你將$n收入槍套中,$n霎時寒冰慢慢消退而去。.\n");
           }
           init_lance(80);
           setup();
           }






