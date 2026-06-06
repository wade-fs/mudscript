// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "北廂房");
  set ("long", @LONG
這是計謀廳老師的廂房，只見房中桌上十分的凌亂，桌上盡放置
著許許多多不同的地形圖，仔細觀看地形圖上有著許許多多的記號
，便可知道老師多麼專研於計謀之使用。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"w3.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/plan_teacher.c" : 1,
]));

  setup();
}
