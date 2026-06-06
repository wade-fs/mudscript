
#include <room.h>
#include <ansi.h>
inherit NPC;

string do_askbluecard();
string askdag();

void create()
{
  set_name("喬小雨",({"joecy"}) );
  set("title",HIB"藍鳳組組長"NOR);
  set("long","原以為有機會看到她的廬山真面目，但是她全身籠罩著一股藍氣令你無法看清她的面孔與體\n"
    "態，傳說中她手中握有一把（絕世匕首），威力不凡看來還是問問她（藍鳳絕殺令）吧！\n");
  set("gender","女性");
  set("age",20);
  set("combat_exp",5000000);

  set("inquiry",([ 
    "藍鳳絕殺令" : (: do_askbluecard :),
    "絕世匕首"   : (: askdag :),
  ]));
  setup();
}

int accept_fight(object me)
{
  return notify_fail("一陣銀鈴般的笑聲：『小朋友，想死的話在來吧：）』！\n");
}

int accept_kill(object me)
{
  return notify_fail("一陣銀鈴般的笑聲：『小朋友，想死的話在來吧：）』！\n");
}

int accept_object( object me , object ob )
{
  object obj;

  if (me->query_temp("askdagger") != 1)
  {
    command("say 甚麼東西啊?");
    return 0;
  }
  if(ob->query("id") == "juchi")
  {
    command("say 這是朱雀匕首…");
    me->set_temp("fire",1);
  }
  else if(ob->query("id") == "chilo")
  {
    command("say 這是青龍匕首…");
    me->set_temp("wind",1);
  }
  else if(ob->query("id") == "sawu")
  {
    command("say 這是玄武匕首…");
    me->set_temp("earth",1);
  }
  else if(ob->query("id") == "bihu")
  {
    command("say 這是白虎匕首…");
    me->set_temp("ice",1);
  }
  destruct(ob);
  if (me->query_temp("fire")  && me->query_temp("wind")
      && me->query_temp("earth")  && me->query_temp("ice") )
  { //已經給了四把匕首，可以練成絕世匕首
    command("nod");
    command("say 你已經給我四把匕首了，等我一下。");
    me->set("make_dagger",1);
    message_vision("喬小雨消失在黑暗之中……過了良久，再次出現在你的面前。",me);
    obj = new("/open/killer/headkill/obj/world_dag.c");
    obj->move(this_player());
    message_vision("$N給$n一把"+obj->name()+"。\n",this_object(),this_player());
    command("say 拿去吧！這是一把煉化型的匕首，它會記憶你的氣，如果不見的話，再來找我！");
    me->delete_temp("fire");
    me->delete_temp("ice");
    me->delete_temp("earth");
    me->delete_temp("wind");
  }
  else
    command("say 仍沒湊齊四把匕首了，繼續補齊吧。");
  return 1;
}

string do_askbluecard ()
{
  object obj, me=this_player();

  if (me->query_temp("head") != 7)
    return "根本沒有通過試煉！滾！";
  else
  {
    command("grin");
    command("say 想得到藍鳳絕殺令的話，服下瞬移丹去那個地方找人要吧！");
    obj = new("/open/killer/headkill/obj/movepill.c");
    obj->move(this_player());
    message_vision("$N給$n一顆"+obj->name()+"。\n",this_object(),this_player());
    me->set_temp("head",8);
    return "拿到藍鳳絕殺令的話，自然可以驅動藍鳳組。";
  }
}

string askdag()
{
  object me=this_player();

  command("nod");
  command("say 那是殺手的超強匕首，必須由四門匕首練成，那四把匕首給我，我就幫你煉。");
  me->set_temp("askdagger",1);
  return "四門是指朱雀、青龍、白虎、玄武。";
}
