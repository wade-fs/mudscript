#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"的寬刃劍",({"wide sword","sword"}));
        else
         { set_name("寬刃劍",({"wide sword","sword"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

	一把精製的長劍, 鑄劍師傅以其精湛的手藝將劍刃的兩側
	打薄, 藉以提高此劍的斬切能力!!是一把不可多得的好劍!!

	
LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
//      set("wield_msg", "$N從刀鞘將$n拔出來之後，寒光四射。\n");
//      set("unwield_msg", "$N用衣服將$n包了起來，其紅色的豪光被布包給遮蔽了。\n");
        }
        init_sword(40);
        setup();
}               
int query_autoload() { return 1; }

      
