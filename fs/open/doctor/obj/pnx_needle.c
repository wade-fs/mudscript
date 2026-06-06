// pnx_needle.c by nike
#include <weapon.h>
#include <ansi.h>
inherit STABBER;
void create()
{
        set_name(HIW"ξ"HIR"赤焰"HIW"ξ"HIY"鳳羽針"NOR, ({"pnx_needle", "needle"}) );
        set_weight(3000);
        if( clonep() )
        set_default_object(__FILE__);
        else
         {
        set("unit", "柄");
        set("no_put",1);
        set("no_get",1);
        set("no_auc",1);
        set("no_drop",1);
        set("no_give",1);
        set("no_sell",1);
        set("material", "steel");
        set("wield_msg", "$N雙手緊緊握起$n，一陣火光閃熾在$N的周圍...\n");
        set("unwield_msg", "$N慢慢放下手中的$n，閃熾的火光也隨之漸漸消逝...\n");
        set("long","此把針是由「火鳳凰」的尾羽所煉化而成的神兵！\n");
        set("value", 1000000);
         }
        init_stabber(120);
        setup();
}



