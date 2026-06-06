#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name("龍擊",({"dragon hit","hit"}));
           set_weight(7500);
           if( clonep() )
                   set_default_object(__FILE__);
           else {
    set("unit","把");
           set("long","這是把由黃金甲龍身上麟片,所製成的戰矛\n");
                   set("value",70000);
                   set("material", "gold");
           set("wield_msg", "$N你從長銷中取出了$n,身上有一股甲龍之氣灌入體內
           ,你力量提升不少。\n");
           set("unwield_msg", "$N將$n插入銷中,甲龍之瞬間氣消失無蹤。\n");
           }
           init_lance(70);
           setup();
           }






