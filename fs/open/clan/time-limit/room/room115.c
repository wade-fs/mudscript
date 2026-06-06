inherit ROOM;
void create() {
	set( "short", "宮殿" );
	set( "exits", ([
		"out"       : "/open/clan/time-limit/room/room116",
	]) );
	set( "long", @LONG
眼前所見是個極度奢華的宮殿,所有器具都是用黃金打照,難怪金光閃閃,可以想像古代君王的
生活有多麼奢侈,最令人驚訝的是這裡居然有水池,不曉得要花多少人力才能將水從河運到金字
塔頂端,前方有個黃金打造的棺材,看來法老王就沉睡在此

LONG);
	setup();
	replace_program(ROOM);
}
