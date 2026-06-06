inherit ROOM;
void create() {
	set( "short", "$HIC$思量之家$HIW$EQ室一$NOR$" );
	set( "owner", "salicili" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 105,
		"file2"    : "/open/killer/obj/s_pill",
	]) );
	set( "build", 10055 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room368.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"east"      : "/open/clan/sky-wu-chi/room/room33.c",
	]) );
	set( "long", @LONG
女：不想再問你　你到底在何方　不想再思量　你能否歸來麼;想著你的心　想著你的臉　想捧在胸口　能不放就不放;;男：ONE NIGHT IN BEIJING 我留下許多情;不管你愛與不愛　都是歷史的塵埃;ONE NIGHT IN BEIJING 我留下許多情;不敢在午夜問路　怕走到了百花深處;;女：人說百花地深處　住著老情人　縫著繡花鞋　面容安詳的老人;依舊等著那出征的歸人;男：ONE NIGHT IN BEIJING 你可別喝太多酒;不管你愛與不愛　都是歷史的塵埃;ONE NIGHT IN BEIJING 我留下許多情;把酒高歌的男兒　是北方的狼族;;女：人說北方的狼族　會在寒風起;站在城門外　穿著腐銹的鐵衣　呼喚城門外　眼中含著淚
LONG);
	setup();
	replace_program(ROOM);
}
