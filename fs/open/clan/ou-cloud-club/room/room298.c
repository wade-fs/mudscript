inherit ROOM;
void create() {
	set( "short", "妖幻空間" );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room311",
	]) );
	set( "owner", "del" );
	set( "object", ([
		"file9"    : "/open/capital/obj/force_book",
		"amount4"  : 1,
		"file5"    : "/open/gblade/obj/sa-head",
		"amount9"  : 1,
		"file8"    : "/open/gblade/obj/sa-head",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/gblade/obj/sa-head",
	]) );
	set( "build", 10059 );
	set( "light_up", 1 );
	set( "long", @LONG
一股濃烈無以形容的味道襲向你，四周的空間變得詭異
，在這裡似乎被某種奇怪的外力扭曲了，原來這裡正是千年
樹妖利用法力所製造出來的空間，朦朧中好像有好幾對泛著
金色光芒的眼睛正在盯著你看，讓你不自覺的想轉身拔腿就
跑。
LONG);
	setup();
	replace_program(ROOM);
}
