//ring guard by bss
//修改自casey的黃金甲龍
//補上對手是否與本npc為相同房間的判斷 by blazakira 2011/6/2

#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N" + HIY + "哇哇大叫，銳利的爪子向$n抓了過去，眼看$n就要被抓到了" + NOR + "。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N" + HIY + "迅速撲至$n面前，滿天爪影朝$n猛擊下去，$n被$N" + HIY + "的攻勢嚇了一跳，竟然忘了閃躲" + NOR + "!!",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抓傷",
            ]),
([ "action" :"$N" + HIY + "將全身力量集中在尾巴，身體忽然快速的旋轉起來，$N" + HIY + "的尾巴如風車般掃向$n" + NOR + "。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  240,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N" + HIY + "朝$n猛撞了過去，千斤重的身體，挾著萬均之勢，令敵人膽顫心驚" + NOR + "。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  275,
             "damage_type":  "撞傷",
            ]),
([ "action":"$N" + HIY + "忽然將自己的身體捲的像一團球一樣，朝$n滾去，由於$N" + HIY + "的身體實在是太大了，
所以$n非常難閃躲" + NOR + "。",
             "dodge"      : -30,
             "parry"      :  -30,
             "damage"     : 292,
             "damage_type":  "嚴重輾傷",
           ]),
       });

void create()
{
  set_name(HIM + "護衛神獸" + NOR ,({"ring guard", "guard"}) );
  set("race", "野獸");
  set("clan_kill",1);
  set("no_exp",1);
  set("title", "守護者");
  set("age",103972);
  set("long","
原本是古代巨人族所養的寵物，因為巨人族作惡太多被天帝所滅，本來也要將它也滅了
可是太上老君不忍這種可愛的動物就這麼絕種，所以留了一隻下來，將它封印在護衛戒
指之中，只有在主人有危難的時候才能出來幫忙。\n");
  set_temp("apply/attack",200);
  set_temp("apply/damage",200);
  set_temp("apply/move",200);
  set("no_plan",1);
  set("max_kee",10000);
  set("kee",10000);
  set("force",19000);
  set("max_force",19000);
  set("force_factor",30);
  set("gin", 8000);
  set("sen", 8000);
  set("max_gin", 8000);
  set("max_sen", 8000);
  set("combat_exp",4700000);
  set("chat_chance_combat", 32);
  set_skill("dodge",200);
  set_skill("move", 200);
  set_skill("parry",200);
  set_skill("unarmed",200);
  set("limbs", ({ "獸首", "獸身", "前肢" , "後足" , "獸尾" }) );
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

  message("vision",
    BLINK+HIY"一道強光從戒指射出，一隻巨大的怪獸緩步走出。\n\n"
    + name() + HIY + "哇哇大叫的說道：我要代替我的主人，懲罰你！\n" + NOR,
    environment(), this_object() );
  enemy = who->query_enemy();
  i = sizeof(enemy);
  while(i--) {
    if( environment(enemy[i]) != environment(this_object()) ) continue; //房間不同就算了 by blazakira
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
  object me=this_object();
  object who = query_leader ();
  if(!who){
    call_out("leave",0);
    return ;
  }
  if(!who->is_fighting()) {
    call_out("leave",0);
    return;
  }
  if(!me->is_fighting()){
    call_out("leave",0);
    return;
  }
  :: heart_beat();
}

void leave()
{
  object who = query_leader ();
  message_vision (HIG + "$N" + HIG + "說道：我已經幫主人你戰鬥完畢囉，下次見！\n" +
    "一陣清風吹過，$N" + HIG + "的身形隨之不見了。\n" + NOR, this_object ());
  if (who)
    who->set_temp("have_guard",0);
  destruct(this_object());
}

void unconcious ()
{
  object who = query_leader ();
  if (who)
    if(!who->query("capital_king"))
      who->set_temp("have_guard",0);
  message_vision (HIB + "$N慘叫一聲啊！消失得無影無蹤。\n", this_object ());
  destruct (this_object ());
}

void die()
{
  object who = query_leader ();
  if (who)
    if(!who->query("capital_king"))
      who->set_temp("have_guard",0);
  message_vision (HIB + "$N慘叫一聲啊！消失得無影無蹤。\n", this_object ());
  destruct (this_object ());

  ::die();
}
