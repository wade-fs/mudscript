// Room: /u/r/red/room/flower.c
inherit ROOM;

void create ()
{
  set ("short", "北廂房");
  set ("long", @LONG
這是學識廳老師的廂房，只見房中桌上十分的整齊，桌上盡放置
著許許多多的經典，仔細觀看桌上的書本，每本看起來都十分的老舊
，便可知道老師多麼專研於學識的研究。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"e3.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/scholar/npc/literate.c" : 1,
]));

  setup();
}
