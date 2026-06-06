#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
int i;
void create()
{
        set_name("完顏烈火",({"Nine Dragon","dragon"}));
        set("long",@LONG
漢江神秘組織『水中寨』的寨主，不但武功霸道強橫，兵法智慧
更是無懈可擊。其擅長武功\有兩套，一為攻守兼備的霸王金身及
破綻之拳，令一套則是尚未面世的蒼老之拳及返老還童不死功\。

LONG);
	set("gender","男性");
	set("class","killer");
	set("nickname",HIB + "九魔龍" + NOR);
	set("title",HIC + "水中寨寨主" + NOR);
	set("family/family_name","黑牙聯");
	set("combat_exp",10000000);
	set("attitude","friendly");
	set("score",1000000);
	set("bellicosity",20000);
	set("age",80);

	set("str", 35);
	set("cor", 35);
	set("cps", 35);
	set("int", 35);
	set("spi", 35);
	set("per", 35);
	set("kar", 35);
	set("con", 35);
	set("force",20000);
	set("max_force",20000);
	set("mana",20000);
	set("max_mana",20000);
	set("atman",20000);
	set("max_atman",20000);
	set("force_factor", 40);
	set("max_kee",50000);
	set("max_gin",50000);
	set("max_sen",50000);
	set_skill("blackforce", 250);
	set_skill("fireforce",250);
	set_skill("dodge", 120);
	set_skill("force",250);
	set_skill("move", 120);
	set_skill("literate",120);
	set_skill("parry", 120);
	set_skill("throwing",120);
	set_skill("shadow-kill",100);
	set_skill("unarmed",120);
	set_skill("dagger",120);
	set_skill("literate",120);
	set_skill("shade-steps",120);
	set_skill("rain-throwing",120);
	set_skill("fireforce",250);
	map_skill("force","blackforce");
	map_skill("dodge","shade-steps");
	map_skill("move","shade-steps");
	map_skill("parry","rain-throwing");
	map_skill("throwing","rain-throwing");
	map_skill("dagger","shadow-kill");
	set("functions/mobkee/level",150);
	set("functions/manakee/level",150);
	set("functions/gold-fire/level",100);
	set("quests/sunfire",1);
	set("quest/gold-fire",1);
	set("quest/new_gold_fire",1);
	set("quest/island",3);
	set("can_use_mobkee",1);
	set("quest/rain",1);
	set("quest/worldpill",1);
	set("clan_kill",1);
	set("no_hole",1);
	set("no_plan_follow",1);
	set("no_mount",1);
	set_temp("armor_vs_force",300);
	set_temp("apply/armor",150);
	set_temp("apply/attack",50);
	set_temp("apply/damage",50);
	setup();
	add_money("cash",300);
	carry_object("/open/magic-manor/obj/dark-soul-dagger");
	carry_object("/autoload/mblade/mring");
}

int accept_kill(object ob)
{
	object me=this_object();
	kill_ob(ob);
	me->delete_temp("is_busy");
	command("wear all");
	command("wield all");
	return 1;

}

void greeting(object ob)
{
	object me = this_object();
	if(!me->is_fighting())
	{
	message_vision(HIW + "完顏烈火運起極火金身秘極封印式「" + HIR + "霸" + HIM + "王" + HIY + "金" + HIC + "身" + HIW + "」，全身透散出耀眼的虹光！\n" + NOR,this_player());
        (int)me->add_temp("apply/parry",10);
        (int)me->add_temp("apply/dodge",10);
	}
	set_heart_beat(1);
	return;
}

void heart_beat()
{
	object me = this_object();
        object *user = all_inventory( environment(me));
        if(!me->is_busy() && random(3) == 1 && me->is_fighting())
        {
            message_vision(HIC + "
            完顏烈火的破綻是那麼的誘人，因此$N毫不猶豫的就展開
            大開大闔的猛攻，啟料這一切皆全都是完顏烈火的誘敵之計，只
            見他霸王金身全力爆發，硬生生震退$N的攻勢，藉著更以
            損耗生命的蒼老之拳硬撼$N。
            
 " + GRN + "▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂▂" + NOR + "
 " + YEL + "████████████████████████████████████████████████████████████" + NOR + "
 " + HIY + "████████████████████████████████████████████████████████████" + NOR + "
 " + HIY + "████████████████████████████████████████████████████████████" + NOR + "
 " + HIY + "████████████████████████████████████████████████████████████" + NOR + "
 " + HIR + "████████████████████████████████████████████████████████████" + NOR + "
 " + HIY + "████████████████████████████████████████████████████████████" + NOR + "
 " + HIY + "████████████████████████████████████████████████████████████" + NOR + "
 " + HIY + "████████████████████████████████████████████████████████████" + NOR + "
 " + YEL + "████████████████████████████████████████████████████████████" + BLK + "
 " + BGRN + "▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆▆\n\n\n" + NOR,this_player());


            for( i=0; i<sizeof(user); i++ )
            {
            if(userp(user[i]))
            {
            user[i]->receive_damage("kee",1800);
            }else{
            user[i]->receive_damage("kee",500);
                 }
            COMBAT_D->report_status(user[i]);
            }
        }

	if( !me->query_temp("weapon") )
	{
	command("wield all");
	command("wear all");
	}

	if( !me->is_fighting() && !me->query_temp("gold-fire") )
	{
	map_skill("force", "fireforce");
	command("perform force.gold-fire");
	map_skill("force", "sunforce");
	}

	if( !is_fighting() ) 
	{
	  if( query("force") < 20000 )
	  command( "ex 270" );
	  if( query("eff_kee") < query("max_kee") )
	  { 
	  map_skill("force", "fireforce");
	  command( "10 exert heal" );
	  map_skill("force", "sunforce");
	  }
	  if( query("gin") < query("eff_gin") )
	  {
	  me->receive_curing("gin",150);
	  me->receive_heal("gin",150);
	  }
	  if( query("kee") < query("eff_kee") )
	  command( "5 exert recover" );
	  if( query("sen") < query("eff_sen") )
	  {
	  me->receive_curing("sen",150);
	  me->receive_heal("sen",150);
	  }
	  if( !me->query("bellup") )
	  {
	  command("cmd bellup");
	  }
	}


    set_heart_beat(1);
	::heart_beat();
}

void unconcious ()
{
	object me,obj,winner;
	me=this_object();
	winner=query_temp("last_damage_from");

	if(!winner || !userp(winner))
	{
	new("/open/magic_palace/npc/4-1.c")->move("/open/magic_palace/room/room34");
	::die();
	return ;
	}else{
        message_vision(HIR + "
        
完顏烈火嘆道:『不想今日命喪於此，莫非天意註定我無法成皇，我偏要逆天而行啊!!』

" + HIY + "九魔龍突然暴起強運返老還童不死功\吸取$N的功\力，

接著以迴光返照之力擊出秘極禁用之" + HIC + "


         --------------           蒼     老     之    拳           --------------

                    
" + HIG + "磅的一聲巨響，$N如斷線風箏般遠遠飛了出去...
                    
        \n\n" + NOR,winner);
	winner->move("/open/magic_palace/room/room36.c");
        COMBAT_D->report_status(winner);
	winner->unconcious();
	     }
        destruct(me);
}
