// Room: /u/g/guetenr/beggar/room/beg1/room25.c
inherit ROOM;

void create ()
{
  set ("short", "石道");
  set ("long", @LONG
青石板鋪成的街道向兩側綿延過去，天空中時時飄著輕盈如飛花的細細
雨絲，沾得路面潤著青青的苔綠；行走至此人跡漸少，但聞湯湯流水如奏宮
商，更有那兩岸楊柳綠袖相招，枝頭鶯燕穿梭啁啾，聊慰寂寥之情。
LONG);

  set("outdoors", "/open/");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"room24.c",
  "west" : __DIR__"room27.c",
  "south" : __DIR__"room26.c",
]));

  setup();
}
