// Room: /u/o/ookami/newarea/aa2.c 
inherit ROOM;
 
void create ()
{
  set ("short", "點蒼山腰");
  set ("long", @LONG
你已經走到點蒼山的山腰上,深深的吸一口氣,這裡的空氣比平地好
多了,環顧四周,到處都是高大的樹木,往西有一條白石小徑,看起來像是
有人刻意鋪設的,不妨沿著小徑走,看看會有什麼奇遇
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"aa3.c",
  "down" : __DIR__"aa1",
]));
  set("outdoors", "/u/o/ookami/newarea");

  setup();
  replace_program(ROOM);
}
