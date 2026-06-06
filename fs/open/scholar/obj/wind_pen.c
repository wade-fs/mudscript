
#include <ansi.h>
#include <weapon.h>
inherit STABBER;
object user;
void create()
{
     set_name("落風之筆",({"wind-pen","pen"}));
     set_weight(1000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {

set("long","筆上刻有君子風真氣運用之法，區需配合此筆方能使用\n");
            set("unit", "件");             
            set("value",10000);
            set("no_sell", 1);
            set("no_drop", 1);
            set("no_auc", 1);
            set("no_put",1);
            set("material","blacksteal");
           }         
        init_stabber(95);
        setup();
}

