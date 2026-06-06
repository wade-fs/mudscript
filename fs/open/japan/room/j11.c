inherit ROOM;

void create()
{
  set ("short", "石垣上");
  set ("long", @LONG
海風徐徐吹來，可以看到南大路橋來來往往的人群。港口來往的
商船，似乎遠方還有商船正在等待這入港。守衛來回巡邏並且透過石
狹間往下嚴密監視在小廣場往來的人群。往南可以通往東櫓二樓

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 3 */
    "eastdown" : __DIR__"j10.c",
    "south" : __DIR__"j13.c",
    "east" : __DIR__"j12.c",
  ]));
  setup();
}
