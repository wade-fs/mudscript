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
           set_name(na+"的龍骨聖刀",({"dragon-bone blade","blade"}));
        else
         { set_name("龍骨聖刀",({"dragon-bone blade","blade"})); }
        seteuid(getuid());
        set_weight(25000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long",@LONG

	龍骨聖刀, 乃當世十八神兵之一, 刀柄上所鑲的三個 
	寶石更是燦爛耀眼, 只見刀上隱隱透出霸王之氣, 真
	是另人愛不釋手!!拿在手上就如同一代梟雄一般, 威
	風八面!!

LONG);
        set("value",12000);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_auc",1);
        set("material", "iron");
//       set("wield_msg", "$N從刀鞘將$n拔出來之後，火光四溢。\n");
//      set("unwield_msg", "$N用衣服將$n包了起來，其紅色的豪光被布包給遮蔽了。\n");
        }
        init_blade(115);
        setup();
}               
int query_autoload() { return 1; }

      
