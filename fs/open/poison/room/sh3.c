// Room: /u/r/ranko/room/sh3.c
inherit ROOM;

void create ()
{
  set ("short", "茶店");
  set ("long", @LONG
一間供人飲茶休憩的小店，內裡擺了幾張桌子供人飲茶聊天，
不少村民常在工作完畢後來這裡喝杯茶，小憩一番。店裡除了賣各
種茶品之外，亦備有一些小菜供人取用。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"v2-4.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/mer3.c" : 1,
]));
  set("light_up", 1);

  setup();
}
