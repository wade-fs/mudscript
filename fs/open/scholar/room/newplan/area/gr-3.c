// Room: /u/s/sueplan/test/test
inherit ROOM;

void create ()
{
  set ("short", "八卦陣角");
  set ("long", @LONG

你步入此地﹐看到眼前有一人用惡狠狠的眼神瞪著你
此地是八卦陣的陣角﹐看來他擋在你面前﹐打倒他不可了。

LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"q4.c",
  "enter" : __DIR__"q5.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/room/newplan/npc/guard3.c" : 1,
]));

  setup();
}
 int valid_leave(object me, string dir)
 {
if(dir=="enter"&&present("guard",environment(me)))
  {
return notify_fail("你發覺有人擋在你面, 不讓你過!!!\n");
   }
  return 1;
}
