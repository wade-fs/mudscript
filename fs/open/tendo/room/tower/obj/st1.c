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
           set_name(na+"ソ太極棍",({"stick"}));
        else
         { set_name("太極棍",({"stick"})); }
        seteuid(getuid());
        set_weight(8000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

        太極棍是一兩端刻有太極圖樣的六尺大銅棍!!揮舞起來
        有如一團的黃光, 可以盡數擋住敵人的攻擊!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
        set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
        }
        init_stick(50);
        setup();
}

int query_autoload() { return 1; }



