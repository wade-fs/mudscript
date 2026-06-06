// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
	set_name(RED "風林火山" NOR, ({ "nature blade","blade" }) );
	set_weight(24000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value",6000000);
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
        set("ski_type2","spell");
        set("ski_level1",80);
        set("ski_level2",85);
	setup();
}

int wield()
{
  object ob;
  ob=this_player();
  message_vision(HIY"上古兵器「風林火山」受法主"+ob->name()+"的咒術招喚.....\n\n"
		"飛往空中吸收大地靈氣,你可以看到一陣陣的絢麗耀眼\n\n"
                "的五彩光芒從四面八方飛往東方,宛如流星趕月一般的\n\n"
                "的消失在你的眼前。......\n\n"NOR,ob);
  ob->add("mana",-100);
  ::wield();
  return 1;
}
