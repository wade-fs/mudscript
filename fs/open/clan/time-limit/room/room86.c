inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$NOR$$YEL$段家$NOR$" );
	set( "object", ([
		"amount5"  : 1,
		"amount4"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/obj/lin-cloud-fan",
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file5"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file6"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount9"  : 1,
		"amount10" : 1,
		"file4"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file8"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file7"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount8"  : 1,
		"file3"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file1"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount1"  : 1,
	]) );
	set( "build", 10125 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room87",
		"north"     : "/open/clan/time-limit/room/room85",
	]) );
	set( "long", @LONG
凌微雲扇飄(Lin-cloud-fan),純靈吟所使用的武器,為一神秘鑄將精心鑄造的
「八色靈器」之一,輕巧卻不失威力,隱隱透著幾股雲氣,純靈吟不但會用一陽指
定住你,還有飄陽扇放出火鳳凰攻擊你,最可怕的是飄陽指連擊,對你的生命造成
嚴重的威脅,而凌微雲扇飄除了當武器使用外,也是聚靈道裡通行的鑰匙

LONG);
	setup();
	replace_program(ROOM);
}
