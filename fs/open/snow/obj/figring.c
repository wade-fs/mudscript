#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
        set_name(HIC "金鋼指環" NOR,({"figring"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
        set("long","這是一只以金鋼石所製成的指環，可以提升空手的傷害力．\n");
                set("sharp",8);

                set("value",10000);
                set("material", "steel");
        set("wield_msg", "$N戴上$n，霎時間$N覺得力量提升了數倍  \n");
        set("unwield_msg", "$N將手上的$n卸了下來 。\n");
        }
	init_unarmed(45);
set("need_exp",900000);    // by frequency
        setup();
}
int wield()  //fix by frequency
{
 if(!this_player()) return 1;
            if( this_player()->query_skill("unarmed",1) < 101 )
            return notify_fail("你的力量還未夠班，無法自在使用。\n");
            if( this_player()->query("combat_exp") < 900000 )
            return notify_fail("哈！鬼才相信你轟得下劉全書。\n");
  ::wield();
 return 1;
}
