inherit ROOM;
void create() {
	set( "short", "$HIB$斜角巷$HIM$街頭$NOR$" );
	set( "object", ([
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount5"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount1"  : 1,
		"amount3"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-helmet",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount2"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount6"  : 1,
		"amount10" : 1,
	]) );
	set( "owner", "car" );
	set( "build", 10715 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room49",
		"west"      : "/open/clan/time-limit/room/room51.c",
		"east"      : "/open/clan/time-limit/room/room50.c",
		"out"       : "/open/clan/time-limit/room/room53",
	]) );
	set( "long", @LONG
一走入斜角巷,馬上感受到這是個非常熱鬧的市集,路旁的小販不停的叫賣,
街上人來人往,有的人拿著大包小包,有的人看著商品興嘆,這時你才想到,
你並沒有巫師世界的錢,不過沒關係,巫師世界的銀行-古靈閣就在前方,
你可以先去古靈閣領錢後再來血拼, 就這情形看來你得要大失血了

LONG);
	setup();
	replace_program(ROOM);
}
