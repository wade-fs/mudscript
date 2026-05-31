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
           set_name(na+"的[31m火燄刀[0m",({"fire blade","blade"}));
        else
         { set_name("[31m火燄刀[0m",({"fire blade","blade"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

	一把紅光靄靄的大刀, 鑄刀師傅以其精湛的手藝將刀鑄造
	成具有火燄的熱度, 藉以提高此刀的傷害力!!是一把不可
	多得的好刀!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
        set("wield_msg", "[36m$N從刀鞘將$n拔出來之後，[31m火光四溢[0m。\n");
        set("unwield_msg", "[36m$N用衣服將$n包了起來，其[31m紅色的豪光[36m被布包給遮蔽了[0m。\n");
        }
        init_blade(85);
        setup();
}               
int query_autoload() { return 1; }

      
