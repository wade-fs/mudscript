inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

地道到了這裡漸漸的開始往下傾斜，你極力往前望去--黑壓壓的一片，什
麼也看不見，四周一片死寂，耳朵也因此發出嗡嗡的聲響，彷彿有無數的
蜜蜂在你耳邊飛舞，你下意識的揮舞雙手。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"c2-5.c",
  "east" : __DIR__"c2-7.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/mob5.c" : 1,
]));

  setup();
}
int valid_leave(object me,string dir)
{
	if(dir=="east"&&present("big rat",environment(me)))
	if(me->query("pass_gblade")<5)
	return notify_fail("你陷入巨鼠所挖的地洞動彈不得 !\n");
	return ::valid_leave(me,dir);
}
