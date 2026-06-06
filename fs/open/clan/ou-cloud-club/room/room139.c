inherit ROOM;
void create() {
	set( "short", "$HIG$Rage Against The Machine$NOR$" );
	set( "owner", "devil" );
	set( "object", ([
		"amount2"  : 3,
		"file10"   : "/open/common/obj/liz_meat",
		"amount3"  : 5,
		"amount1"  : 1,
		"file2"    : "/open/mon/obj/thousand-nectar",
		"amount7"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/killer/obj/dagger",
		"amount10" : 1,
		"amount6"  : 17,
		"amount9"  : 1,
		"file4"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file9"    : "/open/common/obj/liz_meat",
		"amount5"  : 1,
		"file3"    : "/open/killer/obj/s_pill",
		"file1"    : "/obj/gift/unknowdan",
		"file8"    : "/open/magic-manor/obj/magic-sign",
		"file6"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10828 );
	set( "exits", ([
		"enter"     : "/open/clan/ou-cloud-club/room/room177",
		"north"     : "/open/clan/ou-cloud-club/room/room479",
	]) );
	set( "long", @LONG

來自洛杉磯的暴力四人組Rage Against The Machine，
在Hip Hop/Punk主力潮流中一枝獨秀，造因於他們在激
進震動人心的音樂下言之有物，有思想的歌詞透過Hip 
Hop與Punk撞擊的曲式訴求政治、社會議題，強勢吉他
聲線和剽悍憤恕的吶喊引動群眾的共鳴。 

LONG);
	setup();
	replace_program(ROOM);
}
