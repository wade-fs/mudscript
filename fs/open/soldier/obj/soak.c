#include <weapon.h>                           
#include <ansi.h>

inherit LANCE;
void create()
{           
           seteuid(getuid());
           set_name("雨不沾",({"rainno-soak","soak","rainno"}));
           set_weight(5000);
           if( clonep() )
                   set_default_object(__FILE__);
           else {
                   set("unit", "把");
           set("long","這是皮古在一個風雨大作,雷電交加的夜晚,所打造而成的長槍 .\n");
                   set("value",10000);
                   set("material", "blacksteel");
           set("wield_msg", "$N手中握起$n,忽然雷雨大作,突然你覺得$n是一個不可多
           得的好兵器 。 .\n");
           set("unwield_msg", "$N將$n收了起來,$N感覺$n絲毫沒有半滴血留在上面。.\n");
           }
           init_lance(75);
           setup();
           }






