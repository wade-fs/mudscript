inherit ROOM;

void create()
{
  set ("short", "石垣上");
  set ("long", @LONG
通過狹長的通道之後，好不容易登上石垣上方。石垣上守衛來回
嚴密巡視，避免有人趁機進來搗亂。南方有通路可以通往西櫓二樓。
石垣則往東方繼續延伸。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"j05.c",
    "west" : __DIR__"j11.c",
  ]));
  setup();
}
