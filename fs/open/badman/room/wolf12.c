inherit ROOM;
void create()
{
   set ("short","小道");
  set ("long",@LONG
到了這裡 ,連狼隻的氣息都感應不到了 .四周寂靜無聲的氣息反而
比剛才狼隻圍繞你的感覺更令人恐懼 .東邊是一個小空地 ,而西邊則是
一間殘破的廟宇 .
LONG);

  set("outdoors","/open/badman");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wolf15.c",
  "south" : __DIR__"wolf10.c",
  "west" : __DIR__"wolf13.c",
  "east" : __DIR__"wolf14.c",
]));

  setup();
}
