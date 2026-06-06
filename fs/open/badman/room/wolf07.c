inherit ROOM;
void create()
{
  set ("short","村莊口");
  set ("long",@LONG
這裡似乎是一個小村莊 ,來到這裡 ,狼群變的更奇怪了 ,不但不怕
你 ,還很親熱的聞著你身上的味道 .這裡看來是這個村莊唯一的出入口
 ,進去看一看吧 .
LONG);

  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"wolf08.c",
  "southup" : __DIR__"wolf04.c",
]));

  set("objects",([ /* sizeof() == 2 */
  "/open/badman/npc/wolf02.c" : 2,
]));

  setup();
}
