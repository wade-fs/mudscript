// Room: /u/m/moner/water/mblade/r4.c
inherit ROOM;

void create ()
{
  set ("short", "密室");
  set ("long", @LONG

這是一間密室，四周光線極弱，眼前有一位白髮飄散，眼神凌
立的人，可是此室散發出難聞臭味，眼前的人似乎被關在這。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"r3.c",
]));
set("objects",([
"/daemon/class/blademan/npc/old-man.c":1,
]));
set("no_transmit", 1);
  setup();
}
void init()
{
add_action("do_jump","to-jump");
}
int do_jump(string str)
{
  object me;
  me=this_player();
if(me->query_temp("can_jump")!=1)
return notify_fail("跳....跳....你要跳河呀！\n");
  if( str != "hole" )
return notify_fail("不要在地上亂爬啦？\n");
message_vision("你找到一個秘洞，就奮力往洞內一跳！\n",me);
me->move("/daemon/class/blademan/bladeroom.c");
me->set_temp("can_jump",0);
  return 1;
}
