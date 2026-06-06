// Room: /open/gsword/room/wghouse.c
inherit ROOM;

void create ()
{
set("short","魔龍塔");
  set ("long", @LONG

這裡是魔龍塔最後的一層，一踏入這裡，四周的空氣好像沉重了起來，
耳中聽不到一絲的聲音，令你以為自己的雙耳已失去作用了，你努力的
睜眼四顧，地上覆著一層薄薄的灰塵，顯示這裡少有人來。

LONG);

  set("exits", ([ /* sizeof() == 2 */
   "north" : __DIR__"r6.c",
   "out":"/open/snow/room/back",
]));
set("no_transmit",1);
  set("objects", ([ /* sizeof() == 1 */
"/open/gblade/npc/gud.c":1,
]));

  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if((dir=="out"||dir=="north")&& present("run mou",environment(me)))
   return notify_fail(" 邢濤說道 :這裡是仙劍重地 ,你還是快離開吧!!!\n");
return ::valid_leave(me,dir);
}
