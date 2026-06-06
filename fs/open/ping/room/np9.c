inherit ROOM;

void create ()
{
  set ("short", "前庭");
  set ("long", @LONG
你看到兩位弟子在此拆招, 武藝雖然不高, 但其身法出手之嚴謹
, 卻在在顯露出名門的風範, 你不由得想到這幾年, 段家門人在江湖
上好生興旺, 不是沒有道理的...

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"np6",
  "north" : __DIR__"np12",
  "east" : __DIR__"np7",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/ping/npc/disciple1.c" : 2,
]));

  setup();
  replace_program(ROOM);
}
