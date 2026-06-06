// Room: /u/g/guetenr/beggar/room/beg1/room28.c
inherit ROOM;

void create ()
{
  set ("short", "石道");
  set ("long", @LONG
走在阡陌縱橫的田埂上，空氣中滿是泥土的芬芳，你悠然地漫步著，偶
爾俯身細細觀望身旁的秧田，淡淡籠罩著的青煙中，初生的嫩芽上尚凝著晨
露點點，輝映著點點晶瑩的光芒，襯著那清澈水面的倒影，渲染成一地的柔
綠；水田向四方漫去，任你隨意賞玩。
LONG);

  set("outdoors", "cs");
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"bank37.c",
  "north" : __DIR__"room27.c",
  "west" : __DIR__"room30.c",
]));

  setup();
}
