inherit ROOM;
void create() {
	set( "short", "nanahara小天地" );
	set( "object", ([
		"file6"    : "/obj/gift/shenliwan",
		"amount1"  : 7,
		"file4"    : "/open/common/obj/liz_meat",
		"amount3"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/common/obj/pill2",
		"amount5"  : 5,
		"amount2"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 1,
		"file2"    : "/open/common/obj/liz_meat",
		"file3"    : "/open/common/obj/liz_meat",
		"file7"    : "/open/common/obj/liz_meat",
	]) );
	set( "build", 10278 );
	set( "owner", "nanahara" );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"east"      : "/open/clan/sky-wu-chi/room/room506",
	]) );
	set( "long", @LONG
四諦又稱為四聖諦。聖諦即『真理』之意。四聖諦為苦諦、集諦、道諦和滅諦。;苦諦說人有生苦、老苦、病苦、死苦、憂然煩苦、怨憎會苦、恩愛別離苦和所欲不得苦等八苦。人叢生到死，一直在苦海中沉浮。;集諦是因緣論，認為一切事物並無實體，只不過是因緣的組合而已。一切因緣皆起源於『無明』，『無明』是所有惡事的根源。如果通過修行，把『無明』除掉，就除掉一切痛苦，不會再生、再死，得意從生死輪迴中超脫。;道諦主要講人如何才能脫離因緣的束縛而超脫輪迴之苦，就是佛宗修行的具體方法，主要是戒、定、慧三學，包括四念住、四正勤、四神足、五根、五力、七覺支、八正道等修行法門，共稱三十七道品。;四聖諦的最後一諦是滅諦，修成後便可以進入「涅磐」的地步。
LONG);
	setup();
	replace_program(ROOM);
}
