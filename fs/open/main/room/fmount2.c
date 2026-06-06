//末日火山 by frequency
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "末日火山");
	set( "build", 24 );
  set ("long", @LONG
越往北方前行，地勢亦逐漸攀升，然而氣溫卻並未因此而下降，
反而明顯的越來越高。只見前方的高山頂上隱隱泛著紅光，似乎所有
高溫皆源自於山頂。
LONG);

  set("exits", ([
  "northup" : __DIR__"fmount3.c",
  "southdown" : __DIR__"fmount1.c",

               ]));
  set("outdoors", "/open/main");
  set("no_transmit",1);
  setup();
}

void init()
{
 object me = this_player();
 if(me->query("attribute") != "fire")
  {
    me->add("gin",-2*(me->query("max_gin"))/5);
    me->add("kee",-2*(me->query("max_kee"))/5);
    me->add("sen",-2*(me->query("max_sen"))/5);
  }
}
