// Room: /open/badman/room/t2.c

inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG
你慢慢的往前走，眼睛總算是稍微能夠適應這裡的黑暗。四周
的山壁上竟長滿了一根根的藤蔓，讓你不禁感到奇怪，在地道中沒
有陽光這些植物怎麼能夠生長呢?

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : "/open/badman/room/t3",
  "south" : "/open/badman/room/t1",
]));

  setup();
}
