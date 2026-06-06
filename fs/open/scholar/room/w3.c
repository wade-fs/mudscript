// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "計謀廳");
  set ("long", @LONG
這是儒門高級儒生們研究計謀的廳房，此地你可看到許多高
級儒生正坐在桌上研究著兵法的運用，廳房的南邊是計謀廳長老
休息及讀書的廂房，北邊是計謀廳老師的廂房，西邊是通往中堂
西側。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"w3_s.c",
  "west" : __DIR__"r16.c",
  "north" : __DIR__"w3_n.c",
  "east" : __DIR__"w2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/trainer.c" : 2,
]));

  setup();
}
