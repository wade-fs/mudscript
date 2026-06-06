#include <ansi.h>
inherit ITEM;
void create()
{
      set_name(HIR"獨孤嵊的人頭"NOR, ({ "sa-head","head" }));
        set_weight(5000);
        set("feed",1); //可以餵馬
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "個");
        set("long","武天至聖『獨孤嵊』的人頭。\n");
        set("value", 0);
        //set("no_put",1);
        //set("no_drop",1);
        }
}

