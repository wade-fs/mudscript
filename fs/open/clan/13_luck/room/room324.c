inherit ROOM;
void create() {
	set( "short", "鎖龍窟" );
	set( "owner", "pighead" );
	set( "object", ([
		"amount4"  : 1,
		"file1"    : "/open/capital/guard/gring",
		"amount10" : 1,
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount5"  : 1,
		"amount7"  : 1,
		"file5"    : "/obj/gift/lingzhi",
		"file7"    : "/open/mogi/castle/obj/leave",
		"file9"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount3"  : 44,
		"amount9"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/obj/evil-kill-claw",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount8"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"file6"    : "/open/capital/room/king/obj/dagger1",
		"file2"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10395 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room276",
	]) );
	set( "long", @LONG

    一陣陰森的感覺襲來，踏入此洞之中，心裡感到陣陣的不安，一
聲聲的鐵鍊重擊聲不絕於耳，不時也傳出陣陣怒吼聲，被困於魔界禁
地地底牢籠中的黃金甲龍(Goldendragon)，被滅殺龍【波動皇拳】重
創後，便一直被禁錮此處，無法在危害世人。


LONG);
	setup();
	replace_program(ROOM);
}
