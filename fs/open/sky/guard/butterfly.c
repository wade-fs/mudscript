//將receive_damage的攻擊參數補上攻擊方之參數 by blazakira 2011/7/19

#include <ansi.h>
inherit NPC;

mapping *action = ({
([ "action" :"$N"HIG"喝聲道，銳利的爪子向$n"HIG"抓了過去，眼看$n"HIG"就要被抓到了!!!"NOR,
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N"HIG"漫天爪影朝$n"HIG"猛擊下去，$n"HIG"被$N"HIG"的攻勢嚇了一跳，竟然忘了閃躲!!!"NOR,
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N"HIG"身體忽然快速的旋轉起來，$N"HIG"的尾巴如風車般掃向$n!!!"NOR,
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  240,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N"HIG"朝$n"HIG"猛撞了過去，碩大的身軀，挾著萬均之勢，令$n"HIG"防無可防!!!"NOR,
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  275,
             "damage_type":  "撞傷",
            ]),
([ "action":"$N"HIG"將自己的身體捲的像球一樣，朝$n"HIG"滾去，龐大的身軀下$n"HIG"無處可躲!!!"NOR,
             "dodge"      : -30,
             "parry"      :  -30,
             "damage"     : 292,
             "damage_type":  "嚴重輾傷",
           ]),
});

void create()
{
  set_name(HIM"織蝶"NOR ,({"butterfly guard", "guard"}) );
  set("race", "野獸");
  set("nickname", HIG"幻飛舞"NOR);
  set("age",1032);
  set("long","蘊藏在幻彩靈戒的四大神獸之一。盡其一生守護其所認定的主人。\n");
  set("str", 45);
  set("cor", 45);
  set("int", 45);
  set("con", 45);
  set("cps", 45);
  set("spi", 45);
  set("per", 45);
  set("kar", 45);
  set("kee", 30000);
  set("gin", 30000);
  set("sen", 30000);
  set("atman",30000);
  set("mana",30000);
  set("force", 100000);
  set("max_kee", 30000);
  set("max_atman",30000);
  set("max_mana",30000);
  set("max_gin", 30000);
  set("max_sen", 30000);
  set("max_force", 30000);
  set("score",1000000);
  set("bellicosity", 20000);
  set_skill("move",300);
  set_skill("dodge",300);
  set_skill("parry",300);
  set_skill("unarmed",300);
  set_skill("force",500);
  set("force_factor",30);
  set_skill("unarmed",200);
  set_temp("apply/armor",120);
  set_temp("apply/attack",50);
  set_temp("apply/damage",50);
  set_temp("apply/defense", 200);
  set("limbs", ({ "獸首", "獸身", "前肢" , "後足" , "獸尾" }) );
  set("verbs",({"bite","claw"}));
  setup();

  set("default_actions", (: call_other, __FILE__,"query_action" :));
  reset_action();
  set_heart_beat(1);
}

mapping query_action()
{
  return action[random(sizeof(action))];
}

void invocation(object who)
{
  int i;
  object *enemy;

  message("vision",HIC"什麼人這麼大膽，敢傷害我所守護的人\n"
    NOR+name() + HIY + "輕輕的說道 : 要命的快離開吧!!\n"NOR,environment(), this_object() );
  enemy = who->query_enemy();
  i = sizeof(enemy);
  while(i--) {
    if( enemy[i] && living(enemy[i]) ) {
      kill_ob(enemy[i]);
      if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
      else enemy[i]->kill_ob(this_object());
    }
  }
  command("defend "+who->query("id"));
  who->set_temp("have_guard",1);
  set_leader(who);
}

void init()
{
  set_heart_beat(1);
}

void heart_beat()
{
  object *enemy,me,who;
  int i,j;
  me=this_object();
  who = query_leader();
  j=random(100);
  if(!who)
  {
    call_out("leave",0);
    return ;
  }

  if( me->is_fighting() )
  {
    if( j > 50 && j < 65 )
    {
      enemy = me->query_enemy();
      for(i=0;i< sizeof(enemy);i++)
      {
        if(!enemy[i]) return ;
        if(environment(me) == environment(enemy[i]))
        {
          message_vision("$N"HIM"身上發出一道紫光向$n"HIM"捲了過去，$n"HIM"走避不及被紫光罩住了!!!\n"+NOR,me,enemy[i]);
          enemy[i]->receive_damage("kee", 350, me);
          enemy[i]->apply_condition("faint",random(4)+5);
          COMBAT_D->report_status(enemy[i], 1);
        }
      }
    }
    if( j > 65 && j < 75 )
    {
      enemy = me->query_enemy();
      for(i=0;i< sizeof(enemy);i++)
      {
        if(!enemy[i]) return ;
        if(environment(me) == environment(enemy[i]))
        {
          message_vision("$N"HIM"身上發出一道紫光向$n"HIM"飛了過去，$n"HIM"走避不及被紫光罩住了!!!\n"+NOR,me,enemy[i]);
          enemy[i]->receive_damage("kee", 350, me);
          enemy[i]->apply_condition("rose_poison",random(4)+5);
          COMBAT_D->report_status(enemy[i], 1);
        }
      }
    }
    if( j > 75 && j < 80 )
    {
      enemy = me->query_enemy();
      for(i=0;i< sizeof(enemy);i++)
      {
        if(!enemy[i]) return ;
        if(environment(me) == environment(enemy[i]))
        {
          message_vision("$N"HIM"身上發出數道紫光向$n"HIM"襲了過去，$n"HIM"走避不及被紫光罩住了!!!\n"+NOR,me,enemy[i]);
          enemy[i]->receive_damage("kee", 350, me);
          enemy[i]->apply_condition("snake_poison",random(4)+5);
          COMBAT_D->report_status(enemy[i], 1);
        }
      }
    }
    if( j > 80 && j < 84 )
    {
      enemy = me->query_enemy();
      for(i=0;i< sizeof(enemy);i++)
      {
        if(!enemy[i]) return ;
        if(environment(me) == environment(enemy[i]))
        {
          message_vision("$N"HIM"身上發出數十道紫光向$n"HIM"撲了過去，$n"HIM"走避不及被紫光罩住了!!!\n"+NOR,me,enemy[i]);
          enemy[i]->receive_damage("kee", 350, me, me);
          enemy[i]->apply_condition("five_poison",random(4)+5);
          COMBAT_D->report_status(enemy[i], 1);
        }
      }
    }
  }
  if(!who->is_fighting())
  {
    call_out("leave",0);
    return;
  }
  if(!me->is_fighting())
  {
    call_out("leave",0);
    return;
  }
//  set_heart_beat(1);
  :: heart_beat();
}

void leave()
{
  object who = query_leader();
  message_vision ("$N"HIY"說道﹕我已經盡完守護的責任了！與主人暫別！\n" +
    "靈光漸漸散去，$N"HIY"的身形隱入了幻彩靈戒中了。\n" NOR, this_object());
  if (who)
    who->set_temp("have_guard",0);
  destruct(this_object());
}

void unconcious ()
{
  object who = query_leader();
  if (who && !who->query_temp("master"))
    who->set_temp("have_guard",0);
  message_vision ("$N"HIB"慘叫一聲  啊！  恕我無法再保護主人了。\n"NOR, this_object());
  destruct (this_object());
}

void die()
{
  object who = query_leader();
  if (who && !who->query_temp("master"))
    who->set_temp("have_guard",0);
  message_vision ("$N"HIB"慘叫一聲  啊！  恕我無法再保護主人了。\n"NOR, this_object());
  destruct (this_object());

  ::die();
}
