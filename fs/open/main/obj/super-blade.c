// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(RED + "風林火山" + NOR, ({ "nature blade","blade" }) );
	set_weight(24000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
         set("no_sale",1);
		set("material", "steel");
		set("long", @LONG
這把刀看起來像是一把平凡無奇的木刀,但在刀身上可以隱隱約約的看出
「風林火山」四個小字,難道這就是傳說中的遠古神器？
LONG);
		set("wield_msg", "\
$N口中喃喃念著$n刀背上的咒語,瞬間天地變色! $n從$N背後的刀鞘中\n\
衝向天際吸取刀氣,在空中迴旋了幾圈後慢慢的降在$N的手中,並且發出黯黯的紅光。\n");
		set("unwield_msg", "\
$N將$n往空中拋去,$n在空中釋放刀氣後伴隨著\n\
一陣強光,咻~~~一聲$n回到$N背後的刀鞘中。\n");
	}
	init_blade(100);
   
        set("ski_type1","blade");
         set("ski_level1",100);
	setup();
}

