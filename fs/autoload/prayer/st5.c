#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"的[31m責殺棍[0m",({"kill stick","stick"}));
        else
         { set_name("[31m責殺棍[0m",({"kill stick","stick"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

	上古神秘兵器之一的～～[31m責殺棍[0m～～!! 
	
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
        init_stick(60);
        setup();
}               

int query_autoload() { return 1; }
      
