inherit ROOM;
void create() {
	set( "short", "戰鬥著衣間" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount1"  : 1,
		"amount3"  : 1,
		"file1"    : "/open/gsword/obj1/ring",
		"file3"    : "/open/ghost-hole/obj/light-spirit",
	]) );
	set( "build", 10083 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room250",
	]) );
	set( "long", @LONG
牆邊衣櫃中掛著許多外出服，在『屠龍刀』外出時，
會先在右邊的戰鬥準備室找有沒有乾淨的舊衣服可以穿，
不夠的才來這邊拿新的衣服。一旁的落地鏡照出了您強健
的體魄，由此可見屠龍刀有點自戀。梳妝台上的CK香水，
您可別偷拿唷。
LONG);
	setup();
	replace_program(ROOM);
}
