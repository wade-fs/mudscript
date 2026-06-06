// Room: /u/g/guetenr/beggar/room/beg1/room30.c
inherit ROOM;

void create ()
{
  set ("short", "水田");
  set ("long", @LONG
走在阡陌縱橫的田埂上，空氣中滿是泥土的芬芳，你悠然地漫步著，偶
爾俯身細細觀望身旁的秧田，淡淡籠罩著的青煙中，初生的嫩芽上尚凝著晨
露點點，輝映著點點晶瑩的光芒，襯著那清澈水面的倒影，渲染成一地的柔
綠；水田向四方漫去，任你隨意賞玩。

LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room28",
  "south" : __DIR__"room32.c",
  "west" : __DIR__"room31.c",
]));

  setup();
}
