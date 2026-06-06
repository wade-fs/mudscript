#include <room.h>
#include <ansi.h>
inherit NPC;

string do_heal();

void create()
{
set_name("殺手醫生",({"doctor"}) );
set("long","這是一個犯過錯老殺手，但是醫術超高會治療毒傷，所以並沒有被殺，\n
            如果你有需要的話，問他是否願意治療(heal)吧。\n");
set("gender","男性");
set("age",55);
set("combat_exp",200000);

set("inquiry",([ 
    "heal" : (: do_heal :),]));
setup();
}

int accept_fight(object me)
{
   return notify_fail("放過我吧！讓我度過餘生吧！我會治療(heal)。。。\n");
}

string do_heal()
{
  object who;

  who = this_player();
  message_vision("老人迅速地在$N身上各大穴插銀針，雙掌提氣按住你的背部\n",who);
  message_vision("閉上雙眼，運起黑牙神功\ 終 極 密 招-- 化氣成針\n",who);
  message_vision("感到有一道強烈的氣運走奇經八脈，令你渾身暢快不已\n",who);
  who->clear_condition();
  return "毒隨著銀針排出體外了\n";
}
