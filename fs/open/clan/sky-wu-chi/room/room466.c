inherit ROOM;
void create() {
	set( "short", "九層塔七樓" );
	set( "owner", "intel" );
	set( "object", ([
		"amount4"  : 1,
		"file4"    : "/open/gblade/obj/sa-head",
	]) );
	set( "build", 10467 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"down"      : "/open/clan/sky-wu-chi/room/room465.c",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
		"up"        : "/open/clan/sky-wu-chi/room/room467.c",
	]) );
	set( "long", @LONG
這裡是九曾塔的第七樓，旁邊有各式各樣的模具和模型，但是樣子都很像是
從惡魔化出來的分身，兇神惡煞！當你的眼神跟它正面交鋒時，好像靈魂快被它
吸過去一樣，所以你在這都感到魂身不對正。偏偏這裡到處都是長的一樣，你已
不曉得你身在何方了。
LONG);
	setup();
	replace_program(ROOM);
}
