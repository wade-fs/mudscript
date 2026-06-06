inherit ROOM;

void create ()
{
  set ("short", "練武場");
	set( "build", 19 );
  set ("long", @LONG
 
看到青石地板被踏出一個個的腳印，你驚訝的說不出話，心想好深厚的功
力。旁邊有兩個金刀門的弟子正在練武，你看到他們手中擲出的暗器，竟
然是白花花的銀子，真是有錢的一個門派。

LONG);

  set("objects", ([ /* sizeof() == 3 */
  "/open/gblade/npc/shouhon" : 1,
  "/obj/money/silver.c" : 1,
  "/open/gblade/npc/trainee" : 2,
]));
  set("light_up", 1);
  set("outdoors", "/open/gblade");
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"g1-3",
]));

  setup();
}
