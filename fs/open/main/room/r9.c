// Room: /open/main/room/r9.c

inherit ROOM;

void create ()
{
  set ("short", "道路");
	set( "build", 24 );
  set ("long", @LONG
走到這裡,你已漸漸遠離人跡,走在寬廣的蜀州盆地上,卻讓
你有一種蒼茫的感覺,道路在此通向北方或西方,而你,卻也不知
何處可走,去求仙呢? 還是回去溫暖的凌雲村?
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/main");

  set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"r8",
  "north" : __DIR__"r6",
  "south" : __DIR__"m2",
]));

  setup();
}
