// Room: /open/gsword/room/g6-6.c
inherit ROOM;

void create ()
{
  set ("short", "思過崖");
  set ("long", @LONG
眼前正是仙劍思過崖，每當弟子犯下大錯時，往往會被罰在崖上面璧
思過，北方有個小山洞，是思過之所在，站在崖邊，視野異常遼闊，極目
遠眺，甚至能看到大陸極東之新京，當你轉頭往西方瞧去，想看看仙劍禁
地是何模樣，可惜事與願違，一面大壁聳立在崖西，完全擋住了你的視線
。
 
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword/room");

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/gsword/room/g6-7.c",
  "eastdown" : "/open/gsword/room/g6-5",
]));

  setup();
}
