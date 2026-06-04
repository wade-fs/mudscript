inherit ITEM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>

void create()
{
  set_name(MAG + "忍者裝束" + NOR,({"ninja-eq"}));
  set("long",HIC + "這是傳說中被封印的忍者裝備(open ninja or close ninja)。" + NOR);
  set("unit","套");
  set("no_auc",1);
  set("no_put",1);
  set("no_sell",1);
  set("no_give",1);
  set("no_drop",1);
  set("no_steal",1);
  set("no_save",1);
  set("no_get",1); //目前並非開放的eq 未來開放時 另做考量 
  setup();
}

int query_autoload()
{
  return 1;
}

void init() 
{
  object me=this_player();
  object ob;
  ob=present("ninja-eq",me);
  if(ob&&ob->name()==MAG + "忍者裝束" + NOR)
  {
    add_action("do_open","open");
    add_action("do_close","close");
  }
}

int do_open(string str) 
{
  object me,eq01,eq02,eq03,eq04,eq05,eq06,eq07,eq08,eq09,eq10,eq11,eq12,eq13;
  object ob;
  string name;
  me=this_player();
  if(!str||sscanf(str, "%s",name)!=1)
    return 0;
  if(name != "ninja")
    return 0;
  ob=present("ninja-eq",me);
  if(ob->query_temp("ninjaeq/open")==1)
    return notify_fail("忍者裝束的封印已經解除了﹗\n");
  message_vision(HIC + "\n$N運用忍術解除封印, $N的忍者裝束漸漸換化成\許\多裝備。\n\n" + NOR,me);
  eq01 = new(__DIR__"nshield");
  eq02 = new(__DIR__"nboots");
  eq03 = new(__DIR__"narmband");
  if(userp(me))
    eq04 = new(__DIR__"ncloth");
  else
    eq04 = new(__DIR__"ninja-cloth");
  eq05 = new(__DIR__"nhands");
  eq06 = new(__DIR__"nhelmet");
  eq07 = new(__DIR__"nleggings");
  eq08 = new(__DIR__"nneck");
  eq09 = new(__DIR__"npants");
  eq10 = new(__DIR__"nring");
  eq11 = new(__DIR__"nsurcoat");
  eq12 = new(__DIR__"nwaist");
  eq13 = new(__DIR__"nwrists");
// 原則上可以偷竊 作為降低npc防禦的手段 但是不能存(int query_autoload(){return 0;}) by blazakira
//  eq01->set("no_steal",1);
  eq01->set("no_drop",1);
  eq02->set("no_drop",1);
  eq03->set("no_drop",1);
  eq04->set("no_drop",1);
  eq05->set("no_drop",1);
  eq06->set("no_drop",1);
  eq07->set("no_drop",1);
  eq08->set("no_drop",1);
  eq09->set("no_drop",1);
  eq10->set("no_drop",1);
  eq11->set("no_drop",1);
  eq12->set("no_drop",1);
  eq13->set("no_drop",1);
  if (me->query("ninjaeq/getshield")==1) eq01->move(me);
  if (me->query("ninjaeq/getboots")==1) eq02->move(me);
  if (me->query("ninjaeq/getarmband")==1) eq03->move(me);
  if (me->query("ninjaeq/getcloth")==1) eq04->move(me);
  if (me->query("ninjaeq/gethands")==1) eq05->move(me);
  if (me->query("ninjaeq/gethelmet")==1) eq06->move(me);
  if (me->query("ninjaeq/getleggings")==1) eq07->move(me);
  if (me->query("ninjaeq/getneck")==1) eq08->move(me);
  if (me->query("ninjaeq/getpants")==1) eq09->move(me);
  if (me->query("ninjaeq/getring")==1) eq10->move(me);
  if (me->query("ninjaeq/getsurcoat")==1) eq11->move(me);
  if (me->query("ninjaeq/getwaist")==1) eq12->move(me);
  if (me->query("ninjaeq/getwrists")==1) eq13->move(me);
  ob->set_temp("ninjaeq/open",1);
  me->set_temp("ninjaeq/open",1);
  return 1;
}

int do_close(string str)
{
  object me,ob;
  string name;
  me=this_player();
  ob=present("ninja-eq",me);
  if(!str||sscanf(str, "%s",name)!=1)
    return 0;
  if(name != "ninja")
    return 0;
  if(me->query_temp("ninjaeq/open")!=1)
    return notify_fail("你並沒有開啟忍者裝束！\n");
  if(ob->query_temp("ninjaeq/open")==1) {
    if (me->query("ninjaeq/getwrists")==1) destruct(present("ninja bracelet",me));
    if (me->query("ninjaeq/getwaist")==1) destruct(present("ninja belt",me));
    if (me->query("ninjaeq/getsurcoat")==1) destruct(present("ninja surcoat",me));
    if (me->query("ninjaeq/getring")==1) destruct(present("ninja ring",me));
    if (me->query("ninjaeq/getpants")==1) destruct(present("ninja pants",me));
    if (me->query("ninjaeq/getneck")==1) destruct(present("ninja gem",me));
    if (me->query("ninjaeq/getleggings")==1) destruct(present("ninja legging",me));
    if (me->query("ninjaeq/gethelmet")==1) destruct(present("ninja helmet",me));
    if (me->query("ninjaeq/gethands")==1) destruct(present("ninja hands",me));
    if (me->query("ninjaeq/getcloth")==1) destruct(present("ninja cloth",me));
    if (me->query("ninjaeq/getarmband")==1) destruct(present("ninja armband",me));
    if (me->query("ninjaeq/getboots")==1) destruct(present("ninja boots",me));
    if (me->query("ninjaeq/getshield")==1) destruct(present("ninja shield",me));
    me->delete_temp("ninjaeq/open");
    ob->delete_temp("ninjaeq/open"); 
    message_vision(HIC + "\n$N利用忍術再度將忍者裝束封印起來。\n\n" + NOR,me);
  }
  return 1;
}
