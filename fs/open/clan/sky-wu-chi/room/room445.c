inherit ROOM;
void create() {
	set( "short", "$HIR$麥當勞$HIY$大廳$HIC$二樓$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/obj/lunar-heart",
		"amount8"  : 1,
		"file4"    : "/open/magic-manor/obj/lunar-heart",
		"file2"    : "/open/magic-manor/obj/sun-heart",
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"file8"    : "/open/magic-manor/obj/lunar-heart",
		"amount4"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/magic-manor/obj/sun-heart",
	]) );
	set( "build", 20018 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room441",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是一個很大很大的餐館，要等你點完了東西才能來這裡坐的喔。這裡有好多張的椅子
你可以一張張的把它合併起來，再把一張張的桌子給合併，那你就可以跟親朋好友在一起用餐
了。不過你也要看一下位子的方向喔，只有下方有門喔。
LONG);
	setup();
	replace_program(ROOM);
}
