#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "走道");
  set ("long", @LONG
南邊的門(door)似乎不同於之前所看到的那些門，比較起來，這一扇門似乎感
覺高貴了許多，看來住在這間房間的人應該是一個滿重要的人吧。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/death" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "door" : "這扇門並沒有把手可以轉動，看來用普通的方法是打不開的。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"b_r06",
]));

  setup();
}
void init()
{
add_action("do_pray","pray");
}
int do_pray(string arg)
{
object me;
me=this_player();
if(!arg||arg!="door")
return notify_fail("你要祈禱什麼？\n");
if(me->query_temp("quest_corpse")!=2)
return notify_fail("你輕聲的向大門祈禱，卻什麼是也沒發生。\n");
else{
tell_object(me,"你似乎感覺的到有人在跟你道謝....\n\n");
message_vision(HIB + "      $N的身體突然被一團藍光包圍住，整個人騰空消失了！！\n\n" + NOR,me);
tell_object(me,"你穿過了門板，進入了房間內。\n");
me->move(__DIR__"b_q");
return 1;
}
}
