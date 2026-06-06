#include <room.h>
#include <ansi.h>

inherit F_VENDOR;
string recover()
{
  object who;
  string str;
  int rec_time=0;

  who = this_player();

  rec_time=who->query_temp("recove");
  if (who->query_temp("power")==1)
    return "等回復完再來吧！" ;
  if (rec_time >10)
    return "抱歉，你最近身體已經不適合再回復了";
  str = "回復一次一兩黃金，\n";
  if( !who->can_afford(10000) ) 
  {
    str += "錢不夠啊！那就對不起了。\n";
    return str;
  }
  else 
  {
    who->pay_money(10000);
    message_vision("$N付給他一筆錢。\n", who);
    message_vision("只見他雙手運氣後，似乎有一股金色光芒射入你的體內\n",who);
    message_vision("你感到體內有一股溫暖的氣走遍經脈\n",who);
    command("say 想動也可以，要過一會才會回復體力");
    who->set_temp("power",1);
    rec_time=rec_time+1;
    who->set_temp("recove",rec_time);
    call_out("power",4,who);
    return "充滿體力的感覺真好";
  }
}

int power (object who)
{
  tell_object(who,"你感到體內湧出一股充沛的體力，看來你的體力回復了\n");
  who->set_temp("power",0);
  who->receive_heal("kee",250);
  return 1;
}

void create()
{
set_name("氣功\師",({"rester"}) );
set("long","此人乃天山派的最終弟子，當年天山派被滅時，葉孤城路過救了他一命\n
            為了報恩，決定加入黑牙聯，專門替殺手們回復體能狀況。\n
            想回復的話，可以問他有關(recover)的事。\n");
set("gender","男性");
set("age",47);
set("combat_exp",200000);

set("inquiry",([
    "recover" : (: recover :), 
    ]));
setup();
}

int accept_fight(object me)
{
  return notify_fail("放肆！連葉孤城都對我禮遇三分，居然想挑戰我\n");
}
int accept_killer(object me)
{
  return notify_fail("放肆！連葉孤城都對我禮遇三分，居然想砍我？\n");
}
