#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name(HIW + "方天化戟" + NOR,({"Godmelt-lance","lance"}));
           set_weight(8000);    
           if( clonep() )
                   set_default_object(__FILE__);
           else {
                   set("unit","隻");
 set("long","這是一把身長八尺極俱威風八面的槍.\n");
                   set("value",50000);
                   set("material", "silver");
           set("wield_msg", "$N拿起$n,嘴巴不自覺的喊: 雄....壯....威....武...
           $N突然間覺的信心大增。.\n");
           set("unwield_msg", "$N放下$n,你那股自信漸漸消失了。.\n");
           }
   init_lance(90);
           setup();
           }






