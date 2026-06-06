// Room : /open/clan/ou-cloud-club/room/room29.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$YEL$絲綢之路$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10126 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
大大小小的沙丘橫列在眼前,不過你依稀可以看到西邊有一座
城市,揉了揉眼,難道是幻覺嗎,這就是海市蜃樓嗎,多想無用,自古
以來不知多少企圖橫越征服這大沙漠的人被這幻象所迷惑,而終致
心神俱疲,死於荒漠,嗯...還是加緊腳步趕路吧!!
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room27",
  "west" : "/open/clan/ou-cloud-club/room/room30.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
