// Room : /open/clan/ou-cloud-club/room/room25.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "河西走廊" );
	set( "object", ([
		"amount10" : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/gsword/obj1/blosword",
		"file6"    : "/open/gsword/obj1/blosword",
		"amount3"  : 1,
		"file1"    : "/open/gsword/obj1/blosword",
		"amount1"  : 1,
		"file2"    : "/open/gsword/obj1/blosword",
		"amount6"  : 1,
		"file7"    : "/open/gsword/obj1/blosword",
		"file4"    : "/open/gsword/obj1/blosword",
		"file5"    : "/open/gsword/obj1/blosword",
		"amount2"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/gsword/obj1/blosword",
		"file10"   : "/open/gsword/obj1/blosword",
		"file3"    : "/open/gsword/obj1/blosword",
	]) );
	set( "build", 24468 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
往西過去就是一望無際的大沙漠了,傳聞進入這個大沙漠的
人很少能夠安然返回的,大多在烈日下缺乏水分而遭烈陽活活枯
曬致死,因此在進入前可要先準備好足夠的水和糧食喔~~如果都
還沒準備好的話還是往東回去美麗的故鄉吧.

LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room24",
  "west" : "/open/clan/ou-cloud-club/room/room26.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
