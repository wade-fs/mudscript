// Room: /u/w/whatup/poison_hole/room22
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "懸崖");
  set ("long", @LONG
一登上這個懸崖，離地數百公尺，看著遙遠的地方，腳上不禁的發
抖。底下好像有一點異樣，應該爬下去觀察一下。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"room12",
]));
  set("outdoors", "/u/w");

  setup();
}
void init()
{
  add_action("use_rope","use");
  add_action("use_climb","climb");

}
int use_climb(string arg)
{
  object me = this_player();
  message_vision("$N利用雙手雙腳往下爬，但一個不小心，直接摔落山谷，並且發出啊啊啊啊啊啊的慘叫聲。\n",this_player());

  me->receive_wound("kee",me->query("max_kee")/2);
  me->receive_wound("sen",me->query("max_sen")/2);
  me->receive_wound("gin",me->query("max_gin")/2);

  me->move(__DIR__"room01.c");
    return 1;

}
int use_rope(string arg)
{
  object obj,me;
  me = this_player();
  if(!arg || arg != "rope" )
  {
    write("你要使用什麼？\n");
    return 1;
  }
  if( !obj = present("rope",me))
  {
    write("你身上沒這個東西。\n");
    return 1;
  }
  destruct(obj);
  if(random(3) == 1)
  {
  message_vision("$N一個不小心，直接摔落山谷，並且發出啊啊啊啊啊啊的慘叫聲。\n",this_player());
  CHANNEL_D->do_channel(this_object(),"mud",HIR + this_player()->query("name") + "發出一陣慘叫聲就從山上滾到山腳下了。\n"NOR);

  me->receive_wound("kee",me->query("max_kee")/2);
  me->receive_wound("sen",me->query("max_sen")/2);
  me->receive_wound("gin",me->query("max_gin")/2);

  me->move(__DIR__"room01.c");
    return 1;
  }
  message_vision("$N利用雙手雙腳順著繩索往下爬，好不容易終於爬到了下面的山洞。\n",this_player());
  me->move(__DIR__"hole01.c");

  return 1;
}
