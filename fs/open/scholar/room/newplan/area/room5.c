// Room: /u/s/sueplan/newplan/area/room5
inherit ROOM;

void create ()
{
  set ("short", "天同星");
  set ("long", @LONG
武王所以能夠討紂成功，稱霸天下，原是託父親文王貢獻甚多。後
來，幫助武王，揚威四方的許多軍師，將軍、忠臣、都是文王所聘用的
。就是說，文王善於調和融合，使部屬們忠心愛國。所以雖然然壯志未
酬，但文王去世後，太白金星便請他的靈魂永留『天同星』，掌管『融
合』和『溫順』。

LONG);

  set("no_transmit", 1);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"room4.c",
  "north" : __DIR__"room6.c",
]));

  setup();
}
