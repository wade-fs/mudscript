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
           set_name(na+"的長老之杖",({"elder stick","stick"}));
        else
         { set_name("長老之杖",({"elder stick","stick"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

	上古神秘兵器之一的～～長老之杖～～!! 
	
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
        init_stick(55);
        setup();
}               
int query_autoload() { return 1; }

      
