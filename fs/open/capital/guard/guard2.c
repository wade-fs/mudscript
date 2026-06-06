//ring guard by bss
//修改自casey的黃金甲龍
//做出三隻不同的,king can call 3 隻,else can call 1 隻
//補上對手是否與本npc為相同房間的判斷 by blazakira 2011/6/2

#include <ansi.h>
inherit NPC;
mapping *action = ({
([ "action" :"$N嘎嘎大叫，銳利的爪子向$n抓了過去，眼看$n就要被抓到了"NOR"。",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "抓傷",
           ]),
([ "action" :"$N迅速撲至$n面前，快速的搧動羽翼，$n在強風吹撫之下，顯得搖搖欲墜，$N見機不可失，尖嘴以疾快的速度朝$n刺去"NOR"!!",
             "dodge"      :  -20,
             "parry"      :  -35,
             "damage"     :  270,
             "damage_type":  "破體之傷",
            ]),
([ "action" :"$N忽然用眼睛緊盯著$n，$n只覺得$n眼前的$N忽然變得好大，使$n心生膽怯，身體因過度驚嚇而無法動彈"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  240,
             "damage_type":  "恐懼之傷",
            ]),
([ "action" :"$N朝$n猛撞了過去，因飛行所產生的巨風，挾著萬均之勢，令敵人膽顫心驚"NOR"。",
             "dodge"      :  -30,
             "parry"      :  -35,
             "damage"     :  275,
             "damage_type":  "撞傷",
            ]),
([ "action":"$N自己的身上的火燄燃到最高點，使得全身有如火球一般，炙熱非常，$N一展翅，就這麼朝$n飛去，
$n被這種攻勢所驚嚇，除了逃之外，似乎沒有別條路了!!"NOR,
             "dodge"      : -100,
             "parry"      :  -100,
             "damage"     : 892,
             "damage_type":  "嚴重灼傷",
           ]),
       });

void create()
{
  set_name(HIR"火鳳凰"NOR ,({"ring guard", "guard"}) );
  set("race", "野獸");
  set("clan_kill",1);
  set("no_exp",1);
  set("title", "守護者");
  set("age",103972);
  set("long","
生長在火山附近的異獸，因全身無時無刻不在發出炙熱的火燄而得名。\n");
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
  set("limbs", ({ "鳳首", "鳳身", "鳳足" ,"鳳翼" }) );
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
    BLINK+HBMAG+HIY"一道強光從戒指射出，一隻巨大的鳳凰從戒指中飛出。\n\n"
    + name() +BLINK+HBMAG+HIY "緩緩的說道：人不犯我，我不犯人!!\n"NOR,
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
  message_vision (HIR"$N"HIR"說道：我已經幫主人你戰鬥完畢囉，下次見！\n" +
    "一陣清風吹過，$N"HIR"的身形隨之不見了。\n" NOR, this_object ());
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
    if(!who->query("capital_king"))
      who->set_temp("have_guard",0);
  message_vision (HIB"$N慘叫一聲啊！消失得無影無蹤。\n", this_object ());
  destruct (this_object ());
  ::die();
}
