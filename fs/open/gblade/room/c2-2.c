inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG

地道到了這裡突然變得非常的狹窄，起初一個人通行還覺得沒有障礙，到
了後來必須縮著身體才能勉強的擠進通道，好不容易把身上的肥油擠的乾
乾淨淨終於擠近了通道，不過全身也被石壁上尖銳的石頭給劃得遍體鱗傷
了。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"c2-1.c",
  "north" : __DIR__"c2-3.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gblade/npc/mob2" : 1,
]));

  setup();
}

int valid_leave(object me,string dir)
{
 	if(dir=="north"&&present("curious snake",environment(me)))
	if(me->query("pass_gblade")<2)
	return notify_fail("肥遺擋在你的身前 , 不讓你通行 !\n");
	return ::valid_leave(me,dir);
}
