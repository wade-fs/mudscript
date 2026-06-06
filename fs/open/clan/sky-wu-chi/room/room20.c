// Room : /open/clan/sky-wu-chi/room/room20.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "exits", ([ /* sizeof() == 2 */
		"west"      : "/open/clan/sky-wu-chi/room/room9.c",
]) );
	set( "cmkroom", 1 );
	set( "light_up", 1 );
	set( "long", @LONG

這裡是攘袂生的小窩，和對面的我想上好像曾有何不可告人的
關係，做任何事都要跟對面的成對立，不禁讓人想起以前電視
所演的鐵師玉玲瓏的戲。攘袂生在我想上武道館要落成前也開始
著手一間氣功館在離南邊不遠處了，世界真是小，兩個奇怪的
人也會在同一個地方生存。

LONG);
	set( "short", "【攘袂生的房間】" );
	set( "object", ([
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
	]) );
	set( "build", 2728 );
	set( "clan_room", "天道無極" );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
