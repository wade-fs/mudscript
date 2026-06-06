#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
int b;
void create()
{
        set_name("巴斯八",({"World King","king"}));
        set("long",@LONG
萬世魔教的教主，其武功魔法出自於萬變寶籙，亦為世上絕頂魔功之一，
齊創立的萬世魔教和孫虎臣暗中把持朝政，然而巴斯八卻又身兼蒙古國師
之職，可說一舉一動皆牽動天下命脈。

LONG);
	set("gender","男性");
	set("class","dancer");
	set("nickname",HIG + "萬世魔王" + NOR);
	set("title",HIM + "萬世教主" + NOR);
	set("family/family_name","夜夢小築");
	set("combat_exp",9000000);
	set("attitude","aggressive");
	set("score",1000000);
	set("bellicosity",3000);
	set("age",50);
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
	set("atman",999999);
	set("max_atman",20000);
	set("force_factor", 35);
	set("max_kee",50000);
	set("max_gin",50000);
	set("max_sen",50000);
	set_skill("unarmed",120);
	set_skill("dreamforce",250);
	set_skill("dreamdance",120);
	set_skill("paull-steps",120);
	set_skill("dremagic",100);
	set_skill("move",120);
	set_skill("dodge",120);
	set_skill("magic",120);
	set_skill("parry",120);
	set_skill("force",250);
	map_skill("magic","dremagic");
	map_skill("dodge","paull-steps");
	map_skill("force","dreamforce");
	map_skill("move","paull-steps");
	map_skill("unarmed","dreamdance");
	set("spells/confuse/level",100);
	set("spells/fireball/level",100);
	set("spells/thunder/level",100);
	set("spells/fdragon/level",100);
	set("spells/firedance/level",100);
	set("spells/dreamwings/level",100);
	set("spells/hellfire/level",100);
	set("spells/dreamcure/level",100);
	set("spells/meteor/level",100);
	set("functions/rainbow-steps/level",100);
	set("chat_chance_combat",50);
	set("allow_hellfire",1);
	set("allow_fdragon",1);
	set("allow_meteor",1);
	set("get_dan_sp",1);
	set("adv_dancer",1);
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
	carry_object("/open/magic-manor/obj/fire-color-ribbon");

}

int accept_kill(object ob)
{
	kill_ob(ob);
	command("wield all");
	command("conjure thunder");
	command("conjure fireball");
	command("conjure firedance");
	command("conjure fdragon");
	command("conjure hellfire");
	return 1;

}

void greeting(object ob)
{
	ob=this_player();
        set_heart_beat(1);
	return;
}

void heart_beat()
{
	object who=this_player(),me=this_object();
        object mob;
        if(!environment()) {
          set_heart_beat(0);
          return ;
        }
        if(me->is_fighting() && !present("False King"))
        {
          message_vision(HIR + "
          
          巴斯八吼道:『選擇你的命運吧!!』
          " + HIY + "
          
          只見巴斯八一化為二，二化為四，再化為八，
          
          剎那間竟有八個一模一樣的巴斯八將你包圍起來。
          
                                           \n" + NOR,who);
          for(b=0;b<7;b++)
	  {
	   mob=new("/open/magic_palace/npc/4-2f.c");
           mob->move(environment(this_player()));
           mob->invocation(this_player());
          }
        }
	if( !me->query_temp("weapon") )
	{
	command("wield all");
	command("wear all");
	}
	if( !me->is_busy() && who->is_busy() )
	{
	command("conjure thunder");
	command("conjure fireball");
	command("conjure");
	}
	if( !me->is_busy() && !who->is_busy() )
	{
	command("conjure thunder");
	command("conjure fireball");
	command("conjure hellfire");
        
	}
	if(!me->query_temp("mana_shield") )
	{
	command("conjure dreamwings");
	}
	if( !me->is_fighting() && !me->query_temp("ranbow-steps") )
	{
	command("perform dodge.rainbow-steps");
	}
	if( me->is_fighting() && !me->query_temp("ranbow-steps") && !me->is_busy() )
	{
	command("perform dodge.ranbow-steps");
	}
	if( !is_fighting() ) 
	{
	  if( query("force") < 20000 )
	  command("ex 270");
	  if( query("atman") < 20000 )
	  command("res 300");
	  if( query("eff_kee") < query("max_kee") )
	  command("conjure dreamcure");
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
	}
	::heart_beat();
}

void unconcious()
{
	object me,obj,winner;
	me=this_object();
	winner=query_temp("last_damage_from");

	if(!winner || !userp(winner))
	{
    mapping map;
    obj = new("/open/magic_palace/npc/4-2.c");
    obj->move("/open/magic_palace/room/room35");
	//new("/open/magic_palace/npc/4-2.c")->move("/open/magic_palace/room/room35");
    map = allocate_mapping(1);
    map["/open/magic_palace/npc/4-2.c"] = obj;
    environment(this_object())->set_temp("objects",map);
	::die();
	return ;
	}else{
        message_vision(HIR + "
        
巴斯八吼道:『輸給魔界金典以外的武功，我不甘心啊!!』

" + HIW + "萬變寶籙最後一擊發動:" + HIY + "

   ----------------------------     命   運   歸   一    ----------------------------
                    
           " + HIG + "無數幻影回歸巴斯八身上，作出瀕死一擊，將$N送往不知名的世界。
                    
        \n\n" + NOR,winner);
	winner->move("/open/magic_palace/room/room36.c");
        winner->unconcious();
        COMBAT_D->report_status(winner);
	     }

tell_object(users(),HIR + "\n\n

西方天空突然多出一顆火紅的太陽......

              \n\n" + NOR);

	destruct(me);
}

