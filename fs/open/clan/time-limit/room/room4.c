inherit ROOM;
void create() {
	set( "short", "$HIY$蜂蜜$HIC$公爵$NOR$" );
	set( "owner", "woodsword" );
	set( "object", ([
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/wood/obj/wood-sword",
		"file4"    : "/open/magic-manor/wood/obj/wood-sword",
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount2"  : 1,
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file9"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount4"  : 1,
		"amount6"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/wood/obj/wood-sword",
	]) );
	set( "build", 10098 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room7",
	]) );
	set( "long", @LONG
蜂蜜公爵裡的糖果之多讓你目不暇給,學生大把大把的買,老闆則是笑逐顏開的收錢,
人群中看到素有搗蛋王之稱的衛斯理雙胞胎兄弟偷偷摸摸的將口袋裡的糖果往架子上放,
奇怪!怎麼不是偷拿糖果,反而將東西放上去,聽說這兩兄弟想開惡作劇商店,
難道是想找人做人體實驗?你趕緊將手上的糖果放回架子上

LONG);
	setup();
	replace_program(ROOM);
}
