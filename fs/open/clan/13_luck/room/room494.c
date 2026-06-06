inherit ROOM;
void create() {
	set( "short", "觀景亭" );
	set( "owner", "evonne" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room493",
	]) );
	set( "long", @LONG

　　這裡是鳳凰崖裡取景角度最好的地方，放眼望去，雲生足底，有
如置身天上，於縹緲氤雲之中，隱隱可見山下宏偉的狂龍殿。亭內有
一個小石桌，旁邊有石椅，四根亭柱是用花崗石雕刻而成的，亭柱上
分別雕刻著龍、鳳、龜和麒麟四大祥獸的圖騰。

LONG);
	setup();
	replace_program(ROOM);
}
