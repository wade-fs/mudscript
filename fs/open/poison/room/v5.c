// Room: /open/poison/room/v5.c
inherit ROOM;

void create ()
{
  set ("short", "村長的家");
	set( "build", 1 );
  set ("long", @LONG
這裡是村長的家，村長是村中最有威嚴的人，村民們要是有了
爭執或是有甚麼不能解決的事，都會登門拜訪請求村長的協助，而
村長也總是義不容辭的進力替村民們解決難題，排解糾紛，因而受
到村民們的敬崇。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"v2-6.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/poison/npc/vleader.c" : 1,
]));
  set("light_up", 1);

  setup();
}
