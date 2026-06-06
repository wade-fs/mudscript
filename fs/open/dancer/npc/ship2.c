// /open/dancer/npc/ship2.c
//增加防瞪的功能 by blazakira 2011/8/5

#include "/open/open.h"
inherit NPC;

int time=0;

void create()
{
  set_name("彎月舫", ({ "ship" }) );
  set("long", @LONG
雕飾著雲女玩月圖的彎月舫，船體是由千年神木所輮製而成，
是當今京城首富贈與雙月姊妹的禮物，只為能夠欣賞一次她們媲美
天仙的技藝。姊妹偶爾會乘著彎月舫遊湖賞景，但通常都是讓弟子
們外出購物用。
LONG);
//  set("attitude", "friendly");
  set("attitude", "heroism");
  set("score",1000000); //有防對手殺氣過高被瞪的功能
  set_temp("roared",1); //預設roar過，不然會有一點問題
  setup();
}

void init()
{
  add_action("do_look","look");
  add_action("do_look","l");
  set_heart_beat(1);
}

void heart_beat()
{
  if(!this_object() || !environment(this_object())) return;
  time++;
  if(time==1)
  {
    say("前往鏡月島的渡船到囉，請趕快搭(board)船 !\n");
  }
  if(time==11)
  {
    say("開船囉，沒搭上的人下次請早 !\n");
    destruct(this_object());
    return;
  }
}

int do_look(string str)
{
  if(str=="ship")
  {
    write("雕飾著雲女玩月圖的彎月舫，船體是由千年神木所輮製而成，
是當今京城首富贈與雙月姊妹的禮物，只為能夠欣賞一次她們媲美
天仙的技藝。姊妹偶爾會乘著彎月舫遊湖賞景，但通常都是讓弟子
們外出購物用。\n");
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
