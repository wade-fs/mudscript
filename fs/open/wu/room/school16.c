// Room: /open/wu/room/school16
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
這是正晴武館二樓穿堂。由於這兒是走廊的角落，所以顯得有一點陰暗
，看到東邊透出一些燈光，你不由地想去看一看究竟。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/wu/room/school15",
  "east" : "/open/wu/room/school17",
]));

  set("light_up", 1);
  setup();
}
