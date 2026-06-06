inherit ROOM;
void create() {
	set( "short", "$HIM$酷思拉$HIC$小屋$NOR$" );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "item_desc", ([
		"swing" : @ITEM
不要懷疑...在你面前的東西的確是鞦韆...
ITEM,
		"flower" : @ITEM
一朵花、兩朵花、三朵花‧‧‧
‧‧‧
‧‧‧
N 朵花
你數到頭暈了.......
ITEM,
	]) );
	set( "object", ([
		"amount4"  : 121,
		"file1"    : "/obj/stone/powder",
		"amount10" : 1,
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 89,
		"amount5"  : 6,
		"file2"    : "/obj/stone/suipian",
		"file3"    : "/obj/stone/jiao",
		"amount6"  : 8,
		"amount2"  : 59,
		"file8"    : "/open/dancer/obj/maple_ribbon",
		"amount1"  : 15,
		"amount8"  : 1,
		"file7"    : "/open/ping/obj/poison_pill",
		"file4"    : "/open/mon/obj/mon-pill",
		"file10"   : "/obj/gift/shenliwan",
		"amount3"  : 2,
	]) );
	set( "light_up", 1 );
	set( "build", 10041 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room503",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
$HIW$$HBCYN$　　﹌　　　　　ζ　　　　　$NOR$　　　在你面前出現了一棟奇形怪狀的小屋，
$HIW$$HBCYN$　﹌　﹌　　　　　ζ　　　　　　$NOR$　　屋頂是用各種雜物拼湊起來，看起來相當
$HBCYN$　　　　　▂▂▂▂$BRED$$HIW$〒$HBCYN$　　　　　　$NOR$　　不牢固，但卻又不會塌下來，加上房子門
$HBCYN$　　　　◢$BRED$﹟﹟﹟﹟﹟$HBCYN$◣　　　　　$NOR$　　面的造形，大門上還有一個『酷』字，足
　　　◢$HBGRN$$HIM$╳╳╳╳╳╳╳$NOR$◣　　　　$NOR$　　見屋主品味多麼與眾不同‧‧‧
　　　　│⊕╭─╮⊕│$RED$╦╤╤╦　$NOR$
$HIY$β$HIC$Υ$HIR$ξ　$NOR$│★│$HBBLU$$HIW$酷$NOR$│★│$RED$∥$NOR$｜｜$RED$∥　$NOR$　　對了！屋子兩旁還有一片花埔(flower)和
$HIG$ΨΨΨ　$NOR$╰╮│　│╭╯$RED$∥$NOR$╘╛$RED$∥　$NOR$　　一座看起來快斷掉的鞦韆(swing)‧‧‧
$YEL$████████████████$NOR$

LONG);
	setup();
	replace_program(ROOM);
}
