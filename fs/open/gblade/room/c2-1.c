inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

陣陣陰風迎面吹來，手中的火把也忽明忽滅，以致你看不太清楚四周的環
境，一個不小心，被石頭絆了一跤，整個人跌在地上，正想起身，赫然發
現竟然跌在一具剛死不久的屍體上面；看樣子屍體是被野獸咬死後，拖到
這裡來的；屍體的被咬的面目全非，還有幾條蛆從看起來應該是眼睛和鼻
子的地方爬進爬出。你突然感到胃部一陣絞痛，吐了一地。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"c2.c",
  "north" : __DIR__"c2-2.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/mob1" : 1,
]));

  setup();
}

int valid_leave(object me,string dir)
{
	if(dir=="north"&& present("fly-head adultoid",environment(me)))
	if(me->query("pass_gblade")<1)
	return notify_fail("落頭蟲擋住了你的去路 , 似乎不讓你過去 !\n");
	return ::valid_leave(me,dir);
}
