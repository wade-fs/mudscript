inherit ROOM;
void create ()
{
  set ("short", "銀針門庫房");
	set( "build", 7 );
  set ("long", @LONG

　　這裡是銀針門的庫房，此地是專門用來放置一些還未用到的雜物
及藥品的地方，這裡有許多的藥櫃及藥罐，諸如：天山雪蓮、千年靈
芝及野山人參....等，都是極奇珍貴的稀有藥材！

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"3",     
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/doctor/npc/lan.c" : 1,
]));

  set("light_up", 1);
  setup();
}


