// Room: /u/o/ookami/newarea/aa3.c 
inherit ROOM;
 
void create ()
{
  set ("short", "點蒼山腰");
  set ("long", @LONG
你已經走到點蒼山的山腰上,深深的吸一口氣,這裡的空氣比平地好
多了,環顧四周,到處都是高大的樹木,往
西北有一條白石小徑
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"aa2.c",
  "northwest" : __DIR__"aa4",
]));
  set("outdoors", "/u/o/ookami/newarea");

  setup();
  replace_program(ROOM);
}
