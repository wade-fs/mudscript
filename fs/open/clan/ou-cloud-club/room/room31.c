// Room : /open/clan/ou-cloud-club/room/room31.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$YEL$絲綢之路$NOR$" );
	set( "object", ([
		"amount3"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount2"  : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount10" : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount4"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount8"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount7"  : 1,
	]) );
	set( "build", 10165 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "long", @LONG
這裡應是歐亞大陸的中心地帶吧!!來往絡繹不絕的駱駝商隊
顯示這是條重要的商業道路,而越往西前進,越能見到更多不同於
中土人民的陌生面孔,這些人大多藍眼睛,鼻子略挺,皮膚略黑,且
多身材高大之人,雖語言不通,談吐間卻能看出非一般不識字之鄉
野匹夫,或許自古以來的天朝上國,四夷臣服的觀念要有所修正了
LONG);
	set( "cmkroom", 1 );
	set( "exits", ([ /* sizeof() == 2 */
		"west"      : "/open/clan/ou-cloud-club/room/room34",
		"east"      : "/open/clan/ou-cloud-club/room/room30.c",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
