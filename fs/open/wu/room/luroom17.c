// Room: /open/wu/room/luroom17.c
// 瀧山武館的玄關
inherit ROOM;
void create ()
{
  set ("short", "玄關");
	set( "build", 2 );
  set ("long", @LONG
這裡是瀧山派玄關,往西的話是通往瀧山派的大廳,東邊則是瀧山派的
練武場地,由於此處極為重要,所以任正晴委派瀧山派高手--陳玄龍--
來看守。看到看守的人的目光,不禁讓你心神一震!!!!
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"luroom9.c",
  "east" : __DIR__"luroom18.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/wu/npc/chen" : 1,
]));

  setup();
}
