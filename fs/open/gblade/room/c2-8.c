inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

走到這裡你突然覺得有點不太對勁，總覺得有東西在你身旁，後頸總覺得
有一點點涼颼颼的感覺，本來只是後頸有異樣的感覺，漸漸的這感覺好像
螞蟻一樣爬滿了全身。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"c2-7.c",
  "east" : __DIR__"c1-2.c",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/gblade/npc/mob7.c" : 1,
  "/open/gblade/npc/mob6.c" : 1,
]));

  setup();
}
int valid_leave(object me,string dir)
{
	if(dir=="west"&&present("nine-switch tortoise",environment(me)))
	{
	if(me->query("pass_gblade")<6)
	return notify_fail("三首九尾龜橫身擋住了你的退路 !!\n");
	}
	if(dir=="east"&&present("dragon",environment(me)))
	{
	if(me->query("pass_gblade")<7)
	return notify_fail("九天應龍擋在你面前讓你不能前進 !\n");
	}
	return ::valid_leave(me,dir);
}
