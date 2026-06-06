// /open/center/npc/vendor.c
//增加線索暗示 by blazakira 2010/10/20
#include <obj.h>
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
object *stones;
void create()
{
      set_name("老人", ({ "old man", "man" }) );
      set("long","你看到這裡有一位沉睡的老人正在床上，不過你正在嘗試著叫醒(wakeup)他");
        set("attitude", "friendly");
        set("title",HIB + "(沉睡中)" + NOR);
        set("combat_exp",30000000);
        set_temp("apply/dodge",500);
        set_temp("apply/parry",500);
        setup();
}
void init()
{
  object ob = previous_object();
  call_out("greeting", 1, ob);
  add_action("wakeup","wakeup");
  ::init();
}
int wakeup(string arg)
{
  object who;
  object me ; 
  me = this_player();
  if(!arg  || !who = present(arg,environment(this_player())))
      return notify_fail("你要叫醒誰？\n");
  if(arg != "old man" && arg != "man")
      return notify_fail("你要叫醒誰？\n");
  me->set_temp("quests/confuse",5); //基本上能進來這房間已經通過前面的quest的判定 不過補上指定who=本npc的判斷好了 避免wakeup 玩家 這種bug by blazakira 2010/11/7
  message_vision(HIW + "$N試著叫醒$n，但是一直叫不醒，$N腦袋中突然浮現一種治療方法 -- 「" + HIC + "靈魂出竅" + HIW + "」\n$N想不起來，到底這種刺激人體相關穴道的治療方法要到哪個門派找人協助，唉～\n" + NOR,me,who);
  return 1;
}
void greeting(object ob)
{
  if(ob->query("id") == "chuan liu")
  {
    if(!ob->query_temp("empty") && !ob->query_temp("follow"))
    {
      message_vision("$N覺得一個羞愧\，身為銀針門第一弟子，竟然被用暴力方法帶來此地，$N馬上拿著針往自已頭上插上去！\n",ob);
      ob->die();
      return ;
    }
    message_vision(CYN + "$N說道：既然被你已經被你用計騙來此地，我也認命了，來準備一些我需要的器材和藥品來施行靈魂出竅大法。\n" + NOR,ob);
    message_vision(CYN + "$N說道：你必需要有天靈丹一顆、三葉芝蘭之草一顆與蠍毒一份，這些東西都交給我後，我才能施行。\n" + NOR,ob);
  }
  ::greeting();
}

