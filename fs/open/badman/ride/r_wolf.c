#include <combat.h>
#include <ansi.h>
#include <mudlib.h>
inherit NPC;
void create() {
  set_name("紅狼", ({"red wolf","red","wolf"}));
  set("title","血光");
  set("long", "一匹目露殺氣，身透紅光的狼。\n");
  set("horse",1);
  set("max_force",1500);
  set("force",1500);
  set("max_kee",1000);
  set("kee",1000);
  set("max_gin",1000);
  set("gin",1000);
  set("max_sen",1000);
  set("sen",1000);
  set("race", "野獸");
  set("combat_exp",320000);
  set_skill("parry",80);
  set_skill("dodge",90);
  set_skill("move",90);
  set("verbs",({"bite","claw"}));
  setup();
}

void init() {
  add_action("do_runaway","back_home");
  add_action("do_ascend","ride");
  add_action("do_descend","dismount");
}

  int do_runaway()
{
  object me,wolf,target;
  string *name;
  me = this_player();
  wolf = this_object();
  target = me->query_enemy();
  if(!query_leader())
  return notify_fail("你是這匹狼的主人嗎？\n");
  message_vision("紅狼聽從你的指揮往森林的方向走去\n",me);
  me->delete_temp("is_riding");
  me->delete_temp("apply/name",name);
  me->delete_temp("marks/have_wolf");
  destruct(wolf);
  return 1;
}
int do_ascend()
{
  object me,wolf,target;
  me = this_player();
  wolf = this_object();
  target = me->query_enemy();
  if(wolf->query("horse")!=1)
  return notify_fail("你要騎這東西不如去妓院！\n");
  if(me->query("class")!="bandit")
  return notify_fail("這動物不是你可以坐的！\n");
  if (me->query("combat_exp") < 600000)
  return notify_fail("你可沒有這種歷練來應付在狼上的狀況。\n");
  if (me->query_skill("riding",1) < 1 )
  return notify_fail("你還不知道騎術的基本，要怎麼騎？\n");
  if(me->query_temp("is_riding"))
  return notify_fail("你正在騎著呢！\n");
  message_vision("$N腳一蹬，手一甩，身一翻，就這麼騎在狼上了！\n",me);
  wolf->set_leader(me);
  me->set_temp("ride_name",me->name()+"騎在一匹"+this_object()->name()+"上");
//me->add_temp("apply/name",({ me->name()+"（正騎著"+this_object()->name()+"）"}));
  me->set_temp("is_riding", 1);
  move(me);
  me->set_heart_beat(1);
  return 1;
}

int do_descend()
{
  object me;
        string *name;

        me=this_player();
  if (!me->query_temp("is_riding"))
  return notify_fail("你沒騎東西，幹嘛下來？\n");
  message_vision("$N一個轉身，便已應聲落地，好好地站在地上。\n",me);
  me->delete_temp("is_riding");
  me->delete_temp("ride_name");
//me->delete_temp("apply/name",name);
  move(environment(me));
  me->set_heart_beat(0);

  return 1;
}

int heal_up()
{
  object *enemy,who,user;
  int i,dodge;
        user = query_leader();
  who = this_player();
if(!who) return ;
if(!user) return ;
  if( user->is_fighting() )
  {
   if (random(100) < (user->query_skill("riding",1)))
   {
    enemy=user->query_enemy();
    i=random(sizeof(enemy));
    message_vision(""+user->query("name")+"靈活運用騎術，趁$n不注意時，\n
使狼將$n整個人壓在地上，動彈不得！\n",who,enemy[i]);
    enemy[i]->receive_damage("kee",100);
    enemy[i]->start_busy(1);
    COMBAT_D->report_status(enemy[i], 1);
   }
  }
  return ::heal_up() + 1;
}
