// Room: /u/m/moner/room/room21.c
inherit ROOM;

void create ()
{
  set ("short", "後院");
  set ("long", @LONG

這裡是魔刀門內栽花植草的地方，因門人多為習刀嗜武之人，鮮少有
愛花惜草之人，所以院內少有人照料，奇花異草和雜花雜草生長在一起
，不仔細看的話是分辨不出來的，彩蝶翩翩的穿梭在花叢間，蜜蜂辛勤
採著蜜。
         清風微微的吹拂著，一隻蝴蝶不小心飛到你身旁了。
LONG);

  set("light_up", 1);
  set("outdoors", "wind");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room20.c",
  "north" : __DIR__"room22.c",
]));

  setup();
}
