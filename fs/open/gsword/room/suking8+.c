// Room: /u/s/smore/room/suking/suking8+.c

inherit ROOM;

void create ()
{
  set ("short", "將軍席");
	set( "build", 24 );
  set ("long", @LONG
這裡就是將軍席，也就是平西大將軍　左正平日辦處理公事
的地方，將軍雖然年記已經老大不小了，但是處理起公務倒還是
有條不紊，這不單只是將軍的工作成果，他的左右手師爺　張冰
也是助益良多
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/gsword/room/suking11+",
  "south" : "/open/gsword/room/suking6.c",
]));

  set("objects", ([ /* sizeof() == 2 */
  "/open/gsword/mob/zuozhen" : 1,
  "/open/gsword/mob/zhang" : 1,
]));

  set("light_up", 1);

  setup();
}
