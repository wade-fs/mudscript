// Room: /u/g/guetenr/beggar/room/beg1/room27.c
inherit ROOM;

void create ()
{
  set ("short", "石道");
  set ("long", @LONG
青石板鋪成的街道向兩側綿延過去，天空中時時飄著輕盈如飛花的細細
雨絲，沾得路面潤著青青的苔綠；行走至此人跡漸少，但聞湯湯流水如奏宮
商，更有那兩岸楊柳綠袖相招，枝頭鶯燕穿梭啁啾，聊慰寂寥之情。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room28.c",
  "east" : __DIR__"room25.c",
]));
  set("outdoors", "/open/");
  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/exp_3000beg.c" : 1,
  __DIR__"npc/exp_1000beg.c" : 1,
]));

  setup();
}
