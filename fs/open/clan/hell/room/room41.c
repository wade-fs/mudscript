inherit ROOM;
void create() {
	set( "short", "$HIW$黑輪臥房 - $HIC$練氣房$NOR$" );
	set( "object", ([
		"file1"    : "/open/scholar/obj/icefan",
		"amount1"  : 1,
		"amount10" : 1,
		"file10"   : "/open/killer/weapon/k_torch",
	]) );
	set( "item_desc", ([
		"map" : @ITEM

            --------------------
           |                    |
           | == 黑輪臥室地圖 == |
           |                    |
            --------------------



主室 -- 藏寶房 -- 練氣房 -- 房具室 -- 武器室
                       



ITEM,
	]) );
	set( "build", 10148 );
	set( "exits", ([
		"down"      : "/open/clan/hell/room/room87",
		"east"      : "/open/clan/hell/room/room48.c",
		"out"       : "/open/clan/hell/room/hall.c",
		"up"        : "/open/clan/hell/room/room6.c",
		"west"      : "/open/clan/hell/room/room40",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
走到這裡，你敏銳的身體感覺到了空氣的凝重每
向前一步，就彷彿將被撕裂一般，越是運功抗衡，越
是痛苦，這不是一般人能待的地方阿‧
這裡有一張地圖(Map)

             ψ劍魔ψ 黑輪

               【練氣房】




LONG);
	setup();
	replace_program(ROOM);
}
