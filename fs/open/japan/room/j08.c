inherit ROOM;

void create()
{
  set ("short", "北櫓");
  set ("long", @LONG
入口兩旁，守衛正查看著往來的人們，看看是否有通緝犯混在其
中。而二樓上方似乎也有守衛正透過狹間往下面監視著。往北可以進
入江戶大街。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "north" : __DIR__"j17.c",
    "south" : __DIR__"j07.c",
  ]));
  setup();
}
