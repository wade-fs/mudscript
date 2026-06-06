inherit ROOM;
void create() {
	set( "short", "$HIY$【平南書院】 $HIW$杏林醫廬$NOR$" );
	set( "owner", "lonsan" );
	set( "light_up", 1 );
	set( "object", ([
		"file8"    : "/open/fire-hole/obj/b-pill",
		"file7"    : "/open/fire-hole/obj/y-pill",
		"amount7"  : 2000,
		"amount8"  : 110,
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 52,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount3"  : 2632,
		"amount1"  : 47,
		"file6"    : "/open/fire-hole/obj/y-pill",
		"amount5"  : 36,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 200,
		"file4"    : "/open/fire-hole/obj/p-pill",
	]) );
	set( "build", 10059 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room197",
	]) );
	set( "long", @LONG

                *********************************       
                *                               *
                *        $HIY$醫 者 父 母 心$NOR$         *
                *                               *
                *********************************

一走進醫廬，就可以看到斗大的幾個燙金字，這是當代最偉大的名醫--華陀，
在蒞臨過此處後留下的真跡，也是杏林醫廬多年來行醫的宗旨，無論是黑道白道，
王公貴族或者平民百姓，只要求醫至此，必定竭盡心力救治，是以多年來此處隱然
已經是武林中的非戰之區，總使兩人仇深似海，在此處相遇也必定不會兵刃相向，
總是相約到外面解決。醫廬裡面十分簡樸，除了一個寬闊的大廳，有一張看診桌及
兩張椅子外，也沒有別的東西，在旁邊有一扇門，裡面只有醫廬裡的人可以進去，
而四周牆壁上有著一排排的凹槽，上面放的無非是藥草靈丹等藥及藥引，還有一些
可以提供閱讀的一些佛經。
LONG);
	setup();
	replace_program(ROOM);
}
