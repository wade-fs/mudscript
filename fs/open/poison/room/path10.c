// Room: /open/poison/room/path10
inherit ROOM;

void create ()
{
  set ("short", "蝙蝠洞");
  set ("long", @LONG
當你走入這洞穴時，引起數以千計的蝙蝠驚動，滿洞飛
舞的蝙蝠幾乎遮住你的視野，隱約間可看到這是一個四壁凹
凹凸凸的鐘乳石洞，四處棲息著大小不同的蝙蝠，其中有一
隻十分奇特的大蝙蝠。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path5",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/poison/npc/bat" : 2,
  "/open/poison/npc/batking" : 1,
]));

  setup();
}
