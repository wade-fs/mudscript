#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name(HIB + "天" + HIC + "水" + HIW + "一字戢" + NOR,({"sky-water-lance"}));
           set_weight(9000);
           if( clonep() )
                   set_default_object(__FILE__);
           else {
           set("unit","把");
           set("long","海之王者所配帶的神矛。\n");
           set("value",900000);
           set("material", "crimsonsteel");
           set("no_save",1);
           set("no_drop",1);
           set("no_auc",1);
           set("no_sell",1);
           set("no_sac",1);
           set("no_give",1);
           set("no_get",1);
           set("no_put",1);
           set("no_steal",1);
                }
           init_lance(99);
           setup();
           }






