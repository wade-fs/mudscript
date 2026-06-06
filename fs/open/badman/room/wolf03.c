inherit ROOM;
void create()
{
  set ("short","狼谷");
  set ("long", @LONG
這裡是惡人谷附近的一個小山谷 ,映入眼前的 ,除了形勢陡峻的谷地
外 ,便是結伴成群的狼 .但這些狼兒卻是好像受過訓練一般 ,只是看著你
 ,而不攻擊 .

LONG);

  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"wolf01.c",
  "northwest" : __DIR__"wolf06.c",
  ]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/wolf.c" : 2,
]));
  setup();
}
