// Room: /u/s/smore/room/suking/suking13.c

inherit ROOM;

void create ()
{
  set ("short", "監獄");
  set ("long", @LONG
這是蜀中城關犯罪的地方，裡面有形形色色的犯人，你的西
方，便是鐵籠.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/suking4",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/jail" : 1,
]));

  setup();
}
