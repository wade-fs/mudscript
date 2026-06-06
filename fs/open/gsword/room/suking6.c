// Room: /u/s/smore/room/suking/suking6.c

inherit ROOM;

void create ()
{
  set ("short", "府衙大廳");
  set ("long", @LONG
走近將軍席，你的心裡充滿了恐懼與不安，大紅色的地毯襯
托出將軍的氣派非凡，抬頭望去，將軍席就在你的北方不遠處，
左右兩邊則是左侍衛房及右侍衛房
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : "/open/gsword/room/suking3",
  "west" : "/open/gsword/room/suking5",
  "north" : "/open/gsword/room/suking8+",
  "east" : "/open/gsword/room/suking7",
]));

  set("light_up", 1);

  setup();
}
