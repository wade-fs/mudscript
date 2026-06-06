inherit ROOM;
void create() {
	set( "short", "吹雪之松小徑" );
	set( "light_up", 1 );
	set( "object", ([
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount9"  : 11,
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount8"  : 320,
		"file3"    : "/open/fire-hole/obj/y-pill",
		"file9"    : "/open/doctor/pill/sky_pill",
		"file8"    : "/open/fire-hole/obj/r-pill",
		"amount10" : 51,
		"amount7"  : 330,
		"file5"    : "/open/doctor/pill/human_pill",
		"amount4"  : 180,
		"amount2"  : 270,
		"file10"   : "/open/ping/obj/poison_pill",
		"file1"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 30,
		"amount5"  : 15,
		"amount1"  : 88,
		"amount3"  : 16,
		"file6"    : "/open/fire-hole/obj/k-pill",
		"file2"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "build", 12120 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room117",
		"enter"     : "/open/clan/sky-wu-chi/room/room136.c",
		"out"       : "/open/clan/sky-wu-chi/room/room151.c",
	]) );
	set( "long", @LONG
走進了『霸氣堂』後，你來到了通往空瓶子臥室的迴路小徑上
這裡氣溫開始下降，可能是空瓶子的居所是依山而建的，所以也就
往裡面走等於是往山上走了上去。氣溫也越來越低，兩旁的松樹上
都沾滿了厚厚的雪花，四周景色也開始變成一片的雪白色。此時你
已用輕功奔走了快三里的路程，但是就是還沒到空瓶子居的後院，
眼中開始因雪花飄飄落下而模糊起來。

LONG);
	setup();
	replace_program(ROOM);
}
