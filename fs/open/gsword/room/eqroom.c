// Room: /open/gsword/room/wghouse.c
//強化greeting的判斷以減少錯誤 by blazakira 2011/6/2

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "仙劍ソ藏劍室");
  set ("long", @LONG
這裡是仙劍師兄弟們為了造福剛login沒EQ的玩家所特別開闢的房間 ,
看著地上堆滿的EQ ,你不禁誠心感謝眾師兄弟的熱心.
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "down" :"/open/gsword/room/g5-1.c",
]));

  set("light_up", 1);
  set ( "no_transmit", 1 );
  set("no_clean_up",1);
  set("no_fight",1);
  set("valid_startroom", 1);
  setup();
  call_other("/obj/board/swordsman_b2","????");
}

void init()
{
  object who;
  add_action("do_pass","pass");
  add_action("do_verify","verify");
  if( interactive( who= this_player()))
  {
    remove_call_out("greeting");
    call_out("greeting", 0, who);
  }
}

int do_pass()
{
  object me=this_player();
  me->move("/open/ping/room/road3");
  return 1;
} 

int do_verify(string arg)
{
  object me,ob;
  me=this_player();
  ob=new("/autoload/swordsman/sun_sword_book");
  if( arg!="sun_sword_book")
  {
    write("你要申請什麼\n");
    return 1;
  }
  else if(me->query("quest/sun_fire_sword",1)!=1)
  {
    write("你拿了這東西也沒用\n");
    return 1;
  }
  else if( present(ob,me) )
  {
    write("你已經有一本了\n");
    return 1;
  }
  else
  {
    write("好好保管此書, 別再弄丟了.\n");
    ob->move(me);
    return 1;
  }
}

int greeting (object who)
{
  if (!who) return 1;
  if (who->query("title")==HIR + "殺手全力追殺的人頭" + NOR)
  {
    message_vision(HIY + "劍士頭目的靈魂傳送了訊息過來：么\壽！！殺手人頭ㄋㄟ，頭目也幫不了你了！！\n" + NOR,who);
  }
  //解風青雲後之title
  else if (who->query("family/family_name")=="仙劍派" && who->query("quests/sunfire")==1)
  {
    if (who->query("title")!="仙劍聖者")
    {
      message_vision(HIY + "劍士頭目的靈魂傳送了訊息過來：你的title 混亂了..我幫你回復過來。\n" + NOR,who);
      who->set("title",HIC + "仙劍聖者" + NOR);
    }
  }
  else if (who->query("family/family_name")=="仙劍派" && who->query("quest/sun_fire_sword")==1)
  {
    if(who->query("title")!="仙劍派絕代劍俠")
    {
      message_vision(HIY + "劍士頭目的靈魂傳送了訊息過來：你的title 混亂了..我幫你回復過來。\n" + NOR,who);
      who->set("title","仙劍派絕代劍俠");
    }
  }
  else if (who->query("family/family_name")=="仙劍派" && who->query("get_sha_sp")==1)
  {
    if(who->query("title")!="仙劍派一代劍俠")
    {
      message_vision(HIY + "劍士頭目的靈魂傳送了訊息過來：你的title 混亂了..我幫你回復過來。\n" + NOR,who);
      who->set("title","仙劍派一代劍俠");
    }
  }
  else if (wizardp(who))
  {
    message_vision(HIY + "劍士頭目的靈魂傳送了訊息過來：咦？"+who->query("name")+HIY"專程來這呀？歡迎～歡迎～～\n" + NOR,who);
  }
  else
  {
    message_vision(HIY + "劍士頭目的靈魂傳送了訊息過來：你的title 混亂了..我幫你回復過來。\n" + NOR,who);
    who->set("title","仙劍派小小弟子");
  }
}
