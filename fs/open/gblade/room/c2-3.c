inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

一進這裡，刺鼻的血腥味直往你身體裡鑽，雖然把鼻子掩住了，這味道似
乎還是能從毛細孔裡鑽進去，直達你的腦部，地上盡是血跡，碎肉，你實
在沒有勇氣把腳往那上面踏下去。裡頭有幾隻不知名的怪獸正抓著一副副
的屍體在那大快朵頤。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"c2-2.c",
  "north" : __DIR__"c2-4.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/mob3" : 1,
]));

  setup();
}
 int valid_leave(object me,string dir)
{
	if(dir=="north"&&present("two-heads snake",environment(me)))
	if(me->query("pass_gblade")<3)
	return notify_fail("六足雙頭蛇擋注了你的去路 , 對你搖搖頭 !\n");
	return ::valid_leave(me,dir);
}
