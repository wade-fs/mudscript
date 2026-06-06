inherit ROOM;
void create() {
	set( "short", "$HIC$【$HIW$武器室$HIC$】$NOR$龍魔人 " );
	set( "owner", "cong" );
	set( "object", ([
		"file2"    : "/open/mogi/dragon/obj/power",
		"file5"    : "/open/mogi/mountain/obj/frog-pill",
		"file3"    : "/daemon/class/blademan/obj/iceblade",
		"file1"    : "/daemon/class/fighter/armband",
		"amount1"  : 1,
		"amount9"  : 1,
		"file4"    : "/obj/gift/lingzhi",
		"file8"    : "/open/scholar/obj/icefan",
		"amount4"  : 1,
		"file6"    : "/daemon/class/blademan/obj/shield",
		"amount2"  : 4,
		"amount8"  : 1,
		"file9"    : "/daemon/class/blademan/obj/shield",
		"amount5"  : 4,
		"amount6"  : 1,
		"amount3"  : 1,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room154",
	]) );
	set( "build", 10050 );
	set( "long", @LONG
這裡是小弟我放東西的地方，看起來似乎很雜亂
可是又是那麼的亂中有序，平常可能不常上線，所以
這裡都是空空的，不過為了早日成為一流的刀客，我
還是會努力的，平常到這裡時記得上面所寫的，給在
玩的自已，龍魔人留。

LONG);
	setup();
	replace_program(ROOM);
}
