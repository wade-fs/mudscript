// Room: /u/m/moner/room/room20.c
inherit ROOM;

void create ()
{
  set ("short", "後院");
  set ("long", @LONG

這裡是魔刀門內栽花植草的地方，因門人多為習刀嗜武之人，鮮少有
愛花惜草之人，所以院內少有人照料，奇花異草和雜花雜草生長在一起
，不仔細看的話是分辨不出來的，彩蝶翩翩的穿梭在花叢間，蜜蜂辛勤
採著蜜。

LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room14.c",
  "east" : __DIR__"room21.c",
]));

  setup();
}
