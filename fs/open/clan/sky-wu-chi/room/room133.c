inherit ROOM;
void create() {
	set( "short", "神秘後花園" );
	set( "object", ([
		"amount4"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_skirt",
		"file6"    : "/open/magic-manor/obj/water-ball",
		"file5"    : "/open/killer/obj/k_ring",
		"amount1"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_cloak",
		"amount2"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_hairpin",
		"file4"    : "/open/ping/questsfan/obj/diamond_legging",
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 12000 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room136",
	]) );
	set( "long", @LONG
這裡是整個居所的後花園，也是空瓶子和他的幾位夫人一起賞花看風景
的地方，這裡的花都是一些奇珍異草，其中裡面有一株『萍音蘭草』最是珍
貴，而你絕對想不到這草有怎樣的功用。問了一下原來才知道這奇草原來是
個非常時期的延年續命丹之功用，吃下去之後你會感到你在這世界上有多可
以多活個二十幾年，只是你也只能看而不能吃。因為當你偷摘來吃之時你會
被空瓶子當場發出獵殺令把你給殺了。所以也只能看看這裡的風景，這個花
園真的是很大，有著廣大的草坪還有群群的羊和馬。眼睛一看那帶頭的馬兒
原來是有名的龍駒看牠揚起頭英姿的樣子，你開始覺得也只有這樣子的好馬
才配的上這個房子的主人。

LONG);
	setup();
	replace_program(ROOM);
}
