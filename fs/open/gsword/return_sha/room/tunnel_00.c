// by Alucard 2009/08
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
#include "tunnel_msg.c"
void create () {
        set("short","幽暗隧道");
		set("long", (: printf_msg :) );
        set("evil", 1);
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
        set("exits", ([
            "northeast" :  __DIR__"tunnel_01",
      ]));
        setup();
}

void init()
{
  object me;
  me = this_player();
  if(me->query_temp("quest/return_sha") && me->query_temp("quest/return_sha")==8)
  {
  message_vision(HIW + " 鄭士欣聽到$N的腳步聲，連忙開啟隧道口，讓$N出來。\n" + NOR,me);
  me->move("/open/gsword/room/g5-1");
  }
  return ;
}
