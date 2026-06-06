inherit ROOM;
void create() {
	set( "short", "$HIW$當舖　$HIC$高級廁所$NOR$" );
	set( "owner", "mudu" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount2"  : 1,
	]) );
	set( "build", 10032 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room539",
	]) );
	set( "long", @LONG
這裡是一間高級豪華的廁所，是給當舖裡的貴客使用的，整個馬桶
是用１８Ｋ金的黃金做成的，光馬桶蓋可能就有１０公斤重，萬一不小
心被夾到手指頭，保證會腫的跟一跟熱狗一樣粗，請千萬小心，等被夾
到就來不急救了～～～但是呢被夾到手指頭還是萬幸的，因為被夾到
那而．．．．小鳥就會展翅高飛了！
LONG);
	setup();
	replace_program(ROOM);
}
