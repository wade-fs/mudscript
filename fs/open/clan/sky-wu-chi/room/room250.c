inherit ROOM;
void create() {
	set( "short", "戰鬥準備室" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount1"  : 442,
		"file6"    : "/open/capital/obj/blade2",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 524,
		"amount6"  : 1,
		"amount9"  : 1,
		"file1"    : "/obj/poison/dark_poison",
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file2"    : "/obj/poison/five_poison",
		"file3"    : "/obj/poison/rose_poison",
		"amount4"  : 3,
		"amount3"  : 463,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "light_up", 1 );
	set( "build", 10346 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room122",
		"west"      : "/open/clan/sky-wu-chi/room/room331",
	]) );
	set( "long", @LONG
這邊是『BBSMAN』在出發征戰前的『戰鬥準備室』。每
次出門前總是會來到這邊，做好萬全的準備才會出門。所以
看到滿地零亂的武器跟防具散落一地也不足為奇了。特別的
是，左邊是『BBSMAN』穿衣服的地方，可不要跟警方說唷。
LONG);
	setup();
	replace_program(ROOM);
}
