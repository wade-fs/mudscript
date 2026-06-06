inherit ROOM;
void create() {
	set( "short", "$HIY$黃金梅利號$NOR$" );
	set( "object", ([
		"amount4"  : 1,
		"file7"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"file4"    : "/open/gsword/obj1/sadsword",
		"file3"    : "/open/gsword/obj1/blosword",
		"amount7"  : 1,
		"amount1"  : 1,
		"file1"    : "/open/gsword/obj1/blosword",
	]) );
	set( "owner", "aspsa" );
	set( "light_up", 1 );
	set( "build", 10074 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room250.c",
		"south"     : "/open/clan/ou-cloud-club/room/room472",
		"east"      : "/open/clan/ou-cloud-club/room/room184.c",
	]) );
	set( "long", @LONG
來到這裡，你感受到一股異樣的氣氛，原來你已經踏上魯夫船長
的黃金梅利號，而這股異樣的氣氛，正是由你眼前這群人所散發出來
的，可愛的娜美，冷酷的索隆，搞笑的喬巴，好色的香吉士，還有最
偉大的笨蛋船長..魯夫，大家全都圍了上來，來看你這位闖上黃金梅
利號的笨蛋到底是誰??


LONG);
	setup();
	replace_program(ROOM);
}
