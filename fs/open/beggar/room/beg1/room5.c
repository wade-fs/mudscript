// Room: /u/g/guetenr/beggar/room/beg1/room5.c
inherit ROOM;

void create ()
{
  set ("short", "小坡");
  set ("long", @LONG
空曠的平野彷彿終年寂靜，蔓生的野草叢中隱約有著一條小路向西及東
綿延而去，行走至此卻是座小山坡，新雨後的草坡泛著細細的晶瑩，空氣裏
悠悠繚繞漫著青草的清馨，混著泥土濕潤蒸騰的氣息，卻是一種過分潔淨的
情調；北邊坡上一頂小小的布棚，細看來倒有些人影晃動其中。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"room4.c",
  "north" : __DIR__"room6.c",
  "west" : __DIR__"room7.c",
]));
  set("outdoors", "/open/");

  setup();
}
