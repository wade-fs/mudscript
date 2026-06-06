// Room: /d/oldpine/epath2.c

inherit ROOM;

void create ()
{
  set ("short", "蒼松迎客");
	set( "build", 294 );
  set ("long", @LONG
你走在蜀山小徑上,兩株青松向你迎來,碧綠的針葉,挺拔的枝
幹,像似以滿心的愉悅,歡迎你的到來,你抬頭西望, 昂然的蜀山就
在你眼前,這裡就是進入蜀山的入口:____蒼松迎客____ .
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/main/obj/torch" : 1,
]));

  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"froad2",
  "east" : __DIR__"su4",
"north" : "/open/tendo/m1",
]));

  setup();
}
