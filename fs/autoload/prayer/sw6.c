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
           set_name(na+"的[32m正宗劍[0m",({"master sword","sword"}));
        else
         { set_name("[32m正宗劍[0m",({"master sword","sword"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

	上古神秘兵器之一的～～[32m正宗劍[0m～～!!劍的本身
	具有知性, 是一把會選擇持有者的黑暗劍!! 
	
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
        init_sword(65);
        setup();
}               

int query_autoload() { return 1; }
      
