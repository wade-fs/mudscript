#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;
int special_att ();

void create()
{
     set_name("鎮塔明王",({"tower king","king"}));
     set("title",HIW + "天界之神" + NOR);
     set("long","他奉命下凡鎮守鎖妖塔.........\n");
     set("gender","男性");
     set("class","taoist");
     set("family/family_name","天道派");
     set("age",1200);
     set("str",70);
     set("kar",70);
     set("per",50);
     set("cps",70);
     set("cor",70);
     set("combat_exp",35000000);
     set("spi",70);
     set("int",70);
     set("max_s_kee",100);
     set("s_kee",100);
     set("sec_kee","tiger");
     set("max_kee",180000);
     set("kee",180000);
     set("max_sen",80000);
     set("sen",80000);
     set("max_gin",80000);
     set("gin",80000);
     set("max_force",25000);
     set("force",25000);
     set("max_mana",25000);
     set("mana",25000);
     set("max_atman",25000);
     set("atman",25000);

     set_skill("cure",90);
     set_skill("taoism",100);
     map_skill("cure","taoism");
     set_skill("force",180);
     set_skill("fiendforce",180);
     set_skill("gforce",180);
     map_skill("force","gforce");
     set_skill("dodge",120);
     set_skill("g-steps",120);
     map_skill("dodge","g-steps");
     set_skill("magic",100);
     set_skill("gmagic",100);
     map_skill("magic","gmagic");
     set_skill("whip",120);
     set_skill("gwhip",120);
     map_skill("whip","gwhip");
     set_skill("parry",120);
     map_skill("parry","gwhip");
     set_skill("spells",100);
     set_skill("necromancy",100);
     map_skill("spells","necromancy");

     set("spells/feeblebolt/level",100);
     set("spells/missible/level",100);
     set("spells/hardshell/level",100);
     set("spells/invocation/level",100);
     set("spells/godfight/level",100);
     set("spells/stopmove/level",1);
     set("spells/manabody/level",1);
     set("spells/stopmove/level",1);
     set("spells/lightfire/level",1);
     set("spells/flee/level",60);
     set("spells/manabody/level",1);

     set("force_factor",25);
     set("chat_chance_combat",70);
     set("chat_msg_combat", ({
     (: special_att :),}));

     set("functions/fight/level",120);

     set("quest/have_hawk",1);
     set("clan_kill",1);
     set("no_hole",1);
     set("no_plan_follow",1);
     set("no_mount",1);
     set("adv_taoist",1);
     set("marks/god-kee",1);

     set_temp("armor_vs_force",300);
     set_temp("no_die_soon",1);
     set_temp("rob",1); 
     set_temp("no-plan",1);
     set_temp("mount",1);
     set_temp("follow",1);
     set_temp("speed",1);
     set_temp("empty",1);
     set_temp("false",1);
     set_temp("roared",1);
     
     set_temp("apply/armor",150);
     set_temp("apply/attack",150);
     set_temp("apply/damage",150);
     set_temp("apply/defense",150);
     
     setup();
     
     carry_object("/open/tendo/room/tower/obj/kwhisk")->wield();
     carry_object("/open/tendo/room/tower/obj/karmband")->wear();
     carry_object("/open/tendo/room/tower/obj/kbelt")->wear();
     carry_object("/open/tendo/room/tower/obj/kcape")->wear();
     carry_object("/open/tendo/room/tower/obj/kcloth")->wear();
     carry_object("/open/tendo/room/tower/obj/khat")->wear();
     carry_object("/open/tendo/room/tower/obj/klegging")->wear();
     add_money("gold",10);

}



int special_att ()
{
  object me = this_object ();
  object *enemy = query_enemy (), victim;
  int i = sizeof (enemy), damage;
  victim = enemy[random(i)];
      message_vision(HIB+
"              鎮塔明王怒氣狂提，不顧身上的傷口，不斷地將內力運至十二成。\n        
                          " + HIR + "鎮塔明王身上發出一股強大的殺意\n
                 " + HIY + "鎮塔明王的全身開始聚起強烈的" + HIW + "寒冰" + HIW + "與" + HIR + "烈火" + HIY + "兩道環身氣勁，\n
                      " + HIW + "～ 兩道氣勁源源不斷的向手上凝聚！ ～\n
                              " + HIY + "倏地鎮塔明王大喝一聲\n
                 " + HIY + "左手使出一招" + RED + "天書" + MAG + "絕學" + HIY + "中之終極奧義 - -" + HIW + "寒 冰 勁" + HIY + "–-\n
                 " + HIC + "右手一翻使出" + RED + "天書" + MAG + "絕學" + HIC + "中之武學祕技 ～～" + HIR + "烈 火 勁" + HIC + "～～ \n　
                   " + HIB + "只見寒冰與烈火兩道氣勁如狂風暴雨般地擊向$N\n
                        " + HIW + "此乃天書之不秘之傳" + HIC + " 『" + HIW + "寒冰" + HIR + "烈火" + HIW + "勁" + HIC + "』\n"+NOR,me);

  if (random (3) >= 1)
    {
      damage = (victim->query ("max_gin") / 20);
      damage = (victim->query ("max_kee") / 20);
      damage = (victim->query ("max_sen") / 20);
message_vision(HIR + "$N閃躲不及,被寒冰烈火兩道氣勁透體而過,全身上下被烈火及寒冰包圍著,不停的嘶吼!\n" + NOR,victim);
      victim->apply_condition ("bleeding", random (i * i));
      victim->receive_damage ("kee", damage, me);
      COMBAT_D->report_status (victim, 0);
    }
  else
    {
message_vision(HIW + "只可惜離$N差了一點, 劈到地上, 轟的一聲巨響, 地皮頓時裂了開來.\n" + NOR,victim);
    }
  start_busy (1);
  return 1;
}

int accept_fight(object who)
{
	if((int)who->query("combat_exp")<=1000000)
	{
	command("say 閣下還沒有實力與我較量..");
	return 0;
	}
        map_skill("force","gforce");
	command("conj hardshell");
        map_skill("force","fiendforce");
	command("say 請指教！");
	return 1;
 }

int accept_kill(object ob)
{
	message_vision( HIR + "$n使出天界絕學之定身術使$N不能動彈。\n",this_player(),this_object());
        map_skill("force","gforce");
	command("conj hardshell");
        map_skill("force","fiendforce");
	set("no_sword",1);
	this_player()->start_busy(3);
	return 1;
}

void heart_beat()
{
	object me=this_object(), *enemy;
	int i, j, k, m;

	enemy = me->query_enemy();
	i = random(5);
	k = random(13);
	j = random(sizeof(enemy));
	m = 5000;

	if( !me->query_temp("fight") )
	{
	me->delete_temp("is_busy");
	me->delete_busy();
	me->delete_temp("no_power_f");
	me->delete_temp("no_power_e");
        map_skill("force","fiendforce");
	command("perform force.fight");
        map_skill("force","gforce");
	me->delete_busy();
	}

	if( me->is_fighting() )
	{

	  if ( !me->query_temp("hardshell") )
	  {
	  me->delete_temp("is_busy");
	  me->delete_busy();
          map_skill("force","gforce");
	  command("conj hardshell");
          map_skill("force","fiendforce");
	  }

	  if( !me->query_temp("have_hawk") )
	  {
	  me->delete_temp("is_busy");
	  me->delete_busy();
	  command("cast waken");
	  }

//	  if( i == 0 )
//	  {
//	  command("cast godfight");
//	  }

	  if( i == 1 && me->is_busy() )
	  {
          message_vision(HIW + "$N展開一層「天神結界」，阻斷了攻勢，得以短暫的喘息之機。\n" + NOR, me);
	  me->delete_busy();
	  }

	  if( i == 2 )
	  {
	    me->receive_curing("kee",(enemy[j]->query("max_kee")/5));
	    me->receive_heal("kee",(enemy[j]->query("max_kee")/5));
	    me->receive_curing("gin",(enemy[j]->query("max_gin")/5));
	    me->receive_heal("gin",(enemy[j]->query("max_gin")/5));
	    me->receive_curing("sen",(enemy[j]->query("max_sen")/5));
	    me->receive_heal("sen",(enemy[j]->query("max_sen")/5));
	    me->add("force",(enemy[j]->query("max_force")/5));
	  }

	  if( i == 3 )
	  {
	    if( random(2) == 1 ) 
	    {
	    command("cast missible");
	    me->set("adv_taoist",1);
	    }else{
	    command("cast feeblebolt");
	    me->delete("adv_taoist");
	    }
	  }

	  if( i == 4 )
	  {
	  command("cast stopmove");
	  }
	}
 
	if( !me->is_fighting() ) 
	{
	  if( query("force") < 40000 ) 
	  command( "ex 270" );
	  if( query("kee") < query("eff_kee") ) 
	  {
	  me->receive_curing("kee",1000);
	  me->receive_heal("kee",1000);
	  }
	  if( query("gin") < query("eff_gin") )
	  {
	  me->receive_curing("gin",1000);
	  me->receive_heal("gin",1000);
	  }
	  if( query("kee") < query("eff_kee") ) 
	  command( "5 exert recover" );
	  if( query("sen") < query("eff_sen") ) 
	  {
	  me->receive_curing("sen",1000);
	  me->receive_heal("sen",1000);
	  }
	}

	set_heart_beat(1);
	::heart_beat();
}

void die()
{
        object winner = query_temp("last_damage_from");
	winner->set_temp("ko_towerking",1);
	tell_object(winner,HIY + "鎮塔明王的一點靈光飛入了你的身體之中!!\n" + NOR);
        tell_object(users(),
HIW + "\n鎮塔明王咽下最後一口氣唉道:\n\n
                 " + HIR + "～ ～ ～天   啊～ ～ ～我～的～任～務～呀～\n
          " + HIC + "今日竟然會斷送於" + HIW + ""+winner->query("name")+"" + HIC + "之手！！\n" + NOR);


        :: die();
}

      


