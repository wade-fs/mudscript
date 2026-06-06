inherit ROOM;
void create() {
	set( "short", "$HIC$陰陽界$NOR$" );
	set( "owner", "spicy" );
	set( "object", ([
		"file2"    : "/open/mon/obj/mon-pill",
		"amount7"  : 1,
		"file6"    : "/open/ping/questsfan/obj/box",
		"file10"   : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount10" : 1,
		"file9"    : "/open/ping/questsfan/obj/stone",
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount8"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/ping/questsfan/obj/glaze",
		"amount2"  : 350,
		"file7"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount4"  : 300,
		"amount6"  : 1,
		"amount1"  : 1,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 1,
	]) );
	set( "item_desc", ([
		"black" : @ITEM
他全身黑色裝扮，帽上寫著「天下太平」。身材矮小，俗稱八爺。

ITEM,
		"white" : @ITEM
他全身白色裝扮，帽上寫著「一見生財」。身材高挑，俗稱七爺。

ITEM,
		"soul" : @ITEM
它在人間是屬於邪惡的人。

ITEM,
	]) );
	set( "build", 14140 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room49",
	]) );
	set( "long", @LONG
              

你正站在陽世跟陰間交界之處，四周一片渾沌，瀰漫著朦朦的煙氣。
不時有遊魂從你身邊飄過，似乎都沒注意到你的存在。
一縷輕煙般的遊魂(soul)正從你身旁飄過。
一縷輕煙般的遊魂(soul)正從你身旁飄過。
專司陰間前往陽世鉤拿陽壽已終的白無常(white)正在抓回游魂。
專司陰間前往陽世鉤拿陽壽已終的黑無常(black) 正在抓回游魂。

LONG);
	setup();
	replace_program(ROOM);
}
