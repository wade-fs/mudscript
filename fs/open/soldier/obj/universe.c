#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name("六合乾坤槍",({"universe_lance","lance"}));
           set_weight(2000);
           if( clonep() )
                   set_default_object(__FILE__);
           else {
                   set("unit", "把");
           set("long","這是一把輕巧無比的神兵利器.\n");
                   set("value",40000);
                   set("material", "gold");
           set("wield_msg", "$N身子一側$n瞬間飛出,你握起了$n幾乎感覺不出它的
            重量。 .\n");
           set("unwield_msg", "$N將$n向天空拋去,霎時$n消失無蹤.\n");
           }
           init_lance(60);
           setup();
           }






