inherit ROOM;
void create() {
	set( "short", "細細品味喔(2)" );
	set( "owner", "dfyw" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10030 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room547",
	]) );
	set( "long", @LONG
吃飯的時候，七分飽的滿足感總是最舒服的。
　　吃到六七分飽的時候，齒頰味蕾還留著美味食物的香味，然後再
加上餐後的飯後甜點、水果、咖啡或茶等等，保持身材和身體健康絕
對足夠。  
　　但是，如果已經到了六七分飽還繼續吃，或者以上情形還是可以
持續保有，但是因為每個人的體質不同，或者吃的東西不同，就會有
許多隨之而來的後遺症，如：腸胃不適而勤跑洗手間、過於飽漲
而有了噁心感、無法享用餐後甜點、吃得太飽會想睡覺....等等，完全
喪失了吃飯的樂趣。 
LONG);
	setup();
	replace_program(ROOM);
}
