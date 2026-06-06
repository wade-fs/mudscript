#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" : "$N使出絕情神掌第一招"+HIY+"【亢龍有悔】"+NOR+"，右掌劃了個圈圓，向$n的$l推去",
                "dodge"      :    -25,
                "parry"      :    -20,                                      
                "damage"     :    110,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N使出絕情神掌第二招"+HIG+"【飛龍在天】"+NOR+"，猶如飛龍般躍起半空，居高下擊，向$n
的$l擊出",
                "dodge"      :     -50,
                "parry"      :     -10,
                "damage"     :     130,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N使出絕情神掌第三招"+HIR+"【突如其來】"+NOR+"，於迅雷不及掩耳的速度，讓$n攻其不備",
                "dodge"      :    -30,
                "parry"      :    -45,
                "damage"     :    150,
                "damage_type":   "瘀傷",
            ]),
([ "action" : "$N使出絕情神掌第四招"+HIB+"【雙龍取水】"+NOR+"，左右分使絕情神掌，令$n無法敵擋，內
外皆受到極大的傷害", 
                "dodge"      :   -50,
                "parry"      :   -50,
                "damage"     :   100,
                "damage_type":   "瘀傷",
            ]),
   });

void create()
{
  set_name("顏烈", ({"lye"}));
  set("title","風護法");
  set("nickname","絕情門二弟子");
  set("gender","男性");
  set("age", 24);
  set("combat_exp", 800000);
  set("long", "他是絕情門的護法，是絕情門主林楓的得意門生，但出招狠毒，
每招都攻擊要害，絕情神掌的功力和門主林楓不相上下。\n");
  set("str", 20);
  set("cor", 20);
  set("int", 24);
  set("spi", 22);
  set("cps", 30);
  set("cps", 30);
  set("con", 30);
  set("max_gin", 1500);
  set("max_kee", 3000);
  set("max_sen", 1500);
  set("max_force", 1500);
  set("force", 1500);
  set("force_factor", 10);
  set("bellicosity",1000);
  set_skill("dodge",80);
  set_skill("force",60);
  set_skill("linpo-steps",60);
  set_skill("unarmed",70);
  map_skill("dodge","linpo-steps");
  set("chat_chance_combat",25);
  set_temp("apply/armor",80);
  set_temp("apply/damage",40);
  set("chat_msg", ({
     (: this_object(),"random_move" :),
  }) );
  setup();
carry_object("/open/love/obj/hat.c")->wear();
carry_object("/open/love/obj/claw.c")->wield();
  add_money("silver", 10);
  set("default_actions", (: call_other, __FILE__,"query_action" :));

  reset_action();
         
}
mapping query_action()
{
   return action[random(sizeof(action))];
}
void greeting(object ob)
{
  int exp,lv_1;
  string skill;
  object weapon;
  exp =ob->query("combat_exp",1);
  weapon = ob->query_temp("weapon");
  if( weapon ) skill = weapon->query("skill_type");
  else skill = "unarmed";
  lv_1 =(int) 1.8 * ob->query_skill(skill, 1);
  return;
}
void heart_beat()
{
  object env,mob,*enemy,target;
  int i,kee;

  mob = this_object();
  env = environment(mob);

     if( random(70) < 15)
 {
   enemy=mob->query_enemy();
	if( i = sizeof(enemy) ) {
   target=enemy[random(i)];
   kee = target->query("max_kee") * 0.2;
   if( env == environment(target) )
   {
     message_vision(HIW+"$N看見顏烈，祭起"+HIY+"「絕情訣」"+HIW+"以精化氣，以
氣御神，以神聚力，只見顏烈的"+HIR+"手臂通紅"+HIW+"，
直向$N的"+HIR+"心臟"+HIW+"抓來，你頓時"+HIR+"血液完全被抽乾\n"+NOR,target);
     target->receive_damage("kee",(int)kee,mob);
     COMBAT_D->report_status(target,0);
   }
	}
 }
 set_heart_beat(1);
   ::heart_beat();
}
