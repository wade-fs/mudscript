// Room : /open/clan/ou-cloud-club/room/room82.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIC$蟲穴$NOR$" );
	set( "object", ([
		"amount4"  : 11,
		"file8"    : "/obj/stone/powder",
		"amount9"  : 5,
		"file7"    : "/obj/gift/shenliwan",
		"amount2"  : 27,
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 1,
		"amount5"  : 3,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file5"    : "/obj/stone/jiao",
		"amount10" : 21,
		"file10"   : "/obj/stone/suipian",
		"file4"    : "/open/ping/obj/poison_pill",
		"amount1"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"amount8"  : 180,
		"amount6"  : 5,
	]) );
	set( "owner", "ttt" );
	set( "build", 10468 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room563",
		"north"     : "/open/clan/ou-cloud-club/room/room415.c",
	]) );
	set( "no_clean_up", 0 );
	set( "long", @LONG
一踏入此地‧‧‧便有一股傲情俠骨的氣息朝你直撲而來
‧‧‧原來這便是傳說中仙意靈地的傲雲山莊，據說當年乃此
莊主劍君十二恨召集武林上赫赫有名的雪蒼、瀧山、聖火、仙
劍、儒門、段家、舞者、殺手、惡人、魔刀、金刀的各派的第
一強者，窮盡畢生功力合力所創出來的空間，而莊主也為了武
林的安危，便立下重誓，要幫眾一生除惡懲奸，如此情操早已
令傲雲山莊成為全天下第一大幫了‧‧‧






LONG);
	set( "cmkroom", 1 );
	set( "clan_room", "傲雲山莊" );
	set( "no_transmit", 1 );
	setup();

	}
