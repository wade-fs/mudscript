inherit ROOM;
void create() {
	set( "short", "$HIR$密室$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/wind-rain/obj/sun_red_cloth",
		"amount2"  : 1,
		"file2"    : "/open/main/obj/et_sword",
	]) );
	set( "item_desc", ([
		"黑輪雕像" : @ITEM
這是傳說中ㄉ黑輪
這是傳說中ㄉ黑輪
這是傳說中ㄉ黑輪
ITEM,
	]) );
	set( "build", 11515 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room56",
	]) );
	set( "long", @LONG
走到這裡，你敏銳的身體感覺到了空氣的凝重每
向前一步，就彷彿將被撕裂一般，越是運功抗衡，越
是痛苦，這不是一般人能待的地方阿‧

             ψ劍魔ψ 黑輪

               【練氣房】


LONG);
	setup();
	replace_program(ROOM);
}
