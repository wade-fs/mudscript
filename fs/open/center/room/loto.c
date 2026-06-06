// Room: /open/center/room/loto.c

inherit ROOM;

void create ()
{
  set ("short", "駱駝行");
	set( "build", 12 );
  set ("long", @LONG
這是一家駱駝行, 店老板就就劉駱駝, 大概是長年累月跟駱駝
為伍, 長得倒是有三分像人七分像駱駝. 不過別看他彎腰駝背的模
樣就以為他好欺負, 塞北明駝木高峰的名頭可是響遍北盧關附近三
寨十八窩. 雙手兩把彎刀不知砍死多少英雄好漢, 想來你口袋裡的
荷包得看緊一點, 否則, 嘿嘿...
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road1",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/loto" : 2,
]));

  set("light_up", 1);

  setup();
}
