inherit ROOM;

void create()
{
  set ("short", "東櫓");
  set ("long", @LONG
入口兩旁，守衛正查看著往來的人們，看看是否有通緝犯混在其
中。而二樓上方似乎也有守衛正透過狹間往下面監視著。往東可以進
入入口。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "east" : __DIR__"j06.c",
    "west" : __DIR__"j03.c",
  ]));
  setup();
}
