// Room: /open/badman/room/forest16.c
// written by powell 96.4.26@FS

inherit ROOM;

void create ()
{
  set ("short", "湖邊竹林");
  set ("long", @LONG
這兒也有著一大片的竹林，是由東邊的竹林綿延過來，只不過
這兒的竹子(bamboo)比東邊的稀疏了點，也因此這裡較先前的地方
明亮了許多，這個竹林的西邊是個明亮清澈的湖泊。
 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lake0",
  "east" : __DIR__"forest15",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "bamboo" : "一根根細長的竹子。
",
]));
  set("outdoors", "/open/badman");

  setup();
}
