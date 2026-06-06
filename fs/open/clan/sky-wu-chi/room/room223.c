inherit ROOM;
void create() {
	set( "short", "$HIW$側房$NOR$" );
	set( "owner", "cong" );
	set( "object", ([
		"file10"   : "/open/gsword/obj/may_ring",
		"amount2"  : 120,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"file5"    : "/open/gblade/obj/sa-head",
		"file7"    : "/open/gblade/obj/sa-head",
		"file3"    : "/open/gblade/obj/sa-head",
		"amount10" : 1,
		"amount7"  : 1,
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
		"amount8"  : 1,
		"file2"    : "/open/killer/obj/black",
		"amount6"  : 1,
		"file6"    : "/open/capital/obj/king-ring",
		"file1"    : "/open/mogi/castle/obj/lochagem",
		"file9"    : "/daemon/class/blademan/obj/shield",
	]) );
	set( "light_up", 1 );
	set( "build", 13785 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room242",
		"north"     : "/open/clan/sky-wu-chi/room/room222",
	]) );
	set( "long", @LONG
這裡是霹靂貓的小房間，裡面有一台小小的電腦，似乎正在運轉中
哈.. 原來才PII - 300MHZ，什麼年代了，還在用P-II，
喔..  不過這台SamSung 753DF的螢幕看起來挺高級的，
還算有點本錢，電腦好像正在執行ZMud，可是人卻沒在電腦前面，
一定是給我在跑rebot，你中心突然有股歪念，嘿嘿.........
偷偷把他sui...  ^oo^

LONG);
	setup();
	replace_program(ROOM);
}
