// Room: /u/m/moner/room/room/class/r1.c 
inherit ROOM;
 
void create ()
{
set("short","魔龍塔");
  set ("long", @LONG

這裡是魔龍塔最後的一層，一踏入這裡，四周的空氣好像沉重了起來，
耳中聽不到一絲的聲音，令你以為自己的雙耳已失去作用了，你努力的
睜眼四顧，地上覆著一層薄薄的灰塵，顯示這裡少有人來。

LONG);

  set("exits", ([ /* sizeof() == 6 */
  "春" : __DIR__"r7.c",
"夏":__DIR__"r8.c",
"冬":__DIR__"r9.c",
  "秋" : __DIR__"r8.c",
]));
set("no_transmit",1);
set("objects",([
"/daemon/class/blademan/npc/corpse7.c":4,
]));
  setup();
  replace_program(ROOM);
}
