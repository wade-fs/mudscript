// Room: /u/g/guetenr/beggar/room/beg2/clr29.c
inherit ROOM;

void create ()
{
  set ("short", "長老室");
  set ("long", @LONG
這裡是長老的房間，他們專管幫派弟子生活上的鎖事，包
括傳授武功、清除叛徒及擾亂幫派安寧的傢伙，你想叛幫嗎？
勸你最好三思.....

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"clr31.c",
  "west" : __DIR__"clr30.c",
  "out" : __DIR__"clr26.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/beggar/room/beg1/npc/leader_su.c" : 1,
]));

  setup();
}
