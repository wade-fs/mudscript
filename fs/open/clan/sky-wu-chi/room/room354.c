inherit ROOM;
void create() {
	set( "short", "六分刀" );
	set( "owner", "panhermes" );
	set( "light_up", 1 );
	set( "object", ([
		"amount6"  : 1,
		"file2"    : "/open/killer/obj/s_pill",
		"file4"    : "/open/doctor/pill/human_pill",
		"amount3"  : 35,
		"file3"    : "/open/doctor/pill/gnd_pill",
		"amount1"  : 596,
		"amount5"  : 1,
		"amount4"  : 201,
		"file8"    : "/open/capital/room/king/obj/km-belt",
		"amount2"  : 5,
		"file6"    : "/open/capital/room/king/obj/km-belt",
		"amount8"  : 1,
		"file5"    : "/open/capital/room/king/obj/km-belt",
		"file1"    : "/open/doctor/pill/sky_pill",
		"file7"    : "/open/capital/room/king/obj/km-belt",
		"amount7"  : 1,
	]) );
	set( "build", 12237 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room278",
	]) );
	set( "long", @LONG
坎坷世路，踏遍傷心之地。滄桑歲月，一生不平之事。
半紙虛名，誤我五倫橫逆。一劍輕生，誅師殺父傷身。
黃泉不容，求死談何容易。舉目茫茫，殘杯冷酒無味。
拔劍四顧，斷腸強忍豪氣。兩聲猿猴，驚動客夜難寐。
江湖冷落，莫道男兒無淚。滿川紅葉，盡是眼中血墜。
LONG);
	setup();
	replace_program(ROOM);
}
