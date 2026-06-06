inherit ROOM;
void create() {
	set( "short", "$HIW$長庚醫院$HIR$急診室$NOR$" );
	set( "owner", "hamster" );
	set( "object", ([
		"amount6"  : 1,
		"amount9"  : 1,
		"amount3"  : 656,
		"file6"    : "/open/scholar/obj/icefan",
		"amount5"  : 1,
		"amount2"  : 1003,
		"file2"    : "/open/doctor/pill/sky_pill",
		"amount8"  : 685,
		"file3"    : "/open/doctor/item/ground_item",
		"amount1"  : 415,
		"file9"    : "/obj/gift/xiandan",
		"file5"    : "/obj/gift/hobowdan",
		"file8"    : "/open/doctor/item/sky_item",
		"file10"   : "/obj/gift/hobowdan",
		"amount7"  : 1,
		"file1"    : "/open/doctor/pill/gnd_pill",
		"amount10" : 1,
		"file4"    : "/open/common/obj/liz_meat",
		"amount4"  : 1,
		"file7"    : "/obj/gift/xisuidan",
	]) );
	set( "item_desc", ([
		"registration" : @ITEM

         掛號方式 : 
                       外科 : tell hamster heal代號gin
                       內科 : tell hamster heal代號kee
                      精神科: tell hamster heal代號sen
                      消防科: tell hamster deffire

         PS:請排隊看診, 每次看診需時兩秒

ITEM,
	]) );
	set( "build", 10120 );
	set( "exits", ([
		"south"     : "/open/clan/hell/room/room80",
		"north"     : "/open/clan/hell/room/hall",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
在魑魅魍魎橫行, 妖魔鬼怪充斥的陰曹地府內, 還是和陽間一樣需要醫生的,
因為陰間和人間的區別, 僅在於地上地下, 陰陽日夜之差別而已, 眾鬼怪嘍囉還是
會有七情六慾, 有生老病死, 因此水月立志要當個在陰間行醫濟世的醫生, 還特別
針對地府眾弟兄怕光怕熱的習性, 研究出了一套獨特的防火醫術, 如果你怕光怕熱,
或者身體違和的話, 記得向水月醫生掛號看病唷~~~

    掛號單(Registration)
LONG);
	setup();
	replace_program(ROOM);
}
