// /open/center/npc/vendor.c
//排版 與增加防瞪之類等功能 by blazakira 2011/8/21

#include "/open/open.h"
inherit NPC;

int time=0;

void create()
{
  set_name("渡船", ({ "ship" }) );
  set("long", @LONG
看來十分破舊不知會開往何處！
LONG);
//  set("attitude", "friendly");
  set("attitude", "heroism");
  set("score",1000000); //有防對手殺氣過高被瞪的功能
  set_temp("roared",1); //預設roar過，不然會有一點問題
  setup();
  set_heart_beat(1);
}

void init()
{
  add_action("do_look","look");
  add_action("do_look","l");
}

void heart_beat()
{
  object me=this_object();
  if(!me || !environment(me)) return;
  time++;
  if(time==1)
  {
    say("前往幻龍海岸的渡船到囉，請趕快搭(board)船！\n");
  }
  if(time==11)
  {
    say("開船囉，沒搭上的人等下一班吧！\n");
    destruct(this_object());
  }
}

int do_look(string str)
{
  if(str=="ship")
  {
    write("看來十分破舊不知會開往何處！\n");
    return 1;
  }
  return 0;
}

int accept_fight(object me)
{
  return notify_fail("看清楚，那並不是生物！\n");
}

int accept_kill(object me)
{
  return notify_fail("看清楚，那並不是生物！\n");
}
