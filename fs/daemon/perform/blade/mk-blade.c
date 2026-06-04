// 靈刀 by swy, 精簡 by babe
// 改版 by frequency 
#include <ansi.h>
#include <carry.h>

inherit F_FUNCTION;

int perform( object me )
{
	int	damage;
	object	ob;

seteuid(getuid());
	damage	= me->query_skill("blade");

	if( me->query("class") != "blademan" )
		return notify_fail( "此術只限刀客使用。\n");
	if( !me->query("mk-blade") )
		return notify_fail( "無此能力使用特攻。\n" );
	if( me->query("combat_exp") < 5000000 )
		return notify_fail( "江湖歷練不足。\n" );
	if( me->query("max_force") < 4000 )
		return notify_fail( "內力不足。\n" );
	if( me->query("force") < 3500 )
		return notify_fail( "真氣不足。\n" );
	if( me->query("bellicosity") < 25 )
		return notify_fail( "殺氣不足。\n" );
	if( me->query("potential") - me->query("learned_points") < 60 )
		return notify_fail( "潛能不足。\n" );
  if( sizeof(all_inventory(me))  >= MAX_CARRY ) return notify_fail("你身上的東西太多了。\n");
	if( me->query_temp("del")==1 && !wizardp(me) )
		return notify_fail( "真氣不足, 請休息一會兒。\n" );
	if( damage > 350 )
		damage = 350;
        if(me->query("family/family_name") == "金刀門")
        {
        ob = new("/daemon/class/blademan/obj/fblade.c");
        ob->set_name( GRN + "柳" + HIG + "葉" + HIC + "霸" + HIB + "刀" + NOR, ({ "mk-blade" }) );
	ob->set( "weapon_prop/damage", damage );
	ob->move(me);
	message_vision( HIY + "$N大喝一聲:" + HIR + "『"BLINK"" + HIG + "聚葉成刀" + NOR + "" + HIR + "』" + HIY + "只見$N的殺意催動四周空氣，捲起一陣強大的暴風。\n", me );
	message_vision( HIC + "暴風到處，柳葉紛紛飄落，往$N的手上聚集，頓時一把由柳葉所形成的刀已匯聚而成。\n" + NOR, me );
        me->add( "force", -3000 );
        me->add( "potential", -50 );
	me->add( "bellicosity", -20 );
	me->set_temp( "del", 1 );
        call_out( "del", me->query("functions/leaf-blade/level")+20, me );
        }else{
             ob = new("/daemon/class/blademan/obj/mkblade.c");
             ob->set_name( HIM + "魄邪" + HIC + "魂冰" + NOR, ({ "mk-blade" }) );
	     ob->set( "weapon_prop/damage", damage );
	     ob->move(me);
	     message_vision( HIY + "$N大喝一聲:『"BLINK"" + HIG + "邪靈制刀術" + NOR + "" + HIY + "』\n" + BLU + "只見陰風徐徐, 無數的陰靈從地表竄出。\n", me );
	     message_vision( MAG + "$N運起真氣, 配合體內的殺氣, 運勁往手掌一送, 無數陰靈往$N的手上聚集。\n", me );
	     message_vision( HIW + "頓時一把由陰靈所匯成的刀已在$N手上。\n" + NOR, me );
             me->add( "force", -3000 );
             me->add( "potential", -50 );
	     me->add( "bellicosity", -20 );
	     me->set_temp( "del", 1 );
	     call_out( "del", me->query("functions/mk-blade/level")+20, me );
        }
	return 1;
}

int del( object me )
{
	if( !me )
		return 0;
	me->delete_temp("del");
	if(me->query("family/family_name") == "金刀門")
	{
	  if( me->query("functions/leaf-blade/level") < 100 )
	  function_improved( "leaf-blade", random(1000) );	
	}else{
        	if( me->query("functions/mk-blade/level") < 100 )
		function_improved( "mk-blade", random(1000) );
	     }
	return 1;
}
