// Room: /open/capital/room/SCH.c

inherit ROOM;

void create ()
{
  set ("short", "書生公會");
  set ("long", @LONG
這裡是書生們平常聚集的地方﹐他們都在這兒討論天下大事﹐暢所
欲言。牆壁上掛著一副詩聯(poet)﹐而在前堂上坐著一位老先生﹐原來
是天下書生都很佩服的楊書文--楊尚書﹐他正髯著他的大鬍子看著堂中
的一切。

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "poet" : "	┌────────────┐
	│		          │
	│  談 文 論 武 道 玄 機  │
	│  春 夏 秋 冬 一 色 衣  │
	│  遨 遊 江 湖 千 萬 里  │
	│  身 藏 天 地 兩 卷 書  │
	│		          │
	│		京城楊大  │
	│		  醉後狂草│
	└────────────┘
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"SCH1",
  "east" : __DIR__"h01",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/scholar/master" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{
        if( dir=="south" )
	{
	if( me->query("class") != "scholar" )
	  return notify_fail("非書生不得進入!\n");
	if( !me->query_temp("進入書房") )
	  return notify_fail("未得楊書文同意(agree), 不得進入!\n");
	}
	return ::valid_leave(me, dir);
}
