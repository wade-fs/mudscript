inherit ROOM;
void create() {
	set( "short", "望月樓五樓" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room581.c",
		"south"     : "/open/clan/13_luck/room/room694.c",
		"down"      : "/open/clan/13_luck/room/room593.c",
	]) );
	set( "long", @LONG

    你正走在望月樓五樓的走廊上，店小二裏裏外外正忙得團團轉。
深夜時分，四周安安靜靜，大家都在睡夢當中，你獨自一人站在這，
觀看那天空中皎潔的明月。螢火蟲在夜空中飛舞，更為那美麗的夜空
，添加幾分詩情畫意。

LONG);
	setup();
	replace_program(ROOM);
}
