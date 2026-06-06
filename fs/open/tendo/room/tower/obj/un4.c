#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        string na;
        object me;
        me = this_player();
        na = (me->name(0));

        if (me)
           set_name(na+"ソ黃金指環",({"ring"}));
        else
         { set_name("黃金指環",({"ring"})); }
        seteuid(getuid());
        set_weight(5000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

        上古神秘兵器之一的～～黃金指環～～!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "gold");
        set("wield_msg", "$N戴上$n，霎時間你覺得力量提升了數倍。\n");
        }
        init_unarmed(65);
        setup();
}
int query_autoload() { return 1; }

