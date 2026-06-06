// Room: /u/m/moner/room/room/class/r11.c 
inherit ROOM;
 
void create ()
{
set("short","武聖居"); 
	set( "build", 168 );
  set ("long", @LONG

這裡是魔龍塔最後的一層，一踏入這裡，四周的空氣好像沉重了起來，
耳中聽不到一絲的聲音，令你以為自己的雙耳已失去作用了，你努力的
睜眼四顧，地上覆著一層薄薄的灰塵，顯示這裡少有人來。

LONG);
set("no_plan",1);
set("exits", ([ /* sizeof() == 2 */
"up" :"/open/snow/room/back",
//"north":"/open/gblade/mrm/room/class/get-meq-room.c",
"down":"/open/gblade/mrm/room/class/r10",
]));
set("no_transmit",1);
set("sa-room",1);
set("objects",([
"/open/gblade/npc/sa.c":1,
]));
  setup();
}
int valid_leave(object me, string dir)
{
if((dir=="up"||dir=="north")&& present("degu sa",environment(me)))     
   return notify_fail("獨孤嵊說道：這裡是你說來就來，說走就走的地方嗎？\n");
return ::valid_leave(me,dir);
}
