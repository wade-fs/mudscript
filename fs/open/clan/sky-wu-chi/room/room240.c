inherit ROOM;
void create() {
	set( "short", "育繭島" );
	set( "owner", "borkiller" );
	set( "object", ([
		"amount4"  : 1,
		"file4"    : "/open/gblade/obj/sa-head",
		"amount2"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/wu/obj/ya-head",
		"file1"    : "/open/wu/obj/ya-head",
		"file3"    : "/open/wu/obj/ya-head",
		"amount1"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10190 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room161",
		"west"      : "/open/clan/sky-wu-chi/room/room254.c",
		"north"     : "/open/clan/sky-wu-chi/room/room252.c",
		"east"      : "/open/clan/sky-wu-chi/room/room253.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
你進入這個房間,就感到一股詭異的氣氛
仔細一看,房間的四周都放滿了大大小小的蝶繭
這個房間的主人是神蝶,傳說中的西亞神殿的主人
最近很迷早安少女的吉澤瞳加護亞依過希美矢口真里
LONG);
	setup();
	replace_program(ROOM);
}
