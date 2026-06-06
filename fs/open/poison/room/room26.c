inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG
走道這裡 ,已經可以清楚的聽見流水的聲音 ,西邊有一條陡直的
山路 ,大概是有什麼高人住在上面吧 .....

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room25",
  "north" : __DIR__"room27",
  "westup" : __DIR__"room32",
]));
  setup();
}


