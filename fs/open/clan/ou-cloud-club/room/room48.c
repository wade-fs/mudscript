// Room : /open/clan/ou-cloud-club/room/room48.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$鍊金研究棟$NOR$" );
	set( "build", 10001 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 3 */
		"westup"    : "/open/clan/ou-cloud-club/room/room49.c",
		"east"      : "/open/clan/ou-cloud-club/room/room50.c",
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
