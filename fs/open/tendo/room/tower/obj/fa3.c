#include <weapon.h>
#include <ansi.h>

inherit STABBER;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"ソ銀扇",({"fan"}));
        else
         { set_name("銀扇",({"fan"})); }
        seteuid(getuid());
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

        上古神秘兵器之一的～～銀扇～～!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "silver");
        set("wield_msg", "$N從懷中掏出一把$n拿在手中。\n");
        }
       init_stabber(60);
        setup();
}
int query_autoload() { return 1; }


