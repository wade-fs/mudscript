//ring guard by bss
//修改自casey的黃金甲龍
//做出三隻不同的,king can call 3 隻,else can call 1 隻
//補上對手是否與本npc為相同房間的判斷 by blazakira 2011/6/2

#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N眼露兇光，勁貫雙臂，向$n猛力擊了過去，眼看$n就要被重拳打到了"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "擊傷",
           ]),
([ "action" :"$N迅速衝到$n面前，趁著$n不注意的時候竟朝$n抱了過去，$n被$N的攻勢嚇了一跳，竟然忘了閃躲"NOR"!!",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抱傷",
            ]),
([ "action" :"$N將全身力量集中在尾巴，用力朝地板打了過去，從地上被打起的土石有如波濤般擊向$n"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  240,
             "damage_type":  "內傷",
            ]),
([ "action" :"$N從嘴巴中吐出一股驚人的勁氣，灼熱的氣體所含的高熱使得$n不舒服起來!!"NOR,
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  275,
             "damage_type":  "灼傷",
            ]),
([ "action":"$N忽然將自己的身體捲的像一團球一樣，朝$n滾去，由於$N的身體實在是太大了，所以$n非常難閃躲"NOR"。",
               "dodge"       : -100,
               "parry"       : -100,
               "damage"       : 892,
             "damage_type":  "嚴重輾傷",
           ]),
       });

void create()
{
  set_name(HIW"聖天白猿"NOR ,({"ring guard", "guard"}) );
  set("race", "野獸");
  set("clan_kill",1);
  set("no_exp",1);
  set("title", "守護者");
  set("age",103972);
  set("long","
守護著蟠桃園的神獸，天生神力，曾義救牡丹仙子而被王母娘娘所升為仙，後來自願被封
印在護衛戒指之中以守護戒指的所有人。\n");
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
  set("limbs", ({ "猿首", "猿身", "前肢" , "後足" , "猿尾" }) );
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
    BLINK+HBMAG+HIY"一道強光從戒指射出，一隻巨大的白猿緩步走出。\n\n"
    + name() +BLINK+HBMAG+HIY "大叫的說道：今天我就要替天行道，死吧！\n"NOR,
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
  message_vision (HIG"$N說道：我已經幫主人你戰鬥完畢囉，下次見！\n" +
    "一陣清風吹過，$N的身形隨之不見了。\n" NOR, this_object ());
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
  message_vision (HIB"$N慘叫一聲啊！消失得無影無蹤。\n", this_object ());
  destruct (this_object ());
}

void die()
{
  object who = query_leader ();
  if (who)
    if(!who->query("capital_king")){
      who->set_temp("have_guard",0);
    }
  message_vision (HIB"$N慘叫一聲啊！消失得無影無蹤。\n", this_object ());
  destruct (this_object ());
  ::die();
}
