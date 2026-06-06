inherit ROOM;
void create() {
	set( "short", "風陵小徑" );
	set( "owner", "evonne" );
	set( "object", ([
		"amount9"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"file5"    : "/open/killer/obj/dagger",
		"file8"    : "/open/killer/obj/bellstar",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"file10"   : "/open/magic-manor/obj/dark-soul-dagger",
		"file7"    : "/open/killer/obj/dagger",
		"file2"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount8"  : 99999,
	]) );
	set( "build", 10020 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room653",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
你走在一條寬仄不勻的枯乾小徑上，由於小徑西去便是終日炎火的烈燄
峽谷，此間顯得酷燥不已。徑旁幾乎寸草不生，除卻些餘矮種針狀植物外，
再難它覓。因無濃蔭蔽蔽，一旦炎風吹來，益發焚酷不已，猶如置身熱鍋中
，非得脫到赤精條條地，或能暫驅署氣！

LONG);
	setup();
	replace_program(ROOM);
}
