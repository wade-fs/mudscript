//更正en force的錯誤 by blazakira 2010/10/3
//增加receive_damage的攻擊者參數 by blazakira 2011/4/16

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;
int i;
void create()
{
  set_name("孫虎臣",({"Tiger Shiun","shiun"}));
  set("long",@LONG
天下四絕之一的孫虎臣，不但官居極品，一手天虎橡皮功\更是
強大無匹，足以承受天底下任何武技的攻擊。

LONG);
  set("gender","男性");
  set("class","bandit");
  set("nickname",HIY + "虎神" + NOR);
  set("title",HIW + "當今鏢騎大將軍" + NOR);
  set("family/family_name","惡人谷");
  set("combat_exp",10000000);
  set("attitude","friendly");
  set("score",1000000);
  set("bellicosity",20000);
  set("age",45);
  set("str", 35);
  set("cor", 35);
  set("cps", 35);
  set("int", 35);
  set("spi", 35);
  set("per", 35);
  set("kar", 35);
  set("con", 35);
  set("force",20000);
  set("max_force",80000);
  set("mana",20000);
  set("max_mana",20000);
  set("atman",20000);
  set("max_atman",20000);
  set("force_factor", 35);
  set("max_kee",50000);
  set("max_gin",50000);
  set("max_sen",50000);
  set_skill("dodge",120);
  set_skill("sword",120);
  set_skill("ghost-steps",120);
  set_skill("force", 250);
  set_skill("counter",100);
  set_skill("badforce",250);
  set_skill("move", 120);
  set_skill("parry",120);
  set_skill("unarmed",120);
  set_skill("badstrike",120);
  set_skill("fireforce",250);
  map_skill("unarmed", "badstrike");
  map_skill("parry", "badstrike");
  map_skill("force", "badforce");
  map_skill("dodge", "ghost-steps");
  map_skill("move", "ghost-steps");
  set("functions/evil-blade/level",100);
  set("functions/badroar/level",100);
  set("functions/gold-fire/level",100);
  set("chat_chance_combat", 50);
  set("chat_msg_combat", ({
    (: perform_action, "badstrike.evil-blade" :),
  }) );
  set("quests/sunfire",1);
  set("quest/gold-fire",1);
  set("quest/new_gold_fire",1);
  set("quests/badroar",1);
  set("marks/kar",1);
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
  carry_object("/open/magic-manor/obj/evil-kill-claw");
  carry_object("/open/ping/obj/ring-2");

}

int accept_kill(object ob)
{
  object me=this_object();
  kill_ob(ob);
  me->delete_temp("is_busy");
  command("wield all");
  command("wear all");
  command("perform badstrike.evil-blade");
  return 1;
}

void heart_beat()
{
  object who=this_player(),me=this_object();
  object *user;
  if(!environment(me)) return ;
  user = all_inventory( environment(me) ); //all_inventory()傳回一個物件的內容物品
  
  if(!me->is_busy() && random(3) == 1 && me->is_fighting())
  {
/*
魚缸@台北 說 (下午 11:30):
if(sizeof(user) ) return user[1]; else return me;
魚缸@台北 說 (下午 11:47):
就直接用sizeof(user)? user[0] : me
魚缸@台北 說 (下午 11:47):
if 我只是跟你說會轉成哪樣
*/
    message_vision(HIR + "
            孫虎臣突然單手扣住$N的左手，運起天虎橡皮功\和地虎護身勁，
            接著引爆預先埋藏好的火藥，碰的一聲巨響，火光四射。
            $N遭受相當嚴重的炸傷，而虎神仍屹立不搖。
            
            \n" + NOR,sizeof(user) ? user[0] : me);
    for( i=0; i<sizeof(user); i++ )
    {
      if(userp(user[i]))
      {
        user[i]->receive_damage("kee",1500,me);
        COMBAT_D->report_status(user[i]);
      }else{
        user[i]->receive_damage("kee",500,me);
        COMBAT_D->report_status(user[i]);
      }
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
    map_skill("force", "badforce");
  }

  if( !me->is_busy() && !who->is_busy() )
  {
    me->clear_condition();
    command("perform badstrike.badroar");
//    command("perform unarmed.badroar");
  }

  if( !is_fighting() ) 
  {
    if( query("force") < 20000 )
      command( "ex 270" );
    if( query("eff_kee") < query("max_kee") )
    { 
      command( "10 exert heal" );
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
  }

  set_heart_beat(1);
  ::heart_beat();
}

void unconcious ()
//void die()
{
  object me,obj,winner;
  me=this_object();
  winner=query_temp("last_damage_from");
  if(!winner || !userp(winner))
  {
  new("/open/magic_palace/npc/4-4.c")->move("/open/magic_palace/room/room33");
  ::die();
  return ;
  }else{
        message_vision(HIR + "
        
虎神怒道:『想不到以我堂堂大將軍之尊，今日竟敗於草野群莽手中，可惡啊!!』

" + HIW + "孫虎臣一口氣引爆所有埋藏於地底的火藥

同時運起最後的天虎橡皮功\和地虎護身勁，" + HIY + "
                    
" + HIG + "轟的一聲巨響，$N如斷線風箏般遠遠飛了出去...
                    
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
