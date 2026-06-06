#include <weapon.h>
#include <ansi.h>
inherit STABBER;
void create()
{
        object me=this_player();
        set_name(HIB"玄鐵仗"NOR, ({"havey-staff", "staff"}) );
        set_weight(20000);
        if( clonep() )
         set_default_object(__FILE__);
        else
         {
          set("unit", "把");
          set("long","一柄十分沈重的鐵仗, 上面透出隱隱血光。\n");
        set("wield_msg", HIR"$N將$n"HIR"握在手上，全身頓時充滿了邪惡的力量。\n"NOR);
          set("value", 30000);
          set("material", "crimsonsteel");
         }
        init_stabber(120);
        setup();
}

