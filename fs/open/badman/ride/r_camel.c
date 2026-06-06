#include <combat.h>
// 2003/01/15修改desertwall的時間 -- by kalin 
#include <ansi.h>
#include <mudlib.h>
inherit NPC;
void create() {
  set_name("駱駝", ({"desert camel","desert","camel"}));
  set("title","塵沙");
  set("long", "一頭嘴巴不停地咀嚼，眼神呆滯的駱駝。\n");
  set("horse",1);
  set("no_kill",1);
  set("no_fight",1);
  set("max_force",2750);
  set("force",2750);
  set("max_kee",3200);
  set("kee",3200);
  set("max_gin",1500);
  set("gin",1500);
  set("max_sen",2250);
  set("sen",2250);
  set("race", "野獸");
  set("combat_exp",750000);
  set_skill("parry",120);
  set_skill("move",100);
  set_skill("dodge",100);
  set("verbs",({"bite","claw"}));
setup();
}

void init() {
  add_action("do_ascend","ride");
  add_action("do_descend","dismount");
  add_action("do_wall","desertwall");
  add_action("do_runaway","back_desert");
}

int do_runaway()
{
  object me,wolf,target;
  string *name;
  me = this_player();
  wolf = this_object();
  target = me->query_enemy();
  if(!query_leader())
  return notify_fail("你是這駱駝的主人嗎？\n");

  message_vision("駱駝乖乖地聽你的話，回家去了。\n",me);
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
  if (me->query("combat_exp") < 1200000)
  return notify_fail("你的江湖歷練看來不能應付在駱駝上的狀況。\n");
  if (me->query_skill("riding",1) < 1 )
  return notify_fail("你還不知道騎術的基本，要怎麼騎？\n");
  if(me->query_temp("is_riding"))
  return notify_fail("你正在騎著呢！\n");
  message_vision("$N身子一轉，雙腳一踏，瞬間便安坐在駝峰之上！\n",me);
  wolf->set_leader(me);
  me->set_temp("ride_name",me->name()+"騎在一匹"+this_object()->name()+"上");
//me->add_temp("apply/name",({ me->name()+"（正騎著"+this_object()->name()+"）"}));
  me->set_temp("is_riding", 1);
  me->add("marks/h_camel",random(5));
  move(me);
set_heart_beat(1);
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
set_heart_beat(0);

  return 1;
}

int do_wall()
{
  object me,who;
  string *name;
  int dodge,camel;
  //新增time --by kalin /2003/01/15
  int times = (this_player()->query("combat_exp")/500000+10);
  who=this_player();
  dodge=((who->query_skill("riding",1)+who->query_skill("parry",1))/2);
  camel=(who->query("marks/h_camel"));
  me=query_leader();
  who->add("marks/h_camel",random(3));
  if (!me)
  return notify_fail("這駱駝不當你是主人，還是騎騎看吧！\n");
  if (who->query_temp("marks/wall",1))
  return notify_fail("你前面已經有道沙牆了！\n");
  if (random(200)>(who->query_skill("riding",1)))
  return notify_fail("駱駝不聽你的指揮，不幫你築起沙牆！\n");
  if (random(500) > camel)
  return notify_fail("看來你和駱駝的感情不夠好，牠不理你。\n");
 message_vision(""+me->query("name")+"坐下駱駝忽然雙眼一睜，四腳力踏地面，\n
塵沙滿天飛舞，"+who->query("name")+"身前現起一道沙牆！\n",who);
  who->add_temp("apply/defense",dodge);
  who->set_temp("marks/wall",1);
//  call_out("remove_effect",10,who); <--原本的time
  call_out("remove_effect",times,who);  //2003/01/15 修改 --by kalin
  return 1;
}

void remove_effect()
{
  object me,who;
  string *name;
  int dodge;
  who=this_player();
  me=query_leader();
if(!who)  return;
if(!me)  return;
  dodge=((who->query_skill("riding",1)+who->query_skill("parry",1))/2);
  message_vision("轟的一聲，矗立在"+me->query("name")+"前的沙牆已消失！\n",who);
  who->add_temp("apply/defense",-dodge);
  who->delete_temp("marks/wall");
}

int heal_up()
{
  object *enemy,who,user;
  int i,dodge;
        user = query_leader();
  who = this_player();
  if(!user) return 1;
  if( user->is_fighting() )
  {
   user->add("marks/h_camel",random(3));
   if (random(120) < (user->query_skill("riding",1)))
   {
    enemy=user->query_enemy();
    i=random(sizeof(enemy));
   if(environment(enemy[i]) == environment(who))
  {
    message_vision(""+user->query("name")+"座下駱駝突然張開嘴巴，\n
以迅雷不及掩耳之勢向$n吐了幾口口水！$n瞬間錯愕不已，無法自己！\n",who,enemy[i]);
    enemy[i]->start_busy(2);
  }
   }
  }
  return ::heal_up() + 1;
}
