// blade.c
#include <weapon.h>
#include <ansi.h>
inherit BLADE;

int damage_down( object me , int power )
{
	message_vision("附在$N身上的幽靈魔力消失了。\n",me);
	me->add_temp("apply/damage",-power);
	delete("in_using");
	return 1;
}
void create()
{
	set_name(HIB"幽靈魔刀"NOR,({"ghost blade","blade"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
     set ("unit","柄");
          set("value", 10000);
		set("material", "iron");
	set("long","這是一把傳說中的魔刀﹐相傳只要在戰鬥中使用(use)﹐就能產生怨靈魔氣。\n");
	set("no_drop",1);
	set("no_give",1);
          set("wield_msg", "$N裝備$n。\n");
		set("unequip_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
          set("armor_prop/blade",10);
	init_blade(60);
	setup();
}
void init()
{
	add_action("do_use","use");
}
int do_use( string arg )
{
	object me = this_player() , ob = this_object();
	int power;
	if( !arg || arg != "blade" ) return 0;
	if( query("in_using") ) return notify_fail("你已經在用了。\n");
	if( !this_player()->is_fighting() )
		return notify_fail("這把刀必須在戰鬥中才能使用。\n");
	if( me->query("force") < 100 )
		return notify_fail("你的內力不夠。\n");
	message_vision( HIB + @LONG
$N將幽靈魔刀向著天空一舉～～～～～～～
頓時一陣狂風捲沙、山崩地搖 .......
只見數十道幽靈的影子聚集在魔刀之上～～～
LONG + NOR,me);
	power = me->query("force") / 20;
	me->add_temp("apply/damage", power );
	me->add("force",-100);
	set("in_using",1);
	call_out("damage_down",30,me,power);
	return 1;
}
int query_autoload() { return 1; }
