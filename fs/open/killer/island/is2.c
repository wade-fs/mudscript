// Room: /u/u/unfinished/room/is2.c
inherit ROOM;

void create ()
{
  set ("short", "斜坡");
  set ("long", @LONG
西高東低的斜坡, 遍地都是堅硬的大岩石, 岸邊只有幾株乾枯的樹幹, 荒涼
無生氣, 看來這座島應該是做荒島吧. 北邊是樹林, 樹木長的十分高大, 就算在
陽光普照的天氣, 北邊的樹林看起來還是十分陰森. 再往西邊爬上去便是石丘了
.

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"is1",
  "east" : __DIR__"is3.c",
]));
  set("outdoors", "/u/u");

  setup();
}
