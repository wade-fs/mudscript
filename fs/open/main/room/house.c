inherit ROOM;

void create ()
{
  set ("short", "茅草屋");
  set ("long", @LONG
這是一間小小的茅草屋，這裡有個老頭，似乎正在哀嚎，不知道
所為何事？
LONG);

  set("objects", ([
  "/open/doctor/npc/oldman" : 1,
]));
  set("exits", ([
  "east" : __DIR__"m23",
]));
  setup();
}
