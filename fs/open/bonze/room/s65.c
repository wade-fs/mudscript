// Room: /open/soulin/room/s65.c

inherit ROOM;

void create ()
{
  set ("short", "少林寺前廣場");
  set ("long", @LONG
	
這裡是少林弟子們練功的場所，四周擺滿了練功的器具。從整齊劃一
的口令聲，還有一旁木人上面傷痕累累的痕跡可以看的出來少林弟子
們的認真及努力。你心想若有機會和他們切磋切磋對自身武藝也有增
進。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/bonze/npc/c_monk" : 2,
]));
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"s66.c",
  "east" : __DIR__"k07",
  "west" : __DIR__"s63.c",
  "south" : __DIR__"s29.c",
]));
  set("have_reborn", 1);
  set("outdoors", "/open/bonze");

  setup();
}
