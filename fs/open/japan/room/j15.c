inherit ROOM;

void create()
{
  set ("short", "小通路");
  set ("long", @LONG
兩旁圍牆中間，圍出一條只容兩個人錯身的通路。通路裡面似乎
有守衛在正在巡守並且透過狹間監視著圍牆外的一舉一動。往東有一
小段樓梯往上，原來這是通往北櫓二樓的通道。

LONG);

  set("light_up", 1);
  set("outdoors", "/open/japan/room");
  set("exits", ([ /* sizeof() == 2 */
    "eastup" : __DIR__"j16.c",
    "south" : __DIR__"j14.c",
  ]));
  setup();
}
