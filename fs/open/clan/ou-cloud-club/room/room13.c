// Room : /open/clan/ou-cloud-club/room/room13.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIC$寒冰$HIR$玉床$NOR$" );
	set( "owner", "enter" );
	set( "object", ([
		"amount3"  : 800,
		"amount6"  : 450,
		"amount7"  : 800,
		"amount8"  : 755,
		"amount1"  : 800,
		"file6"    : "/open/doctor/pill/ice_pill",
		"amount5"  : 422,
		"file2"    : "/open/doctor/pill/ice_pill",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/doctor/pill/human_pill",
		"file4"    : "/open/doctor/pill/human_pill",
		"file9"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 500,
		"file10"   : "/open/killer/memory/static",
		"file1"    : "/open/doctor/pill/human_pill",
		"amount10" : 1,
		"file8"    : "/open/doctor/pill/human_pill",
		"amount2"  : 450,
		"file5"    : "/open/doctor/pill/ice_pill",
		"amount9"  : 821,
	]) );
	set( "build", 10541 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/ou-cloud-club/room/room180",
		"west"      : "/open/clan/ou-cloud-club/room/room119.c",
]) );
	set( "clan_room", "傲雲山莊" );
	set( "long", @LONG
幫主的主臥房，只見左邊牆上放著一幅五百張的狗狗
拼圖，圖上小狗極其可愛，右邊牆上掛滿著主人四處征戰
所獲得的戰利品，一些武林中極其稀有的武器防具盡在牆
上，居中放著一張寒冰玉床，正是他從古墓中取回來，一
陣陣寒氣逼來，真懷疑這要怎麼睡人．

LONG);
	set( "cmkroom", 1 );
	set( "no_clean_up", 0 );
	set( "light_up", 1 );
	setup();

	}
