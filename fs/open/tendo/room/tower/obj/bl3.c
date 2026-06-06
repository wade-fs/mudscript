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
           set_name(na+"ソ狂刀",({"blade"}));
        else
         { set_name("狂刀",({"blade"})); }
        seteuid(getuid());
        set_weight(6000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

        一把鐵製的大刀, 鑄刀師傅在鑄造的過程中加入了白銀
        提高了此刀的硬度, 密度與強度!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "silver");
        set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
        }
        init_blade(75);
}
int query_autoload() { return 1; }



