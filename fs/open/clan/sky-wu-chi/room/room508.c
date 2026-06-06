inherit ROOM;
void create() {
	set( "short", "小木屋" );
	set( "object", ([
		"file3"    : "/open/ping/obj/chilin_legging",
		"file7"    : "/open/wu/obj/armband",
		"file8"    : "/open/wu/obj/ywhelme",
		"amount5"  : 1,
		"file5"    : "/open/gsword/obj/yau_glove",
		"amount1"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/gsword/obj/yuboots",
		"amount3"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/scholar/obj/icefan",
		"file2"    : "/open/ping/obj/ring-2",
		"file6"    : "/open/gsword/obj/yugem",
		"amount6"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/love/obj/cloth1",
		"amount4"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10019 );
	set( "item_desc", ([
		"新區域" : @ITEM
小小黃的房間
ITEM,
		"這裡一眼望去 只有一張床 跟一張小板凳" : @ITEM
這裡有張小桌子 但是上面都是灰塵
ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room509",
	]) );
	set( "long", @LONG
門口掛了張牌子 寫著小小黃的房間 進到裡面只見到一張小床
上面只有一層厚厚的灰塵 看來應該是許久沒有人進去過了
再仔細看去 牆上佈滿了蜘蛛網 還可以看到 老鼠從牆邊的破洞鑽了進去
讓你不由的心生厭惡 只想快點離去
LONG);
	setup();
	replace_program(ROOM);
}
