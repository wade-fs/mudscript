// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "學識廳");
  set ("long", @LONG
這是儒門高級儒生們學習學識的廳房，此地你可看到許多高
級儒生正坐在桌上研讀著四書五經，廳房的南邊是學識廳長老休
息及讀書的廂房，北邊是學識廳老師的廂房，東邊是通往中堂東
側。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"e3_s.c",
  "north" : __DIR__"e3_n.c",
  "west" : __DIR__"e2.c",
  "east" : __DIR__"r18.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/trainer.c" : 2,
]));

  setup();
}
