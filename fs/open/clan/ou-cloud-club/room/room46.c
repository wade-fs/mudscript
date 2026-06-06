// Room : /open/clan/ou-cloud-club/room/room46.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "神秘實驗室" );
	set( "object", ([
		"amount8"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-belt",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-leggings",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-ring",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount9"  : 1,
		"amount10" : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-boots",
	]) );
	set( "owner", "snowy" );
	set( "build", 15502 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room28",
  "up" : "/open/clan/ou-cloud-club/room/room47.c",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
這裡已經沒有通路了,不過牆上砌著一塊塊一尺見方的小平台
,呈螺旋型的圍繞著圓柱型的牆壁蜿蜒而上,若是不在乎幾個奇怪
小骨骸滴著黃綠色液體陪伴著前進的話,你可以藉著這些小石台
跳躍而上,遠處似乎傳來一陣教堂裡才能聽到的鐘聲..
LONG);
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	setup();

	}
