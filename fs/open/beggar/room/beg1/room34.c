// Room: /u/g/guetenr/beggar/room/beg1/room34.c
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

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room36.c",
  "east" : __DIR__"room32.c",
]));
  set("outdoors", "/u/g");
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/exp_3000beg.c" : 1,
  __DIR__"npc/exp_3000beg2.c" : 1,
]));

  setup();
}
