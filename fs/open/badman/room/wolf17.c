inherit ROOM;
void create()
{
  set ("short","狼谷");
  set ("long", @LONG
這裡是狼谷谷壁突出的一塊小平台。往下看去，還可模糊地看見剛
剛所待的破廟及村莊的影子。但你心中很清楚一件事，摔下去絕對沒有
啥好下場。把你拉上來的人的武功一定非常厲害。谷壁有一條從上方懸
下來的藤蔓。
LONG);

  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 1 */
  "up" :__DIR__"wolf06.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/young.c" : 1,
]));

  setup();
}
