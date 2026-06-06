inherit ROOM;

void create()
{
  set ("short", "小通路");
  set ("long", @LONG
兩旁圍牆中間，圍出一條只容兩個人錯身的通路。通路裡面似乎
有守衛在正在巡守並且透過狹間監視著圍牆外的一舉一動。小通路向
北延伸，不知道會連接到哪邊。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"camp01.c",
    "north" : __DIR__"j15.c",
  ]));
  setup();
}
