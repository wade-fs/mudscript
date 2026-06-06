// Room: /u/d/dhk/room/richrm1.c-------------by dhk 2000.5.11
//補上玩家人物是否存在的判斷 by blazakira 2011/7/11

inherit ROOM;
#include <ansi.h>
#include <room.h>
#include "/open/open.h"

void create ()
{
  set ("short", "宏禧山莊─莊門口");
  set ("long", @LONG
此地即是素有天下第一莊之稱的§宏禧山莊§。
傳聞中莊主是世界首富，不但富可敵國，其莊上門僕
也都是一些武林名宿，而且山莊神秘莫測是一個充滿
傳說之地。正當你仔細一瞧後發現，這大門雖與一般
豪宅無異，但特殊的是它竟然造在兩座山山壁之間，
相當令人詫異。如此推斷那傳說中的山莊竟然是整座
的山谷了，實在很難以相信呀！

LONG);

  set("outdoors", "/u/d");
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
    "south" : "/open/main/room/d7",
//    "enter" : "/u/d/dhk/workroom.c",
  ]));
  set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/guard.c" : 1,
  ]));

  setup();
}

void init()
{
//  remove_call_out("lookhoho");
  call_out("lookhoho",1,this_player());
}

void lookhoho(object who)
{
  int i,flag;
  mixed all;
  object obj,lee,box;

  if(!who) return;
  if(who->query_temp("find_moon") != 8) box=new("/open/ping/questsfan/obj/box.c");
  else box=new("/open/dancer/obj/note.c");

  flag=0;
  all=all_inventory(environment(who));
  for(i=0;i<sizeof(all);i++)
  {
    obj=all[i];
    if(obj->query("id")=="grandfather lee" && who->query_temp("goodman") && who->query_temp("box_ok")==0)
    {
      lee=obj;
      flag=1;
    }
  }
  if(flag)
  {
    tell_object(who,"謝謝你護送我家老爺回來，非常感謝。\n");
    tell_object(who,"我家老爺交代我將這禮物送你。\n");
    box->move(who);
    who->set_temp("box_ok",1);
    destruct(lee);
  }
}
/*
int valid_leave(object who,string dir)
{
  if(dir=="enter"&&present("leespace guard",environment(who)))
  {
    if(who->query("goodman")!=1)
    {
      tell_object(who,"山莊守衛怒喝 : 閒雜人等休想進去一步\n");
      return notify_fail("山莊守衛怒喝 : 閒雜人等休想進去一步\n");
    }
    return :: valid_leave(who,dir);
  }
  return :: valid_leave(who,dir);
}
*/
