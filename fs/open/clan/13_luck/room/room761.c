inherit ROOM;
void create() {
	set( "short", "$HIW$客廳" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/fire-hole/obj/k-pill",
		"file5"    : "/open/mon/obj/mon-pill",
		"amount6"  : 1,
		"amount10" : 7,
		"file7"    : "/open/ping/obj/poison_pill",
		"amount1"  : 4,
		"file2"    : "/open/fire-hole/obj/p-pill",
		"amount3"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file4"    : "/open/fire-hole/obj/b-pill",
		"file3"    : "/open/killer/obj/fire-knife",
		"amount5"  : 2,
		"file10"   : "/open/mon/obj/thousand-nectar",
		"amount4"  : 2,
		"amount7"  : 3,
	]) );
	set( "owner", "kanako" );
	set( "build", 11088 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room690",
	]) );
	set( "long", @LONG
    碩大的客廳放一張$HIY$搖椅$HIW$及$HIC$腳凳
在$HIY$搖椅$HIW$旁準備一盞$HIR$燈$HIW$,如此你可一邊$HIM$思考$HIW$一邊看書
$HIW$窗戶用$MAG$厚毯子$HIW$或$CYN$遮光簾$HIW$蓋住,
如此不會被$HIC$早晨$HIW$之$HBGRN$$HIY$亮光或聲音$NOR$$HIW$吵醒,多麼$HIM$慵懶呀!!
$HIW$準備一個$HIG$冰桶$HIW$放置你喜歡的$HBMAG$$HIC$清涼飲料
$NOR$$HIC$隨時都可以找三五好友來$HIR$小酌一杯...
$HIW$生活上真是輕鬆愜意呀!!
LONG);
	setup();
	replace_program(ROOM);
}
