#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void bleed(object me, object victim, object weapon, int damage);
void block(object me, object victim, object  weapon, int damage);
mapping *action = ({
([ "action":"$N使出『雨流狂落斬』握著手中的$w全力衝去.隨即身形一變,向前方斬了
數十刀",
	"dodge": 40,
	"parry": -50,
	"damage":210,
	"damage_type":"刀傷",
	"post_action" : (: call_other, __FILE__, "block" :),
]),
(["action":"$N使出『五月花斬』,整個身子急速的旋轉,手中的$w順勢化為一刀芒向前斬
去",
	"dodge": 50,

	"parry":-40,
	"damage":180,
	"damage_type":"刀傷",
	"post_action" : (: call_other, __FILE__, "bleed" :),
]),
});
void create()
{
	set_name(HIW + "" + NOR+WHT + "W" + NOR+HIW + "" + NOR+WHT + "M" + NOR+HIW + "" + NOR+WHT + "" + NOR+HIW + "" + NOR+WHT + "B" + NOR,({"blade"}) );

        set_weight(10000);
        if( clonep() )
		set_default_object(__FILE__);
	else{
		set("unit", "柄");
		set("long","
村雨是從源氏時代即流傳下來的名刀，是稱霸關東者的證明。相傳其『刀一
出鞘，連露珠都會滴下。』\n");

		set("value", 2000);
		set("material", "blacksteel");
		set("wield_msg","
$N緩緩地將$n從鞘中拔出，感到四周圍的空氣似乎因此而凝結了。\n");

		set("unwield_msg", "
$N將$n歸還刀鞘。\n");

		init_blade(80, SECONDARY);
		set("actions", (: __FILE__, "query_action" :) );
 
		setup();
}
}
mapping query_action()
{
	return action[random(sizeof(action))];
}
void block(object me,object victim,object weapon,int damage)
{
	if(damage > 180)
{
	victim->start_busy( random((int)me->query_skill("blade", 1)/100 + 1 ));
	message_vision(HIW + "名刀  村雨的刀身上氾來陣陣刀芒，光芒刺得$n的眼睛睜不開來，使得$n呆立原地，動彈不得!\n" + NOR,me,victim);
}
}

void bleed(object me,object victim,object weapon,int damage)
{
	int cond;
	if(damage> 200)
{
	cond = victim->query_condition("bleeding");
	cond += random(me->query_skill("sword", 1)/100 );
	victim->apply_condition("bleeding", cond);
	message_vision(HIW + "名刀  村雨的刀鋒劃破了$n的皮膚，使得$n大量失血，無法止住!\n" + NOR,me,victim);
}
}
