// Room: /open/death/room/h1-1
inherit ROOM;

void create ()
{
  set ("short", "第一殿--正廳");
  set ("long", @LONG
這裡是第一殿，由秦廣明王管轄，居中而坐的便是秦廣明王，大廳
右邊牆上寫著『若要來離此關，需要急早行善』，左邊牆上寫著『輪迴
分六道，轉世變三生』，你看了不禁恐慌起來..........
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"h1-6",
]));
  set("light_up", 1);

  setup();
}
