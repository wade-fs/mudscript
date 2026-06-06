//--暫時關閉，以免經驗值暴高   firedancer 2002/7/28
inherit ROOM;

void create ()
{
        set( "short", "崑崙山頂" );
	set( "build", 36 );
        set( "long", @LONG
偌大的銀色山谷，終年白雪皚皚，地上還積
了一層薄薄的雪，雖是如此還是長了不少的花草
，你到處找找說不定還能找到一些珍貴的藥物。

LONG);

  set("outdoors", "1");
        set("no_fight", 1);
        set("no_magic", 1);
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"m4",
  "enter" : "/open/fire-hole/f-1.c",
  "west" : __DIR__"m6",
  "south" : __DIR__"m2",
]));

  setup();
}
//改成進去在check
// int valid_leave( object me, string dir )
//{
//      if( dir=="enter" && me->query("combat_exp")<5000000 )
//              return notify_fail( "經驗值不夠, 進入火龍幻界也是徒然送死。\n" );
//      return 1;
//}
