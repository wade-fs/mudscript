#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"的龍牙鑲金刀",({"dragon-tooth blade","blade"}));
        else
         { set_name("龍牙鑲金刀",({"dragon-tooth blade","blade"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

	一把鐵製的大刀, 鑄刀師傅在鑄造的過程中加入了黃金 
	提高了此刀的硬度, 密度與強度!!並且在刀的兩側加上
	了龍牙做為增加殺傷力的利器!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
//        set("wield_msg", "$N從刀鞘將$n拔出來之後，火光四溢。\n");
        }
        init_blade(90);
        setup();
}               
int query_autoload() { return 1; }

      
