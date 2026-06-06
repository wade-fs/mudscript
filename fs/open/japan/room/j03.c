inherit ROOM;

void create()
{
  set ("short", "小廣場");
  set ("long", @LONG
寬廣的小廣場上，北邊有高聳的石垣正擋在前方通路，而上方似
乎有不少守衛正透過石狹間往下監視著人們的一舉一動。東西兩邊各
有一個櫓，成包圍之勢圍住，要是輕舉妄動可能會同時受到三方的攻
擊。東方的櫓下方似乎有通道可以通行，看起來進入江戶的真正入口
在這邊。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"j04.c",
    "south" : __DIR__"j02.c",
  ]));
  setup();
}
