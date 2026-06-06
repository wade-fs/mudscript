// Room : /open/clan/ou-cloud-club/room/room37.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$入口$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/mon/obj/ghost-claw",
		"amount8"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file2"    : "/open/mon/obj/ghost-claw",
		"amount5"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
	]) );
	set( "build", 11664 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
這裡是通往渾沌國度-惡魔城的唯一通道,當你甫踏進此房間,
身後的門隨即 呀~~~ 的一聲關上了,在前面等待你的,是未知的
黑暗世界,以及令人恐懼的惡魔氣息...寒風驟然襲來,圓滿無缺
的皎潔月輪,彷彿一起為你演奏起悲壯的夜曲,前進吧~~~已沒有
退路了...
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room38.c",
  "out" : "/open/clan/ou-cloud-club/room/room36",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
