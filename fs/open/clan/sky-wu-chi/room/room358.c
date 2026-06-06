inherit ROOM;
void create() {
	set( "short", "寒霜居-大廳" );
	set( "owner", "noman" );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/obj/example/besttea",
		"file1"    : "/open/common/obj/liz_meat",
		"amount1"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10182 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room206",
		"east"      : "/open/clan/sky-wu-chi/room/room362.c",
		"west"      : "/open/clan/sky-wu-chi/room/room361.c",
		"south"     : "/open/clan/sky-wu-chi/room/room241.c",
	]) );
	set( "long", @LONG
雖然這座大廳跟所有的房間並沒有太大的差別，一樣都是由水
晶所製成的，但卻比任何一個房間要大的許多。向天花板看去可以
看到由水晶所組成的龍型浮雕，其微妙為俏的程度令你懷疑那個龍
型浮雕是否會向你襲擊。向兩邊看去可以看到兩間大門緊閉的房間
，西邊的房間上方的匾額寫著｛練功房｝，你感覺到從西邊的房間
隱隱散發出一種來自天地宇宙間的神秘而且壓迫的感覺，令你猶豫
著是否應該入內一探究竟。而東邊的房間上的匾額則寫著｛藏經閣
｝，看來在這房間中似乎有著武林人士所爭相追求的祕笈寶典吧。
LONG);
	setup();
	replace_program(ROOM);
}
