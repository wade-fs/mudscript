inherit ROOM;
void create() {
	set( "short", "$RED$分岐點$NOR$" );
	set( "item_desc", ([
		"sign" : @ITEM
$HIW$   內～有～惡～貓   $NOR$
ITEM,
	]) );
	set( "object", ([
		"file2"    : "/open/killer/obj/k_ring",
		"amount2"  : 1,
	]) );
	set( "build", 10058 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room12.c",
		"east"      : "/open/clan/hell/room/room21.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
經過了漫長的旅途，你費了九牛二虎之力來到了此地，
路邊放了一塊小路牌(sign)，路牌上的字跡似乎已經模糊不
清了，前方的路被一層迷蒙的霧所覆蓋，而左邊的路卻一直
傳來陣陣的貓聲。

　　　　　 $HIW$喵～　喵～　$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
